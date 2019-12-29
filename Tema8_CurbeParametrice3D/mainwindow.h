#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QPaintEvent>
#include <QVector>
#include <QVector3D>

#include "wireframe.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    double f(double u);
    double g(double u);
    double h(double u);
    void paintEvent(QPaintEvent *event);

    double a, b, rezolutie;
    double R=200, c=100, d=-1000;

    QVector<QVector3D> puncte;
    Wireframe desen;

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
