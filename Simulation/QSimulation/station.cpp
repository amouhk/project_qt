#include "station.h"
#include <iostream>

namespace Model
{
    Station::Station(QGraphicsItem *parent, qreal x, qreal y) :
        QGraphicsItem(parent)
    {
        // Positionnement de la Station
        setPos(x, y);
        setFlags(QGraphicsItem::ItemIsMovable |
                 QGraphicsItem::ItemIsSelectable |
                 QGraphicsItem::ItemIgnoresTransformations);
    }

    //---------------------------------------------------------------------------

    Station::~Station()
    {
       std::cout << "Delete : Model::Station " << std::endl;
    }

    //---------------------------------------------------------------------------
    void Station::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
    {
        // Declaration
        qreal c_width  = 20.0f;
        qreal c_height = 10.0f;
        QRectF l_rectangle(0, 0, c_width, c_height);

        // configuration du pinceau
        painter->setRenderHint( QPainter::Antialiasing );

        // on dessine un rectangle
        painter->setPen( QPen( Qt::black, 2 ) );
        painter->drawRect( l_rectangle );
        // on dessine l'antenne
        painter->setPen( QPen( Qt::red));
        painter->drawLine(10, 0, 0, -10);
        painter->drawLine(10, 0, 10, -10);
        painter->drawLine(10, 0, 20, -10);
    }

    //---------------------------------------------------------------------------

   QRectF Station::boundingRect() const
   {
       return QRectF(0, -10, 20, 20);
   }

   //---------------------------------------------------------------------------

   void Station::setLastPosition(QPointF &pos)
   {
       m_lastPosition = pos;
   }

   //---------------------------------------------------------------------------
   QPointF Station::lastPosition() const
   {
       return m_lastPosition;
   }


}

