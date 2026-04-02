#include <iostream>
#include <cstring>

using namespace std;

class ContoBancario {
    char intestatario[30];
    float saldo;

public:
    ContoBancario(const char nome[], float s) {
        strcpy(intestatario, nome);
        saldo = s;
    }

    void applicaInteresse(float percentuale) {
        saldo += saldo * percentuale / 100;
    }

    void applicaTassa(float tassa) {
        saldo -= tassa;
    }

    void stampa() {
        cout << "Intestatario: " << intestatario
             << " - Saldo: " << saldo << endl;
    }
};

int main() {
    // Array statico di 3 conti
    ContoBancario conti[3] = {
        ContoBancario("Mario", 1000),
        ContoBancario("Luca", 500),
        ContoBancario("Anna", 200)
    };

    // Primo ciclo: applica operazioni
    for (int i = 0; i < 3; i++) {
        conti[i].applicaInteresse(2.5);
        conti[i].applicaTassa(30);
    }

    // Secondo ciclo: stampa risultati
    cout << "--- Stato finale dei conti ---" << endl;
    for (int i = 0; i < 3; i++) {
        conti[i].stampa();
    }

    return 0;
}