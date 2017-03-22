#ifndef COMMANDSTATIONMOVE_H
#define COMMANDSTATIONMOVE_H
class CommandStationMove;

#include "station.h"
#include <QUndoCommand>

namespace Model
{

    class CommandStationMove : public QUndoCommand
    {
    public:
        explicit CommandStationMove(Station* station, QPointF origin, QPointF target);
        virtual ~CommandStationMove();

        virtual void redo();
        virtual void undo();

    private:
        Station* mp_station;
        QPointF m_origin;
        QPointF m_target;

    };

}

#endif // COMMANDSTATIONMOVE_H
