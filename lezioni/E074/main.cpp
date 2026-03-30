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

int main()
{
    Punto p;

    Punto * pp = &p;
    pp->_x = 100;
    pp->_y = 200;
    
    cout << " Il valore di pp->_x prima di chiamare riscala: " << pp->_x << endl; 

    pp->riscala(0.5);

    cout << " Il valore di pp->_x dopo di chiamare riscala: " << pp->_x; 

    return 0;
}
