#ifndef COMMANDSTATIONADD_H
#define COMMANDSTATIONADD_H

class CommandStationAdd;
#include <QUndoCommand>
#include "scene.h"

namespace Model
{



    class CommandStationAdd : public QUndoCommand
    {
    public:
        CommandStationAdd(Scene *scene, QPointF point);
        virtual ~CommandStationAdd();

        virtual void redo();
        virtual void undo();


    private:
        Scene * mp_scene;
        Station* mp_station;

    };

}

#endif // COMMANDSTATIONADD_H
