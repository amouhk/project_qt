#include "scene.h"
#include "station.h"
#include <iostream>
#include <QTransform>
#include <QDomDocument>
#include "commandstationadd.h"
#include "commandstationdelete.h"
#include "commandstationmove.h"
#include <QDebug>
#include <QMenu>


namespace Model
{

    //---------------------------------------------------------------------------

    Scene::Scene(QObject *parent, QUndoStack *undoStack)
        :QGraphicsScene(parent)
    {
        // Dimensionnement de notre scene
        setSceneRect(0, 0, 400, 400);
        setBackgroundBrush(Qt::yellow);

        // Init
        mp_selectedStation = 0;
        mp_undoStack       = undoStack;
    }

    //---------------------------------------------------------------------------

    Scene::~Scene()
    {
        std::cout << "Delete " <<  metaObject()->className() << std::endl;
    }

    //---------------------------------------------------------------------------

    void Scene::toXML(QDomNode* node)
    {
        // node : la racine du flux xml

        QDomDocument* l_xmlDoc = (QDomDocument*)(node);

        // creer la base <scene>
        QDomElement l_sceneTag = l_xmlDoc->createElement(QString("SCENE"));
        l_xmlDoc->appendChild(l_sceneTag);

        if ( !mp_undoStack->isClean() )
        {
            int l_nbCmd = mp_undoStack->count();
            for (int l_indexCmd = 0; l_indexCmd < l_nbCmd; l_indexCmd++)
            {
               UndoCommand* l_undoCommand = (UndoCommand*)mp_undoStack->command(l_indexCmd);

               l_undoCommand->toXML(l_xmlDoc, &l_sceneTag);

                //std::cout << "Toto " << mp_undoStack->command(l_indexCmd)->text().toStdString() << std::endl;
            }
        }

        // TODO: serealiser plus tard le reste

    }

    //---------------------------------------------------------------------------

    void Scene::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent)
    {
        // Declarartion
        QPointF l_position(0,0);
        qreal l_x = 0;
        qreal l_y = 0;

        // Recuperation de la position du curseur
        // On s'interesse seumlement aux click gauche
        if (mouseEvent->button() == Qt::LeftButton)
        {
            l_position = mouseEvent->scenePos();
            l_x = l_position.rx();
            l_y = l_position.ry();

            mp_selectedStation  = dynamic_cast<Station*>(itemAt(l_position, QTransform()));

            if (mp_selectedStation == 0)
            {
                mp_selectedStation = new Station(0, l_x, l_y);

                CommandStationAdd *lp_addCommand = new CommandStationAdd(this, l_position);
                mp_undoStack->push(lp_addCommand);

                // Emission du message pour la status bar.
                QString l_message("Add Station at %1 %2");
                emit( message(l_message.arg(l_x).arg(l_y)));
            }

            QGraphicsScene::mousePressEvent(mouseEvent);
            mp_selectedStation->setLastPosition(l_position);

        }
    }

    //---------------------------------------------------------------------------

    void Scene::mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent)
    {
        if (mp_selectedStation != 0)
        {
            QPointF l_currentPosition(mouseEvent->scenePos().rx(), mouseEvent->scenePos().ry());

            // Emission du message pour la status bar.
            QString l_message("Move Station at %1 %2 to %3 %4");
            emit( message(l_message.arg(mp_selectedStation->lastPosition().rx()).arg(mp_selectedStation->lastPosition().ry())
                                    .arg(l_currentPosition.rx()).arg(l_currentPosition.ry())));

            // Positionnement de la station
            CommandStationMove* l_cmdStationMove = new CommandStationMove(mp_selectedStation, mp_selectedStation->lastPosition(), mouseEvent->scenePos());
            mp_undoStack->push(l_cmdStationMove);

        }

        QGraphicsScene::mouseReleaseEvent(mouseEvent);

        mp_selectedStation = 0;


    }

    //---------------------------------------------------------------------------

    void Scene::mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent)
    {
        // Emission du message pour la status bar.
        QString l_message("Clicked at %1 %2");
        emit( message(l_message.arg(mouseEvent->scenePos().rx()).arg(mouseEvent->scenePos().ry())));

        if (mp_selectedStation != 0)
        {
            QPointF l_currentPosition(mouseEvent->scenePos().rx(), mouseEvent->scenePos().ry());

            // Emission du message pour la status bar.
            QString l_message("Moving Station : %1 %2 ");
            emit( message(l_message.arg(l_currentPosition.rx()).arg(l_currentPosition.ry())));
        }

        QGraphicsScene::mouseMoveEvent(mouseEvent);

    }

    //---------------------------------------------------------------------------

    void Scene::contextMenuEvent(QGraphicsSceneContextMenuEvent *ctxEvent)
    {

        std::cout << " Menu Delete selected " << std::endl;
        QMenu l_deleteMenu;
        QAction* lp_deleteAction;

        QPointF l_currentPosition = ctxEvent->scenePos();

        mp_selectedStation = dynamic_cast<Station*>(itemAt(l_currentPosition, QTransform()));

        if (mp_selectedStation != 0)
        {
            std::cout << " Menu Delete selected : not empty " << std::endl;
            lp_deleteAction = l_deleteMenu.addAction("Delete Station");

            // Exec thread bloquante pour l'usager
            if ( l_deleteMenu.exec(ctxEvent->screenPos()) ==  lp_deleteAction)
            {
                CommandStationDelete* cmdStationDel = new CommandStationDelete(this, mp_selectedStation);
                mp_undoStack->push(cmdStationDel);

                emit( message(QString("Delete Station at %1 %2").arg(l_currentPosition.rx())
                                                                .arg(l_currentPosition.ry())));
            }
            mp_selectedStation = 0;
        }

    }


}
