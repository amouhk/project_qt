#include "commandstationmove.h"
#include <iostream>

namespace Model
{
    //-------------------------------------------------------------

    CommandStationMove::CommandStationMove(Station* station, QPointF origin, QPointF target)
    {
        std::cout << "Create : CommandStationMove::CommandStationMove " << std::endl;

        mp_station = station;
        m_origin   = origin;
        m_target   = target;

        UndoCommand::setText(QString("Move Station from (%1, %2) to (%3, %4)").arg(origin.rx())
                                            .arg(origin.ry()).arg(target.rx()).arg(target.ry()));
    }

    //-------------------------------------------------------------

    CommandStationMove::~CommandStationMove()
    {
        std::cout << "Delete : CommandStationMove::~CommandStationMove " << std::endl;
    }

    //-------------------------------------------------------------

    void CommandStationMove::redo()
    {
        std::cout << "Call : CommandStationMove::redo " << std::endl;
        mp_station->setPos(m_target);
    }

    //-------------------------------------------------------------

    void CommandStationMove::undo()
    {
        std::cout << "Call : CommandStationMove::undo " << std::endl;
        mp_station->setPos(m_origin);

    }

    //-------------------------------------------------------------

    void CommandStationMove::toXML(QDomDocument* doc, QDomNode* node)
    {
        //Creer un balise
        QDomElement l_moveTag = doc->createElement(QString("MOVE"));

        QDomElement l_posTag;
        // 1ere balise de position
        l_posTag = doc->createElement(QString("Position-Origin"));
        l_posTag.setAttribute(QString("X"), m_origin.x());
        l_posTag.setAttribute(QString("Y"), m_origin.y());
        l_moveTag.appendChild(l_posTag);

        // 2eme balise de position
        l_posTag = doc->createElement(QString("Position-Target"));
        l_posTag.setAttribute(QString("X"), m_target.x());
        l_posTag.setAttribute(QString("Y"), m_target.y());
        l_moveTag.appendChild(l_posTag);

        // Ajout de la balise
        node->appendChild(l_moveTag);
    }

}

