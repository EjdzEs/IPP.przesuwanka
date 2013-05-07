#ifndef POMOC_H
#define POMOC_H

#include <QDialog>
#include <QGraphicsScene>

namespace Ui {
class Pomoc;
}

class Pomoc : public QDialog
{
    Q_OBJECT
    
public:
    explicit Pomoc(QWidget *parent = 0);
    ~Pomoc();
    
private:
    Ui::Pomoc *ui;
    QGraphicsScene *scene;
};

#endif // POMOC_H
