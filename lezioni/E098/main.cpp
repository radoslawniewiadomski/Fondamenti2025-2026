#include <iostream>
#include <cstring>
using namespace std;

class Film
{
    char* _titolo;
    int _durata;
    int _anno;

public:
    // Costruttori
    Film();
    Film(char* titolo, int durata, int anno);
    // Costruttore di copia
    Film(const Film& otherFilm);
    // Distruttore
    ~Film();

    // Selettori e modificatori
    char* getTitolo() const;
    void setTitolo(const char* titolo);
    int getDurata() const;
    void setDurata(int durata);
    int getAnno() const;
    void setAnno(int anno);

    void stampaFilm() const;
};

//////////////////////////////////////////////////////////////
// Definizioni delle metodi

Film::Film()
{
    _titolo = new char[20];
    strcpy(_titolo, "N/D");
    _durata = 0;
    _anno = 0;
}

Film::Film(char* titolo, int durata, int anno)
{
    _titolo = new char[strlen(titolo) + 1];
    strcpy(_titolo, titolo);
    _durata = durata;
    _anno = anno;
}

Film::Film(const Film& otherFilm)
{
    _titolo = new char[strlen(otherFilm._titolo) + 1];
    strcpy(_titolo, otherFilm._titolo);
    _durata = otherFilm._durata;
    _anno = otherFilm._anno;
}

Film::~Film()
{
    delete[] _titolo;
}

char* Film::getTitolo() const
{
    return _titolo;
}

void Film::setTitolo(const char* titolo)
{
    delete[] _titolo;
    _titolo = new char[strlen(titolo) + 1];
    strcpy(_titolo, titolo);
}

int Film::getDurata() const
{
    return _durata;
}

void Film::setDurata(int durata)
{
    _durata = durata;
}

int Film::getAnno() const
{
    return _anno;
}

void Film::setAnno(int anno)
{
    _anno = anno;
}

void Film::stampaFilm() const
{
    cout << "Titolo: " << _titolo << endl;
    cout << "Durata: " << _durata << " minuti" << endl;
    cout << "Anno: " << _anno << endl;
}

/////////////////////////////////////////////////////////////////////////////


int main()
{
    const int size=3;
    Film* listaFilm[size];

    // Richiesta all'utente di inserire i dati per ciascun Film
    for (int i = 0; i < size; ++i)
    {

        int lunghezzaTitolo;
        cout << "Inserisci la lunghezza del titolo del " << i + 1 << " film: ";
        cin >> lunghezzaTitolo;

        // Allocazione dinamica della memoria per il titolo del Film
        char* titolo = new char[lunghezzaTitolo + 1];

        cout << "Inserisci il titolo del " << i + 1 << " film:  (massimo " << lunghezzaTitolo << " caratteri): ";
        cin >> titolo;

        int durata, anno;

        cout << "Inserisci la durata in minuti del " << i + 1 << " film: ";
        cin >> durata;

        cout << "Inserisci l'anno di produzione del " << i + 1 << " film: ";
        cin >> anno;

        listaFilm[i] = new Film(titolo, durata, anno); // Creazione del nuovo Film
        delete[] titolo; // Liberiamo la memoria allocata per il titolo
    }

    // Stampa dei Film
    for (int i = 0; i < size; ++i)
    {
        cout << "Film " << i + 1 << ":" << endl;
        listaFilm[i]->stampaFilm();
        cout << endl;
    }

    // Deallocazione della memoria
    for (int i = 0; i < size; ++i)
    {
        delete listaFilm[i];
    }

    return 0;
}
