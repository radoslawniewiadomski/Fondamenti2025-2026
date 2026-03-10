#include <iostream>
using namespace std;

// funzione che restituisce la somma di due numeri
double somma(double x, double y)
{
    return x + y;
}

// funzione che restituisce la differenza
double differenza (double x, double y)
{
    return x - y;
}

// funzione che restituisce il prodotto
double prodotto (double x, double y)
{
    return x * y;
}

// funzione che restituisce il rapporto (divisione)
// se il secondo numero è 0 evita la divisione e restituisce 0
double rapporto (double x, double y)
{
    if (y != 0.0)
        return x / y;
    else
        return 0.0;
}

int main()
{
    // semplice calcolatrice con puntatori a funzione

    const int dim = 4;

    // array con i simboli delle operazioni
    char operatori[dim] = {'+', '-', '*', '/'};

    // array di puntatori a funzione
    // ogni elemento punta a una funzione che prende due double
    // e restituisce un double
    double (*pf[dim])(double, double) = {somma, differenza, prodotto, rapporto};

    double op1, op2, res;
    char op;

    // spiegazione per l'utente
    cout << "Inserisci un'operazione nel formato: numero operatore numero" << endl;
    cout << "Esempio: 5 + 3" << endl;
    cout << "Operatori disponibili: +  -  *  /" << endl;

    // lettura dei dati
    cin >> op1 >> op >> op2;

    // ricerca dell'operatore nell'array operatori
    for (int i = 0; i < dim; i++)
        if (op == operatori[i])
            // chiamata della funzione tramite puntatore
            res = (*pf[i])(op1, op2);

    // stampa del risultato
    cout << op1 << " " << op << " " << op2 << " = " << res << endl;

    return 0;
}
