#include <QVector>
#include <QPair>
#include <QVector3D>

class Wireframe
{
public:
    QVector<QVector3D> varfuri;
    QVector<QPair<int, int>> uniri;
    QVector<QPair<double, double>> puncte;

    const int zp=2000;

    Wireframe();
    void reseteaza();
    void adaugaVarf(int x, int y, int z);
    void adaugaUnire(int x, int y);

    void setVarfuri(QVector<QVector3D> newVarfuri);
    QVector<QVector3D> getVarfuri();
    void setUniri(QVector<QPair<int, int>> uniri);
    QVector<QPair<int, int>> getUniri();

    void genereazaPuncte2D(int l, int h);
    QVector3D centruGreutate();
};
