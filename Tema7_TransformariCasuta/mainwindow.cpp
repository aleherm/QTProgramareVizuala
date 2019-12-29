#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    this->start=true;
    this->adaugaCoordonate();
    ui->setupUi(this);
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

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    if(start)
    {
        this->desen.genereazaPuncte2D(width(), height());
        for(int i=0; i<this->desen.uniri.size(); i++)
            painter.drawLine(this->desen.puncte[this->desen.uniri[i].first].first, this->desen.puncte[this->desen.uniri[i].first].second,
                             this->desen.puncte[this->desen.uniri[i].second].first, this->desen.puncte[this->desen.uniri[i].second].second);
        this->start=false;
        qDebug()<<start;
    }
    else
    {
        Wireframe desenNou;
        QVector<QVector3D> varfuriVechi;
        varfuriVechi=this->desen.getVarfuri();
        double xp, yp, zp;
        for(int i=0; i<varfuriVechi.length(); i++)
        {
            transf.aplicareTransformare(varfuriVechi[i].x(), varfuriVechi[i].y(), varfuriVechi[i].z(), xp, yp, zp);
            desenNou.adaugaVarf(xp, yp, zp);
        }

        desenNou.genereazaPuncte2D(width(), height());
        desenNou.setUniri(this->desen.getUniri());

        for(int i=0; i<desenNou.uniri.size(); i++)
            painter.drawLine(desenNou.puncte[desenNou.uniri[i].first].first, desenNou.puncte[desenNou.uniri[i].first].second,
                             desenNou.puncte[desenNou.uniri[i].second].first, desenNou.puncte[desenNou.uniri[i].second].second);

    }
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_W)
    {
        this->transf.translatie(0, -10, 0);
    }
    if(event->key() == Qt::Key_S)
    {
        this->transf.translatie(0, 10, 0);
    }
    if(event->key() == Qt::Key_D)
    {
        this->transf.translatie(-10, 0, 0);
    }
    if(event->key() == Qt::Key_A)
    {
        this->transf.translatie(10, 0, 0);
    }
    if(event->key() == Qt::Key_Plus)
    {
        this->transf.scalareOrigine(1.1, 1.1, 1.1);
    }
    if(event->key() == Qt::Key_Minus)
    {
        this->transf.scalareOrigine(0.9, 0.9, 0.9);
    }
    //rotire sus in jurul Ox
    if(event->key() == Qt::Key_1)
    {
        QVector3D centru=this->desen.centruGreutate();
        this->transf.rotatieOx(0.1, QVector3D(0, centru.y(), centru.z()));
    }
    //rotire jos in jurul Ox
    if(event->key() == Qt::Key_2)
    {
        QVector3D centru=this->desen.centruGreutate();
        this->transf.rotatieOx(-0.1, QVector3D(0, centru.y(), centru.z()));
    }
    if(event->key() == Qt::Key_3)
    {
        QVector3D centru=this->desen.centruGreutate();
        this->transf.rotatieOy(0.1, QVector3D(centru.x(), 0, centru.z()));
    }
    if(event->key() == Qt::Key_4)
    {
        QVector3D centru=this->desen.centruGreutate();
        this->transf.rotatieOy(-0.1, QVector3D(centru.x(), 0, centru.z()));
    }

    if(event->key() == Qt::Key_5)
    {
        QVector3D centru=this->desen.centruGreutate();
        this->transf.rotatieOz(0.1, QVector3D(centru.x(), centru.y(), 0));
    }
    if(event->key() == Qt::Key_6)
    {
        QVector3D centru=this->desen.centruGreutate();
        this->transf.rotatieOz(-0.1, QVector3D(centru.x(), centru.y(), 0));
    }

    if(event->key() == Qt::Key_Z)
    {
        QVector3D centru=this->desen.centruGreutate();
        this->transf.rotatieOrigine(0.1, 0.1, 0.1, centru);
    }
    if(event->key() == Qt::Key_X)
    {
        this->transf.simetrieOrigine();
    }
    if(event->key() == Qt::Key_C)
    {
        this->transf.scalarePunct(1.1, 1.1, 1.1, QVector3D(10, 10, 10));
    }
    repaint();
}
