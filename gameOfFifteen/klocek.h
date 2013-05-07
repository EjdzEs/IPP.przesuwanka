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
    int bokKwadratu;

    QBrush brush;
    QPen pen;

    void przesuwa();
    int min(int liczba1, int liczba2);
    void animacja(Klocek *k);

public:
    void move(QString kierunek);

    Klocek(qreal x, qreal y, int wartosc);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *widget);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *);
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);
};

#endif // KLOCEK_H
