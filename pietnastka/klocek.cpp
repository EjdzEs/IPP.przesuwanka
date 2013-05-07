#include "klocek.h"
#include <QWidget>
#include <QFont>

#include <iostream>
#include <string>

int Klocek::min(int liczba1, int liczba2)
{
    return (liczba1 <= liczba2) ? liczba1 : liczba2;
}

Klocek::Klocek()
{
}

Klocek::Klocek(qreal x, qreal y, qreal width, qreal height) : QGraphicsRectItem(x * width, y * width, width, height)
{
    this->x = x;
    this->y = y;
}

void Klocek::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *widget)
{
    int bokKwadratu = (min(widget->width(), widget->height()))/5;

    setRect(x * bokKwadratu, y * bokKwadratu, bokKwadratu, bokKwadratu);

    QRectF rect = boundingRect();

    QBrush brush;
    brush.setColor(Qt::blue);
    brush.setStyle(Qt::SolidPattern);

    painter->setBrush(brush);
    QPen pen(Qt::red);

    QFont font;
    font.setPixelSize(bokKwadratu/3);


    pen.setWidth(3);
    QString::number(x);
    painter->setPen(pen);
    painter->setFont(font);
    painter->drawRect(rect);
    painter->drawText(rect,Qt::AlignCenter,QString::number(x) + ", " + QString::number(y));
}

void Klocek::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
//    update();
}


