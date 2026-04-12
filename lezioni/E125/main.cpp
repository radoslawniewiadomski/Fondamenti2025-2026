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


int main() {
 Punto p(5.0, 1.0);
 Punto q(5.0, 1.0);

 if(p==p) cout <<"Si"; else cout<<"No";
 if(p==q) cout <<"Si"; else cout<<"No";

 return 0;
}
