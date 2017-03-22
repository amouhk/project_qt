#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>
#include <QFile>
#include <QColor>
#include <QTextStream>
#include <QTextCursor>
#include <QDebug>

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
    QList<QString> m_info;

    // Declaration de slots
private slots:
    // Callback pour quitter l'application
    void quit();
    // Callback pour l'ajout de texte. (addbutton)
    void add();

    //Progress Bar actions
    void incr();
    void reset();


};

#endif // MAINWINDOW_H
