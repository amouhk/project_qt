#include "mathplugin.h"


MathPlugin::MathPlugin()
{
    m_opeList << QString("Addition") << QString("Soustraction")
              << QString("Multiplication") << QString("Division");
}

MathPlugin::~MathPlugin()
{
}


QStringList MathPlugin::operationList()
{
    return m_opeList;
}

bool MathPlugin::canCalculate( QString opName)
{
    return m_opeList.contains(opName);
}

int MathPlugin::numVariable( QString opName)
{
    if (opName.compare(QString("Addition")) == 0
            || opName.compare(QString("Multiplication")) == 0 )
        return 3;
    else
        return 2;
}

QString MathPlugin::calculate( QString opName, QStringList variableList)
{
    int l_result = 0;

    if ( opName.compare(QString("Addition")) == 0 )
    {
        l_result = 0;

        foreach(QString str, variableList)
        {
            std::cout << str << std::endl;
            l_result = l_result + str.toInt();
        }
    }
    else if ( opName.compare(QString("Multiplication")) == 0 )
    {
         l_result = 1;

        foreach(QString str, variableList)
        {
            l_result *= str.toInt();
        }
    }
    else if ( opName.compare(QString("Soustraction")) == 0 )
    {
        l_result = variableList.at(0).toInt() - variableList.at(0).toInt();
    }
    else if ( opName.compare(QString("Division")) == 0 )
    {
       l_result = variableList.at(0).toInt() / variableList.at(0).toInt();
    }

    return QString("%1").arg(l_result);

}
