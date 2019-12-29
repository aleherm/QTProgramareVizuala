#ifndef TRANSFORMARE_H
#define TRANSFORMARE_H

#include <QtMath>
#include <QVector3D>

class Transformare
{
    double t[4][4];
    void produs(double s[4][4]);
    void reset(double m[4][4]);

public:
    Transformare() { reset(t); }
    void translatie(double dx, double dy, double dz);
    void scalareOrigine(double sx, double sy, double sz);
    void aplicareTransformare(double x, double y, double z, double &xp, double &yp, double &zp);

     void scalarePunct(double sx, double sy, double sz, QVector3D punct);
     void rotatieOz(double alfa, QVector3D axis);
     void rotatieOy(double beta, QVector3D axis);
     void rotatieOx(double gama, QVector3D axis);
     void rotatieOrigine(double alfa, double beta, double gama, QVector3D centru);
     void simetrieOrigine();
     void simetriePlan();
     void simetriePunct(double sx, double sy, double sz, QVector3D punct);

};

#endif // TRANSFORMARE_H
