#include "pomoc.h"
#include "ui_pomoc.h"

#include <QGraphicsSimpleTextItem>
#include <QFont>

Pomoc::Pomoc(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Pomoc)
{
    ui->setupUi(this);
    setWindowTitle("Pomoc");

    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    QGraphicsSimpleTextItem *text = new QGraphicsSimpleTextItem();

    QFont font;
    font.setPixelSize(15);

    text->setFont(font);
    text->setText("Witaj w instrukcji programu 'Game of fifteen'\n");


    scene->addItem(text);
}

Pomoc::~Pomoc()
{
    delete ui;
}
