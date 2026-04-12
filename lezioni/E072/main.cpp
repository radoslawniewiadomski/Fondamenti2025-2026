#include <iostream>
using namespace std;

//ATTENZIONE: QUESTO CODICE CONTIENE UN ERRORE E NON SI COMPILA!

class Punto
{
    void test(int n);

    
public:
    double _x;
    double _y;
   
    void riscala(double f);
  
};

void Punto::riscala(double f)
{
    _x*=f;

}

void Punto::test(int f){

}

int main()
    {
        Punto p;
        p._x = 100;	// OK
        p._y = 200;	// OK
        p.riscala(2.0);	// OK
        p.test(3);		// ERRORE! test � membro privato!
        cout << p._x;
        return 0;
    }
