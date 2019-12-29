#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector3D>
#include <QPainter>
#include "transformare.h"
#include "wireframe.h"
#include <QKeyEvent>


namespace Ui
{
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    bool start;
    double x[100], y[100], z[100];
    int nv;
    Transformare transf;
    Wireframe desen;
    QVector<QVector3D> varfuriNew;


    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void paintEvent(QPaintEvent *e);
    void keyPressEvent(QKeyEvent *event);
    void adaugaCoordonate();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
