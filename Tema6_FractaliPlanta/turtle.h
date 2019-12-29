#include <QPainter>
#include <math.h>
#include <complex>
#include "randomizer.h"

#include<QDebug>
#include<QVector>
#include<QColor>

class Turtle
{
private:
    double x, y, dir;
    void rotatie(double u);
    void inainteaza(QPainter &painter, double l, bool dara);

public:
    Randomizer random;

    Turtle(double x0, double y0, double dir0);
    double getDir();
    double getX();
    double getY();

    void planta(QPainter &painter, double d, int n);
    void plantaOptional(QPainter &painter, double d, int n);
    void covorSierpinski(QPainter &painter, double x, double y, double d, int n);
    void triunghiSierpinski(QPainter &painter, double x, double y, double d, int n);
    void covorSierpinskiDreptunghi(QPainter &painter, double x, double y, double L, double l, int n);

    void Mandelbrot(QPainter &painter, int rows, int columns);

};
