#include <QDir>
#include <QFile>
#include <QDebug>
#include <QFileInfo>
#include <QFileInfoList>

#include <thread>
#include <chrono>

#include "filewalker.h"

FileWalker::FileWalker(size_t workersCount, const QString &startPath, const QString &textToFind, QObject *parent) :
    QObject(parent),
    mStartPath(startPath), mTextToFind(textToFind),
    mWaitCounter(0), mWorkersCount(workersCount),
    mIsFinished(false), mIsPaused(false),
    mPrefixFunction(mTextToFind.size(), 0) {
    computePrefixFunc();
}

FileWalker::~FileWalker() {
    joinWorkers();
}

void FileWalker::enqueue(const QString &path) {
    {
        std::lock_guard<std::mutex> lock(mEventMutex);

        if (!mIsFinished) {
            mTasks.push_back(path);
        }
    }

    mEvent.notify_one();
}

void FileWalker::startWalk() {
    mIsFinished = false;
    mIsPaused = false;
    mWorkers.clear();

    for (size_t i = 0; i < mWorkersCount; ++i) {
        mWorkers.emplace_back([=](){
            while (true) {
                QString task;
                {
                    std::unique_lock<std::mutex> lock(mEventMutex);

                    if (mIsFinished) {
                        break;
                    }

                    if (mIsPaused) {
                        mOnResume.wait(lock, [=]() { return !mIsPaused; });
                    }

                    {
                        std::lock_guard<std::mutex> counterLock(mWaitCounterMutex);
                        ++mWaitCounter;
                        if (mWaitCounter == mWorkersCount && mTasks.empty()) {
                            emit finish_search();
                            break;
                        }
                    }

                    mEvent.wait(lock, [=](){ return mIsFinished || !mTasks.empty(); });

                    {
                        std::lock_guard<std::mutex> counterLock(mWaitCounterMutex);
                        --mWaitCounter;
                    }

                    if (mIsFinished || mTasks.empty()) {
                        break;
                    }

                    task = std::move(mTasks.front());
                    mTasks.pop_front();
                }

                computeTask(task);
            }
        });
    }

    enqueue(mStartPath);
}

void FileWalker::pauseWalk() {
    {
        std::lock_guard<std::mutex> lock(mEventMutex);
        mIsPaused = true;
    }

    mEvent.notify_all();
}

void FileWalker::continueWalk() {
    {
        std::lock_guard<std::mutex> lock(mEventMutex);
        mIsPaused = false;
    }

    mOnResume.notify_all();

}

void FileWalker::finishWalk() {
    joinWorkers();
}

void FileWalker::computeTask(const QString &task) {
    if (QDir(task).exists()) {
        QDir dir = QDir(task);
        processDir(dir);
        return;
    }

    if (QFile(task).exists()) {
        QFile file(task, nullptr);
        processFile(file);
        return;
    }
}

void FileWalker::joinWorkers() {
    {
        std::unique_lock<std::mutex> lock(mEventMutex);
        if (mIsFinished) {
            return;
        }

        mIsFinished = true;
        mIsPaused = false;
    }

    mOnResume.notify_all();
    mEvent.notify_all();

    for (auto& worker : mWorkers) {
        worker.join();
    }
}

void FileWalker::m_print_text(QString message) {
    std::lock_guard<std::mutex> lock(mOutMutex);
    emit print_text(message);
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
}

void FileWalker::m_print_info(QString message) {
    std::lock_guard<std::mutex> lock(mOutMutex);
    emit print_info(message);
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
}

void FileWalker::m_print_error(QString message) {
    std::lock_guard<std::mutex> lock(mOutMutex);
    emit print_error(message);
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
}

void FileWalker::computePrefixFunc() {
    int j = 0, i = 1;

    while (i < mTextToFind.size()) {
        if (mTextToFind[j] == mTextToFind[i]) {
            mPrefixFunction[i] = j + 1;
            ++i;
            ++j;
        } else {
            if (j == 0) {
                mPrefixFunction[i] = 0;
                ++i;
            } else {
                j = mPrefixFunction[j - 1];
            }
        }
    }
}

