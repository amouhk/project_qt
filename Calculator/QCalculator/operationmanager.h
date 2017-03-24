#ifndef OPERATIONMANAGER_H
#define OPERATIONMANAGER_H

class OperationManager;

#include <QList>
#include "OperationInterface.h"

namespace Operation
{
    class OperationManager
    {

    public:
       virtual ~OperationManager();
       static OperationManager * getInstance();

       QStringList operationList();
       int numVariable(QString opName);
       QString calculate( QString opName, QStringList operandes);


    private:
        OperationManager();
        static OperationManager* m_instance;
        QList<OperationInterface*> m_operationList;
    };
}

#endif // OPERATIONMANAGER_H

