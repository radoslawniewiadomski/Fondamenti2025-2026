#include <iostream>
using namespace std;

class Punto
{

public:
    // Costruttori
    Punto() : _x(0), _y(0) {}
    Punto(double x, double y) : _x(x), _y(y) {}

    // Metodo per riscala
    void riscala(double f)
    {
        _x *= f;
        _y *= f;
    }

    void stampa() const
    {
        cout << "(" << _x << ", " << _y << ")" << endl;
    }

    Punto& setX(double x)
    {
        _x = x;
        return *this;
    }

    Punto& setY(double y)
    {
        _y = y;
        return *this;
    }

private:
    double _x;
    double _y;
};


int main()
{
    Punto p;
    p.setX(4.0).setY(3.5);
    p.stampa();
    return 0;
}
