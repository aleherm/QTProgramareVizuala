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

void Wireframe::setVarfuri(QVector<QVector3D> newVarfuri)
{
    this->varfuri=newVarfuri;
}

QVector<QVector3D> Wireframe::getVarfuri()
{
    return this->varfuri;
}

void Wireframe::setUniri(QVector<QPair<int, int>> uniri)
{
    this->uniri=uniri;
}
QVector<QPair<int, int>> Wireframe::getUniri()
{
    return this->uniri;
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

QVector3D Wireframe::centruGreutate()
{
    double centruX=0, centruY=0, centruZ=0;

    for(int i=0; i<this->varfuri.size(); i++)
    {
        centruX+=this->varfuri[i].x();
        centruY+=this->varfuri[i].y();
        centruZ+=this->varfuri[i].z();
    }

    centruX=(double)centruX/this->varfuri.size();
    centruY=(double)centruY/this->varfuri.size();
    centruZ=(double)centruZ/this->varfuri.size();

    QVector3D punctCentru(centruX, centruY, centruZ);

    return punctCentru;
}

void Wireframe::reseteaza()
{
    this->puncte.clear();
}
