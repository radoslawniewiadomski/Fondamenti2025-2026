#include <iostream>
using namespace std;

class Matrice {
public:
    Matrice(); // dichiarazione costruttore
    int getElemento(int riga, int colonna) const; // dichiarazione selettore

private:
    int _dati[2][3];
};

// Definizione costruttore
Matrice::Matrice() {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            _dati[i][j] = 0;
        }
    }
}

// Definizione selettore
int Matrice::getElemento(int riga, int colonna) const {
    return _dati[riga][colonna];
}

int main() {
    Matrice m;

    cout << "Elemento (0,0): " << m.getElemento(0, 0) << endl;
    cout << "Elemento (1,2): " << m.getElemento(1, 2) << endl;

    return 0;
}