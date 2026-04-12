#include <iostream>
#include <math.h>  // Per usare le funzioni matematiche
using namespace std;

// Definizione della classe Punto
class Punto {
    // Attributi privati per rappresentare le coordinate del punto
    double _x;
    double _y;

public:
    // Costruttori
    Punto();                     // Costruttore di default
    Punto(double x, double y);   // Costruttore con parametri

    // Distruttore
    ~Punto();                    // Distruttore (solo per messaggio di debug)

    // Metodi modificatori (setter)
    void setX(double x);         // Imposta la coordinata X
    void setY(double y);         // Imposta la coordinata Y

    // Metodi selettori (getter)
    double getX();               // Restituisce la coordinata X
    double getY();               // Restituisce la coordinata Y

    // Metodo per stampare le coordinate del punto
    void stampaPunto();
};

// DEFINIZIONE DEI METODI DELLA CLASSE

// Costruttore di default: inizializza il punto a (-1, -1)
Punto::Punto() {
    _x = -1;
    _y = -1;
}

// Costruttore con parametri: inizializza il punto con le coordinate fornite
Punto::Punto(double x, double y) {
    _x = x;
    _y = y;
}

// Setter per X
void Punto::setX(double x) {
    _x = x;
}

// Setter per Y
void Punto::setY(double y) {
    _y = y;
}

// Getter per X
double Punto::getX() {
    return _x;
}

// Getter per Y
double Punto::getY() {
    return _y;
}

// Metodo per stampare le coordinate del punto
void Punto::stampaPunto() {
    cout << "Coordinate del punto: (" << _x << ", " << _y << ")" << endl;
}

// Distruttore: stampa un messaggio quando un oggetto Punto viene distrutto
Punto::~Punto() {
    cout << "Questo è il distruttore" << endl;
}

//////////////////////////////////////////////////////

// Funzione che crea 10 punti posizionati su un cerchio attorno a un punto dato
Punto* creaPuntiDistanti(Punto* punto) {
    Punto* punti = new Punto[10];  // Array dinamico di 10 punti
    double angleIncrement = 2 * M_PI / 10;  // Angolo tra i punti (360° / 10)
    double radius = 100;  // Raggio del cerchio

    for (int i = 0; i < 10; ++i) {
        double angle = i * angleIncrement;  // Calcolo dell'angolo corrente
        // Calcolo delle nuove coordinate in base al centro e al raggio
        double newX = punto->getX() + radius * cos(angle);
        double newY = punto->getY() + radius * sin(angle);
        punti[i].setX(newX);
        punti[i].setY(newY);
    }

    return punti;  // Ritorna l'array di punti
}

//////////////////////////////////////////////////////


int main() {
    // Creazione dinamica di un oggetto Punto con coordinate (10, 10)
    Punto* p2 = new Punto(10, 10);
    p2->stampaPunto();  // Stampa le coordinate del punto

    // Creazione dei 10 punti attorno a p2
    Punto* puntiCreati = creaPuntiDistanti(p2);
    for (int i = 0; i < 10; ++i) {
        puntiCreati[i].stampaPunto();  // Stampa ogni punto generato
    }

    // Liberazione della memoria allocata dinamicamente
    delete[] puntiCreati;  // Elimina l'array di punti
    delete p2;             // Elimina il punto originale

    return 0;
}
