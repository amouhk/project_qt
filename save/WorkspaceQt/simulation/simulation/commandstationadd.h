#ifndef COMMANDSTATIONADD_H
#define COMMANDSTATIONADD_H
class CommandStationAdd;
#include <QDomDocument>
#include <QDomNode>
#include <QObject>
#include "scene.h"
#include "station.h"
#include "undocommand.h"

/* Concrete command du pattern Memento */
class CommandStationAdd : public UndoCommand
{
public:
    CommandStationAdd(Scene* scene, qreal x, qreal y);
    virtual ~CommandStationAdd();
    virtual void redo();
    virtual void undo();
    virtual void toXML(QDomDocument* doc, QDomNode* node);
private:
    Scene* scene;
    Station* station;
    const qreal createX;
    const qreal createY;
};

#endif // COMMANDSTATIONADD_H
