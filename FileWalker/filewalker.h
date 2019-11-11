#ifndef FILEWALKER_H
#define FILEWALKER_H

#include <mutex>
#include <thread>
#include <condition_variable>

#include <QDir>
#include <QFile>
#include <QQueue>
#include <QString>
#include <QThread>
#include <QTextBrowser>

class FileWalker : public QObject {
    Q_OBJECT
public:
    explicit FileWalker(size_t, const QString &, const QString &, QObject *parent = nullptr);

    ~FileWalker();

    void enqueue(const QString &path);

    void startWalk();

    void pauseWalk();

    void continueWalk();

    void finishWalk();

    void clearInfo();

signals:
    void finish_search();

    void print_text(const QString &output);

    void print_info(const QString &output);

    void print_error(const QString &output);

private:
    QString mStartPath;
    QString mTextToFind;

    size_t mWaitCounter;
    size_t mWorkersCount;

    bool mIsFinished;
    bool mIsPaused;

    QQueue<QString> mTasks;
    std::vector<std::thread> mWorkers;

    std::mutex mOutMutex;
    std::mutex mEventMutex;
    std::mutex mWaitCounterMutex;

    std::condition_variable mEvent;
    std::condition_variable mOnResume;

    std::vector<size_t> mPrefixFunction;

    void computeTask(const QString &);

    void joinWorkers();

    void m_print_text(QString message);

    void m_print_info(QString message);

    void m_print_error(QString message);

    void computePrefixFunc();

    void processDir(QDir &);

    void processFile(QFile &);

};

#endif
