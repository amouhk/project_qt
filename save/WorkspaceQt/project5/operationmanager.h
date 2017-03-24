#ifndef OPERATIONMANAGER_H
#define OPERATIONMANAGER_H
class OperationLManager;
#include <QList>
#include <QString>
#include <QStringList>
#include "OperationInterface.h"

/* Singleton */
class OperationManager
{
public:
    static OperationManager* getInstance();
    virtual ~OperationManager();
    virtual QStringList operationList();
    virtual int numVariable(QString opName);
    virtual QString calculate(QString opName, QStringList operandes);
    //virtual void setSelectedOperation(QString opName);
private:
    OperationManager();
    static OperationManager* instance;

    QList<OperationInterface *> opList;
    OperationInterface* selectedOperation;
};

#endif // OPERATIONMANAGER_H
