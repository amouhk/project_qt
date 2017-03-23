#ifndef COMMANDSTATIONADD_H
#define COMMANDSTATIONADD_H

class CommandStationAdd;
#include "undocommand.h"
#include "scene.h"

namespace Model
{



    class CommandStationAdd : public UndoCommand
    {
    public:
        CommandStationAdd(Scene *scene, QPointF point);
        virtual ~CommandStationAdd();

        virtual void redo();
        virtual void undo();
        virtual void toXML(QDomDocument* doc, QDomNode* node);

    private:
        Scene * mp_scene;
        Station* mp_station;

    };

}

#endif // COMMANDSTATIONADD_H
