#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    this->introducere=true;
    this->nv=0;
    ui->setupUi(this);
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
        for(int i=0; i<this->nv; i++)
        {
            painter.drawArc(this->x[i]-5, this->y[i]-5, 10, 10, 16*360, 16*360);
        }
    }
    else
    {
        QPainterPath path;
        for(int i=0; i<this->nv; i++)
        {
            painter.drawArc(this->x[i]-5, this->y[i]-5, 10, 10, 16*360, 16*360);
        }

        path.moveTo(x[0], y[0]);
        for(int i=1; i<nv; i++)
            path.lineTo(x[i], y[i]);
        path.lineTo(x[0], y[0]);
        painter.drawPath(path);

        /*
         * for(int x=0; x<=width(); x++)
            for(int y=0; y<=height(); y++)
            {
                if(interiorVerif(qMakePair(x, y))==true)
                {
                    painter.setPen(Qt::red);
                    painter.drawPoint(x, y);
                }
                else
                {
                    painter.setPen(Qt::cyan);
                    painter.drawPoint(x, y);
                }
            }
            */
    }
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_Escape )
    {
        QMessageBox message;
        if(convexVerif()==true)
            message.setText("Convex");
        else
            message.setText("Concav");
       this->introducere=false;
       repaint();

       message.exec();
    }
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    Qt::MouseButton button=event->button();
    if(button&Qt::LeftButton && introducere)
    {
        this->x.append(event->x());
        this->y.append(event->y());
        this->nv++;
        repaint();
    }
}

double MainWindow::cotire(QPair<double, double> A, QPair<double, double> B, QPair<double, double> C)
{
    return (B.first-A.first)*(C.second-A.second)-(C.first-A.first)*(B.second-A.second);
}

bool MainWindow::convexVerif()
{
    bool convex;

        if(this->cotire(qMakePair(x[0], y[0]), qMakePair(x[1], y[1]), qMakePair(x[2], y[2])) < 0)
            convex=false;
        else
            convex=true;

        for(int i = 1; i < this->nv + 3; i++)
        {
            double rez=cotire(qMakePair(x[i%nv], y[i%nv]), qMakePair(x[(i+1)%nv], y[(i+1)%nv]), qMakePair(x[(i+2)%nv], y[(i+2)%nv]));
            if(rez<0 && convex==true)
                return false;
            if(rez>0 && convex == false)
                return false;
        }
        return true;
}

bool MainWindow::interiorVerif(QPair<double, double> punct)
{
    bool interior;
    if(cotire(punct, qMakePair(x[0], y[0]), qMakePair(x[1], y[1]))<0)
        interior=false;
    else
        interior=true;

    for(int i = 0; i < this->nv + 3; i++)
    {
        double rez=cotire(qMakePair(x[i%nv], y[i%nv]), qMakePair(x[(i+1)%nv], y[(i+1)%nv]), qMakePair(x[(i+2)%nv], y[(i+2)%nv]));
        if(rez<0 && interior==true)
            return false;
        if(rez>0 && interior == false)
            return false;
    }
    return true;
}
