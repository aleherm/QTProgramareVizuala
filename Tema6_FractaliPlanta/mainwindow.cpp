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

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter;
    painter.begin(this);
    Turtle t(300, 300, 4.72);
    t.planta(painter, 100, 15);
    //t.covorSierpinski(painter, 50, 50, 300, 3);
    //t.triunghiSierpinski(painter, 50, 50, 300, 3);
   //t.covorSierpinskiDreptunghi(painter, 50, 50, 200, 300, 3);
    //t.Mandelbrot(painter, width(), height());
    painter.end();
}
