#include "bezier.h"

double Bezier::xBezier(double t, QVector<double> x)
{
    double sum=0;
    int n=x.size()-1;
    for(int i=0; i<=n; i++)
        sum+=x[i]*Bernstein(t, i, n);
    return sum;
}

double Bezier::yBezier(double t, QVector<double> y)
{
    double sum=0;
    int n=y.size()-1;
    for(int i=0; i<=n; i++)
        sum+=y[i]*Bernstein(t, i, n);
    return sum;
}

int Bezier::factorial(int nr)
{
    int p=1;
    for(int i=2; i<=nr; i++)
        p*=i;
    return p;
}
double Bezier::combinari(int n, int k)
{
    return factorial(n)/(factorial(k)*factorial(n-k));
}

double Bezier::Bernstein(double t, int i, int n)
{
    return combinari(n, i)*pow(t, i)*pow(1-t, n-i);
}
