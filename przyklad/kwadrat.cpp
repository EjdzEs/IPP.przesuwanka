#include "kwadrat.h"

Kwadrat::Kwadrat(int wiersz, int kolumna)
{
    this->wiersz = wiersz;
    this->kolumna = kolumna;
}

QRectF Kwadrat::boundingRect() const
{
    QRectF rect = QRectF(kolumna, wiersz, 40, 40);
}

void Kwadrat::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
}

void Kwadrat::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
}
