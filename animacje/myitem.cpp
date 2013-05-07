#include "myitem.h"

MyItem::MyItem()
{
    // random start rotation
    angle = (qrand() % 360);
    setRotation(angle);

    // start speed
    speed = 5;

    // random start position
    int StartX = 0;
    int StartY = 0;

    if (qrand() % 1) {
        StartX = (qrand() % 200);
        StartY = (qrand() % 200);
    } else {
        StartX = (qrand() % -100);
        StartY = (qrand() % -100);
    }

    setPos(mapToParent(StartX, StartY));
}

QRectF MyItem::boundingRect() const
{
    return QRect(0, 0, 20, 20);
}

void MyItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rect = boundingRect();
    QBrush Brush(Qt::gray);

    // basic Collision detection

    if (scene()->collidingItems(this).isEmpty()) {
        // no collision
        Brush.setColor(Qt::green);

    } else {

        // collision
        Brush.setColor(Qt::red);

        // set the new position
        DoCollision();
    }

    painter->fillRect(rect, Brush);
    painter->drawRect(rect);
}

void MyItem::advance(int phase)
{
    if (!phase) return;

    QPointF location = this->pos();

    setPos(mapToParent(0, -speed));

}

void MyItem::DoCollision()
{
}
