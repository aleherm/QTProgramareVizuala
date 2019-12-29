#include "bresenham.h"

void Bresenham::line1(QPainter &painter, double x0, double y0, double x1, double y1)
{
    double dx=x1-x0;
    double dy=y1-y0;
    double sy=1;
    if(dy<0)
    {
        sy=-1;
        dy=-dy;
    }

    double dx2=dx+dx;
    double dy2=dy+dy;

    double delta=dy2-dx;
    double y=y0;

    for(double x=x0; x<=x1; x++)
    {
        painter.drawPoint(x, y);
        if(delta>0)
        {
            y+=sy;
            delta-=dx2;
        }
        delta+=dy2;
    }

}

void Bresenham::line2(QPainter &painter, double x0, double y0, double x1, double y1)
{
    double dx=x1-x0;
    double dy=y1-y0;
    double sx=1;
    if(dx<0)
    {
       sx=-1;
       dx=-dx;
    }
    double dx2=dx+dx;
    double dy2=dy+dy;

    double delta=dx2-dy;
    double x=x0;


    for(double y=y0; y<=y1; y++)
    {
        painter.drawPoint(x, y);
        if(delta>0)
        {
            x+=sx;
            delta-=dy2;
        }
        delta+=dx2;
    }
}

void Bresenham::line(QPainter &painter, double x0, double y0, double x1, double y1)
{
    if(abs(y1-y0)<=abs(x1-x0))
    {
        if(x0<x1)
            line1(painter,x0, y0, x1, y1);
        else
            line1(painter, x1, y1, x0, y0);
    }
    else
        if(y0<y1)
            line2(painter, x0, y0, x1, y1);
        else
            line2(painter, x1, y1, x0, y0);
}

void Bresenham::circle(QPainter &painter, double x0, double y0, double R)
{
    double x=R-1;
    double y=0;
    double dx=1;
    double dy=1;
    double R2=2*R;
    double err=dx-R2;

    while(x>=y)
    {
        painter.drawPoint(x0+x, y0+y);
        painter.drawPoint(x0+x, y0-y);
        painter.drawPoint(x0-x, y0+y);
        painter.drawPoint(x0-x, y0-y);
        painter.drawPoint(x0+y, y0+x);
        painter.drawPoint(x0+y, y0-x);
        painter.drawPoint(x0-y, y0+x);
        painter.drawPoint(x0-y, y0-x);

        if(err<=0)
        {
            y++;
            err+=dy;
            dy+=2;
        }

        if(err>0)
        {
            x--;
            dy+=2;
            err+=dx-R2;
        }
    }
}

/*void Bresenham::floodFill(double x, double y, double cc, double cu) //x, y, culoare contur, culoare umplere
{
    QStack<QPair<double, double>> st;
    st.push(qMakePair(x, y));
    QPair<double, double> point;
    while(!st.empty())
    {
        point=st.top();
        st.pop();
        GetPixel(point.first, point.second, color);
        if(color==cc || color=cu)
            continue;
        PutPixel(point.first, point.second, cu);
        if(point.first>0)
            st.push(qMakePair(point.first-1, point.second));
        if(point.first<width())
            st.push(qMakePair(point.first+1, point.second));
        if(point.second>0)
            st.push(qMakePair(point.first, point.second-1));
        if(point.second<height())
            st.push(qMakePair(point.first, point.second+1));
    }


        /*painter.drawLine(x0+x, y0-y, x0-x, y0-y);
        painter.drawLine(x0+x, y0+y, x0-x, y0+y);
        painter.drawLine(x0+y, y0-x, x0+y, y0+x);
        painter.drawLine(x0-y, y0+x, x0-y, y0-x);*/


