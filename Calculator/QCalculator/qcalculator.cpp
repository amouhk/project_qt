#include "qcalculator.h"
#include "ui_qcalculator.h"

QCalculator::QCalculator(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QCalculator)
{
    ui->setupUi(this);
}

QCalculator::~QCalculator()
{
    delete ui;
}
