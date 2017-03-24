#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStringList>
#include "operationmanager.h"
#include <iostream>
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->operationsCB, SIGNAL(activated(QString)), this, SLOT(operationChange(QString)));
    connect(ui->variable1LE, SIGNAL(textChanged(QString)), this, SLOT(valueChange(QString)));
    connect(ui->variable2LE, SIGNAL(textChanged(QString)), this, SLOT(valueChange(QString)));
    connect(ui->variable3LE, SIGNAL(textChanged(QString)), this, SLOT(valueChange(QString)));
    QStringList operationList   = OperationManager::getInstance()->operationList();
    ui->operationsCB->addItems(operationList);
    ui->operationsCB->setCurrentIndex(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}
// callback du combo box
void MainWindow::operationChange(QString opName)
{
    int paramNumber = OperationManager::getInstance()->numVariable(opName);
    ui->variable1LE->setEnabled(paramNumber >= 1);
    ui->variable2LE->setEnabled(paramNumber >= 2);
    ui->variable3LE->setEnabled(paramNumber >= 3);
    valueChange(QString(opName));
}
// callback des line edit
void MainWindow::valueChange(QString value)
{
    QStringList operandes;
    cout << "value = " << value.toStdString() << endl;
    if (ui->variable1LE->isEnabled()) // TODO traiter l'absence de saisie afin de ne pas décaler les parametres
        operandes.append(ui->variable1LE->text());
    if (ui->variable2LE->isEnabled())
        operandes.append(ui->variable2LE->text());
    if (ui->variable3LE->isEnabled())
        operandes.append(ui->variable3LE->text());
    QString opName  = ui->operationsCB->currentText();
    cout << "opName = " << opName.toStdString() << endl;
    QString result = OperationManager::getInstance()->calculate(opName, operandes);
    ui->resultLE->setText(result);
}
