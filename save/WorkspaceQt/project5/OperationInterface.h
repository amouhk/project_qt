#ifndef OPERATIONINTERFACE_H
#define OPERATIONINTERFACE_H
class OperationInterface;
#include <QString>
#include <QStringList>

/* Contrat de codage */
class OperationInterface
{
public:
    virtual ~OperationInterface() {}
    virtual QStringList operationList() = 0;
    virtual bool canCalculate(QString opName) = 0;
    virtual int numVariable(QString opName) = 0;
    virtual QString calculate(QString opName, QStringList variableList) = 0;
};
Q_DECLARE_INTERFACE(OperationInterface, "project5/OperationInterface/1.0")
#endif // OPERATIONINTERFACE_H
