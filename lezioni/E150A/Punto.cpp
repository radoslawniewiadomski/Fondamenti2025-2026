#include <iostream>
#include "Punto.h"

using namespace std;


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

double Punto::getX() const
{
    return _x;
}

double Punto::getY() const
{
    return _y;
}

//distruttore che non fa niente utile
Punto::~Punto()
{
    cout << "Questo e' il distruttore" << endl;
}
