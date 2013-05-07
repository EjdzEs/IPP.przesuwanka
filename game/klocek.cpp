#include "klocek.h"

#include <QWidget>
#include <QFont>
#include <iostream>
#include <string>
#include <QDebug>
#include <QGraphicsItemAnimation>
#include <QTimeLine>
#include <QObject>

#include "mainwindow.h"

void Klocek::przesuwa()
{
    x += 1;
    y += 1;
}

int Klocek::min(int liczba1, int liczba2)
{
    return (liczba1 <= liczba2) ? liczba1 : liczba2;
}

void Klocek::animacja(Klocek *k)
{
    QTimeLine *timeLine = new QTimeLine();
    timeLine->setLoopCount(1);

    // definiujemy animacje
    QGraphicsItemAnimation *animation = new QGraphicsItemAnimation();
    animation->setItem(k);
    animation->setTimeLine(timeLine);

    // animacja
    int odcinek = bokKwadratu;
    animation->setTranslationAt(0.3, odcinek, odcinek);

    timeLine->start();

}

void Klocek::move(QString kierunek)
{
    if (kierunek == "up") --y; else
        if (kierunek == "down") ++y; else
            if (kierunek == "left") --x; else
                if (kierunek == "right") ++x;
}

// 10 jest dowolną wartością początkową
Klocek::Klocek(qreal x, qreal y, int wartosc) : QGraphicsRectItem(x * 10, y * 10, 10, 10)
{
    setAcceptHoverEvents(true);

    this->x = x;
    this->y = y;
    this->wartosc = wartosc;

    pen.setColor(Qt::red);
    pen.setWidth(2);

    brush.setColor(Qt::blue);
    brush.setStyle(Qt::SolidPattern);
}

void Klocek::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *widget)
{
    bokKwadratu = (min(widget->width(), widget->height()))/5;

    setRect(x * bokKwadratu, y * bokKwadratu, bokKwadratu - 3, bokKwadratu - 3);

    QRectF rect = boundingRect();

    painter->setBrush(brush);
    painter->setPen(pen);

    QFont font;
    font.setPixelSize(bokKwadratu/3);

    painter->setFont(font);
    painter->drawRect(rect);
    painter->drawText(rect,Qt::AlignCenter, QString::number(wartosc));
}

void Klocek::mousePressEvent(QGraphicsSceneMouseEvent *)
{
    if (((x - 1) > 0) && (MainWindow::plansza.wypiszElement(x - 1, y) == 0)) {
        move("left");
        qDebug() << "lewo";
    } else
        if (((y - 1) > 0) && (MainWindow::plansza.wypiszElement(x, y - 1) == 0)) {
            move("up");
            qDebug() << "gora";
        } else
            if (((x + 1) < 4) && (MainWindow::plansza.wypiszElement(x + 1, y) == 0)) {
                move("right");
                qDebug() << "prawo";
            } else
                if (((y + 1) < 4) && (MainWindow::plansza.wypiszElement(x - 1, y) == 0)) {
                    move("down");
                    qDebug() << "dol";
                }
}

void Klocek::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    pen.setColor(Qt::green);

    update();
}

void Klocek::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    pen.setColor(Qt::red);

    update();
}


