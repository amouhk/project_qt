#include "commandstationdelete.h"
#include <iostream>

namespace Model
{
    //------------------------------------------------------------------

    CommandStationDelete::CommandStationDelete(Scene* scene, Station* station)
    {
        std::cout << "Create : CommandStationDelete::CommandStationDelete"  << std::endl;

        mp_scene   = scene;
        mp_station = station;
        UndoCommand::setText(QString("Delete Station at (%1, %2)").arg(mp_station->x()).arg(mp_station->y()));

    }

    //------------------------------------------------------------------

    CommandStationDelete::~CommandStationDelete()
    {
        std::cout << "Delete : CommandStationDelete::CommandStationDelete"  << std::endl;

        if (!mp_scene->items().contains(mp_station))
        {
            delete mp_station;
        }
    }

    //------------------------------------------------------------------

    void CommandStationDelete::redo()
    {
        std::cout << "Call : CommandStationDelete::redo"  << std::endl;
        mp_scene->removeItem(mp_station);
    }

    //------------------------------------------------------------------

    void CommandStationDelete::undo()
    {
        std::cout << "Call : CommandStationDelete::undo"  << std::endl;
        mp_scene->addItem(mp_station);
    }

    //------------------------------------------------------------------

    void CommandStationDelete::toXML(QDomDocument* doc, QDomNode* node)
    {
        //Creer un balise command station
        QDomElement l_delTag  = doc->createElement(QString("DELETE"));

        // creer un balise de position
        QDomElement lp_posTag = doc->createElement("Position");
        lp_posTag.setAttribute(QString("X"), mp_station->x());
        lp_posTag.setAttribute(QString("Y"), mp_station->y());
        // ajout de la balise de position a celle de command station
        l_delTag.appendChild(lp_posTag);

        // Ajout de la balise command station a son parent
        node->appendChild(l_delTag);
    }
}
