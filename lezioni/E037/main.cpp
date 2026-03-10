#include <iostream>    
using namespace std;  

int main()
{
    int n;   // Variabile che conterrà il numero di elementi dell'array

    // Chiede all'utente quanti elementi vuole nell'array
    cout << "Inserire il numero di elementi: ";
    cin >> n;

    // Controllo: se il numero inserito è <= 0 il programma termina con errore
    if (n <= 0) return -1;

    // Allocazione dinamica di un array di n interi nell'HEAP
    int* a = new int[n];

    if (a == 0) return -1;

    // Riempie l'array 
    for (int i = 0; i < n; i++)
        a[i] = i + 1;

    // Stampa tutti gli elementi tranne l'ultimo
    // serve per evitare la virgola finale
    for (int j = 0; j < n - 1; j++)
        cout << a[j] << ", ";

    // Stampa l'ultimo elemento senza virgola
    cout << a[n - 1] << endl;

    // Libera la memoria allocata dinamicamente nell'heap
    delete [] a;

    return 0;   
}