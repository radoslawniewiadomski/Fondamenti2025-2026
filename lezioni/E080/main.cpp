#include <iostream>
using namespace std;

class PuntoRef {
public:
    PuntoRef(double &x, double &y);  // costruttore con parametri

    double& _x;  // riferimento
    double& _y;  // riferimento
};

PuntoRef::PuntoRef(double &x, double &y) : _x(x), _y(y) {}

int main() {
    double a = 1.0;
    double b = 3.0;

    PuntoRef punto(a, b);
    cout << "Prima: (" << punto._x << ", " << punto._y << ")\n";

    // Modifico le variabili originali
    a = 5.0;
    b = 6.0;

    cout << "Dopo modifica esterna: (" << punto._x << ", " << punto._y << ")\n";

    // Modifico tramite l'oggetto
    punto._x = 10.0;
    punto._y = 20.0;

    cout << "Dopo modifica tramite oggetto: a=" << a << ", b=" << b << "\n";

    return 0;
}