#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "kwadrat.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new QGraphicsScene();
    ui->graphicsView->setScene(scene);

//    ui->graphicsView->viewport()->setMouseTracking(true);
//    QMainWindow::setMouseTracking(true);
//    ui->graphicsView->setMouseTracking(true);
//    ui->graphicsView->viewport()->setMouseTracking(true);
//    ui->graphicsView->

    kwadrat *k = new kwadrat(10,10,40);

    scene->addItem(k);


}

MainWindow::~MainWindow()
{
    delete ui;
}
