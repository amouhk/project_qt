#include "scene.h"
#include <iostream>
using namespace std;
#include <QAction>
#include <QMenu>
#include "station.h"
#include "commandstationadd.h"
#include "commandstationdelete.h"
#include "commandstationmove.h"

Scene::Scene(QObject *parent, QUndoStack* undoStack) :
    QGraphicsScene(parent)
{
    this->undoStack = undoStack;
    setSceneRect(0, 0, 400, 200);
    selectedStation = 0;
}

Scene::~Scene()
{
    cout << metaObject()->className() << " deleted" << endl;
}

void Scene::toXML(QDomNode* node)
{
    // node represent la racine du flux XML
    QDomDocument* doc        = (QDomDocument*) node;
    // creer la balise <scene>
    QDomElement sceneTag     = doc->createElement(QString("scene"));
    doc->appendChild(sceneTag);
    if (undoStack->count() == 0) {
        QDomComment comment      = doc->createComment("Scene vide");
        sceneTag.appendChild(comment);
    }
    // parcourir la pile undoStack et serialiser les commandes
    for (int index = 0; index < undoStack->count(); index ++) {
      //  cout << undoStack->command(index)->text().toStdString() << endl;
        ((UndoCommand*) undoStack->command(index))->toXML(doc, &sceneTag);
    }
}

/* mouse press callback */
void Scene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        QPointF point = event->scenePos();
        qreal x = point.x();
        qreal y = point.y();
        QTransform transform;
        selectedStation    = dynamic_cast<Station*> (itemAt(x, y, transform));
        if (selectedStation == 0)
        {
//            addItem(new Station(0, x, y));
            CommandStationAdd* csa  = new CommandStationAdd(this, x, y);
            undoStack->push(csa);
            QString msg(tr("Add station at (%1, %2)"));
            emit message(msg.arg(x).arg(y));
        } else {
            selectedStation->setLastX(x);
            selectedStation->setLastY(y);
        }
        QGraphicsScene::mousePressEvent(event);
    } else
        emit message(QString(tr("Bad button")));
}

void Scene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    if (selectedStation != 0)
    {
        cout << "Move" << endl;
        qreal originX   = selectedStation->lastX();
        qreal originY   = selectedStation->lastY();
        QPointF point   = event->scenePos();
        qreal x         = point.x();
        qreal y         = point.y();
    //    selectedStation->setPos(x, y);
        CommandStationMove* csm = new CommandStationMove(selectedStation, originX, originY, x, y);
        undoStack->push(csm);
        QString msg(tr("Move station from (%1, %2) to (%3, %4)"));
        emit message(msg.arg(originX).arg(originY).arg(x).arg(y));
        selectedStation = 0;
    }
    QGraphicsScene::mouseReleaseEvent(event);
}

void Scene::contextMenuEvent(QGraphicsSceneContextMenuEvent *event)
{
    QPointF point = event->scenePos();
    qreal x = point.x();
    qreal y = point.y();
    QTransform transform;
    selectedStation    = dynamic_cast<Station*> (itemAt(x, y, transform));
    if (selectedStation != 0)
    {
        // delete menu appears
        QMenu deleteMenu;
        QAction* deleteAction    = deleteMenu.addAction(QString(tr("Delete station")));
        if (deleteAction == deleteMenu.exec(event->screenPos())) {
        //    removeItem(selectedStation);
            CommandStationDelete* csd = new CommandStationDelete(this, selectedStation);
            undoStack->push(csd);
            QString msg(tr("Delete station at (%1, %2)"));
            emit message(msg.arg(x).arg(y));
        } else {
            QString msg(tr("Nothing to do"));
            emit message(msg);
        }
        selectedStation = 0;
    }
}
