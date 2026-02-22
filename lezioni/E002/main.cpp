#include <iostream>
using namespace std;

//ATTENZIONE: IL CODICE CONTIENE UN ERRORE
//ATTENZIONE: IL CODICE NON SI COMPILA

int main()
{
    int x = 1;

    int& y; //ERRORE: riferimento non inizializzato!!

    x++;
    
    cout << x << endl;

    return 0;
}
