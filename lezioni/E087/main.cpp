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

    void stampaFilm();
};

// Definizioni dei metodi
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

void Film::stampaFilm()
{
    cout << "Titolo: " << _titolo << endl;
    cout << "Durata: " << _durata << " minuti" << endl;
    cout << "Anno: " << _anno << endl;
}

int main()
{
    int lunghezzaTitolo;
    cout << "Inserisci la lunghezza del titolo del Film: ";
    cin >> lunghezzaTitolo;

    // Allocazione dinamica della memoria per il titolo del Film
    char* titoloInput = new char[lunghezzaTitolo + 1];

    cout << "Inserisci il titolo del Film (massimo " << lunghezzaTitolo << " caratteri): ";
    cin >> titoloInput;

    int durataInput, annoInput;

    cout << "Inserisci durata: ";
    cin >> durataInput;
    cout << "Inserisci anno: ";
    cin >> annoInput;

    Film p(titoloInput, durataInput, annoInput);
    p.stampaFilm();

    // Liberazione della memoria allocata dinamicamente
    delete[] titoloInput;

    return 0;
}
