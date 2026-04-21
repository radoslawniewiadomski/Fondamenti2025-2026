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
    Film(const char* titolo, int durata, int anno);

    // Costruttore di copia
    Film(const Film& otherFilm);
  
    // Distruttore
    ~Film();

    // Selettori e modificatori
    const char* getTitolo() const;
    void setTitolo(const char* titolo);
    int getDurata() const;
    void setDurata(int durata);
    int getAnno() const;
    void setAnno(int anno);

    // Operatori
    Film operator+(const Film& other) const;
    
    Film& operator+=(const Film& other);
    
    Film& operator=(const Film& otherFilm);



    void stampaFilm() const;
};

// Definizioni dei metodi

Film::Film()
{
    _titolo = new char[4];
    strcpy(_titolo, "N/D");
    _durata = 0;
    _anno = 0;
}

Film::Film(const char* titolo, int durata, int anno)
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

const char* Film::getTitolo() const
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

// Definizione dell'operatore +
Film Film::operator+(const Film& other) const
{
    char* nuovoTitolo = new char[strlen(_titolo) + strlen(other._titolo) + 2];
    strcpy(nuovoTitolo, _titolo);
    strcat(nuovoTitolo, "&");
    strcat(nuovoTitolo, other._titolo);

    int nuovaDurata = _durata + other._durata;
    int nuovoAnno = _anno + other._anno;

    Film nuovoFilm(nuovoTitolo, nuovaDurata, nuovoAnno);

    delete[] nuovoTitolo;
    return nuovoFilm;
}

// Definizione dell'operatore +=
Film& Film::operator+=(const Film& other)
{
    char* nuovoTitolo = new char[strlen(_titolo) + strlen(other._titolo) + 2];
    strcpy(nuovoTitolo, _titolo);
    strcat(nuovoTitolo, "&");
    strcat(nuovoTitolo, other._titolo);

    _durata += other._durata;
    _anno += other._anno;

    delete[] _titolo;
    _titolo = nuovoTitolo;

    return *this;
}


Film& Film::operator=(const Film& otherFilm)
{
    if (this != &otherFilm)
    {
        delete[] _titolo;

        _titolo = new char[strlen(otherFilm._titolo) + 1];
        strcpy(_titolo, otherFilm._titolo);
        _durata = otherFilm._durata;
        _anno = otherFilm._anno;
    }

    return *this;
}

////////////////////////////////////////////////////////////////


int main()
{
    Film film1("Matrix", 120, 2000);
    Film film2("Solaris", 90, 1995);

    Film filmSomma = film1 + film2;
    filmSomma.stampaFilm();

    film1 += film2;
    film1.stampaFilm();

    return 0;
}