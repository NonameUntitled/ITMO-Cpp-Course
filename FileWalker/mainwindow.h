#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QString>
#include <QThread>
#include <QMainWindow>
#include <QDirIterator>

#include "filewalker.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

    ~MainWindow();

private slots:
    void on_startPathClear_clicked();

    void on_textToFindClear_clicked();

    void on_text_browser_append(const QString &);

    void on_info_browser_append(const QString &);

    void on_error_browser_append(const QString &);

    void on_search_complete();

    void on_startSearchButton_clicked();

    void on_pauseSearchButton_clicked();

    void on_continueSearchButton_clicked();

    void on_stopSearchButton_clicked();


private:
    Ui::MainWindow *ui;

    FileWalker *fileWalker;
};

#endif
