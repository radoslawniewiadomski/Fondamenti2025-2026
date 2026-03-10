#include <iostream>
using namespace std;

// funzione che restituisce l'inverso di un numero intero
// esempio: se a = 2 restituisce 1/2 = 0.5
double inverso (int a)
{
    return 1.0 / a;
}

// funzione che restituisce il quadrato di un numero intero
// esempio: se a = 3 restituisce 9
double quadrato (int a)
{
    return double(a * a);
}

// funzione che calcola la somma dei valori restituiti da una funzione passata come parametro
// f = puntatore a funzione che riceve un int e restituisce un double
double somma(int n, double (*f)(int))
{
    double s = 0.0;  // variabile che conterrà la somma totale

    for (int i = 1; i <= n; i++)
        // viene chiamata la funzione puntata da f
        // passando i come parametro
        // il valore restituito viene aggiunto alla somma
        s += (*f)(i);

    return s;
}

int main()
{
    // chiama la funzione somma passando: n = 5 e la funzione inverso
    // quindi calcola: 1/1 + 1/2 + 1/3 + 1/4 + 1/5
    cout << somma(5, inverso) << endl;

    // chiama la funzione somma passando: n = 5 e la funzione quadrato
    // quindi calcola: 1^2 + 2^2 + 3^2 + 4^2 + 5^2
    cout << somma(5, quadrato) << endl;

    return 0;
}

//Alternativa: senza usare un puntatore a funzione

/*
double somma_inverso (int n)
{
    double s = 0.0;
    for (int i = 1; i <= n; i++)
        s += 1.0 /(i);
    return s;
}
double somma_quadrato (int n)
{
    double s = 0.0;
    for (int i = 1; i <= n; i++)
        s+= i*i;
    return s;
}

int main()
{
    cout<<somma_inverso(5)<< endl;
    cout<<somma_quadrato(5)<< endl;
    return 0;
}
 */
