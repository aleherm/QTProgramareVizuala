#ifndef BRESENHAM_H
#define BRESENHAM_H

#endif // BRESENHAM_H

#include <QPainter>
#include <QStack>
#include <QPair>
#include <math.h>

class Bresenham
{

private:
    void line1(QPainter &painter, double x0, double y0, double x1, double y1);
    void line2(QPainter &painter, double x0, double y0, double x1, double y1);
public:
    void line(QPainter &painter, double x0, double y0, double x1, double y1);
    void circle(QPainter &painter, double x0, double y0, double R);
    void floodFill(double x, double y, double cc, double cu);
};
