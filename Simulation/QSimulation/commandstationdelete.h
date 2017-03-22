#ifndef COMMANDSTATIONDELETE_H
#define COMMANDSTATIONDELETE_H

class CommandStationDelete;
#include <QUndoCommand>
#include "station.h"
#include "scene.h"
namespace Model
{

    class CommandStationDelete : public QUndoCommand
    {
    public:
        explicit CommandStationDelete(Scene* scene, Station* station);
        virtual ~CommandStationDelete();

        virtual void redo();
        virtual void undo();

       private:
        Scene* mp_scene;
        Station* mp_station;

    };

}
#endif // COMMANDSTATIONDELETE_H
