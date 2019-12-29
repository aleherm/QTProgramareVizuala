#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <QPainter>
#include <QDebug>
#include "transformare.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void paintEvent(QPaintEvent *event);
    double a, b, rezolutie;
    Transformare transformare;
    bool ok;

    double ox, oy;

    QVector<double> x, y;

private:
    Ui::MainWindow *ui;

    double f(double val);
    double g(double val);

    double minim(QVector<double> v);
    double maxim(QVector<double> v);

    void modificare();
    void grafic();
};

#endif // MAINWINDOW_H
