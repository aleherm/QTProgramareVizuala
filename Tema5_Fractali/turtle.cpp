#include "turtle.h"

Turtle::Turtle(double x0, double y0, double dir0)
{
    this->x=x0;
    this->y=y0;
    this->dir=dir0;
}

void Turtle::rotatie(double u)
{
    this->dir+=u;
}

void Turtle::inainteaza(QPainter &painter, double l, bool dara=true)
{
    double x2=this->x+l*cos(dir);
    double y2=this->y+l*sin(dir);
    if(dara)
        painter.drawLine(this->x, this->y, x2, y2);
    this->x=x2;
    this->y=y2;
}

double Turtle::getDir()
{
    return this->dir;
}
double Turtle::getX()
{
    return this->x;
}
double Turtle::getY()
{
    return this->y;
}

void Turtle::setDir(double d)
{
    this->dir=d;
}
void Turtle::setX(double X)
{
    this->x=X;
}
void Turtle::setY(double Y)
{
    this->y=Y;
}

void Turtle::Cantor(QPainter &painter, double d, int n)
{
    if(!n)
    {
        this->inainteaza(painter, d);
        return;
    }
    d/=3;
    Cantor(painter, d, n-1);
    this->inainteaza(painter, d, false);
    Cantor(painter, d, n-1);

}
void Turtle::Koch(QPainter &painter, double d, int n)
{
    if(!n)
    {
        this->inainteaza(painter, d);
        return;
    }
    d/=3;
    Koch(painter, d, n-1);
    this->rotatie(M_PI/3);
    Koch(painter, d, n-1);
    this->rotatie(-2*M_PI/3);
    Koch(painter, d, n-1);
    this->rotatie(M_PI/3);
    Koch(painter, d, n-1);
}
void Turtle::C(QPainter &painter, double d, int n)
{
    if(!n)
    {
        this->inainteaza(painter, d);
        return;
    }
    d*=sqrt(2)/2;
    this->rotatie(M_PI/4);
    C(painter, d, n-1);
    this->rotatie(-M_PI/2);
    C(painter, d, n-1);
    this->rotatie(M_PI/4);
}
void Turtle::dragon(QPainter &painter, double d, int n, int s)
{
    if(!n)
    {
        this->inainteaza(painter, d);
        return;
    }
    d*=sqrt(2)/2;
    this->rotatie(M_PI/4*s);
    dragon(painter, d, n-1, 1);
    this->rotatie(-M_PI/2*s);
    dragon(painter, d, n-1, -1);
    this->rotatie(M_PI/4*s);
}
