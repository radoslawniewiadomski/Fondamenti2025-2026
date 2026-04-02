#include <iostream>
using namespace std;

class Rettangolo {
    float base;
    float altezza;
    
public:
    // Costruttore di default
    Rettangolo() {
        base = 0;
        altezza = 0;
    }

    // Costruttore con parametri
    Rettangolo(float b, float h) {
        base = b;
        altezza = h;
    }

    // Metodo per area
    float area() {
        return base * altezza;
    }

    // Metodo per perimetro
    float perimetro() {
        return 2 * (base + altezza);
    }
};

int main() {
    // Creazione oggetti
    Rettangolo r1(5, 3);
    Rettangolo r2(2.5, 4);

    // Stampa risultati
    cout << "Rettangolo 1:" << endl;
    cout << "Area: " << r1.area() << endl;
    cout << "Perimetro: " << r1.perimetro() << endl;

    cout << "\nRettangolo 2:" << endl;
    cout << "Area: " << r2.area() << endl;
    cout << "Perimetro: " << r2.perimetro() << endl;

    return 0;
}