#include <QGraphicsPixmapItem>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "pomoc.h"
#include "klocek.h"
#include "obrazek.h"

#include "permutacje.hxx"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    setWindowTitle("Przesuwanka");

    Obrazek *item = new Obrazek(QPixmap(":/obrazPoczatkowy/puzzle15.png"));
    scene->addItem(item);
}

MainWindow::~MainWindow()
{
    delete ui;
}

Plansza MainWindow::plansza = Plansza();

void MainWindow::on_nowaGraButton_clicked()
{
    Permutacje *permutacje = new Permutacje(15);
    int *tabPerm = permutacje->losujeParzystaPermutacje();

    plansza = Plansza(tabPerm);

    scene->clear();
    int licznik = 0;

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (!((i == 3) && (j == 3))) {
                scene->addItem(new Klocek(i, j, tabPerm[licznik++]));
//                scene->addItem(new Klocek(i, j, plansza.wypiszElement(i, j)));
//                scene->addItem(new Klocek(i, j, plansza.wypiszElement(licznik++)));
            }
        }
    }
}

void MainWindow::on_pokazRozwiazanieButton_clicked()
{
//    TODO
}

void MainWindow::on_pomocButton_clicked()
{
    Pomoc pomoc;
    pomoc.setModal(true);
    pomoc.exec();
}
