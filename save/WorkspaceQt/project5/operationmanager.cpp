#include "operationmanager.h"
#include <QApplication>
#include <QDir>
#include <QPluginLoader>
#include <iostream>
using namespace std;

OperationManager* OperationManager::instance = NULL;

OperationManager* OperationManager::getInstance()
{
    if (instance == NULL) {
        instance = new OperationManager();
    }
    return instance;
}

/* Charger les plugins depuis un répertoire "plugins"
 * pour les faire apparaitre dans le combo box */
OperationManager::OperationManager()
{
    QDir pluginsDir = QDir(QApplication::applicationDirPath());
    bool exist      = pluginsDir.cd("plugins");
    cout << "plugins exit ? " << exist << endl;
    foreach (QString pluginName, pluginsDir.entryList()) {
        QPluginLoader loader(pluginsDir.absoluteFilePath(pluginName));
        cout << loader.fileName().toStdString() << endl;
        QObject* plugin = loader.instance();
        if (plugin == 0) {
            cout << "Mauvais Plugin dans " << loader.fileName().toStdString() << endl;
        } else {
            OperationInterface* operations = qobject_cast<OperationInterface*>(plugin);
            if (operations == 0) {
                cout << "Ce plugin ne respecte pas le contrat OperationInterface" << endl;
            } else {
                opList.append(operations);
            }
        }
    }
}

OperationManager::~OperationManager()
{

}
/* Pour remplir le combo box */
QStringList OperationManager::operationList()
{
    QStringList results;
    foreach (OperationInterface* op, opList) {
        results << op->operationList();
    }
    return results;
}

int OperationManager::numVariable(QString opName)
{
    foreach (OperationInterface* op, opList) {
        if (op->operationList().contains(opName))
            return op->numVariable(opName);
    }
    return 0;
}
// TODO numVariable(const int indexInCombo)

QString OperationManager::calculate(QString opName, QStringList operandes)
{
    foreach (OperationInterface* op, opList) {
        if (op->operationList().contains(opName))
            return op->calculate(opName, operandes);
    }
    return QString("Unknown");
}

