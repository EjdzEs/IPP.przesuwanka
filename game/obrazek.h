#ifndef OBRAZEK_H
#define OBRAZEK_H

#include <QGraphicsPixmapItem>

class Obrazek : public QGraphicsPixmapItem
{
public:
    Obrazek(QPixmap pixmap);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *widget);
};

#endif // OBRAZEK_H
