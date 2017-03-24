#ifndef COMMANDSTATIONDELETE_H
#define COMMANDSTATIONDELETE_H
class CommandStationDelete;
#include <QDomDocument>
#include <QDomNode>
#include "scene.h"
#include "station.h"
#include "undocommand.h"

class CommandStationDelete : public UndoCommand
{
public:
    explicit CommandStationDelete(Scene* scene, Station* station);
    virtual ~CommandStationDelete();
    virtual void undo();
    virtual void redo();
    virtual void toXML(QDomDocument* doc, QDomNode* node);
private:
    Scene* scene;
    Station* station;
    const qreal createX;
    const qreal createY;
};

#endif // COMMANDSTATIONDELETE_H
