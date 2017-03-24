#ifndef OPERATIONINTERFACE_H
#define OPERATIONINTERFACE_H

#include <QString>
#include <QStringList>

namespace Operation
{
    class OperationInterface
    {
    public:
        virtual QStringList operationList() = 0;
        virtual bool canCalculate( QString opName) = 0;
        virtual int numVariable( QString opName) = 0;
        virtual QString calculate( QString opName, QStringList variableList) = 0;
    };
}

#endif // OPERATIONINTERFACE_H

Q_DECLARE_INTERFACE(Operation::OperationInterface, "tp.calculator.OperationInterface/1.0")
