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

void MainWindow::paintEvent(QPaintEvent *e)
{
    QPainter p(this);

    p.begin(this);

    //p.drawElipse(pozx, pozy, 10, 10);
    p.drawLine(20, 20, 500, 20); // sus
    p.drawLine(20, 20, 20, 400); // stanga
    p.drawLine(20, 400, 500, 400); // jos
    p.drawLine(500, 400, 500, 20); // dreapta
     p.drawLine(500, 400, 500, 20); // dreapta

    p.drawLine(20, 300, 170, 300); //pamant stanga
    p.drawLine(350, 300, 500, 300); //pamant dreapta

    p.drawLine(170, 300, 170, 350);
    p.drawLine(350, 300, 350, 350);

    p.drawLine(170, 350, 350, 350); // casa jos

    p.drawLine(170, 300, 170, 200);
    p.drawLine(350, 300, 350, 200);

    p.drawLine(260, 120, 145, 220); //acoperis stanga
    p.drawLine(260, 120, 375, 220); //acoperis dreapta

    p.drawLine(230, 350, 230, 270); // usa stanga
    p.drawLine(230, 270, 280, 270); // usa sus
    p.drawLine(280, 270, 280, 350); // usa dreapta

    p.drawLine(240, 240, 240, 200); //geam_st dr
    p.drawLine(240, 200, 200, 200); //geam_st sus
    p.drawLine(200, 200, 200, 240); //geam_st st
    p.drawLine(200, 240, 240, 240); //geam_st jos

    p.drawLine(280, 240, 280, 200); //geam_dr st
    p.drawLine(280, 200, 320, 200); //geam_dr sus
    p.drawLine(320, 200, 320, 240); //geam_dr dr
    p.drawLine(320, 240, 280, 240); //geam_dr jos

    p.drawLine(240, 220, 200, 220); // + geam st
    p.drawLine(220, 200, 220, 240);
    p.drawLine(280, 220, 320, 220); // + geam dr
    p.drawLine(300, 200, 300, 240);

    p.drawEllipse(QPointF(270, 310), 5, 5);

    p.drawEllipse(QPointF(400, 90), 30, 30);
    p.drawLine(365, 90, 335, 90); // soare st
    p.drawLine(435, 90, 470, 90); // soare dr
    p.drawLine(400, 55, 400, 25); //soare sus
    p.drawLine(400, 125, 400, 155); // soare jos

    p.drawLine(425, 115, 450, 140); // soare dr jos
    p.drawLine(350, 40, 375, 65); // soare st sus
    p.drawLine(425, 65, 450, 40); // soare dr sus
    p.drawLine(375, 115, 350, 140); // soare st jos

    p.drawArc(60, 50, 55, 60, 30*16, 120*16); // pasare sus
    p.drawArc(105, 50, 50, 55, 30*16, 120*16);

    p.drawArc(100, 70, 55, 60, 30*16, 120*16); // pasare jos
    p.drawArc(145, 70, 50, 55, 30*16, 120*16);




}
