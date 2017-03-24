#include "scenehandler.h"
#include <iostream>
using namespace std;
#include "commandstationadd.h"
#include "commandstationdelete.h"
#include "commandstationmove.h"

SceneHandler::SceneHandler(Scene* scene, QUndoStack* undoStack)
{
    this->scene     = scene;
    this->undoStack = undoStack;
}

bool SceneHandler::startDocument()
{
    cout << "Debut de l'analyse" << endl;
    return true;
}

bool SceneHandler::startElement(const QString &namespaceURI,
                                const QString &localName,
                                const QString &qName, const QXmlAttributes &atts)
{
    if (qName.compare(QString("scene")) == 0) {
        undoStack->clear();
    } else if (qName.compare(QString("command-station-add")) == 0) {
        double x = atts.value("x").toDouble();
        double y = atts.value("y").toDouble();

        CommandStationAdd* csa = new CommandStationAdd(scene, qreal(x), qreal(y));
        undoStack->push(csa);
    } else if (qName.compare(QString("command-station-delete")) == 0) {
        double x = atts.value("x").toDouble();
        double y = atts.value("y").toDouble();
        QTransform transform;
        Station* station = dynamic_cast<Station*>(scene->itemAt(qreal(x), qreal(y), transform));
        CommandStationDelete* csd = new CommandStationDelete(scene, station);
        undoStack->push(csd);
    } else if (qName.compare(QString("command-station-move")) == 0) {
        double originX = atts.value("originX").toDouble();
        double originY = atts.value("originY").toDouble();
        double targetX = atts.value("targetX").toDouble();
        double targetY = atts.value("targetY").toDouble();
        QTransform transform;
        Station* station = dynamic_cast<Station*>(scene->itemAt(qreal(originX), qreal(originY), transform));
        CommandStationMove* csm = new CommandStationMove(station, originX, originY, targetX, targetY);
        undoStack->push(csm);
    }
    return true;
}

bool SceneHandler::endElement(const QString &namespaceURI, const QString &localName, const QString &qName)
{
    return true;
}

bool SceneHandler::endDocument()
{
    cout << "Fin de l'analyse" << endl;
    return true;
}
