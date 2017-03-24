#include "commandstationadd.h"
#include <QObject>
#include <iostream>
using namespace std;

CommandStationAdd::CommandStationAdd(Scene* scene, qreal x, qreal y)
    :UndoCommand(), createX(x), createY(y)
{
    this->scene = scene;
    this->station   = new Station(0, x, y);
    QUndoCommand::setText(QString(QObject::tr("Add Station at (%1, %2)")).arg(x).arg(y));
}

CommandStationAdd::~CommandStationAdd()
{
    cout << "Delete " << text().toStdString() << endl;
    if (!scene->items().contains(station))
    {   // station is active
        delete station;
    }
}

void CommandStationAdd::redo()
{
    cout << "redo" << endl;
    scene->addItem(station);
}

void CommandStationAdd::undo()
{
    cout << "undo" << endl;
    scene->removeItem(station);
}

void CommandStationAdd::toXML(QDomDocument* doc, QDomNode* node)
{
    QDomElement commandTag  = doc->createElement(QString("command-station-add"));
    commandTag.setAttribute(QString("x"), createX);
    commandTag.setAttribute(QString("y"), createY);
    node->appendChild(commandTag);
}
