#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QFileDialog>
#include <QGraphicsView>
#include <QMessageBox>
#include <QTextStream>
#include <QXmlInputSource>
#include <QXmlReader>
#include "scenehandler.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    undoStack   = new QUndoStack(0);
    undoView    = 0;
    QMenu* fileMenu     = menuBar()->addMenu(QString(tr("&File")));
    // TODO ajouter un Scene new()
    QAction* openAction = fileMenu->addAction(QString(tr("&Open ...")), this, SLOT(fileOpen()));
    openAction->setShortcut(QKeySequence::Open);
    QAction* saveAction = fileMenu->addAction(QString(tr("&Save as ...")), this, SLOT(fileSaveAs()));
    saveAction->setShortcut(QKeySequence::SaveAs);
    fileMenu->addSeparator();
    QAction* quitAction  = fileMenu->addAction(QString(tr("&Quit ...")), this, SLOT(fileQuit()));
    quitAction->setShortcut(QKeySequence::Quit);

    QMenu* editMenu     = menuBar()->addMenu(QString(tr("&Edit")));
    QAction* undoAction = undoStack->createUndoAction(this);
    undoAction->setShortcut(QKeySequence::Undo);
    QAction* redoAction = undoStack->createRedoAction(this);
    redoAction->setShortcut(QKeySequence::Redo);
    editMenu->addAction(undoAction);
    editMenu->addAction(redoAction);

    QMenu* viewMenu     = menuBar()->addMenu(QString(tr("&View")));
    viewMenu->addAction(QString(tr("&Undo stack")), this, SLOT(showUndoStack()));

    menuBar()->addMenu(QString(tr("&Simulate")));
    menuBar()->addMenu(QString(tr("&Help")));

    scene   = new Scene(this, undoStack);
    QGraphicsView* view = new QGraphicsView(scene, this);
    view->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    this->setCentralWidget(view);

    showMessage(QString(tr("Application is ready")));
    connect(scene, SIGNAL(message(QString)), this, SLOT(showMessage(QString)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showMessage(QString qMessage)
{
    statusBar()->showMessage(qMessage);
}

void MainWindow::showUndoStack()
{
    if (undoView == 0) // undoView invisible
    {
        undoView    = new QUndoView(undoStack);
        // Configuration de undoView
        undoView->setWindowTitle(QString(tr("QSimulate - undo stack")));
        undoView->setAttribute(Qt::WA_QuitOnClose, true);
        undoView->setAttribute(Qt::WA_WState_ExplicitShowHide, true);
        undoView->setAutoScroll(true);
        undoView->setGeometry(geometry().x() + width() + 10, geometry().y(), 200, height());
    }
    undoView->show();
}

bool MainWindow::fileSaveAs()
{
    QString filter      = QString(tr("XML files (*.xml)"));
    QString filename    = QFileDialog::getSaveFileName(this, QString(tr("Save stations")),
                                       QApplication::applicationDirPath(), filter);
    if (filename.isEmpty()) {
        showMessage(QString(tr("Invalid File name")));
        return false;
    } else {
        QFile outputFile(filename);
        if (!outputFile.open(QIODevice::WriteOnly)) {
            showMessage(QString(tr("File %1 is not writable")).arg(filename));
            return false;
        } else {
            QDomDocument* document = new QDomDocument();
            scene->toXML(document);
            QTextStream stream(&outputFile);
            stream << document->toString();
            outputFile.close();
            showMessage(QString(tr("XML transformation")));
        }
    }
    return true;
}

bool MainWindow::fileOpen()
{
    QString filename    = QFileDialog::getOpenFileName(this, QString(tr("Open file name")),
                                 QApplication::applicationDirPath(), QString(tr("Data (*.xml)")));
    if (!filename.isEmpty()) {
        QFile inputFile(filename);
        if (inputFile.open(QIODevice::ReadOnly)) {
            QXmlInputSource source(&inputFile);
            scene->clear();
            QXmlSimpleReader reader;

            SceneHandler handler(scene, undoStack);
            reader.setContentHandler(&handler);
            return reader.parse(&source);
        } else {
            showMessage(QString(tr("The file %1 is not readable")).arg(filename));
        }
    } else {
        showMessage(QString("Bad answer"));
    }
    return false;
}

bool MainWindow::fileQuit()
{
   int answer = QMessageBox::question(this, QString(tr("Close Window")), QString(tr("Are you sure ?")),
                          QMessageBox::Yes|QMessageBox::No);
   if (answer == QMessageBox::Yes) {
       this->close();
       return true;
   } else {
       int response = QMessageBox::warning(this, QString(tr("Save Scene")),
                                           QString(tr("Do you want to save the scene ? ")),
                                           QMessageBox::Save|QMessageBox::Discard);
       if (response == QMessageBox::Save)
           return fileSaveAs();
   }
   return true;
}
