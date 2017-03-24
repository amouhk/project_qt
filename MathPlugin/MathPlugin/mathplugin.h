#ifndef MATHPLUGIN_H
#define MATHPLUGIN_H

class MathPlugin;

#include "OperationInterface.h"
#include <QStringList>

class MathPlugin : public QObject, public Operation::OperationInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "tp.calculator.OperationInterface/1.0")
    Q_INTERFACES(Operation::OperationInterface)

public:
    MathPlugin();
    virtual ~MathPlugin();

    virtual QStringList operationList();
    virtual bool canCalculate( QString opName) ;
    virtual int numVariable( QString opName);
    virtual QString calculate( QString opName, QStringList variableList);

private:
    QStringList m_opeList;

};

#endif // MATHPLUGIN_H
