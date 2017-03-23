#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenuBar>
#include <QStatusBar>
#include <QGraphicsView>
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
    void showMessage(QString);  /*!< Slot de reception des messages*/
    void showUndoStack();       /*!< Slot de l'action undo */

    bool fileNew();
    bool fileOpen();
    bool fileSave();
    bool fileSaveAs();
    //bool quit(); voir close() inheritant

protected:
    void clearSceneDialog(QString label, QString msg);
    virtual void closeEvent(QCloseEvent * event);

private:
    Ui::MainWindow *ui;

    Model::Scene* mp_scene;     /*!< Donnees du model */
    QUndoStack* mp_undoStack;   /*!< Modele de donnes de ma pile */

    QUndoView* mp_undoView;     /*!< Vue de ma pile */

};

#endif // MAINWINDOW_H
