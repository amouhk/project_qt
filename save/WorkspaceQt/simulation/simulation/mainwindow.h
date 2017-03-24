#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "scene.h"
#include <QUndoStack>
#include <QUndoView>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    void showMessage(QString);
    void showUndoStack();
    bool fileSaveAs();
    bool fileOpen();
    bool fileQuit();
private:
    Ui::MainWindow *ui;
    Scene* scene;
    QUndoStack* undoStack;
    QUndoView* undoView;
};

#endif // MAINWINDOW_H
