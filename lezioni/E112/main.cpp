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

    // operatori
    Punto& operator=(const Punto& p);

    // modificatori
    void setX(double x);
    void setY(double y);

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

void Punto::stampaPunto() const
{
    cout << "Coordinate del punto: (" << _x << ", " << _y << ")" << endl;
}

// distruttore
Punto::~Punto()
{
    cout << "Questo e' il distruttore" << endl;
}

// operatore di assegnazione
Punto& Punto::operator=(const Punto& p)
{
    if (this != &p)   // evita l'autoassegnamento
    {
        _x = p._x;
        _y = p._y;
    }
    return *this;
}

int main()
{
    Punto punto1(3.5, 4.2);
    Punto punto2(1.8, 2.4);

    cout << "Coordinate del primo punto: ";
    punto1.stampaPunto();

    cout << "Coordinate del secondo punto: ";
    punto2.stampaPunto();

    cout << "\nTest dell'operatore di assegnamento:\n";
    punto1 = punto2;

    cout << "Dopo l'assegnamento, coordinate del primo punto: ";
    punto1.stampaPunto();

    return 0;
}