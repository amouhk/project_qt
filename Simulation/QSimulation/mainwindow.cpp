#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

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
    menuBar()->addMenu(QString("&File"));
    menuBar()->addMenu(QString("&Edit"));

    // Modification du menu View
    QMenu* l_viewMenu = menuBar()->addMenu(QString("&View"));
    l_viewMenu->addAction(QString("Undo Stack"), this, SLOT(showUndoStack()));
    //menuBar()->addMenu(QString("&View"));

    menuBar()->addMenu(QString("&Simulate"));
    menuBar()->addMenu(QString("&Help"));

    /*** Notre Scene ***/

    //Creation du modele(Scene) et de la vue(View)
    mp_scene = new Model::Scene(this);
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