#include "commandstationmove.h"
#include <QObject>
#include <iostream>
using namespace std;

CommandStationMove::CommandStationMove(Station* station, qreal originX, qreal originY,
                                       qreal targetX, qreal targetY):
    UndoCommand()
{
    this->station   = station;
    this->origin    = QPointF(originX, originY);
    this->target    = QPointF(targetX, targetY);
    QUndoCommand::setText(QString(QObject::tr("Move Station from (%1, %2) to (%3, %4)")).arg(originX)
                          .arg(originY).arg(targetX).arg(targetY));
}

CommandStationMove::~CommandStationMove()
{
    cout << "Delete " << text().toStdString() << endl;
}

void CommandStationMove::undo()
{
    station->setPos(origin);
}

void CommandStationMove::redo()
{
    station->setPos(target);
}

void CommandStationMove::toXML(QDomDocument* doc, QDomNode* node)
{
    QDomElement commandTag  = doc->createElement(QString("command-station-move"));
    commandTag.setAttribute(QString("originX"), origin.x());
    commandTag.setAttribute(QString("originY"), origin.y());
    commandTag.setAttribute(QString("targetX"), target.x());
    commandTag.setAttribute(QString("targetY"), target.y());
    node->appendChild(commandTag);
}
