#include "kwadrat.h"

kwadrat::kwadrat(int x, int y, int bok) : QGraphicsRectItem(x, y, bok, bok)
{
    setAcceptHoverEvents(true);
//    clicked = false;
}

void kwadrat::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    m_pen.setColor(Qt::cyan);
    update();
}

void kwadrat::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    m_pen.setColor(Qt::black);
    update();
}

void kwadrat::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
 painter->setPen(m_pen);

 painter->drawRect(rect());
}

//void kwadrat::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
//{
//    QBrush brush;
//    if (clicked) {
//        brush.setColor(Qt::red);
//    } else {
//        brush.setColor(Qt::yellow);
//    }
//    brush.setStyle(Qt::DiagCrossPattern);
////    QGraphicsRectItem::setBrush(brush);

//    QPen pen(Qt::blue);
//    pen.setWidth(2);
//    painter->setBrush(brush);

//    painter->setPen(pen);
//    painter->drawRect(boundingRect());
//}

//void kwadrat::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
//{
//    if (isUnderMouse()) {
//        clicked = true;
//    } else {
//        clicked = false;
//    }

//    update();
//}

//void kwadrat::mousePressEvent(QGraphicsSceneMouseEvent *event)
//{
////    clicked = true;
////    update();
//}




