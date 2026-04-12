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

    // =========================
    // OPERATORI
    // =========================

    // Operatore di inserimento (cout << p)
    // friend perché accede a membri privati
    friend ostream& operator<<(ostream& os, const Punto& p);

    // Operatore di estrazione (cin >> p)
    friend istream& operator>>(istream& is, Punto& p);

    // Operatore somma tra due punti
    // const: non modifica l’oggetto chiamante
    Punto operator+(const Punto& p) const;

    // modificatori
    void setX(double x);
    void setY(double y);

    // selettori (const: non modificano l’oggetto)
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
    cout << "Costruttore default, this = " << this << endl;
}

// costruttore con parametri
Punto::Punto(double x, double y) {
    _x = x;
    _y = y;
    cout << "Costruttore parametri, this = " << this << endl;
}

// =========================
// MODIFICATORI
// =========================

void Punto::setX(double x) {
    _x = x;
}

void Punto::setY(double y) {
    _y = y;
}

// =========================
// SELETTORI
// =========================

double Punto::getX() const {
    return _x;
}

double Punto::getY() const {
    return _y;
}

// =========================
// ALTRI METODI
// =========================

void Punto::stampaPunto() const {
    cout << "Coordinate del punto: (" << _x << ", " << _y << ")" << endl;
}

// =========================
// DISTRUTTORE
// =========================

// distruttore didattico (solo per vedere quando viene chiamato)
Punto::~Punto() {
    cout << "Distruttore chiamato per oggetto " << this << endl;
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

// Operatore << (output)
// Permette: cout << p;
ostream& operator<<(ostream& os, const Punto& p) {
    os << '(' << p._x << ", " << p._y << ')';
    return os; // importante: ritorna lo stream per concatenazione
}

// Operatore >> (input)
// Permette: cin >> p;
istream& operator>>(istream& is, Punto& p) {
    is >> p._x >> p._y;
    return is;
}

// =========================
// MAIN
// =========================

int main() {
    Punto p(5.0, 2.0);
    Punto q(4.0, 1.0);

    // uso combinato di operatori << e +
    cout << "La somma di " << p << " e " << q << " vale " << p + q << endl;

    return 0;
}