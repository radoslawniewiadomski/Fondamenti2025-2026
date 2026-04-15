#include <iostream>
#include <cstring>

using namespace std;

class Studente {
private:
    char* nome;
    int numCorsi;
    int* voti;

public:
    // Costruttore di default
    Studente() : nome(nullptr), numCorsi(0), voti(nullptr) {}

    // Costruttore parametrico
    Studente(const char* n, int num, const int* v) : nome(nullptr), numCorsi(num), voti(nullptr) {

        if (n != nullptr) {
            nome = new char[strlen(n) + 1];
            strcpy(nome, n);
        } else {
            nome = nullptr;
        }

        setVoti(v,num);
    }

    // Distruttore
    ~Studente() {
        delete[] nome;
        delete[] voti;
    }

    // Setter nome
    void setNome(const char* n) {
        delete[] nome;

        if (n != nullptr) {
            nome = new char[strlen(n) + 1];
            strcpy(nome, n);
        } else {
            nome = nullptr;
        }
    }

 void setVoti(const int* v, int n) {
    delete[] voti;
    voti = nullptr;

    numCorsi = n;

    if (v != nullptr && numCorsi > 0) {
        voti = new int[numCorsi];
        for (int i = 0; i < numCorsi; i++) {
            voti[i] = v[i];
        }
    }
}

    // Getter
    const char* getNome() const {
        return nome;
    }

    int getNumCorsi() const {
        return numCorsi;
    }

    int* getVoti() const {
        return voti;
    }

    // Calcolo media
    float calcolaMedia() const {
        if (numCorsi == 0) {
            return 0;
        }

        int somma = 0;
        for (int i = 0; i < numCorsi; i++) {
            somma += voti[i];
        }

        return (float)somma / numCorsi;
    }

    // Stampa dati
    void stampa() const {
        cout << "Nome studente: " << (nome != nullptr ? nome : "Nessun nome") << endl;
        cout << "Numero corsi: " << numCorsi << endl;
        cout << "Voti: ";

        for (int i = 0; i < numCorsi; i++) {
            cout << voti[i] << " ";
        }

        cout << endl;
    }
};

int main() {
    char buffer[100];
    int numCorsi;

    cout << "Inserisci nome e cognome dello studente: ";
    cin.getline(buffer, 100);

    cout << "Inserisci il numero di corsi: ";
    cin >> numCorsi;

    int* voti = nullptr;

    if (numCorsi > 0) {
        voti = new int[numCorsi];

        for (int i = 0; i < numCorsi; i++) {
            cout << "Inserisci il voto del corso " << i + 1 << ": ";
            cin >> voti[i];
        }
    }

    Studente s(buffer, numCorsi, voti);

    cout << "\n--- DATI STUDENTE ---" << endl;
    s.stampa();

    cout << "Media voti: " << s.calcolaMedia() << endl;

    delete[] voti;

    return 0;
}