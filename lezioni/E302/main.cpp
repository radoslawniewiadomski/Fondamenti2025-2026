#include <iostream>
#include <cstring>
using namespace std;

class Punto {
    double _x;
    double _y;
    char * c;
public:
    Punto();
    Punto(double x, double y);
    ~Punto();
    void cambiaNome(const char *x);
    void stampaNome ();
};

Punto::Punto() {
    _x = 0.0;
    _y = 0.0;
    c = new char [20];
    strcpy(c,"Zero");
}

void Punto::cambiaNome(const char *x){
    delete[] c;
    c = new char[strlen(x) + 1];
    strcpy(c, x);
}
void Punto::stampaNome() {
    cout<<c;
}

Punto::~Punto() {
    cout<<"\n Uso di distruttore del punto chiamato: "<< c << endl;
    delete[] c;  
}

int main() {
    Punto punto1; 
    punto1.cambiaNome("Uno");

    Punto* p2 = new Punto();
    p2->cambiaNome("Due");

    cout<< " Distruggo l'oggetto: puntato da p2"<<endl;
    delete p2;

     cout<< " Distruggo l'oggetto: punto1"<<endl;
    return 0;
}
