#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "myitem.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    scene->setSceneRect(-200, -200, 300, 300);

    QPen mypen = QPen(Qt::red);

    QLineF TopLine(scene->sceneRect().topLeft(), scene->sceneRect().topRight());
    QLineF LeftLine(scene->sceneRect().topLeft(), scene->sceneRect().bottomLeft());
    QLineF RightLine(scene->sceneRect().topRight(), scene->sceneRect().bottomRight());
    QLineF BottomLine(scene->sceneRect().bottomLeft(), scene->sceneRect().bottomRight());

    scene->addLine(TopLine, mypen);
    scene->addLine(LeftLine, mypen);
    scene->addLine(RightLine, mypen);
    scene->addLine(BottomLine, mypen);

    int ItemCount = 1;
    for (int i = 0; i < ItemCount; ++i) {
        MyItem *item = new MyItem();
        scene->addItem(item);
    }



    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), scene, SLOT(advance()));
    timer->start(100);
}

MainWindow::~MainWindow()
{
    delete ui;
}
