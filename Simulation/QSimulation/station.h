#ifndef STATION_H
#define STATION_H

/*!< Classe de donnees du Modele : une station */
class Station;
#include <QGraphicsItem>
#include <QPainter>

namespace Model
{
    class Station : public QGraphicsItem
    {
       // QGraphicsItem n'herite pas de <QObject>
       // Q_OBJECT

    public:
        explicit Station(QGraphicsItem *parent = 0, qreal x = 0.0f, qreal y = 0.0f);
        virtual ~Station();
        virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
        virtual QRectF boundingRect() const;

        void setLastPosition(QPointF &pos);
        QPointF lastPosition() const;

        void setOriginPosition(QPointF pos);
        QPointF originPosition() const;

    private:
        QPointF m_lastPosition;
        QPointF m_originPosition;
    };
}

#endif // STATION_H
