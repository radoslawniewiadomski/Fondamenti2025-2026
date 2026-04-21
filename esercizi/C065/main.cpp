#include <iostream>
using namespace std;

class Campione {
private:
    int codice;
    double temperatura;
    double pressione;

public:
    // Costruttori e distruttore
    Campione();
    Campione(const Campione& c);
    Campione(int cod, double temp, double pres);
    ~Campione();

    // Selettori
    int getCodice() const;
    double getTemperatura() const;
    double getPressione() const;

    // Modificatori
    void setCodice(int cod);
    void setTemperatura(double temp);
    void setPressione(double pres);

    // Operatori
    bool operator==(const Campione& c) const;
    Campione& operator=(const Campione& c);
    bool operator!=(const Campione& c) const;
    bool operator>(const Campione& c) const;
    bool operator<(const Campione& c) const;

    // Operatore binario -
    double operator-(const Campione& c) const;

    // Operatore unario -
    Campione operator-() const;

    // Conversioni
    double temperaturaKelvin() const;
    double pressionePascal() const;

    // Funzione amica
    friend double temperaturaMedia(const Campione& c1, const Campione& c2);

    // Stream operators
    friend istream& operator>>(istream& in, Campione& c);
    friend ostream& operator<<(ostream& out, const Campione& c);
};

// Funzione amica: temperatura media
double temperaturaMedia(const Campione& c1, const Campione& c2) {
    return (c1.temperatura + c2.temperatura) / 2.0;
}
