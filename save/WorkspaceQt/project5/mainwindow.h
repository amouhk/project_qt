#ifndef MAINWINDOW_H
#define MAINWINDOW_H
class MainWindow;
#include <QMainWindow>
#include <QString>

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
private slots:
    // combo box
    void operationChange(QString opName);
    // line edit
    void valueChange(QString value);
};

#endif // MAINWINDOW_H
