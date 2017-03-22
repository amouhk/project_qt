#include "commandstationmove.h"
#include <iostream>

namespace Model
{
    //-------------------------------------------------------------

    CommandStationMove::CommandStationMove(Station* station, QPointF origin, QPointF target)
        : QUndoCommand()
    {
        std::cout << "Create : CommandStationMove::CommandStationMove " << std::endl;

        mp_station = station;
        m_origin   = origin;
        m_target   = target;

        QUndoCommand::setText(QString("Move Station from (%1, %2) to (%3, %4)").arg(origin.rx())
                                            .arg(origin.ry()).arg(target.rx()).arg(target.ry()));
    }

    //-------------------------------------------------------------

    CommandStationMove::~CommandStationMove()
    {
        std::cout << "Delete : CommandStationMove::~CommandStationMove " << std::endl;
    }

    //-------------------------------------------------------------

    void CommandStationMove::redo()
    {
        std::cout << "Call : CommandStationMove::redo " << std::endl;
        mp_station->setPos(m_target);
    }

    //-------------------------------------------------------------

    void CommandStationMove::undo()
    {
        std::cout << "Call : CommandStationMove::undo " << std::endl;
        mp_station->setPos(m_origin);

    }

    //-------------------------------------------------------------

}

