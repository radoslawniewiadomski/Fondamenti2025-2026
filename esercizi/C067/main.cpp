#include <iostream>
#include <cstring>

using namespace std;

class Corso {
private:
    char* nome;
    int voto;

public:
    // Costruttore di default
    Corso() : nome(nullptr), voto(18) {}

    // Costruttore parametrico
    Corso(const char* n, int v) : nome(nullptr), voto(v) {
        if (n != nullptr) {
            nome = new char[strlen(n) + 1];
            strcpy(nome, n);
        } else {
            nome = nullptr;
        }

    }

    // Costruttore di copia
    Corso(const Corso& altro) : nome(nullptr), voto(altro.voto) {
        if (altro.nome != nullptr) {
            nome = new char[strlen(altro.nome) + 1];
            strcpy(nome, altro.nome);
        }
    }

    // Distruttore
    ~Corso() {
        delete[] nome;
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

    // Setter voto con controllo
    void setVoto(int v) {
        if (v >= 18 && v <= 30) {
            voto = v;
        } else {
            cout << "Voto non valido. Impostato a 18." << endl;
            voto = 18;
        }
    }

    // Getter
    const char* getNome() const {
        return nome;
    }

    int getVoto() const {
        return voto;
    }

    // Metodo stampa
    void stampa() const {
        cout << "Nome corso: " << (nome != nullptr ? nome : "Nessun nome") << endl;
        cout << "Voto: " << voto << endl;
    }
};

int main() {
    int n;
    cout << "Quanti corsi vuoi inserire? ";
    cin >> n;
    cin.ignore(1000, '\n');  

    Corso* corsi = new Corso[n];

    char buffer[100];
    int voto;
    int somma = 0;

    for (int i = 0; i < n; i++) {
        cout << "\nInserisci il nome del corso " << i + 1 << ": ";
        cin.ignore();
        cin.getline(buffer, 100);

        cout << "Inserisci il voto del corso " << i + 1 << ": ";
        cin >> voto;

        corsi[i].setNome(buffer);
        corsi[i].setVoto(voto);
    }

    cout << "--- Elenco corsi inseriti ---" << endl;
    for (int i = 0; i < n; i++) {
        corsi[i].stampa();
        cout << endl;
        somma += corsi[i].getVoto();
    }

    float media = (float)somma / n;
    cout << "Media dei voti: " << media << endl;

    delete[] corsi;

    return 0;
}