#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->introducere=true;
    this->points=0;
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    if(!introducere)
    {
        this->curvePoints.clear();
        for(double t=0; t<=1; t+=0.01)
        {
            double x=this->bezier.xBezier(t, this->x);
            double y=this->bezier.yBezier(t, this->y);
            this->curvePoints.append(qMakePair(x, y));
        }
        for(int i=0; i<curvePoints.size()-1; i++)
            painter.drawLine(curvePoints[i].first, curvePoints[i].second, curvePoints[i+1].first, curvePoints[i+1].second);
    }

    for(int i=0; i<this->points; i++)
       painter.drawArc(this->x[i]-5, this->y[i]-10, 20, 20, 16*360, 16*360);
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_Escape)
    {
       this->introducere=false;
       repaint();
    }
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    Qt::MouseButton button=event->button();
    if(button&Qt::LeftButton && introducere)
    {
        this->x.append(event->x());
        this->y.append(event->y());
        this->points++;
        repaint();
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    QPoint p=event->pos();
    bool ok=false;
    int i;
    if(this->introducere == false)
    {
        for(i=0; i<this->points; i++)
            if(p.x()>=x[i]-10 && p.x()<=x[i]+10 && p.y()>=y[i]-10 && p.y()<=y[i]+10)
            {
                ok=true;
                break;
            }
        if(ok==true)
        {
            x[i]=p.x();
            y[i]=p.y();
            repaint();
        }

    }
}
