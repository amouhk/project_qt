#ifndef UNDOCOMMAND_H
#define UNDOCOMMAND_H
class UndoCommand;

#include <QUndoCommand>
#include <QDomNode>
#include <QDomDocument>

namespace Model
{

    class UndoCommand : public QUndoCommand
    {

    public:
        UndoCommand();
        virtual ~UndoCommand();

        virtual void toXML(QDomDocument* doc, QDomNode* node) = 0;
    };

}

#endif // UNDOCOMMAND_H
