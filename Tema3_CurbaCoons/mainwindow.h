#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QKeyEvent>
#include <QMouseEvent>

#include "coons.h"

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
private:
    bool introducere;

    int points;
    QVector<QPair<double, double>> curvePoints;
    Coons coons;

public:
    double x[4], y[4], xprev;

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    void paintEvent(QPaintEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

};

#endif // MAINWINDOW_H
