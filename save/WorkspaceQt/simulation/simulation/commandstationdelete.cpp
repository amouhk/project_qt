#include "commandstationdelete.h"
#include <QObject>
#include <iostream>
using namespace std;

CommandStationDelete::CommandStationDelete(Scene* scene, Station* station) :
    UndoCommand(), createX(station->x()), createY(station->y())
{
    this->scene = scene;
    this->station = station;
    QUndoCommand::setText(QString(QObject::tr("Remove Station at(%1, %2)")).arg(station->x()).arg(station->y()));
}

CommandStationDelete::~CommandStationDelete()
{
    cout << "Delete " << text().toStdString() << endl;
    if (!scene->items().contains(station)) {
        delete station;
    }
}

void CommandStationDelete::undo()
{
    scene->addItem(station);
}

void CommandStationDelete::redo()
{
    scene->removeItem(station);
}

void CommandStationDelete::toXML(QDomDocument* doc, QDomNode* node)
{
    QDomElement commandTag  = doc->createElement(QString("command-station-delete"));
    commandTag.setAttribute(QString("x"), createX);
    commandTag.setAttribute(QString("y"), createY);
    node->appendChild(commandTag);
}
