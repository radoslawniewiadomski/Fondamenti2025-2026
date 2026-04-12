#include <iostream>
#include <cmath>
using namespace std;

class Punto {

public:
    // Costruttori
    Punto() : _x(0), _y(0) {}
    Punto(double x, double y) : _x(x), _y(y) {}

    // Metodo per riscala
    void riscala(double f) {
        _x *= f;
        _y *= f;
    }

    // Calcolo della distanza tra due punti
    double distanza(Punto p) const {
        double dx = _x - p._x;
        double dy = _y - p._y;
        return sqrt(dx * dx + dy * dy);
    }

    // Metodo per stampare il punto
    void stampa() const {
        cout << "(" << _x << ", " << _y << ")" << endl;
    }

private:
    double _x;
    double _y;
};

// Funzione main di esempio
int main() {
    Punto p1(3.0, 4.0);
    Punto p2(0.0, 0.0);

    cout << "Punto 1: ";
    p1.stampa();
    cout << "Punto 2: ";
    p2.stampa();

    cout << "Distanza tra p1 e p2: " << p1.distanza(p2) << endl;

    p1.riscala(2.0);
    cout << "Punto 1 dopo riscalatura (fattore 2): ";
    p1.stampa();

    return 0;
}
