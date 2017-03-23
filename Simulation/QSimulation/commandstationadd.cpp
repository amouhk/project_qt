#include "commandstationadd.h"
#include <iostream>

namespace Model
{
    CommandStationAdd::CommandStationAdd(Scene *scene, QPointF point)
    {
        std::cout << "Create : Station at " << point.rx() << point.ry() << std::endl;

        mp_scene   = scene;
        mp_station = new Station(0, point.rx(), point.ry());


        UndoCommand::setText(QString(QObject::tr("Add station at (%1, %2)").arg(point.rx()).arg(point.ry())));

    }

    //-------------------------------------------------------------------------------------------

    CommandStationAdd::~CommandStationAdd()
    {
        std::cout << "Delete : " << text().toStdString() << std::endl;

        // Verification de la presence de la station a supprime
        // dans la scene
        if (mp_scene->items().contains(mp_station))
        {
            mp_scene->removeItem(mp_station);
            delete mp_station;
        }
    }

    //-------------------------------------------------------------------------------------------

    void CommandStationAdd::redo()
    {
        std::cout << "Call : CommandStationAdd::redo" << std::endl;
        mp_scene->addItem(mp_station);
    }

    //-------------------------------------------------------------------------------------------

    void CommandStationAdd::undo()
    {
        std::cout << "Call : CommandStationAdd::undo" << std::endl;
        mp_scene->removeItem(mp_station);
    }

    //------------------------------------------------------------------------------------------

    void CommandStationAdd::toXML(QDomDocument* doc, QDomNode* node)
    {
        //Creer un balise command station
        QDomElement l_addTag  = doc->createElement(QString("ADD"));

        // creer un balise de position
        QDomElement lp_posTag = doc->createElement(QString("PositionADD"));
        lp_posTag.setAttribute(QString("X"), mp_station->originPosition().x());
        lp_posTag.setAttribute(QString("Y"), mp_station->originPosition().y());
        // ajout de la balise de position a celle de command station
        l_addTag.appendChild(lp_posTag);

        // Ajout de la balise command station a son parent
        node->appendChild(l_addTag);
    }


}

