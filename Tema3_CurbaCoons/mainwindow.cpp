#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->introducere=true;
    this->points=0;
    this->xprev=-100;
    //curvePoints=new QVector<QPair<double, double>>;
    //srand(time(NULL));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    if(introducere)
    {
        for(int i=0; i<this->points; i++)
           painter.drawArc(this->x[i]-5, this->y[i]-5, 10, 10, 16*360, 16*360);
    }
    else
    {
        this->curvePoints.clear();

        for(int i=0; i<this->points; i++)
           painter.drawArc(this->x[i]-5, this->y[i]-5, 10, 10, 16*360, 16*360);

        for(double t=0; t<=1; t=t+0.01)
        {
            double x=this->coons.xCoons(this->x, t);
            double y=this->coons.yCoons(this->y, t);
            this->curvePoints.append(qMakePair(x, y));

            for(int i=0; i<curvePoints.length()-1; i++)
                painter.drawLine(curvePoints[i].first, curvePoints[i].second, curvePoints[i+1].first, curvePoints[i+1].second);
        }
        painter.drawLine(x[0], y[0], x[1], y[1]);
        painter.drawLine(x[2], y[2], x[3], y[3]);
    }
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
    if(button&Qt::LeftButton && points<4 && introducere)
    {
        this->x[points]=event->x();
        this->y[points++]=event->y();
        repaint();
    }

    /*Qt::MouseButton button=event->button();
        if(button&Qt::LeftButton && introducere)
        {
            for(int i=0; i<4; i++)
            {
                int x0=rand()%width();
                int y0=rand()%height();
                x[points]=x0;
                y[points++]=y0;
            }

            introducere=false;
            repaint();
        }
        */
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    QPoint p=event->pos();
    Qt::MouseButton button=event->button();
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
