#ifndef KLOCEK_H
#define KLOCEK_H

#include <QGraphicsItem>
#include <QPainter>

class Klocek : public QGraphicsRectItem
{
private:
    int wartosc;
    int x;
    int y;

    int min(int liczba1, int liczba2);
public:
    Klocek();
    Klocek(qreal x, qreal y, qreal width, qreal height);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *widget);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
};

#endif // KLOCEK_H
