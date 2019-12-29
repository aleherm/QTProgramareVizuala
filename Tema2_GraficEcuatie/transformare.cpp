#include "transformare.h"

void Transformare::produs(double s[3][3])
{
    double r[3][3];
    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
        {
            r[i][j]=0;
            for(int k=0; k<3; k++)
                r[i][j]+=s[i][k]*t[k][j];
        }
    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
           t[i][j]=r[i][j];
}

void Transformare::reset(double m[3][3])
{
    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
            if(i==j)
                m[i][j]=1;
            else
                m[i][j]=0;
}

void Transformare::translatie(double dx, double dy)
{
    double m[3][3];
    reset(m);
    m[0][2]=dx;
    m[1][2]=dy;
    produs(m);
}

void Transformare::rotatie(double alfa, double centruX, double centruY)
{
    this->translatie(-centruX,-centruY);
    double m[3][3];
    reset(m);
    m[0][0]=cos(alfa);
    m[0][1]=-1*sin(alfa);
    m[1][0]=sin(alfa);
    m[1][1]=cos(alfa);
    produs(m);
    this->translatie(centruX, centruY);
}

 void Transformare::scalare(double sx, double sy, double centruX, double centruY)
 {
     this->translatie(-centruX,-centruY);
     double m[3][3];
     reset(m);
     m[0][0]=sx;
     m[1][1]=sy;
     produs(m);
     this->translatie(centruX, centruY);
 }

void Transformare::aplicareTransformare(double x, double y, double &xp, double &yp)
{
    xp=t[0][0]*x+t[0][1]*y+t[0][2];
    yp=t[1][0]*x+t[1][1]*y+t[1][2];
}
