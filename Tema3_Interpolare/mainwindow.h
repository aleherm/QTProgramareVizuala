#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QRandomGenerator>

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
    QVector <double> x, y;
    double xprev;
    int randomX;
    QRandomGenerator rand;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    void paintEvent(QPaintEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void mousePressEvent(QMouseEvent *event);
    double L(double X, int i);
    double P(double X);

};

#endif // MAINWINDOW_H
