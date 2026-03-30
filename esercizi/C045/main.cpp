#include <iostream>
using namespace std;


// STRUCT
struct Persona {
    char nome[50];
    char cognome[50];
};

struct Studente {
    char nome[50];
    char cognome[50];
    int matricola;
};

struct Lavoratore {
    char nome[50];
    char cognome[50];
    double stipendio;
};

// TEMPLATE
template <typename T>
void inserisciDati(T &p) {
    cout << "Inserisci nome: ";
    cin >> p.nome;

    cout << "Inserisci cognome: ";
    cin >> p.cognome;
}

int main() {
    Persona p;
    Studente s;
    Lavoratore l;

    cout << "--- Persona ---" << endl;
    inserisciDati(p);

    cout << "--- Studente ---" << endl;
    inserisciDati(s);

    cout << "--- Lavoratore ---" << endl;
    inserisciDati(l);

    return 0;
}