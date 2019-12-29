#ifndef BEZIER_H
#define BEZIER_H

#endif // BEZIER_H

#include <QVector>

class Bezier
{
public:
    double xBezier(double t, QVector<double> x);
    double yBezier(double t, QVector<double> y);
    double Bernstein(double t, int i, int n);

private:
    double combinari(int n, int k);
    int factorial(int nr);
};
