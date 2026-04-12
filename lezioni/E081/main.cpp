#include <iostream>
using namespace std;

class TestA
{
public:

    TestA() : _a(0) {} // Costruttore predefinito

    TestA(int a) : _a(a) {} // Costruttore con parametro intero

    TestA(const TestA& a) : _a(a._a) {

        cout<<"costruttore di copia A con _a che vale: "<<_a<<endl;
    } // Costruttore di copia


private:
    int _a;
};

//classe composta: uno dei suoi attributti un oggetto di classe TestA
class TestB
{
public:
    TestB();
    TestB(TestA p, int n);

private:
    TestA _t;
    const int _c;
};


TestB::TestB() : _t(), _c(0) // Costruttore predefinito
{
    cout<<"Test B creato con _c che vale: "<<_c<<endl;
}


TestB::TestB(TestA p, int n)
    : _t(p), _c(n)
{
    cout<<"Test B creato con _c che vale: "<<_c<<endl;
} // Costruttore con parametro

/*

//ERRORE: in questo caso NON è possible scrivere il costruttore senza la lista 
TestB::TestB(TestA p, int n){
    _t(p); //ERRORE
    _c=n;  //ERRORE
} 
*/


int main()
{
    cout <<"Creo un oggetto di tipo TestA"<<endl;
    TestA ta(25);

    cout <<"Creo un oggetto di tipo TestB"<<endl;
    TestB tb(ta, 8);

    return 0;
}
