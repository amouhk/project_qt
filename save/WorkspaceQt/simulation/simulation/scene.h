#ifndef SCENE_H
#define SCENE_H
class Scene;
#include <QDomNode>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QUndoStack>
#include "Station.h"

/* Data model of a QGraphicsView
 */
class Scene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit Scene(QObject *parent = 0, QUndoStack* undoStack = 0);
    virtual ~Scene();
    void toXML(QDomNode* node);
protected:
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event);
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    virtual void contextMenuEvent(QGraphicsSceneContextMenuEvent *event);
private:
    Station* selectedStation;
    QUndoStack* undoStack;
signals:
    void message(QString);
public slots:

};

#endif // SCENE_H
