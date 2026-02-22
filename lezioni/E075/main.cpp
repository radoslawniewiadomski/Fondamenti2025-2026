#include <iostream>
using namespace std;

//Attenzione!! QUESTO codice contiene un errore
class Punto {
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
     Punto *pp; //ERRORE!!! manca allocazione di memoria!!!
     pp->_x = 100;
     pp->_y = 200;
     pp->riscala(0.5);
     cout<<pp->_x;

     return 0;
}
