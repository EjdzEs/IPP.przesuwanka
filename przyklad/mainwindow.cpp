#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "kwadrat.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    scene->addItem();
}

MainWindow::~MainWindow()
{
    delete ui;
}
