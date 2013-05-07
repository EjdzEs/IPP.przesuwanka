#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsItemAnimation>
#include <QTimeLine>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
// -----------------------------------------------------------------------
    ui->setupUi(this);
    QGraphicsScene *scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
// -----------------------------------------------------------------------
    // kolor pedzla
    QBrush brush = QBrush(Qt::red);
    brush.setStyle(Qt::DiagCrossPattern);
    // tworzymy obiekts
    QGraphicsRectItem *rect = new QGraphicsRectItem(10, 10, 90, 90);
    rect->setBrush(brush);
// -----------------------------------------------------------------------
// -----------------------------------------------------------------------
    // definiujemy czas trwania animacji
    QTimeLine *timeLine = new QTimeLine(1000);
    timeLine->setFrameRange(0, 100);

    // definiujemy animacje
    QGraphicsItemAnimation *animation = new QGraphicsItemAnimation();
    animation->setItem(rect);
    animation->setTimeLine(timeLine);

    // animacja
    int odcinek = 100;
    for (int i = 0; i < 100; ++i)
           animation->setPosAt(i / 100.0, QPointF(i, i));

    // uruchamiamy scenę i animację
    scene->addItem(rect);
    timeLine->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}
