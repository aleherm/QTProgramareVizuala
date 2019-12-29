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


void Turtle::plantaOptional(QPainter &painter, double d, int n)
{
    if(!n)
        return;
    this->inainteaza(painter, d);
    double x0=x, y0=y, dir0=dir;
    double l;
    double u;

    this->rotatie(M_PI/6);

    this->random.setInterval(1/2, 2/3);
    l=this->random.getRandom();
    planta(painter, d*l, n-1);
    this->x=x0;
    this->y=y0;
    this->dir=dir0;

    this->rotatie(-M_PI/6);

    this->random.setInterval(1/2, 2/3);
    l=this->random.getRandom();
    planta(painter, d*l, n-1);
}

void Turtle::planta(QPainter &painter, double d, int n)
{
    if(!n)
        return;
    this->inainteaza(painter, d);
    double x0=x, y0=y, dir0=dir;
    this->rotatie(M_PI/6);
    planta(painter, d*2/3, n-1);
    this->x=x0;
    this->y=y0;
    this->dir=dir0;
    this->rotatie(-M_PI/6);
    planta(painter, d*2/3, n-1);
}

void Turtle::covorSierpinski(QPainter &painter, double x, double y, double d, int n)
{
    if(!n)
        return;
    d/=3;
    painter.drawRect(x+d, y+d, d, d);

    covorSierpinski(painter, x, y, d, n-1);
    covorSierpinski(painter, x+d, y, d, n-1);
    covorSierpinski(painter, x+2*d, y, d, n-1);

    covorSierpinski(painter, x, y+d, d, n-1);
    covorSierpinski(painter, x+d, y+d, d, n-1);
    covorSierpinski(painter, x+2*d, y+d, d, n-1);

    covorSierpinski(painter, x, y+2*d, d, n-1);
    covorSierpinski(painter, x+d, y+2*d, d, n-1);
    covorSierpinski(painter, x+2*d, y+2*d, d, n-1);
}


void Turtle::triunghiSierpinski(QPainter &painter, double x, double y, double d, int n)
{
    if (n == 0) return;

    //compute triangle points
    double x0 = x;
    double y0 = y;
    double x1 = x0+d;
    double y1 = y0;
    double x2 = x0+d/2;
    double y2 = y0+(sqrt(3))*d/2;

    // draw the triangle
    painter.drawLine(x0, y0, x1, y1);
    painter.drawLine(x0, y0, x2, y2);
    painter.drawLine(x1, y1, x2, y2);

    //recursive calls
    triunghiSierpinski(painter, x0, y0, d/2, n-1);
    triunghiSierpinski(painter, (x0+x1)/2, (y0+y1)/2, d/2, n-1);
    triunghiSierpinski(painter, (x0+x2)/2, (y0+y2)/2, d/2, n-1);
}

void Turtle::covorSierpinskiDreptunghi(QPainter &painter, double x, double y, double L, double l, int n)
{
    if(!n)
        return;
    L/=3;
    l/=3;
    painter.drawRect(x+L, y+l, L, l);

    covorSierpinskiDreptunghi(painter, x, y, L, l, n-1);
    covorSierpinskiDreptunghi(painter, x+L, y, L, l, n-1);
    covorSierpinskiDreptunghi(painter, x+2*L, y, L, l, n-1);

    covorSierpinskiDreptunghi(painter, x, y+l, L, l, n-1);
    covorSierpinskiDreptunghi(painter, x+L, y+l, L, l, n-1);
    covorSierpinskiDreptunghi(painter, x+2*L, y+l, L, l, n-1);

    covorSierpinskiDreptunghi(painter, x, y+2*l, L, l, n-1);
    covorSierpinskiDreptunghi(painter, x+L, y+2*l, L, l, n-1);
    covorSierpinskiDreptunghi(painter, x+2*L, y+2*l, L, l, n-1);
}

void Turtle::Mandelbrot(QPainter &painter, int rows, int columns)
{
    int nMax=50;
    int s=2;
    QVector<QColor> culori;

    for(int i=0; i<10; i++)
        culori.push_back(Qt::darkBlue);
    for(int i=0; i<10; i++)
        culori.push_back(Qt::blue);
    for(int i=0; i<10; i++)
        culori.push_back(Qt::darkCyan);
    for(int i=0; i<10; i++)
        culori.push_back(Qt::darkGreen);
    for(int i=0; i<10; i++)
        culori.push_back(Qt::black);

    for(auto row=0; row<rows; row++)
    {
        for(auto column=0; column<columns; column++)
        {
            std::complex<float> z, c =
            {
                (float)row*2/rows-1.5f,
                (float)column*2/columns-1
            };
            int i=0;
            while(sqrt(z.real()*z.real() + z.imag() * z.imag()) <s && ++i<nMax)
                z = z * z + z + c;
            if(i==nMax)
            {
                painter.setPen(culori[i-1]);
                painter.drawPoint(row, column);
            }
            else
                {
                    painter.setPen(culori[i]);
                    painter.drawPoint(row, column);
                }
        }
    }
}

