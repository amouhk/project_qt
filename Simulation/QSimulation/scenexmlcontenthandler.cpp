#include "scenexmlcontenthandler.h"
#include "commandstationadd.h"
#include "commandstationdelete.h"
#include "commandstationmove.h"
#include <iostream>

namespace Model
{
    //-----------------------------------------------------------------------------------------------
    SceneXmlContentHandler::SceneXmlContentHandler(QUndoStack* undoStack, Scene* scene)
    {
        std::cout << "Create : SceneXmlContentHandler::SceneXmlContentHandler" << std::endl;
        mp_undoStack = undoStack;
        mp_scene     = scene;
    }

        //-----------------------------------------------------------------------------------------------
    SceneXmlContentHandler::~SceneXmlContentHandler()
    {

    }

    //-----------------------------------------------------------------------------------------------

    bool SceneXmlContentHandler::startDocument()
    {
        std::cout << "Call : SceneXmlContentHandler::startDocument" << std::endl;
        return true;
    }

    //-----------------------------------------------------------------------------------------------

    bool SceneXmlContentHandler::startElement(const QString &namespaceURI, const QString &localName,
                              const QString &qName, const QXmlAttributes &atts)
    {

        std::cout << "Call : SceneXmlContentHandler::startElement" << std::endl;

        if( qName.compare(QString("SCENE")) == 0)
        {
            mp_undoStack->clear();
        }
        else if ( qName.compare(QString("PositionADD")) == 0 )
        {

            QPointF l_position(atts.value("X").toFloat(), atts.value("Y").toFloat());

            CommandStationAdd* lp_addCmdsation = new CommandStationAdd(mp_scene, l_position);
            mp_undoStack->push(lp_addCmdsation);

        }
        else if ( qName.compare(QString("PositionDEL")) == 0 )
        {
            QPointF l_position(atts.value("X").toFloat(), atts.value("Y").toFloat());

            Station* l_station = dynamic_cast<Station*>( mp_scene->itemAt(l_position, QTransform()));
            CommandStationDelete* lp_delCmdStation = new CommandStationDelete(mp_scene, l_station);

            mp_undoStack->push(lp_delCmdStation);
        }
        else if ( qName.compare(QString("PositionOrigin")) == 0 ||   qName.compare(QString("PositionTarget")) == 0 )
        {
            QPointF* lp_positionTarget;
            QPointF* lp_positionOrigin;

            if ( qName.compare(QString("PositionOrigin")) == 0 )
            {
                lp_positionOrigin = new QPointF(atts.value("X").toFloat(), atts.value("Y").toFloat());

            }

            if ( lp_positionOrigin != 0 && qName.compare(QString("PositionTarget")) == 0 )
            {
                 lp_positionTarget = new QPointF(atts.value("X").toFloat(), atts.value("Y").toFloat());
                 Station* l_station = dynamic_cast<Station*>(mp_scene->itemAt(*lp_positionOrigin, QTransform()));
                 CommandStationMove* lp_moveCmdStation = new CommandStationMove(l_station, *lp_positionOrigin, *lp_positionTarget);
                 mp_undoStack->push(lp_moveCmdStation);

                 delete lp_positionTarget;
                 delete lp_positionOrigin;

            }

        }
        std::cout << "Call : SceneXmlContentHandler::fin de startElement" << std::endl;
        return true;
    }

    //-----------------------------------------------------------------------------------------------

    bool SceneXmlContentHandler::endElement(const QString &namespaceURI, const QString &localName,
                            const QString &qName)
    {
        std::cout << "Call : SceneXmlContentHandler::endElement" << std::endl;
        return true;
    }

    //-----------------------------------------------------------------------------------------------

    bool SceneXmlContentHandler::endDocument()
    {
        std::cout << "Call : SceneXmlContentHandler::endDocument" << std::endl;
        return true;
    }

 //-----------------------------------------------------------------------------------------------
}
