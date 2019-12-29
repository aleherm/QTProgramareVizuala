#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    //VALORILE PENTRU INTERVAL SI REZOLUTIE
    a=-2;
    b=2;
    ok=false;
    rezolutie=0.01;

    ox=0;
    oy=0;

    ui->setupUi(this);

    grafic();
}

MainWindow::~MainWindow()
{
    delete ui;
}

double MainWindow::f(double val)
{
    return val*sin(val);
    //return cos(val);
    //return val;
}
double MainWindow::g(double val)
{
    return val*cos(val);
    //return sin(val);
    //return val+1;
}

double MainWindow::minim(QVector<double> v)
{
    double min=v[0];
    for(int i=1; i<v.size(); i++)
        if(min>v[i])
            min=v[i];
    return min;
}
double MainWindow::maxim(QVector<double> v)
{
    double max=v[0];
    for(int i=1; i<v.size(); i++)
        if(max<v[i])
            max=v[i];
    return max;
}


void MainWindow::modificare()
{
    QVector<double> newX;
    QVector<double> newY;
    for(int i=0; i<x.size(); i++)
    {
        double xp, yp;
        transformare.aplicareTransformare(x[i], y[i], xp, yp);
        newX.append(xp);
        newY.append(yp);
    }
    x.clear();
    y.clear();
    for(int i=0; i<newX.size(); i++)
    {
        x.append(newX[i]);
        y.append(newY[i]);
    }
    newX.clear();
    newY.clear();

    double newOx, newOy;
    transformare.aplicareTransformare(ox, oy, newOx, newOy);
    ox=newOx;
    oy=newOy;
    transformare.reset(transformare.t);
}


void MainWindow::grafic()
{
    for(double i=a; i<b; i=i+this->rezolutie)
    {
        x.append(f(i));
        y.append(g(i));
    }
    //TRANSLATIE
    transformare.translatie(-minim(x), -minim(y));
    modificare();

    //SCALARE
    double sx, sy;
    sx=width()/maxim(x);
    sy=height()/maxim(y);
    double scal;
    if(sx<sy)
        scal=sx;
    else
        scal=sy;
    transformare.scalare(scal, scal, 0, 0);
    modificare();

    //TRANSLATARE CENTRU
    double dx, dy;
    dx=(width()-maxim(x))/2;
    dy=(height()-maxim(y))/2;
    transformare.translatie(dx, dy);
    modificare();

    //SIMETRIE PE ORIZONTALA
    for(int i=0; i<y.size(); i++)
        y[i]=height()-y[i];

    //MODIFICARI ADUSE CENTRULUI

    this->ok=true;
    repaint();
}


void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    if(this->ok==true)
    {
        for(int i=0; i<x.size()-1; i++)
            painter.drawLine(x[i], y[i], x[i+1], y[i+1]);
        painter.setPen(Qt::blue);
        painter.drawLine(0, oy, width(), oy);
        painter.drawLine(ox, 0, ox, height());

        //sageata ox
        painter.drawLine(width()-10, oy-10, width(), oy);
        painter.drawLine(width()-10, oy+10, width(), oy);

        //sageata oy
        painter.drawLine(ox, 0, ox-10, 10);
        painter.drawLine(ox, 0, ox+10, 10);

        //setare text sageti
        painter.setPen(Qt::red);
        painter.drawText(width()-20, oy-15, "X");
        painter.drawText(ox+15, 20, "Y");
        painter.drawText(ox+10, oy+20, "O");
        //painter.drawText(ox+20, oy-20, "O");
    }
}

