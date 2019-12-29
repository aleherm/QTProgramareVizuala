#include <QVector>
#include <QPair>
#include <QVector3D>

class Wireframe
{
public:
    QVector<QVector3D> varfuri;
    QVector<QPair<int, int>> uniri;

    const int zp=1000;

    void reseteaza();

//public:
    QVector<QPair<double, double>> puncte;

    Wireframe();
    void adaugaVarf(int x, int y, int z);
    void adaugaUnire(int x, int y);
    void genereazaPuncte2D(int l, int h);
};
