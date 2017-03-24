#include "operationmanager.h"
#include <QDir>
#include <QStringList>
#include <QApplication>
#include <QPluginLoader>
#include <iostream>

using namespace std;

namespace Operation
{
     OperationManager* OperationManager::m_instance = 0;

    // -------------------------------------------------------------------------

    OperationManager* OperationManager::getInstance()
    {
        if (m_instance == 0)
        {
            return m_instance = new OperationManager();
        }

        return m_instance;
    }

    // -------------------------------------------------------------------------

    // Chager les plugin depuis un repertoire de "plugin"
    // pour les faire apparaitre dans le combox
    OperationManager::OperationManager()
    {
        QDir l_pluginsDir = QDir(QApplication::applicationDirPath());

        std::cout << QApplication::applicationDirPath().toStdString() << std::endl;

        if (  ! l_pluginsDir.cd("../../../plugins") )
        {
            std::cout << " Echec instantiation de OperationManager" << std::endl;
            return ;
        }

        std::cout << l_pluginsDir.path().toStdString() << std::endl;

        foreach (QString l_pluginName, l_pluginsDir.entryList())
        {
            QPluginLoader l_pluginLoader(l_pluginsDir.absoluteFilePath(l_pluginName));
            QObject* l_plugin = l_pluginLoader.instance();

            if (l_plugin == 0)
            {
                std::cout << "Mauvaix plugin " << std::endl;
            }
            else
            {
                //std::cout << << std::endl;
                OperationInterface * l_operation = qobject_cast<OperationInterface*>(l_plugin);
                if (l_operation == 0)
                {
                    std::cout << "Ce plugin n'a pas la meme interface que OperationInterface" << std::endl;
                }
                else
                {
                    m_operationList.append(l_operation);
                }
            }
        }
    }

    // -------------------------------------------------------------------------

    OperationManager::~OperationManager()
    {

    }

    // -------------------------------------------------------------------------

    // Remplisasge de ma comboBox
    QStringList OperationManager::operationList()
    {
        QStringList l_resultats;

        foreach (OperationInterface* lp_operation, m_operationList)
        {
            l_resultats << lp_operation->operationList();
        }

        return l_resultats;
    }

    // -------------------------------------------------------------------------

    int OperationManager::numVariable(QString opName)
    {
        foreach (OperationInterface* lp_operation, m_operationList)
        {
            if (lp_operation->operationList().contains(opName))
            {
                return lp_operation->numVariable(opName);
            }
        }
    }

    // -------------------------------------------------------------------------

    // ToDo :  get the index of select op then operation name

    // -------------------------------------------------------------------------

    QString OperationManager::calculate( QString opName, QStringList operandes)
    {
        foreach (OperationInterface* lp_operation, m_operationList)
        {
            if (lp_operation->operationList().contains(opName))
            {
                return lp_operation->calculate(opName, operandes);
            }

        }
    }



}
