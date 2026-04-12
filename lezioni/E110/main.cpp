#include <iostream>
using namespace std;

class Punto
{
private:
    // 2 attributi privati
    double _x;
    double _y;

public:
    // costruttori
    Punto();
    Punto(double x, double y);

    // distruttore
    ~Punto();

    // modificatori
    void setX(double x);
    void setY(double y);

    // operatori
    Punto operator+(const Punto& p) const;

    // selettori
    double getX() const;
    double getY() const;

    // altri metodi
    void stampaPunto() const;
};

// definizione dei metodi

// costruttore di default
Punto::Punto()
{
    _x = -1;
    _y = -1;
}

// costruttore con parametri
Punto::Punto(double x, double y)
{
    _x = x;
    _y = y;
}

void Punto::setX(double x)
{
    _x = x;
}

void Punto::setY(double y)
{
    _y = y;
}

double Punto::getX() const
{
    return _x;
}

double Punto::getY() const
{
    return _y;
}

Punto Punto::operator+(const Punto& p) const
{
    Punto q(_x + p._x, _y + p._y);
    return q;
}

void Punto::stampaPunto() const
{
    cout << "Coordinate del punto: (" << _x << ", " << _y << ")" << endl;
}

// distruttore
Punto::~Punto()
{
    cout << "Questo e' il distruttore" << endl;
}

int main()
{
    Punto p(5.0, 2.0);
    Punto q(4.0, 1.0);
    Punto r = p + q;

    r.stampaPunto();

    return 0;
}