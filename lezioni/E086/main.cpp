#include <iostream>
using namespace std;

class Punto
{
public:
    double _x;
    double _y;
    void riscala(double f);
};

void Punto::riscala(double f)
{
    _x *= f;
    _y *= f;
}

int main() {
    Punto p;

    p._x = 100;
    p._y = 200;
    
    cout<<"Stampo gli attributi del punto p: ";
    cout<<p._x<<"; ";
    cout<<p._y<<endl;

    p.riscala(0.5);

    cout<<"Stampo gli attributi del punto p dopo riscalare: ";
    cout<<p._x<<"; ";
    cout<<p._y;
    
    return 0;
}
