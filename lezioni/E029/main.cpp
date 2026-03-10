#include <iostream>
using namespace std;

// funzione che calcola la media di due numeri interi
double media (int a, int b)
{
    // la divisione per 2.0 serve per ottenere un risultato double
    return (a + b) / 2.0;
}

int main()
{
    // dichiarazione di un puntatore a funzione
    // pf può puntare a una funzione che riceve due int e restituisce un double
    double (*pf)(int, int);

    // inizializzazione del puntatore: pf ora punta alla funzione media
    pf = media;

    // dichiarazione delle variabili che conterranno i numeri inseriti dall'utente
    int x, y;

    // richiesta dei due numeri all'utente
    cout << "Inserire due numeri: ";

    // lettura dei valori da tastiera
    cin >> x >> y;

    // chiamata della funzione puntata da pf
    // vengono passati i valori x e y e il risultato viene salvato in m
    double m = (*pf)(x, y);

    // stampa del risultato della media
    cout << "Media = " << m << endl;

    return 0;
}