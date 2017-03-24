#ifndef QCALCULATOR_H
#define QCALCULATOR_H

#include <QMainWindow>
#include <QString>

namespace Ui {
class QCalculator;
}

class QCalculator : public QMainWindow
{
    Q_OBJECT

public:
    explicit QCalculator(QWidget *parent = 0);
    ~QCalculator();

private:
    Ui::QCalculator *ui;

private slots:
    void operationChanged(QString opName);
    void valueChanged(QString value);
};

#endif // QCALCULATOR_H
