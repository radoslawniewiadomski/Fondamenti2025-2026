#include <iostream>
#include <cstring>
#include <fstream>
#include <cmath>

/*
Si scriva, in linguaggio C++, l’interfaccia della classe Campione, 
contenente i dati di temperatura e pressione di un liquido. 
In particolare, la classe sarà dotata dei tre attributi: 
un codice identificativo del campione (un numero intero positivo), 
il valore della temperatura espresso in gradi Celsius (un numero reale) e
 il valore della pressione espresso in bar (un numero reale positivo).

La classe dovrà inoltre prevedere i seguenti metodi:
l’operatore = per assegnare a un oggetto i valori degli attributi di un altro oggetto della stessa classe; 
l’operatore binario - per calcolare la differenza tra le temperature e restituisce un nuovo oggetto di tipo Campione. 
l’operatore unario - per ottenere un nuovo campione con temperatura opposta rispetto a quella del campione dato, lasciando invariati gli altri attributi; 

l’operatore di estrazione >> e l’operatore di inserimento << per leggere e stampare i dati di un campione; 

un metodo che converta la temperatura in kelvin ed un altro metodo che converta la pressione da bar a pascal. Entrambi restituiscono il risultato come un double

Inoltre, si definisca una funzione amica che calcoli la temperatura media di due campioni e restituisce un double.
*/


using namespace std;

class Campione {

  int _codice;
  double _temperatura;
  double _pressione;

  Campione();
  //un costruttore con parametri che riceva i valori del codice identificativo, della temperatura e della pressione; 
  Campione(int codice, double temperatura, double pressione);
  Campione(const Campione &other);

  ~Campione();
  
  //metodi selettori (uno per ciascun attributo); 

  int getCodice() const;
  double getTemperatura() const;
  double getPressione() const;

  //metodi modificatori (uno per ciascun attributo); 

  void setCodice(int codice);
  void setTemperatura(double temperatura);
  void setPressione(double pressione);

    //l’operatore == per verificare se due campioni sono identici, cioè se hanno lo stesso codice, la temperatura e la pressione; 
    //l’operatore != per verificare se due campioni sono diversi; 
    bool operator==(const Campione &other) const;
    bool operator!=(const Campione &other) const;


    //l’operatore > per verificare se un campione ha pressione maggiore di un altro; 
    //l’operatore < per verificare se un campione ha pressione minore di un altro; 
    
    bool operator>(const Campione &other) const;
    bool operator<(const Campione &other) const;


  //l’operatore = per assegnare a un oggetto i valori degli attributi di un altro oggetto della stessa classe; 
  Campione& operator=(const Campione &other);

  //l’operatore binario - per calcolare la differenza tra le temperature e restituisce un nuovo oggetto di tipo Campione. 
   Campione operator-(const Campione &other) const;

  //l’operatore unario - per ottenere un nuovo campione con temperatura opposta rispetto a quella del campione dato, lasciando invariati gli altri attributi; 
  Campione operator-() const;

  double conversioneKelvin() const;
  double conversionePascal() const;

  friend ostream& operator<< (ostream& os, const Campione& other);
  friend istream& operator>> (istream& is, Campione& other);

  friend double temperaturaMedia (const Campione &a, const Campione &b);
};

  double temperaturaMedia (const Campione &a, const Campione &b) {

    return (a.getTemperatura() + b.getTemperatura())/2.0;

  }
