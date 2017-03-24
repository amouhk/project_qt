#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>
#include <Qstring>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QList<QString> infos;

private slots:
    // quit button callback
    void quit();
    // add button callback
    void add();
    // next button callback
    void next();
    // clear button callback
    void clear();

};

#endif // MAINWINDOW_H
