#include <iostream>
using namespace std;

//ATTENZIONE IL CODICE CONTIENE UN ERRORE
//ATTENZIONE IL CODICE SI COMPILA MA SI INTERROMPE

int main()
{

    int* px; // ERRORE: puntatore non inizializzato (comportamento indefinito)

    *px = 1;

    cout<<"Resultati ";

    cout<<"il valore contenuto nella locazione di memoria puntata da px: " << *px <<"\n";

    cout<<"FINE ";

    return 0;
}
