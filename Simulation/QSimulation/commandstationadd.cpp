#include "commandstationadd.h"
#include <iostream>

namespace Model
{
    CommandStationAdd::CommandStationAdd(Scene *scene, QPointF point)
    {
        std::cout << "Create : Station at " << point.rx() << point.ry() << std::endl;

        mp_scene   = scene;
        mp_station = new Station(0, point.rx(), point.ry());

        QUndoCommand::setText(QString("Add station at %1 %2").arg(point.rx()).arg(point.ry()));

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
        std::cout << "CommandStationAdd::redo" << std::endl;
        mp_scene->addItem(mp_station);
    }

    //-------------------------------------------------------------------------------------------

    void CommandStationAdd::undo()
    {
        std::cout << "CommandStationAdd::undo" << std::endl;
        mp_scene->removeItem(mp_station);
    }


}

