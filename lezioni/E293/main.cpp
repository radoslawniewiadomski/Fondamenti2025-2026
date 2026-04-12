#include <iostream>
using namespace std;

//ATTENZIONE IL CODICE NON SI COMPILA!

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

private:
    double _x;
    double _y;
};


int main()
{
    Punto p1;
    Punto p2;

    //cout <<  p1 + p2; //ERRORE: operatore non definito per la classe Punto
    Punto p3=p1+p2; //ERRORE: operatore non definito per la classe Punto

    return 0;
}
