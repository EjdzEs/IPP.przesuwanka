#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPropertyAnimation>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene();
    ui->graphicsView->setScene(scene);

    Klocek *k = new Klocek(0, 0, 40, 40);
    scene->addItem(k);
//    QPropertyAnimation *animation = new QPropertyAnimation(*k, "geometry");
//    animation->setDuration(10000);
//    animation->setStartValue(QRect(0, 0, 100, 30));
//    animation->setEndValue(QRect(250, 250, 100, 30));

//    animation->start();

//    animation.start();
//    for (int i = 0; i < 4; ++i) {
//        for (int j = 0; j < 4; ++j) {
//            scene->addItem(new Klocek(i, j, 40, 40));
//        }
//    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
