#ifndef MATHPLUGIN_H
#define MATHPLUGIN_H
#include <QObject>
#include <QString>
#include <QStringList>
#include "OperationInterface.h"
/* plugin pour Addition, Soustraction, Multiplication, Division */
class MathPlugin: public QObject, public OperationInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "project5/OperationInterface/1.0")
    Q_INTERFACES(OperationInterface)
public:
    MathPlugin();
    virtual ~MathPlugin();
    virtual QStringList operationList();
    virtual bool canCalculate(QString opName);
    virtual int numVariable(QString opName);
    virtual QString calculate(QString opName, QStringList variableList);
private:
    QStringList opList;
};

#endif // MATHPLUGIN_H
