#include <QDir>
#include <QDebug>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "filewalker.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MainWindow), fileWalker(nullptr) {
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}

// UI Slots
void MainWindow::on_startPathClear_clicked() {
    ui->startPathEdit->setText("");
}

void MainWindow::on_textToFindClear_clicked() {
    ui->textToFindEdit->setText("");
}

// Search Callback Slot
void MainWindow::on_search_complete() {
    on_stopSearchButton_clicked();
    on_info_browser_append("Search completed!");
}

// Output Callback Slots
void MainWindow::on_text_browser_append(const QString &message) {
    ui->searchResults->setTextColor("black");
    ui->searchResults->insertPlainText(message);
    ui->searchResults->moveCursor(QTextCursor::End);
}

void MainWindow::on_info_browser_append(const QString &message) {
    ui->searchResults->setTextColor("blue");
    ui->searchResults->insertPlainText(message);
    ui->searchResults->moveCursor(QTextCursor::End);
}

void MainWindow::on_error_browser_append(const QString &message) {
    ui->searchResults->setTextColor("red");
    ui->searchResults->insertPlainText(message);
    ui->searchResults->moveCursor(QTextCursor::End);
}

// Search States Slots
void MainWindow::on_startSearchButton_clicked() {
    ui->searchResults->clear();

    QString startPath = ui->startPathEdit->text();
    QString textToFind = ui->textToFindEdit->text();

    if (startPath.isEmpty() || !QFile(ui->startPathEdit->text()).exists()) {
        on_error_browser_append("Incorrect path! Please enter valid path!");
        return;
    }

    on_info_browser_append("Start searching...");

    ui->startSearchButton->setEnabled(false);
    ui->pauseSearchButton->setEnabled(true);
    ui->continueSearchButton->setEnabled(false);
    ui->stopSearchButton->setEnabled(true);

    fileWalker = new FileWalker(3, ui->startPathEdit->text(), ui->textToFindEdit->text(), this);

    connect(fileWalker, SIGNAL(finish_search()), this, SLOT(on_search_complete()));
    connect(fileWalker, SIGNAL(print_text(QString)), this, SLOT(on_text_browser_append(QString)));
    connect(fileWalker, SIGNAL(print_info(QString)), this, SLOT(on_info_browser_append(QString)));
    connect(fileWalker, SIGNAL(print_error(QString)), this, SLOT(on_error_browser_append(QString)));

    fileWalker->startWalk();
}

void MainWindow::on_pauseSearchButton_clicked() {
    fileWalker->pauseWalk();

//    on_info_browser_append("Search has been paused!");

    ui->startSearchButton->setEnabled(true);
    ui->pauseSearchButton->setEnabled(false);
    ui->continueSearchButton->setEnabled(true);
    ui->stopSearchButton->setEnabled(true);
}

void MainWindow::on_continueSearchButton_clicked() {
//    on_info_browser_append("Continue search...");

    fileWalker->continueWalk();

    ui->startSearchButton->setEnabled(false);
    ui->pauseSearchButton->setEnabled(true);
    ui->continueSearchButton->setEnabled(false);
    ui->stopSearchButton->setEnabled(true);
}

void MainWindow::on_stopSearchButton_clicked() {
    if (fileWalker != nullptr) {
        delete fileWalker;
    }

//    on_info_browser_append("Search has been stopped!");

    ui->startSearchButton->setEnabled(true);
    ui->pauseSearchButton->setEnabled(false);
    ui->continueSearchButton->setEnabled(false);
    ui->stopSearchButton->setEnabled(false);
}
