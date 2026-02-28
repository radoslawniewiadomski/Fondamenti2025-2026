#include <iostream>
using namespace std;

int main() {
   int a = 1;
   int b = 2;
   int c = 3;

   int* p [3];

    p[0] =&a;
    p[1] =&b;
    p[2] =&c;

    cout<<p<<endl; // stampa un indirizzo
    cout<<*p<<endl; // stampa un'altro indirizzo
    cout<<**p<<endl; // stampa un valore

}
