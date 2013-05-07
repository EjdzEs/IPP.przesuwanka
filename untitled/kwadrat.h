#ifndef KWADRAT_H
#define KWADRAT_H
#include <QGraphicsItem>
#include <QPainter>
#include <QPen>

class kwadrat : public QGraphicsRectItem
{
private:
//    bool clicked;
    QPen m_pen;
public:
    kwadrat(int x, int y, int bok);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

//protected:
protected:
 void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
 void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);
//    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
//    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // KWADRAT_H
