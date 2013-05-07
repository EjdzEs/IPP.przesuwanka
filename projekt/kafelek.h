#ifndef KAFELEK_H
#define KAFELEK_H

#include <QGraphicsItem>

class Kafelek : QGraphicsItem
{
private:
    // indeks kafelka w tablicy modelującej plansze
    int index;

public:
    Kafelek(int wiersz, int kolumna);
};

#endif // KAFELEK_H
