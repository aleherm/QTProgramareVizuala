#ifndef TURTLE_H
#define TURTLE_H

#endif // TURTLE_H

#include <QPainter>
#include <math.h>

class Turtle
{
private:
    double x, y, dir;
    void rotatie(double u);
    void inainteaza(QPainter &painter, double l, bool dara);

public:
    Turtle(double x0, double y0, double dir0);
    double getDir();
    double getX();
    double getY();

    void setDir(double d);
    void setX(double X);
    void setY(double Y);

    void Cantor(QPainter &painter, double d, int n);
    void Koch(QPainter &painter, double d, int n);
    void C(QPainter &painter, double d, int n);
    void dragon(QPainter &painter, double d, int n, int s);
};
