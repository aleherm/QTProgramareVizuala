#ifndef TRANSFORMARE_H
#define TRANSFORMARE_H

#include <QtMath>

class Transformare
{
    double t[3][3];
    void produs(double s[3][3]);
    void reset(double m[3][3]);

public:
    Transformare() { reset(t); }
    void translatie(double dx, double dy);
    void rotatie(double alfa, double centruX, double centruY);
    void scalare(double sx, double sy, double centruX, double centruY);
    void aplicareTransformare(double x, double y, double &xp, double &yp);

};

#endif // TRANSFORMARE_H
