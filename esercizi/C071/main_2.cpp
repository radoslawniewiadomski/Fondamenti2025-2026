#include <iostream>
using namespace std;

class Campione {
private:
    int codice;          // numero intero positivo
    double temperatura;  // gradi Celsius
    double pressione;    // bar, numero reale positivo

public:
    // Costruttore di default
    Campione() : codice(0), temperatura(0.0), pressione(1.0) {}

    // Costruttore di copia
    Campione(const Campione& c) {
        codice = c.codice;
        temperatura = c.temperatura;
        pressione = c.pressione;
    }

    // Costruttore con parametri
    Campione(int cod, double temp, double pres) {
        codice = (cod > 0) ? cod : 0;
        temperatura = temp;
        pressione = (pres > 0) ? pres : 1.0;
    }

    // Distruttore
    ~Campione() {}

    // Metodi selettori
    int getCodice() const {
        return codice;
    }

    double getTemperatura() const {
        return temperatura;
    }

    double getPressione() const {
        return pressione;
    }

    // Metodi modificatori
    void setCodice(int cod) {
        if (cod > 0)
            codice = cod;
    }

    void setTemperatura(double temp) {
        temperatura = temp;
    }

    void setPressione(double pres) {
        if (pres > 0)
            pressione = pres;
    }

    // Operatore ==
    bool operator==(const Campione& c) const {
        return (codice == c.codice &&
                temperatura == c.temperatura &&
                pressione == c.pressione);
    }

    // Operatore =
    Campione& operator=(const Campione& c) {
        if (this != &c) {
            codice = c.codice;
            temperatura = c.temperatura;
            pressione = c.pressione;
        }
        return *this;
    }

    // Operatore !=
    bool operator!=(const Campione& c) const {
        return !(*this == c);
    }

    // Operatore >
    bool operator>(const Campione& c) const {
        return pressione > c.pressione;
    }

    // Operatore <
    bool operator<(const Campione& c) const {
        return pressione < c.pressione;
    }

    // Operatore binario -
    double operator-(const Campione& c) const {
        return temperatura - c.temperatura;
    }

    // Operatore unario -
    Campione operator-() const {
        return Campione(codice, -temperatura, pressione);
    }

    // Conversione temperatura in kelvin
    double temperaturaKelvin() const {
        return temperatura + 273.15;
    }

    // Conversione pressione da bar a pascal
    double pressionePascal() const {
        return pressione * 100000.0;
    }

    // Funzione amica: temperatura media
    friend double temperaturaMedia(const Campione& c1, const Campione& c2);

    // Operatore >>
    friend istream& operator>>(istream& in, Campione& c);

    // Operatore <<
    friend ostream& operator<<(ostream& out, const Campione& c);
};

// Funzione amica: temperatura media
double temperaturaMedia(const Campione& c1, const Campione& c2) {
    return (c1.temperatura + c2.temperatura) / 2.0;
}

// Operatore di estrazione >>
istream& operator>>(istream& in, Campione& c) {
    cout << "Inserisci codice identificativo: ";
    in >> c.codice;

    cout << "Inserisci temperatura (Celsius): ";
    in >> c.temperatura;

    cout << "Inserisci pressione (bar): ";
    in >> c.pressione;

    return in;
}

// Operatore di inserimento <<
ostream& operator<<(ostream& out, const Campione& c) {
    out << "Codice: " << c.codice
        << ", Temperatura: " << c.temperatura << " C"
        << ", Pressione: " << c.pressione << " bar";
    return out;
}

// Esempio di utilizzo
int main() {
    Campione c1(1, 25.5, 2.3);
    Campione c2;

    cin >> c2;

    cout << "\nCampione 1: " << c1 << endl;
    cout << "Campione 2: " << c2 << endl;

    cout << "\nDifferenza temperature: " << (c1 - c2) << " C" << endl;
    cout << "Temperatura media: " << temperaturaMedia(c1, c2) << " C" << endl;

    cout << "Temperatura c1 in Kelvin: " << c1.temperaturaKelvin() << " K" << endl;
    cout << "Pressione c1 in Pascal: " << c1.pressionePascal() << " Pa" << endl;

    if (c1 == c2)
        cout << "I due campioni sono identici." << endl;
    else
        cout << "I due campioni sono diversi." << endl;

    if (c1 > c2)
        cout << "c1 ha pressione maggiore di c2." << endl;
    else if (c1 < c2)
        cout << "c1 ha pressione minore di c2." << endl;
    else
        cout << "I due campioni hanno la stessa pressione." << endl;

    Campione c3 = -c1;
    cout << "Campione con temperatura opposta a c1: " << c3 << endl;

    return 0;
}