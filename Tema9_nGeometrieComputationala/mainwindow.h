#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QPaintEvent>
#include <QKeyEvent>
#include <QDebug>
#include <QPair>
#include <QMessageBox>
#include <QString>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QVector<double> x, y;
    bool introducere;
    int nv;

    void paintEvent(QPaintEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void mousePressEvent(QMouseEvent *event);
    bool interiorVerif(QPair<double, double> punct);

    double cotire(QPair<double, double> A, QPair<double, double> B, QPair<double, double> C);
    bool convexVerif();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
