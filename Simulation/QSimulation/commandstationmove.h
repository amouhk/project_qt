#ifndef COMMANDSTATIONMOVE_H
#define COMMANDSTATIONMOVE_H
class CommandStationMove;

#include "station.h"
#include "undocommand.h"

namespace Model
{

    class CommandStationMove : public UndoCommand//, public QObject
    {

       // Q_OBJECT

    public:
        explicit CommandStationMove(Station* station, QPointF origin, QPointF target);
        virtual ~CommandStationMove();

        virtual void redo();
        virtual void undo();
        virtual void toXML(QDomDocument* doc, QDomNode* node);

    private:
        Station* mp_station;
        QPointF m_origin;
        QPointF m_target;

    };

}

#endif // COMMANDSTATIONMOVE_H
