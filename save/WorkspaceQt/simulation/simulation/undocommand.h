#ifndef UNDOCOMMAND_H
#define UNDOCOMMAND_H
class UndoCommand;
#include <QDomDocument>
#include <QDomNode>
#include <QUndoCommand>
/* Abstract class !*/
class UndoCommand : public QUndoCommand
{
public:
    UndoCommand();
    virtual ~UndoCommand();
    virtual void toXML(QDomDocument* doc, QDomNode* node) = 0; // pure virtual
};

#endif // UNDOCOMMAND_H
