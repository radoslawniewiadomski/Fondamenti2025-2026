#include <iostream>
using namespace std;


//Si scriva la funzione C++ massimo che riceva come parametri i puntatori a tre numeri interi a, b e c e restituisca come valore di ritorno il puntatore al pi� grande dei tre numeri (un puntatore a numero intero).
//Nel caso in cui vi siano due numeri uguali, entrambi pi� grandi del terzo numero, la funzione restituisce il puntatore al primo dei due.
//Si scriva quindi un programma C++ per verificare il corretto funzionamento della funzione.
//Il programma chieder� all�utente di immettere da tastiera tre numeri interi, chiamer� la funzione massimo e stamper� a video il valore puntato dal puntatore che la funzione restituisce come valore di ritorno.


// Funzione per trovare il puntatore al massimo tra tre numeri
int* massimo(int* a, int* b, int* c) {
    if (*a >= *b && *a >= *c) {
        return a;
    } else if (*b >= *a && *b >= *c) {
        return b;
    } else {
        return c;
    }
}

int main() {
    int num1, num2, num3;

    // Input dei tre numeri interi
    cout << "Inserisci tre numeri interi:" << endl;
    cout << "Numero 1: ";
    cin >> num1;
    cout << "Numero 2: ";
    cin >> num2;
    cout << "Numero 3: ";
    cin >> num3;

    // Chiamata alla funzione massimo
    int* max_ptr = massimo(&num1, &num2, &num3);

    // Stampa il valore puntato dal puntatore restituito dalla funzione
    cout << "Il numero massimo tra " << num1 << ", " << num2 << " e " << num3 << " e: " << *max_ptr << endl;

    return 0;
}
