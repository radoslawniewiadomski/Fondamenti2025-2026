#include <iostream>
using namespace std;

// definizione delle funzioni

int somma(int a, int b){
    return a + b;
}

int differenza(int a, int b){
    return a - b;
}

int prodotto(int a, int b){
    return a * b;
}

int massimo(int a, int b){
    if(a > b)
        return a;
    else
        return b;
}

int minimo(int a, int b){
    if(a < b)
        return a;
    else
        return b;
}

int potenza(int a, int b){
    int risultato = 1;
    for(int i = 0; i < b; i++)
        risultato *= a;
    return risultato;
}

int main(){

    int (*pf)(int,int);   // puntatore a funzione

    int x, y;
    int scelta;

    cout << "Inserisci due numeri interi: ";
    cin >> x >> y;

    cout << "\nScegli operazione:" << endl;
    cout << "1 - Somma" << endl;
    cout << "2 - Differenza" << endl;
    cout << "3 - Prodotto" << endl;
    cout << "4 - Massimo" << endl;
    cout << "5 - Minimo" << endl;
    cout << "6 - Potenza (x^y)" << endl;

    cin >> scelta;

    // assegnazione funzione al puntatore
    if(scelta == 1)
        pf = somma;
    else if(scelta == 2)
        pf = differenza;
    else if(scelta == 3)
        pf = prodotto;
    else if(scelta == 4)
        pf = massimo;
    else if(scelta == 5)
        pf = minimo;
    else if(scelta == 6)
        pf = potenza;
    else{
        cout << "Operazione non valida." << endl;
        return 0;
    }

    // chiamata della funzione tramite puntatore
    cout << "Risultato: " << pf(x,y) << endl;

    return 0;
}