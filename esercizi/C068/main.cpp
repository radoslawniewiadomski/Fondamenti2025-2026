#include <iostream>
#include <cstring>

using namespace std;

class Corso {
private:
    char* nome;
    int voto;

public:
    Corso() : nome(nullptr), voto(18) {}

    Corso(const char* n, int v) : nome(nullptr), voto(v) {
        nome = nullptr;
        if (n) {
            nome = new char[strlen(n) + 1];
            strcpy(nome, n);
        }

    }

    Corso(const Corso& altro) : nome(nullptr), voto(altro.voto) {
        if (altro.nome) {
            nome = new char[strlen(altro.nome) + 1];
            strcpy(nome, altro.nome);
        }

    }

    ~Corso() {
        delete[] nome;
    }


    void setVoto(int v) {
        if (v >= 18 && v <= 30) voto =v;
        else{
            cout << "Voto non valido. Impostato a 18." << endl;
            voto=18;
        }

    }

    int getVoto() const {
        return voto;
    }

    void stampa() const {
        cout << (nome ? nome : "Nessun nome") << " - " << voto << endl;
    }
};

class Studente {
private:
    char* nome;
    int numCorsi;
    Corso** corsi;  // array di puntatori

public:
    Studente() : nome(nullptr), numCorsi(0), corsi(nullptr) {}

    Studente(const char* n, int num) : nome(nullptr), numCorsi(num), corsi(nullptr) {

        if (n) {
            nome = new char[strlen(n) + 1];
            strcpy(nome, n);
        }

        if (numCorsi > 0) {
            corsi = new Corso*[numCorsi];
            for (int i = 0; i < numCorsi; i++) {
                corsi[i] = nullptr;
            }
        }
    }

    ~Studente() {
        delete[] nome;

        if (corsi) {
            for (int i = 0; i < numCorsi; i++) {
                delete corsi[i];  // delete singoli oggetti
            }
            delete[] corsi; // delete array di puntatori
        }
    }

    void setCorso(int index, const char* nomeCorso, int voto) {
        if (index >= 0 && index < numCorsi) {
            delete corsi[index]; // cancella se già presente
            corsi[index] = new Corso(nomeCorso, voto);
        }
    }

    float calcolaMedia() const {
        if (numCorsi == 0) return 0.0f;

        int somma = 0;
        for (int i = 0; i < numCorsi; i++) {
            if (corsi[i]) {
                somma += corsi[i]->getVoto();
            }
        }
        return (float)somma / numCorsi;
    }

    void stampa() const {
        cout << "Studente: " << (nome ? nome : "Nessun nome") << endl;

        for (int i = 0; i < numCorsi; i++) {
            if (corsi[i]) {
                corsi[i]->stampa();
            }
        }
    }
};

int main() {
    char nomeStudente[100];
    int n;

    cout << "Nome studente: ";
    cin>>nomeStudente;

    cout << "Numero corsi: ";
    cin >> n;
    cin.ignore(1000, '\n');  

    Studente s(nomeStudente, n);

    for (int i = 0; i < n; i++) {
        char nomeCorso[100];
        int voto;

        cout << "\nNome corso: ";
        cin>>nomeCorso;

        cout << "Voto: ";
        cin >> voto;
        cin.ignore(1000, '\n');  // fondamentale

        s.setCorso(i, nomeCorso, voto);
    }

    cout << "\n--- DATI ---" << endl;
    s.stampa();

    cout << "Media: " << s.calcolaMedia() << endl;

    return 0;
}