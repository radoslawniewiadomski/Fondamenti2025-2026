#include <iostream>
using namespace std;

//ATTENZIONE IL CODICE NON SI COMPILA!

class Punto
{
    //2 attibuti privati
    double _x;
    double _y;

public:
    //costruttori
    Punto();
    Punto(double x, double y);

    //distruttore
    ~Punto();

    //modificatori
    void setX(double x);
    void setY(double y);

    //selettori
    double getX();
    double getY();

    //altri metodi
    void stampaPunto();
};


//definizione dei metodi
//costruttore "default"
Punto::Punto()
{
    _x = -1;
    _y = -1;
}

//costruttore con dei parametri
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

double Punto::getX()
{
    return _x;
}

double Punto::getY()
{
    return _y;
}

void Punto::stampaPunto()
{
    cout << "Coordinate del punto: (" << _x << ", " << _y << ")" << endl;
}

//distruttore didattico
Punto::~Punto()
{
    cout << "Sono distruttore" << endl;
}


////////////////////////////////////////////////////////////

int main()
{
    Punto p1  (10, 10);
    p1.stampaPunto();

    Punto p2=-p1;//ERRORE: operatore non definito
    p2.stampaPunto();

    return 0;
}
