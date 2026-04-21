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

    // Operatori sovraccaricati
    Film operator!() const;
    Film operator-()  const;

    void stampaFilm();
};

//////////////////////////////////////////////////////////
// definizioni dei metodi

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

///////////////////////////////////////////////
//operatori sovracaricati

Film Film::operator-()  const {
    char* invertedTitolo = new char[strlen(_titolo) + 1];
    int length = strlen(_titolo);
    for (int i = 0; i < length; ++i) {
        invertedTitolo[i] = _titolo[length - 1 - i];
    }
    invertedTitolo[length] = '\0';

    Film invertedFilm(invertedTitolo, _durata, _anno);
    delete[] invertedTitolo;

    return invertedFilm;
}


Film Film::operator!() const
{
    char* invertedTitolo = new char[strlen(_titolo) + 1];
    int length = strlen(_titolo);
    for (int i = 0; i < length; ++i)
    {
        invertedTitolo[i] = _titolo[length - 1 - i];
    }
    invertedTitolo[length] = '\0';

    Film invertedFilm(invertedTitolo, _durata, _anno);
    delete[] invertedTitolo;

    return invertedFilm;
}

//////////////////////////////////////////


int main()
{
    Film mioFilm("Inception", 148, 2010);
    mioFilm.stampaFilm();

    Film FilmInvertito = -mioFilm;
    cout << "Titolo invertito: " << FilmInvertito.getTitolo() << endl;

    return 0;
}
