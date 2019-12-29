#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "bresenham.h"

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

void MainWindow::paintEvent(QPaintEvent *event)
{
    Bresenham draw;
    QPainter painter(this);
    draw.line(painter, 10, 10, 300, 300);
    draw.line(painter, 300, 10, 10, 300);

    //int cx=300, cy=300, r=150;
    //draw.circle(painter, cx, cy, r); //da la apel coordonatele centrului pentru translatare

    /*painter.setPen(Qt::red);
    for(double a=0; a<=2*M_PI; a+=0.0001)
    {
        int x=cx+r*cos(a);
        int y=cy+r*sin(a);
        draw.line(painter, cx, cy, x, y);
    }*/
    painter.end();
}
