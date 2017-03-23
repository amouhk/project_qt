#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QMenu>
#include <QAction>
#include <QFileDialog>
#include <QTextStream>
#include <QXmlSimpleReader>
#include <QMessageBox>
#include <QCloseEvent>
#include "scenexmlcontenthandler.h"

using namespace Model;

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
    // Modification du menu File
    QMenu* lp_fileMenu       = menuBar()->addMenu(QString("&File"));
    QAction* lp_newAction    = lp_fileMenu->addAction(QString("New"), this, SLOT(fileNew()));
    QAction* lp_openAction   = lp_fileMenu->addAction(QString("Open ..."), this, SLOT(fileOpen()));
    QAction* lp_saveAction   = lp_fileMenu->addAction(QString("Save ..."), this, SLOT(fileSave()));
    QAction* lp_saveAsAction = lp_fileMenu->addAction(QString("Save as ..."), this, SLOT(fileSaveAs()));
    lp_fileMenu->addSeparator();
    QAction* lp_quitAction   = lp_fileMenu->addAction(QString("Save as ..."), this, SLOT(close()));

    lp_newAction->setShortcut( QKeySequence::New );
    lp_openAction->setShortcut( QKeySequence::Open );
    lp_saveAction->setShortcut( QKeySequence::Save );
    lp_saveAsAction->setShortcut( QKeySequence::Save );
    lp_quitAction->setShortcut( QKeySequence::Quit );

    // Modification du menu Edit
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

bool MainWindow::fileNew()
{
  clearSceneDialog(QString("Create new scene"), QString("Create new scene"));
}

//--------------------------------------------------------------------------------

bool MainWindow::fileOpen()
{
    QString l_inputFilename = QFileDialog::getOpenFileName(this, QString("Open File"), QApplication::applicationDirPath(),
                                 QString("Files (*.xml)"));

    if (l_inputFilename.isEmpty())
    {
        showMessage(QString("Fail : Invalid Input filepath"));
        return false;
    }

    QFile l_inputFile(l_inputFilename, this);

    if ( ! l_inputFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        showMessage(QString("Fail : Can not Open file %1").arg(l_inputFilename));
        l_inputFile.close();
        return false;
    }

    // Parser le fichier xml
    QXmlSimpleReader l_xmlReader;
    QXmlInputSource l_xmlSource(&l_inputFile);
    SceneXmlContentHandler* lp_sceneHandler = new SceneXmlContentHandler(mp_undoStack, mp_scene);

    l_xmlReader.setContentHandler(lp_sceneHandler);
    l_xmlReader.parse(&l_xmlSource);

    showMessage(QString("Success : Open file %1").arg(l_inputFilename));

    return true;
}

//--------------------------------------------------------------------------------

bool MainWindow::fileSave()
{
    return false;
}

//--------------------------------------------------------------------------------

bool MainWindow::fileSaveAs()
{
    QString l_outputFilename = QFileDialog::getSaveFileName(this, QString("Save Station"),
                                                    QApplication::applicationDirPath(), QString("Files (*.xml)"));

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
            // creer le stream de sortie
             QTextStream l_outputStream(&l_outputFile);

            //creer un QDomDocumlenbt
            QDomDocument* l_xmlDocument = new QDomDocument("");

            mp_scene->toXML(l_xmlDocument);

            l_outputStream << *l_xmlDocument;

            showMessage(QString("File %1 is not written yet").arg(l_outputFilename));
        }
        return true;
    }
}

//--------------------------------------------------------------------------------

void MainWindow::closeEvent(QCloseEvent * event)
{
    clearSceneDialog(QString("Close application"), QString("Close application"));
}

//--------------------------------------------------------------------------------

//bool MainWindow::quit()
//{
//    emit( closeEvent() );
//}

//--------------------------------------------------------------------------------

void MainWindow::clearSceneDialog(QString label, QString msg)
{
    if ( mp_scene != 0 && mp_undoStack != 0 )
    {
        if (mp_scene->items().count() < 1)
        {
            QMessageBox::information(this, label, msg);
        }
        else
        {
             // Demander a l'utilisatteur de sauvegarder l'etat.
            int l_res = QMessageBox::question(this, label,
                                   QString("Do you want to save this state ?"),
                                   QMessageBox::Yes, QMessageBox::No);

            if ( l_res == QMessageBox::Yes )
            {
                 if ( fileSaveAs() )
                 {
                     QMessageBox::information(this, label, QString(" Save Success"));
                 }

            }
            else
            {
                 QMessageBox::information(this, label, QString("Data lost"));
            }
        }
        mp_scene->clear();
        mp_undoStack->clear();
    }
}


