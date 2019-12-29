#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->introducere=true;
    this->nv=0;
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
        for(int i=0; i<nv; i++)
            painter.drawArc(x[i], y[i], 5, 5, 16*360, 16*360);
        actualizareCentru();
    }
    else
    {
        QPainterPath path;
        for(int i=0; i<nv; i++)
        {
            transf.aplicareTransformare(x[i], y[i], xp[i], yp[i]);
        }
        path.moveTo(xp[0], yp[0]);
        for(int i=1; i<nv; i++)
            path.lineTo(xp[i], yp[i]);
        path.lineTo(xp[0], yp[0]);
        painter.drawPath(path);
        actualizareCentru();
    }
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    Qt::MouseButton button=event->button();
    if(button&Qt::LeftButton && nv<100 && introducere)
    {
        x[nv]=event->x();
        y[nv++]=event->y();
    }
    if(!introducere)
    {
        xprev=event->x();
        yprev=event->y();
    }
    repaint();
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_Escape)
    {
       this->introducere=false;
        repaint();
    }
}

void MainWindow::actualizareCentru()
{
    int x=0, y=0;
    for(int i=0; i<nv; i++)
    {
        x+=xp[i];
        y+=yp[i];
    }
    centruX=(double)x/nv;
    centruY=(double)y/nv;
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    QPoint p=event->pos();
    double dx=0;
    double dy=0;
    if(xprev>=0 && !introducere)
    {
         dx=p.x()-xprev;
         dy=p.y()-yprev;
         if(event->buttons()&Qt::LeftButton)
            transf.translatie(dx, dy);
         if(event->buttons()&Qt::RightButton)
         {
             this->actualizareCentru();
             double alfa=atan2(p.y(),p.x())-atan2(yprev, xprev);
             transf.rotatie(alfa, centruX, centruY);
         }
         if(event->buttons()&Qt::MiddleButton)
         {
             this->actualizareCentru();
             double scalX, scalY;
             /*if(p.x()>xprev)
                 scalX=1.01;
             else
                 scalX=0.99;
             if(p.y()>yprev)
                 scalY=1.01;
             else
                 scalY=0.99;*/
             if(dx>0)
                 scalX=scalY=1+dx/100;
             //else
                 scalX=scalY=1/(1-dx/100);
             transf.scalare(scalX, scalY, centruX, centruY);
         }
         repaint();
    }
    xprev=p.x();
    yprev=p.y();
}



