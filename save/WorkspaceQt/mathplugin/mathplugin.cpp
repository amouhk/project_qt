#include "mathplugin.h"
#include <iostream>
using namespace std;

MathPlugin::MathPlugin()
{
    opList << "Addition" << "Soustraction" << "Multiplication" << "Division";
}

MathPlugin::~MathPlugin()
{

}

QStringList MathPlugin::operationList()
{
    return opList;
}

bool MathPlugin::canCalculate(QString opName)
{
    return opList.contains(opName);
}

int MathPlugin::numVariable(QString opName)
{
    if (opName.compare(QString("Addition")) == 0
            || opName.compare(QString("Multiplication")) == 0)
        return 3;
    else
        return 2;
}

QString MathPlugin::calculate(QString opName, QStringList variableList)
{
    if (opName.compare(QString("Addition")) == 0) {
        int sum = 0;
        for (int index = 0; index < variableList.length(); index++) {
            sum = sum + variableList.at(index).toInt();
        }
        return QString("%1").arg(sum);
    } else if (opName.compare(QString("Soustraction")) == 0) {
        int diff = 0;
        diff = variableList.at(0).toInt() - variableList.at(1).toInt();
        return QString("%1").arg(diff);
    } else if (opName.compare(QString("Multiplication")) == 0) {
        int mult = 0;
        for (int index = 0; index < variableList.length(); index++) {
            mult = mult * variableList.at(index).toInt();
        }
        return QString("%1").arg(mult);
    } else if (opName.compare(QString("Division")) == 0) {
        int division = 0;
        division = variableList.at(0).toInt() / variableList.at(1).toInt();
        return QString("%1").arg(division);
    } else
        cout << "Operation inconnue " << opName.toStdString() << endl;
}
