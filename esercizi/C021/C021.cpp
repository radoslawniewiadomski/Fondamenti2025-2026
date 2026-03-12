#include <iostream>
using namespace std;

struct film {
    int id;
    char titolo[50];
    int durata;
    int anno;
};

/*
Scrivere un programma che realizzi una semplice calcolatrice per numeri interi utilizzando puntatori a funzione. Il programma deve definire sei funzioni che eseguono le seguenti operazioni su due numeri interi: somma, differenza, prodotto, massimo e minimo, potenza.
In main():
dichiarare un puntatore a funzione compatibile con le funzioni definite
leggere da tastiera due numeri interi
mostrare all’utente un menu di scelta dell’operazione (somma, differenza, prodotto, massimo, minimo, potenza)
assegnare al puntatore a funzione la funzione corrispondente all’operazione scelta
utilizzare il puntatore a funzione per chiamare l’operazione selezionata e stampare il risultato.

*/

 film* recente (film* pf1,film* pf2){

    film *pfm;
    
    if (pf1->anno>pf2->anno) pfm=pf1;
    else pfm=pf2;

    return pfm;
 }



int main() {

    film *pf1;
    film film1;

    cout << "Inserisci il titolo: ";
    cin >> film1.titolo;
    cout << "Inserisci durata: ";
    cin >> film1.durata;
    cout << "Inserisci anno: ";
    cin >> film1.anno;
    pf1=&film1;

    film *pf2;
    film film2;

    cout << "Inserisci il titolo: ";
    cin >> film2.titolo;
    cout << "Inserisci durata: ";
    cin >> film2.durata;
    cout << "Inserisci anno: ";
    cin >> film2.anno;
    pf2=&film2;

    film *pfm = recente (pf1,pf2);
    
    cout << "Titolo del film piu recente : " << pfm->titolo << endl;
   

    return 0;
}



/*

// restituisce il triplo
int triplo(int x){
    return 3 * x;
}

// restituisce il quadrato
int quadrato(int x){
    return x * x;
}

// restituisce il numero successivo
int successivo(int x){
    return x + 1;
}

// applica la funzione f a tutti gli elementi dell'array
void applica(int v[], int n, int (*f)(int)){
    for(int i = 0; i < n; i++){
        v[i] = f(v[i]);
    }
}

// funzione per stampare l'array
void stampa(int v[], int n){
    for(int i = 0; i < n; i++){
        cout << v[i] << " ";
    }
    cout << endl;
}

int main(){

    const int N = 5;
    int x[N];

    cout << "Inserisci " << N << " numeri: ";
    for(int i = 0; i < N; i++)
        cin >> x[i];

    applica(x, N, triplo);
    cout << "Triplo: ";
    stampa(x, N);

    applica(x, N, quadrato);
    cout << "Quadrato: ";
    stampa(x, N);

    applica(x, N, successivo);
    cout << "Successivo: ";
    stampa(x, N);

    return 0;
}

*/