void FileWalker::processDir(QDir &dir) {
    dir.setFilter(QDir::Dirs | QDir::Files | QDir::NoDotAndDotDot | QDir::NoSymLinks);
    for (const QFileInfo &fileInfo : dir.entryInfoList()) {
        {
            std::unique_lock<std::mutex> lock(mEventMutex);

            if (mIsFinished) {
                break;
            }

            if (mIsPaused) {
                mOnResume.wait(lock, [=]() { return !mIsPaused; });
            }
        }
        enqueue(fileInfo.absoluteFilePath());
    }
}

void FileWalker::processFile(QFile &file) {
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream textStream(&file);
        QString line, previousLine;
        long long lineCounter = 1;
        int patternPointer = 0, linePointer = 0;

        if (mTextToFind.isEmpty()) {
            std::lock_guard<std::mutex> outLock(mOutMutex);
            emit print_info("Filename: " + file.fileName());
            std::this_thread::sleep_for(std::chrono::milliseconds(10));

            do {
                {
                    std::unique_lock<std::mutex> lock(mEventMutex);

                    if (mIsFinished) {
                        break;
                    }

                    if (mIsPaused) {
                        mOnResume.wait(lock, [=]() { return !mIsPaused; });
                    }
                }

                line = textStream.read(100);
                emit print_text(line);
                std::this_thread::sleep_for(std::chrono::milliseconds(10));
            } while (!line.isNull());
        } else {
            do {
                {
                    std::unique_lock<std::mutex> lock(mEventMutex);

                    if (mIsFinished) {
                        break;
                    }

                    if (mIsPaused) {
                        mOnResume.wait(lock, [=]() { return !mIsPaused; });
                    }
                }

                previousLine = line;
                int messageSize = 100;
                int messageMargin = 50;
                line = textStream.read(messageSize);
                linePointer = 0;

                while (linePointer < line.size()) {
                    Q_ASSERT(linePointer >= 0 && patternPointer >= 0);
                    if (line[linePointer] == '\n') {
                        ++lineCounter;
                    }

                    while (patternPointer > 0 && line[linePointer] != mTextToFind[patternPointer]) {
                        Q_ASSERT(patternPointer >= 0);
                        patternPointer = mPrefixFunction[patternPointer - 1];
                        Q_ASSERT(patternPointer >= 0);
                    }

                    if (line[linePointer] == mTextToFind[patternPointer]) {
                        ++patternPointer;
                        if (patternPointer == mTextToFind.size()) {
                            QString preText = "", postText = "";
                            if (linePointer - (int)mTextToFind.size() + 1 < messageMargin) {
                                preText = previousLine.mid(
                                            std::max<int>(0,
                                                          messageSize - messageMargin + linePointer - mTextToFind.size() + 1));
                            }
                            preText += line.mid(std::max<int>(0, linePointer - (int)mTextToFind.size() + 1 - messageMargin),
                                                std::min<int>(messageMargin,
                                                              messageMargin + linePointer - (int)mTextToFind.size() + 1 - messageMargin));
                            postText = line.mid(linePointer + 1, messageMargin);

                            std::lock_guard<std::mutex> outLock(mOutMutex);
                            emit print_info("File: " + file.fileName() +
                                            ". Line: " + QString::number(lineCounter) +
                                            ". Text: ");
                            emit print_text("..." + preText);
                            emit print_error(mTextToFind);
                            emit print_text(postText + "..." + '\n');
                            std::this_thread::sleep_for(std::chrono::milliseconds(10));
                            patternPointer = 0;
                        }
                    }
                    ++linePointer;
                }
            } while (!line.isNull());
        }
    } else {
//        m_print_error("File: " + file.fileName() + " Unable to read file!" + '\n');
    }
}
