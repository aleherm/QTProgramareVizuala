#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::adaugaCoordonate()
{
    //casa spate
    this->desen.adaugaVarf(-50, 30, 0);
    this->desen.adaugaVarf(-200, 30, 0);
    this->desen.adaugaVarf(-200, 170, 0);
    this->desen.adaugaVarf(-50, 170, 0);

    //casa fata
    this->desen.adaugaVarf(-50, 30, 300);
    this->desen.adaugaVarf(-200, 30, 300);
    this->desen.adaugaVarf(-200, 170, 300);
    this->desen.adaugaVarf(-50, 170, 300);

    //acoperis spate
    this->desen.adaugaVarf(-50, 30, 0);
    this->desen.adaugaVarf(-200, 30, 0);
    this->desen.adaugaVarf(-125, -80, 0);

    //acoperis fata
    this->desen.adaugaVarf(-50, 30, 300);
    this->desen.adaugaVarf(-200, 30, 300);
    this->desen.adaugaVarf(-125, -80, 300);

    //usa
    this->desen.adaugaVarf(-135, 100, 300); //14 st sus
    this->desen.adaugaVarf(-100, 100, 300); //15 dr
    this->desen.adaugaVarf(-135, 170, 300); //17 st jos
    this->desen.adaugaVarf(-100, 170, 300); //16 dr

    //geam stanga
    this->desen.adaugaVarf(-180, 50, 300); //18 st sus
    this->desen.adaugaVarf(-150, 50, 300); //19 dr
    this->desen.adaugaVarf(-180, 80, 300); //20 st jos
    this->desen.adaugaVarf(-150, 80, 300); //21 dr

    //geam dreapta
    this->desen.adaugaVarf(-100, 50, 300); //22 st sus
    this->desen.adaugaVarf(-70, 50, 300); //23 dr
    this->desen.adaugaVarf(-100, 80, 300); //25 st jos
    this->desen.adaugaVarf(-70, 80, 300); //24 dr

    this->desen.adaugaUnire(0, 1);
    this->desen.adaugaUnire(1, 2);
    this->desen.adaugaUnire(2, 3);
    this->desen.adaugaUnire(3, 0);

    this->desen.adaugaUnire(4, 5);
    this->desen.adaugaUnire(5, 6);
    this->desen.adaugaUnire(6, 7);
    this->desen.adaugaUnire(7, 4);

    this->desen.adaugaUnire(0, 4);
    this->desen.adaugaUnire(1, 5);
    this->desen.adaugaUnire(2, 6);
    this->desen.adaugaUnire(3, 7);

    this->desen.adaugaUnire(8, 10);
    this->desen.adaugaUnire(9, 10);

    this->desen.adaugaUnire(11, 13);
    this->desen.adaugaUnire(12, 13);

    this->desen.adaugaUnire(10, 13);

    //usa
    this->desen.adaugaUnire(16, 14);
    this->desen.adaugaUnire(14, 15);
    this->desen.adaugaUnire(15, 17);

    //geamuri
    this->desen.adaugaUnire(18, 19);
    this->desen.adaugaUnire(19, 21);
    this->desen.adaugaUnire(21, 20);
    this->desen.adaugaUnire(20, 18);

    this->desen.adaugaUnire(22, 23);
    this->desen.adaugaUnire(23, 25);
    this->desen.adaugaUnire(25, 24);
    this->desen.adaugaUnire(24, 22);
}

void MainWindow::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    int x, y, xp, yp;

    this->adaugaCoordonate();

    /*
    p.drawRect(20*zp/(zp-za), 20, 600, 500); //chenar

    p.drawRect(170, 280, 180, 170); //casa

    p.drawLine(260, 200, 145, 300); //acoperis stanga
    p.drawLine(260, 200, 375, 300); //acoperis dreapta

    p.drawRect(230, 370, 50, 80); // usa

    p.drawRect(200, 300, 40, 40); //geam st
    p.drawRect(280, 300, 40, 40); //geam dr

    p.drawLine(240, 320, 200, 320); // + geam st
    p.drawLine(220, 300, 220, 340);
    p.drawLine(280, 320, 320, 320); // + geam dr
    p.drawLine(300, 300, 300, 340);
    */

    this->desen.genereazaPuncte2D(width(), height());
    for(int i=0; i<this->desen.uniri.size(); i++)
        painter.drawLine(this->desen.puncte[this->desen.uniri[i].first].first, this->desen.puncte[this->desen.uniri[i].first].second,
                        this->desen.puncte[this->desen.uniri[i].second].first, this->desen.puncte[this->desen.uniri[i].second].second);
    /*for(int i=0; i<this->desen.puncte.size(); i++)
    {painter.drawEllipse(this->desen.puncte[i].first, this->desen.puncte[i].second, 10, 10);
        qDebug()<<this->desen.puncte[i].first<<" "<<this->desen.puncte[i].second;}*/

    //qDebug()<<this->desen.puncte.size();
}
