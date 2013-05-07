#include <QPainter>
#include <QGraphicsPixmapItem>
#include <QWidget>

#include "obrazek.h"

Obrazek::Obrazek(QPixmap pixmap) : QGraphicsPixmapItem(pixmap) {}

void Obrazek::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *widget)
{
    QPixmap qPixmap;

    if ((widget->width()) >= (widget->height())) {
        qPixmap = pixmap().scaledToHeight(-20+(widget->height()), Qt::SmoothTransformation);
    } else {
        qPixmap = pixmap().scaledToWidth(-20+(widget->width()), Qt::SmoothTransformation);
    }

    setPixmap(qPixmap);
    painter->drawPixmap(boundingRect().toRect(), pixmap());
}
