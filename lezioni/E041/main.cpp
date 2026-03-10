#include <iostream>  
using namespace std;  

struct film
{
    int id;        // identificatore del film
    char* titolo;  // puntatore a char: servirà per memorizzare il titolo del film (allocato dinamicamente)
    int durata;    // durata del film in minuti
    int anno;      // anno di produzione del film
};

int main()
{
    film* p = new film;   // allocazione dinamica di una struttura film
                          // p è un puntatore che contiene l'indirizzo della struttura

    int n;
    cout << "Quanto e' lungo il titolo del film?" ;
    cin >> n;   

    p->titolo = new char[n+1];   // allocazione dinamica di un array di caratteri
                               // servirà per memorizzare il titolo

    cout << "Inserisci il titolo: "  << "? ";
    cin >>  p->titolo;   // legge il titolo e lo salva nell'array di caratteri

    cout << "Inserisci durata (in minuti):  ";
    cin >> p->durata;    // inserimento della durata del film

    cout << "Inserisci l'anno di produzione:  ";
    cin >> p->anno;      // inserimento dell'anno di produzione

    cout << "Titolo: " << p->titolo << endl;  // stampa il titolo del film

    delete [] p->titolo;   // libera la memoria allocata per il titolo
    delete p;              // libera la memoria allocata per la struttura film

    return 0;             
}
