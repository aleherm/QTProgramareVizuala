#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    this->introducere=true;
    this->nv=0;
    this->litere="ABCD";
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
            painter.drawText(x[i], y[i]-10, litere.at(i));
        }
    }
    else
    {
        QPainterPath path;
        for(int i=0; i<this->nv; i++)
        {
            painter.drawArc(this->x[i]-5, this->y[i]-5, 10, 10, 16*360, 16*360);
            painter.drawText(x[i], y[i]-10, litere.at(i));
        }

        path.moveTo(x[0], y[0]);
        for(int i=1; i<nv; i++)
            path.lineTo(x[i], y[i]);
        path.lineTo(x[0], y[0]);
        painter.drawPath(path);

        painter.setPen(Qt::red);
        painter.drawLine(x[0], y[0], x[2], y[2]);
        painter.setPen(Qt::black);
    }

}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_Escape && nv==4)
    {
       QMessageBox message;
       //ACB si ACD
       double diag1=cotire(qMakePair(x[0], y[0]), qMakePair(x[2], y[2]), qMakePair(x[1], y[1])) * cotire(qMakePair(x[0], y[0]), qMakePair(x[2], y[2]), qMakePair(x[3], y[3]));
       if(diag1 < 0)
       {
           message.setText("Dreapta AC separa punctele B si D. ");
       }
       else
       {
           message.setText("Dreapta AC NU separa punctele B si D. ");
       }
       //ABD si CBD
       double diag2=cotire(qMakePair(x[0], y[0]), qMakePair(x[1], y[1]), qMakePair(x[3], y[3])) * cotire(qMakePair(x[2], y[2]), qMakePair(x[1], y[1]), qMakePair(x[3], y[3]));
       if (diag2 < 0)
       {
           message.setText(message.text() + "Poligon convex");
       }
       else
       {
           message.setText(message.text() + "Poligon concav");
       }
       this->introducere=false;
       repaint();

       message.exec();
    }
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    Qt::MouseButton button=event->button();
    if(button&Qt::LeftButton && nv<4 && introducere)
    {
        this->x[nv]=event->x();
        this->y[nv++]=event->y();
        repaint();
    }
}

double MainWindow::cotire(QPair<double, double> A, QPair<double, double> B, QPair<double, double> C)
{
    return (B.first-A.first)*(C.second-A.second)-(C.first-A.first)*(B.second-A.second);
}

