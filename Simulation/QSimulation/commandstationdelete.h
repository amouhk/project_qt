#ifndef COMMANDSTATIONDELETE_H
#define COMMANDSTATIONDELETE_H

class CommandStationDelete;
#include "undocommand.h"
#include "station.h"
#include "scene.h"
namespace Model
{

    class CommandStationDelete : public UndoCommand
    {
    public:
        explicit CommandStationDelete(Scene* scene, Station* station);
        virtual ~CommandStationDelete();

        virtual void redo();
        virtual void undo();
        virtual void toXML(QDomDocument* doc, QDomNode* node);
       private:
        Scene* mp_scene;
        Station* mp_station;

    };

}
#endif // COMMANDSTATIONDELETE_H
