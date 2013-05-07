#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>

#include "plansza.hxx"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    void on_nowaGraButton_clicked();

    void on_pokazRozwiazanieButton_clicked();

    void on_pomocButton_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
public:
    static Plansza plansza;
};

#endif // MAINWINDOW_H
