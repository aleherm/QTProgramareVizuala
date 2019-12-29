#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    //VALORILE PENTRU INTERVAL SI REZOLUTIE
    a=-10;
    b=10;
    rezolutie=1000;

    for(double i=a; i<=b; i+=b/rezolutie)
    {
        puncte.append(QVector3D(f(i), g(i), h(i)));
    }

    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

double MainWindow::f(double u)
{
    return R*cos(u);
}
double MainWindow::g(double u)
{
    return R*sin(u);
}
double MainWindow::h(double u)
{
    return c*u+d;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    this->desen.setVarfuri(puncte);

    this->desen.genereazaPuncte2D(width(), height());
    for(int i=0; i<this->desen.puncte.length()-1; i++)
    {
        painter.drawLine(this->desen.puncte[i].first, this->desen.puncte[i].second, this->desen.puncte[i+1].first, this->desen.puncte[i+1].second);
    }
}
