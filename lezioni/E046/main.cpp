#include <iostream>
using namespace std;

//ERRORE: ATTENZIONE QUESTO CODICE CONTIENE UN ERRORE -  S - non e possibile di dedurre il tipo specifico per il tipo generico S
template <typename W, typename S>
S f2 (W x)
{
    int z = x/2;
    return z;
}

int main()
{
    double d1=3.9;
     
     cout << f2(d1) << endl; // ERRORE!!!
    //int d2 = f2(d1) ;    // ERRORE!!!
     
    return 0;
}
