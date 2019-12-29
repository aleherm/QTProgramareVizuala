#include <QVector>
#include <QPair>
#include <QVector3D>

class Wireframe
{
public:
    QVector<QVector3D> varfuri;
    QVector<QPair<int, int>> uniri;
    QVector<QPair<double, double>> puncte;

    const int zp=1000;

    Wireframe();
    void reseteaza();

    void setVarfuri(QVector<QVector3D> newVarfuri);
    QVector<QVector3D> getVarfuri();

    void genereazaPuncte2D(int l, int h);
};
