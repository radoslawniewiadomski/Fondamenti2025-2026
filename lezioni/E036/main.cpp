#include <iostream>   
using namespace std;  

// Definizione della struttura "film"
struct film {
    int id;           // Identificatore del film
    char titolo[50];  // Titolo del film (stringa di massimo 50 caratteri)
    int durata;       // Durata del film in minuti
    int anno;         // Anno di produzione
};

int main() {

    // Array di puntatori a strutture film (può contenere 2 film)
    film* elencoFilm[2];

    // ===== PRIMO FILM =====
    film film1;  // Creazione della prima variabile di tipo film

    cout << "Inserisci il titolo del primo film: ";
    cin >> film1.titolo;   // Inserimento titolo

    cout << "Inserisci durata (in minutes): ";
    cin >> film1.durata;   // Inserimento durata

    cout << "Inserisci anno di produzione: ";
    cin >> film1.anno;     // Inserimento anno

    film1.id = 0;          // Assegnazione ID al primo film

    // Salvo l'indirizzo di film1 nell'array di puntatori
    elencoFilm[0] = &film1;


    // ===== SECONDO FILM =====
    film film2;  // Creazione della seconda variabile di tipo film

    cout << "Inserisci il titolo del secondo film: ";
    cin >> film2.titolo;

    cout << "Inserisci durata (in minutes): ";
    cin >> film2.durata;

    cout << "Inserisci anno di produzione: ";
    cin >> film2.anno;

    film2.id = 2;   // Assegnazione ID al secondo film

    // Salvo l'indirizzo di film2 nell'array
    elencoFilm[1] = &film2;


    // ===== STAMPA DEI FILM =====
    // Ciclo che stampa i dati dei film salvati nell'array
    for (int i = 0; i < 2; ++i) {

        // -> serve per accedere ai campi della struttura tramite puntatore
        cout << "Film " << i + 1 << ": "
             << elencoFilm[i]->titolo
             << ", durata: "
             << elencoFilm[i]->durata
             << " minuti. "
             << endl;
    }

    return 0; 
}