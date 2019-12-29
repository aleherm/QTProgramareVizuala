#include "transformare.h"

void Transformare::produs(double s[4][4])
{
    double r[4][4];
    for(int i=0; i<4; i++)
        for(int j=0; j<4; j++)
        {
            r[i][j]=0;
            for(int k=0; k<4; k++)
                r[i][j]+=s[i][k]*t[k][j];
        }
    for(int i=0; i<4; i++)
        for(int j=0; j<4; j++)
           t[i][j]=r[i][j];
}

void Transformare::reset(double m[4][4])
{
    for(int i=0; i<4; i++)
        for(int j=0; j<4; j++)
            if(i==j)
                m[i][j]=1;
            else
                m[i][j]=0;
}

void Transformare::translatie(double dx, double dy, double dz)
{
    double m[4][4];
    reset(m);
    m[0][3]=dx;
    m[1][3]=dy;
    m[2][3]=dz;
    produs(m);
}


void Transformare::scalareOrigine(double sx, double sy, double sz)
{
    double m[4][4];
    reset(m);
    m[0][0]=sx;
    m[1][1]=sy;
    m[2][2]=sz;
    produs(m);
}

void Transformare::scalarePunct(double sx, double sy, double sz, QVector3D punct)
{
    this->translatie(punct.x(), punct.y(), punct.z());
    this->scalareOrigine(sx, sy, sz);
    this->translatie(-punct.x(), -punct.y(), -punct.z());
}
//xOy
void Transformare::rotatieOz(double alfa, QVector3D axis)
{
    this->translatie(-axis.x(), -axis.y(), -axis.z());
    double m[4][4];
    reset(m);
    m[0][0]=cos(alfa);
    m[0][1]=-sin(alfa);
    m[1][0]=sin(alfa);
    m[1][1]=cos(alfa);
    produs(m);

    this->translatie(axis.x(), axis.y(), axis.z());
}
//zOx
void Transformare::rotatieOy(double beta, QVector3D axis)
{
    this->translatie(-axis.x(), -axis.y(), -axis.z());
    double m[4][4];
    reset(m);
    m[0][0]=cos(beta);
    m[0][2]=-sin(beta);
    m[2][0]=sin(beta);
    m[2][2]=cos(beta);
    produs(m);

    this->translatie(axis.x(), axis.y(), axis.z());
}
//yOz
void Transformare::rotatieOx(double gama, QVector3D axis)
{
    this->translatie(-axis.x(), -axis.y(), -axis.z());
    double m[4][4];
    reset(m);
    m[1][1]=cos(gama);
    m[1][2]=-sin(gama);
    m[2][1]=sin(gama);
    m[2][2]=cos(gama);
    produs(m);

    this->translatie(axis.x(), axis.y(), axis.z());
}

void Transformare::rotatieOrigine(double alfa, double beta, double gama, QVector3D centru)
{
    this->rotatieOx(gama, centru);
    this->rotatieOy(beta, centru);
    this->rotatieOz(alfa, centru);
}

void Transformare::simetrieOrigine()
{
    this->scalareOrigine(-1, -1, -1);
}

void Transformare::simetriePlan()
{
    this->scalareOrigine(1, -1, -1);
}

void Transformare::simetriePunct(double sx, double sy, double sz, QVector3D punct)
{

}

void Transformare::aplicareTransformare(double x, double y, double z, double &xp, double &yp, double &zp)
{
    xp=t[0][0]*x+t[0][1]*y+t[0][2]*z+t[0][3];
    yp=t[1][0]*x+t[1][1]*y+t[1][2]*z+t[1][3];
    zp=t[2][0]*x+t[2][1]*y+t[2][2]*z+t[2][3];
}
