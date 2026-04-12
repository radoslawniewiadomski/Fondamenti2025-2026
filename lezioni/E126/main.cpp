#include <iostream>
using namespace std;

class Punto {
    // 2 attributi privati
    double _x;
    double _y;

public:
    // costruttori
    Punto();
    Punto(double x, double y);

    // distruttore
    ~Punto();

    // =========================  OPERATORI

    // Operatore somma tra due punti const: non modifica l'oggetto chiamante
    Punto operator+(const Punto& p) const;
    bool operator==(const Punto& p) const;

    // modificatori
    void setX(double x);
    void setY(double y);

    // selettori (const: non modificano l'oggetto)
    double getX() const;
    double getY() const;

    // altri metodi
    void stampaPunto() const;
};

// =========================
// COSTRUTTORI
// =========================

// costruttore di default
Punto::Punto() {
    _x = -1;
    _y = -1;
    }

// costruttore con parametri
Punto::Punto(double x, double y) {
    _x = x;
    _y = y;
   }

// =========================

void Punto::setX(double x) {
    _x = x;
}

void Punto::setY(double y) {
    _y = y;
}

// =========================

double Punto::getX() const {
    return _x;
}

double Punto::getY() const {
    return _y;
}

// =========================

void Punto::stampaPunto() const {
    cout << "Coordinate del punto: (" << _x << ", " << _y << ")" << endl;
}

// ========================= DISTRUTTORE

// distruttore didattico (solo per vedere quando viene chiamato)
Punto::~Punto() {
}

// =========================
// OPERATORI
// =========================

// Somma tra due punti
Punto Punto::operator+(const Punto& p) const {
    // crea un nuovo oggetto risultato
    Punto q(_x + p._x, _y + p._y);
    return q; // ritorno per valore
}

bool Punto::operator==(const Punto& p) const {
    return (_x == p._x) && (_y == p._y);
}

// =========================
// MAIN
// =========================

int main() {
    Punto p(5.0, 2.0);
    Punto q(4.0, 1.0);

    if(p+q==q+p) cout <<"Si"; else cout<<"no";

    return 0;
}