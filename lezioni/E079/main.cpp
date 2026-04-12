#include <iostream>
using namespace std;

class Rettangolo {
public:
    // Costruttore con parametri di default
    Rettangolo(double base = 1.0, double altezza = 1.0)
        : _base(base), _altezza(altezza) {}

    void stampa() const {
        cout << "Base: " << _base << ", Altezza: " << _altezza << endl;
    }

private:
    double _base;
    double _altezza;
};

int main() {
    Rettangolo r1;           // base=1.0, altezza=1.0
    Rettangolo r2(5.0);      // base=5.0, altezza=1.0
    Rettangolo r3(5.0, 3.0); // base=5.0, altezza=3.0

    r1.stampa();
    r2.stampa();
    r3.stampa();

    return 0;
}