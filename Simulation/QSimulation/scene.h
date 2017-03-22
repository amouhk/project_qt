#ifndef SCENE_H
#define SCENE_H

/*!< Modeles de donnees de QGraphicsView */

class Scene;
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include "station.h"
#include <QUndoStack>
#include <QDomNode>

namespace Model
{

class Scene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit Scene(QObject *parent = 0, QUndoStack * undoStack = 0);
    virtual ~Scene();
    void toXML(QDomNode* node);  /*!< recriture: cpp to xml */

signals:
    void message(QString);  /*!< Signal de la scene pour la bar de status */

public slots:

protected:
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent);
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent);
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent);

    virtual void contextMenuEvent(QGraphicsSceneContextMenuEvent *ctxEvent);

private:
    Station* mp_selectedStation;
    QUndoStack* mp_undoStack;
};

}

#endif // SCENE_H

