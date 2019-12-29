#include <wireframe.h>

Wireframe::Wireframe()
{
}
void Wireframe::setVarfuri(QVector<QVector3D> newVarfuri)
{
    this->varfuri=newVarfuri;
}

QVector<QVector3D> Wireframe::getVarfuri()
{
    return this->varfuri;
}

void Wireframe::genereazaPuncte2D(int l, int h)
{
    double x, y;
    for(int i=0; i<this->varfuri.size(); i++)
    {
        x = l/2 - varfuri[i].x() * this->zp / (this->zp - varfuri[i].z());
        y = h/2 + varfuri[i].y() * this->zp / (this->zp - varfuri[i].z());

        this->puncte.append(qMakePair(x, y));
    }
}

void Wireframe::reseteaza()
{
    this->puncte.clear();
}
