#include <wireframe.h>

Wireframe::Wireframe()
{
}

void Wireframe::adaugaVarf(int x, int y, int z)
{
   this->varfuri.append(QVector3D(x, y, z));
}

void Wireframe::adaugaUnire(int x, int y)
{
    this->uniri.append(qMakePair(x, y));
}

void Wireframe::genereazaPuncte2D(int l, int h)
{
    //this->reseteaza();
    double x, y;
    for(int i=0; i<this->varfuri.size(); i++)
    {
        x = l/2 + varfuri[i].x() * this->zp / (this->zp - varfuri[i].z());
        y = h/2 + varfuri[i].y() * this->zp / (this->zp - varfuri[i].z());

        this->puncte.append(qMakePair(x, y));
    }
}

void Wireframe::reseteaza()
{
    this->puncte.clear();
}
