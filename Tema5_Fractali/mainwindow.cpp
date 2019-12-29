#include "mainwindow.h"
#include "ui_mainwindow.h"

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

void MainWindow::fulgKoch(QPainter &painter, double d, double n)
{
    Turtle t(200, 300, 0);
    t.Koch(painter, d, n);
    t.setDir(2*M_PI/3);
    t.Koch(painter, d, n);
    t.setDir(-2*M_PI/3);
    t.Koch(painter, d, n);
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter;
    painter.begin(this);
    Turtle t(200, 200, 0);
   // t.Cantor(painter, 400, 3);
    //t.Koch(painter, 400, 5);
    fulgKoch(painter, 300, 5);
    //t.C(painter, 300, 15);
    //t.dragon(painter, 400, 15, 1);
    painter.end();
}
