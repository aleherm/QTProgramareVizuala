#include "coons.h"

double Coons::xCoons(double x[4], double t)
{
    double ax=x[1]-x[0];
    double cx=x[3]-x[2];

    double mx=cx-2*x[2]+ax+2*x[0];
    double nx=3*x[2]-3*x[0]-cx-2*ax;

    double qx=x[0];
    double px=ax;

    double X=mx*t*t*t+nx*t*t+px*t+qx;
    return X;
}

double Coons::yCoons(double y[5], double t)
{
    double ay=y[1]-y[0];
    double cy=y[3]-y[2];

    double my=cy-2*y[2]+ay+2*y[0];
    double ny=3*y[2]-3*y[0]-cy-2*ay;

    double py=ay;
    double qy=y[0];

    double Y=my*t*t*t+ny*t*t+py*t+qy;
    return Y;
}
