#include <iostream>
using namespace std;

// funzione che restituisce la somma di due numeri
double somma(double x, double y){
  return x + y;
}

// funzione che restituisce la differenza tra due numeri
double differenza(double x, double y){
  return x - y;
}

int main()
{
    // dichiarazione di un puntatore a funzione
    // pf può puntare a una funzione che riceve due double e restituisce un double
    double (*pf) (double, double);

    // inizialmente il puntatore viene fatto puntare alla funzione somma
    pf = somma;

    // dichiarazione delle due variabili che verranno lette da input
    double a, b;

    // lettura dei due numeri da tastiera
    cin >> a >> b;

    // se il primo numero è maggiore del secondo
    if (a > b)
        // il puntatore pf punta alla funzione somma
        pf = somma;
    else
        // altrimenti il puntatore pf punta alla funzione differenza
        pf = differenza;

    // viene chiamata la funzione a cui punta pf
    // passando a e b come parametri e stampando il risultato
    cout << (*pf)(a, b);

    return 0;
}