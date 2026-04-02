#include <iostream>
#include <cstring>

using namespace std;

class Prodotto {
public:
    char nome[20];
    float prezzo;
    int quantita;

    // Costruttore vuoto
    Prodotto() {
        strcpy(nome, "Sconosciuto");
        prezzo = 0;
        quantita = 0;
    }

    // Costruttore con parametri
    Prodotto(const char n[], float p, int q) {
        strcpy(nome, n);
        prezzo = p;
        quantita = q;
    }
};

int main() {
    int n;

    cout << "Quanti prodotti vuoi inserire? ";
    cin >> n;

    // Array dinamico di puntatori
    Prodotto** elenco = new Prodotto*[n];

    for (int i = 0; i < n; i++) {
        char nome[20];
        float prezzo;
        int quantita;

        cout << "\nProdotto " << i + 1 << endl;
        
        cout << "Nome: ";
        cin >> nome;

        cout << "Prezzo: ";
        cin >> prezzo;

        cout << "Quantita: ";
        cin >> quantita;

        elenco[i] = new Prodotto(nome, prezzo, quantita);
    }

    // Stampa
    cout << "\n--- Elenco prodotti ---" << endl;
    for (int i = 0; i < n; i++) {
        cout << elenco[i]->nome
             << " - prezzo: " << elenco[i]->prezzo
             << " - quantita: " << elenco[i]->quantita << endl;
    }

    // Calcolo totale
    float totale = 0;
    for (int i = 0; i < n; i++) {
        totale += elenco[i]->prezzo * elenco[i]->quantita;
    }

    cout << "\nValore totale del magazzino: " << totale << endl;

    // Deallocazione
    for (int i = 0; i < n; i++) {
        delete elenco[i];
    }
    delete[] elenco;

    return 0;
}