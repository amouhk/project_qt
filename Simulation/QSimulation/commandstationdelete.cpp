#include "commandstationdelete.h"
#include <iostream>

namespace Model
{
    //------------------------------------------------------------------

    CommandStationDelete::CommandStationDelete(Scene* scene, Station* station)
        :QUndoCommand()
    {
        std::cout << "Create : CommandStationDelete::CommandStationDelete"  << std::endl;

        mp_scene   = scene;
        mp_station = station;
        QUndoCommand::setText(QString("Delete Station at (%1, %2)").arg(mp_station->x()).arg(mp_station->y()));

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
}
