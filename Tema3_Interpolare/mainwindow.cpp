#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->introducere=true;
    this->points=0;
    this->xprev=0;
    this->randomX=0;

    //srand(time(NULL));


    rand.bounded(0, width());

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
        for(int i=x[0]; i<=x[x.size()-1]; i++)
        {
            double x=i;
            double y=P(i);
            this->curvePoints.append(qMakePair(x, y));
        }

        for(int i=0; i<curvePoints.size()-1; i++)
            painter.drawLine(curvePoints[i].first, curvePoints[i].second, curvePoints[i+1].first, curvePoints[i+1].second);
    }

    for(int i=0; i<this->points; i++)
       painter.drawArc(this->x[i]-5, this->y[i]-5, 10, 10, 16*360, 16*360);
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    /*if(event->key()==Qt::Key_Escape)
    {
       this->introducere=false;
       repaint();
    }*/
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    /*Qt::MouseButton button=event->button();
    if(button&Qt::LeftButton && introducere)
    {
        if(event->x()>this->xprev)
        {
            this->xprev=event->x();
            this->x.append(event->x());
            this->y.append(event->y());
            this->points++;
            repaint();
        }
    }*/

    Qt::MouseButton button=event->button();
        if(button&Qt::LeftButton && introducere)
        {

            if(this->points<10)
            {
                this->randomX=rand.bounded(randomX, width());
                int randomY=rand.bounded(0, height());
                this->x.append(randomX);
                this->y.append(randomY);
                this->points++;
            }
            else
                this->introducere=false;

            repaint();
        }

}


double MainWindow::L(double X, int i)
{
    double prod=1;
    for(int j=0; j<this->x.size(); j++)
        if(i!=j)
            prod*=(X-this->x[j])/(this->x[i]-this->x[j]);
    return prod;
}

double MainWindow::P(double X)
{
    double sum=0;
    for(int i=0; i<this->x.size(); i++)
        sum+=this->y[i]*this->L(X, i);
    return sum;
}
