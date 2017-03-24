#ifndef STATION_H
#define STATION_H
class Station;
#include <QGraphicsItem>
#include <QPainter>
#include <QRectF>
#include <QStyleOptionGraphicsItem>
#include <QWidget>

class Station : public QGraphicsItem
{
public:
    explicit Station(QGraphicsItem *parent = 0, qreal x = 0.0f, qreal y = 0.0f);
    virtual ~Station();
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    virtual QRectF boundingRect() const;
    void setLastX(qreal lx);
    void setLastY(qreal ly);
    qreal lastX() const;
    qreal lastY() const;
private:
    qreal lx;
    qreal ly;
};

#endif // STATION_H
