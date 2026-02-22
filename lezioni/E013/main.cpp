#include <iostream>
using namespace std;

//ATTENZIONE: IL CODICE CONTIENE UN ERRORE
//ATTENZIONE: IL CODICE NON SI COMPILA

int main(){

    int a = 3;

    int* p1 = &a;
    
    int** p2 = &p1;

    cout << p1 <<", "<< p2 << endl;

    cout << *p1 <<", "<< *p2<< endl;
    
    p2=p1;      //ERRORE: non è consentita l’assegnazione di un int* a una variabile di tipo int**

    return 0;

}
