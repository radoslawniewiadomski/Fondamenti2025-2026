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

    void stampaFilm() const;

    // Dichiarazione di funzione amica
    friend bool stessoAnno(const Film& f1, const Film& f2);
};

// Definizioni delle funzioni

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

// Definizione della funzione amica

bool stessoAnno(const Film& f1, const Film& f2)
{
    return f1._anno == f2._anno;
}

/*
// Versione senza funzione amica:
bool stessoAnno(const Film& f1, const Film& f2)
{
    return f1.getAnno() == f2.getAnno();
}
*/

//////////////////////////////////////////////////

int main()
{
    Film film1("Matrix", 120, 2000);
    Film film2("Solaris", 90, 1995);
    Film film3("Inception", 148, 2000);

    cout << "Film 1 e Film 2 sono stati realizzati nello stesso anno? ";
    if (stessoAnno(film1, film2))
    {
        cout << "Sì" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    cout << "Film 1 e Film 3 sono stati realizzati nello stesso anno? ";
    if (stessoAnno(film1, film3))
    {
        cout << "Sì" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    return 0;
}