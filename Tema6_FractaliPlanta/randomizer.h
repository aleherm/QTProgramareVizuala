#include <time.h>
#include <qrandom.h>

class Randomizer
{
public:
    double a, b;
    Randomizer()
    {
        //qsrand(QTime::currentTime().msec());
        srand(time(NULL));
    }
    void setInterval(double A, double B)
    {
        this->a=A;
        this->b=B;
    }

    double getRandom()
    {
        //double f = (double)rand() / RAND_MAX;
        //return this-> a + f * (this->b - this->a);

        //return rand() % ((this->b - this->a) + 1) + this->a;

        /*QRandomGenerator rand;
        rand.bounded(this->a, this->b);
        double ceva = rand.generate();
        return ceva;*/
    }
};
