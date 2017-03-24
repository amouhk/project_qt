#ifndef COMMANDSTATIONMOVE_H
#define COMMANDSTATIONMOVE_H
class CommandStationMove;
#include <QDomDocument>
#include <QDomNode>
#include "station.h"
#include "undocommand.h"

class CommandStationMove : public UndoCommand
{
public:
    explicit CommandStationMove(Station* station, qreal originX, qreal originY,
                                qreal targetX, qreal targetY);
    virtual ~CommandStationMove();
    virtual void undo();
    virtual void redo();
    virtual void toXML(QDomDocument* doc, QDomNode* node);
private:
    Station* station;
    QPointF origin;
    QPointF target;
};

#endif // COMMANDSTATIONMOVE_H
