#include "qcalculator.h"
#include "ui_qcalculator.h"
#include "operationmanager.h"
#include <iostream>

QCalculator::QCalculator(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QCalculator)
{
    ui->setupUi(this);

    connect(ui->operationCBox, SIGNAL(activated(QString)), this, SLOT(operationChanged(QString)));
    connect(ui->var1LineEdit, SIGNAL(textChanged(QString)), this, SLOT(valueChanged(QString)));
    connect(ui->var2LineEdit, SIGNAL(textChanged(QString)), this, SLOT(valueChanged(QString)));
    connect(ui->var3LineEdit, SIGNAL(textChanged(QString)), this, SLOT(valueChanged(QString)));
    connect(ui->resultlineEdit, SIGNAL(textChanged(QString)), this, SLOT(valueChanged(QString)));

    QStringList l_operationList = Operation::OperationManager::getInstance()->operationList();

    ui->operationCBox->addItems(l_operationList);
    ui->operationCBox->setCurrentIndex(0);
}

QCalculator::~QCalculator()
{
    delete ui;
}

void QCalculator::operationChanged(QString opName)
{
    int l_paramNumber = Operation::OperationManager::getInstance()->numVariable(opName);
    ui->var1LineEdit->setEnabled( l_paramNumber >= 1);
    ui->var2LineEdit->setEnabled( l_paramNumber >= 2);
    ui->var3LineEdit->setEnabled( l_paramNumber >= 3);
    valueChanged(QString());
}

void QCalculator::valueChanged(QString value)
{
    QStringList l_operande;

    if (ui->var1LineEdit->isEnabled())
    {
        l_operande.append(ui->var1LineEdit->text());
    }
    else if ( ui->var2LineEdit->isEnabled() )
    {
       l_operande.append(ui->var2LineEdit->text());
    }
    else if ( ui->var2LineEdit->isEnabled() )
    {
       l_operande.append(ui->var3LineEdit->text());
    }

    QString l_opName = ui->operationCBox->currentText();
    QString l_result = Operation::OperationManager::getInstance()->calculate(l_opName, l_operande);


    std::cout << "fin " << std::endl;

    ui->resultlineEdit->setText(l_result);

    std::cout << "fin " << std::endl;

}
