#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QMenu>
#include <QAction>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Implementation d'un MVC
    // Modele
    mp_undoStack = new QUndoStack(this);
    // Vue
    mp_undoView  = 0;

    /*** MenuBar ***/
    QMenu* lp_fileMenu = menuBar()->addMenu(QString("&File"));
    QAction* lp_saveAction = lp_fileMenu->addAction(QString("Save as ..."), this, SLOT(fileSaveAs()));
    lp_saveAction->setShortcut(QKeySequence::SaveAs);

    QMenu* l_editMenu = menuBar()->addMenu( "&Edit" );
    QAction* lp_undoAction = mp_undoStack->createUndoAction( this );
    QAction* lp_redoAction = mp_undoStack->createRedoAction( this );
    lp_undoAction->setShortcut( QKeySequence::Undo );
    lp_redoAction->setShortcut( QKeySequence::Redo );
    l_editMenu->addAction( lp_undoAction );
    l_editMenu->addAction( lp_redoAction );

    // Modification du menu View
    QMenu* l_viewMenu = menuBar()->addMenu(QString("&View"));
    l_viewMenu->addAction(QString("Undo Stack"), this, SLOT(showUndoStack()));


    menuBar()->addMenu(QString("&Simulate"));
    menuBar()->addMenu(QString("&Help"));

    /*** Notre Scene ***/

    //Creation du modele(Scene) et de la vue(View)
    mp_scene = new Model::Scene(this, mp_undoStack);
    QGraphicsView* lp_view = new QGraphicsView(mp_scene, this);

    // Ajout de la vue sur la fenetre
    lp_view->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    this->setCentralWidget(lp_view);

    // Connection du signal de la scene a la bar de status
    connect(mp_scene, SIGNAL(message(QString)), this, SLOT(showMessage(QString)));

    /*** Status Bar ***/
    //statusBar()->showMessage("QSimulate is ready");
    showMessage(QString("QSimulate is ready"));


}

//--------------------------------------------------------------------------------

MainWindow::~MainWindow()
{
    std::cout << "Delete Mainwindow" << std::endl;
    delete mp_undoView;
    delete ui;
}

//--------------------------------------------------------------------------------

void MainWindow::showMessage(QString ai_msg)
{
    statusBar()->showMessage(ai_msg);
}

//--------------------------------------------------------------------------------

void MainWindow::showUndoStack()
{
    if (mp_undoView == 0) // pas de vue (invisible)
    {
        // Instanciation du modele aupres de la vue
        mp_undoView = new QUndoView(mp_undoStack);

        // Configuration de la fenetre d'affichage
        mp_undoView->setWindowTitle(QString("QSimulate - undo stack"));
        mp_undoView->setAttribute(Qt::WA_QuitOnClose, true);
        mp_undoView->setAutoScroll(true);
        mp_undoView->setGeometry(geometry().x() + geometry().width() + 2, geometry().y(), 50, 100);
    }
    mp_undoView->show();
}

//--------------------------------------------------------------------------------
bool MainWindow::fileSaveAs()
{
    QString l_outputFilename = QFileDialog::getSaveFileName(this, QString("Save Station"),
                                                    QApplication::applicationDirPath(), QString("(*.xml)"));

    if (l_outputFilename.isEmpty())
    {
        showMessage(QString("Invalid Filename"));
        return false;
    }
    else
    {
        QFile l_outputFile(l_outputFilename);
        if ( l_outputFile.open(QIODevice::WriteOnly) )
        {
            showMessage(QString("File %1 is not written yet").arg(l_outputFilename));
        }
    }
}
