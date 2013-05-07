#ifndef KWADRAT_H
#define KWADRAT_H

#include <QPainter>
#include <QGraphicsRectItem>
#include <QDebug>

class Kwadrat : public QGraphicsRectItem
{
private:
    int wiersz;
    int kolumna;
public:
    Kwadrat(int wiersz, int kolumna);

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

protected:
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
};

#endif // KWADRAT_H
