#include "station.h"
#include <iostream>
using namespace std;

Station::Station(QGraphicsItem *parent, qreal x, qreal y) :
    QGraphicsItem(parent)
{
    QGraphicsItem::setPos(x, y);
    QGraphicsItem::setFlags(QGraphicsItem::ItemIsMovable
                            | QGraphicsItem::ItemIsSelectable
                            | QGraphicsItem::ItemIgnoresTransformations	);
}

Station::~Station()
{
    cout << "Station at (" << pos().rx()
         << ", " << pos().ry() << ") deleted" << endl;
}

void Station::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(Qt::blue);
    painter->setRenderHint(QPainter::Antialiasing, true);
    QRectF rect(-5, -5, 8, 6);
    painter->fillRect(rect, QColor(100, 100, 200));
    painter->drawLine(0, -5, 0, -10);
    painter->drawLine(0, -5, 10, -10);
    painter->drawLine(0, -5, -5, -10);
}

QRectF Station::boundingRect() const
{
    return QRectF(-6, -12, 18, 15);
}

void Station::setLastX(qreal lx)
{
    this->lx = lx;
}

void Station::setLastY(qreal ly)
{
    this->ly = ly;
}

qreal Station::lastX() const{
    return lx;
}
qreal Station::lastY() const {
    return ly;
}
