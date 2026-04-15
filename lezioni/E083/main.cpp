#include <iostream>
#include <cstring>
using namespace std;

class Punto {
    double _x;
    double _y;
    char *c;  // puntatore a memoria dinamica per il nome

public:
    Punto();
    Punto(const Punto &p); // Costruttore di copia 
    void cambiaNome(const char *x);
    void stampaNome();
};

Punto::Punto() {
    _x = 0.0;
    _y = 0.0;

    // Allocazione dinamica per la stringa
    c = new char[20];

    // Inizializzo con "Zero"
    strcpy(c, "Zero");
}

Punto::Punto(const Punto &p)  {
    _x = p._x;
    _y = p._y;

    // alloco nuova memoria invece di copiare il puntatore
    c = new char[strlen(p.c) + 1];
    strcpy(c, p.c);
}

void Punto::cambiaNome(const char *x) {
    // Libero la vecchia memoria per evitare memory leak
    delete[] c;

    // Alloco nuova memoria della dimensione corretta
    c = new char[strlen(x) + 1];

    // Copio il nuovo contenuto
    strcpy(c, x);
}

void Punto::stampaNome() {
    cout << c << endl;
}

int main() {
    Punto punto1;

    // Cambio nome (usa memoria dinamica)
    punto1.cambiaNome("Uno");

    // Creo una copia (usa il costruttore di copia = deep copy)
    Punto punto2(punto1);

    // Modifico solo punto1
    punto1.cambiaNome("Quattro!");

    // Verifica: punto2 deve restare "Uno"
    cout << "Il nome del punto1 : ";
    punto1.stampaNome();
    
    cout << "Il nome del punto2 : "; 
    punto2.stampaNome();
   
    return 0;
}