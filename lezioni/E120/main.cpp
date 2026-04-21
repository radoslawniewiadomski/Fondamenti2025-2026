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
    // Distruttore
    ~Film();

    //operatori
    int operator>(const Film& Film2) const ;
    Film& operator=(const Film& otherFilm);


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

int Film::operator>(const Film& Film2) const
{
    // Confronto sulla durata dei Film
    if (getDurata() > Film2.getDurata()) return true;
    return false;
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


/* SECONDA VERSIONE
bool Film::operator>(const Film& Film2) {
    // Confronto sulla data di produzione dei Film (dove maggiore significa pi� vecchio)
    return getAnno() < Film2.getAnno();
}
*/

Film::Film(char* titolo, int durata, int anno)
{
    _titolo = new char[strlen(titolo) + 1];
    strcpy(_titolo, titolo);
    _durata = durata;
    _anno = anno;
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

///////////////////////////////////////////////////////////////

class Impiegato
{
private:
    char nome[32];
    char cognome[32];
public:
    Impiegato(const char* _nome, const char* _cognome);
    Impiegato();

    // Operatore ">" sovraccaricato per confrontare due impiegati in base al cognome
    bool operator>(const Impiegato& imp) const;

    void stampa() const;
};

Impiegato::Impiegato()
{
    strcpy(nome, "N/D");
    strcpy(cognome, "N/D");

}


Impiegato::Impiegato(const char* _nome, const char* _cognome)
{
    strcpy(nome, _nome);
    strcpy(cognome, _cognome);
}

bool Impiegato::operator>(const Impiegato& imp) const
{
    if (strcmp(cognome, imp.cognome) > 0) return true;
    return false;
}

void Impiegato::stampa() const
{
    cout << "Nome: " << nome << ", Cognome: " << cognome << endl;
}

///////////////////////////////////////////////////////////////

template<typename T>
void swap2(T& a, T& b)
{
    T temp = a;
    a = b;
    b = temp;
}

template<typename T>
void BubbleSort (T v[], int n)
{
    int i, j;
    T tmp;
    for (i = n - 1; i > 0; i--)
        for (j = 0; j < i; j++)
            if (v[j] > v[j+1])
            {
                tmp = v[j];
                v[j] = v[j+1];
                v[j+1] = tmp;
            }
}


int main()
{
    int a[5] = {3, 2, 6, 1, 4};
    Impiegato imp[3] = {{"Mario", "Rossi"}, {"Paola", "Bianchi"}, {"Riccardo", "Bianccardi"}};

    Film FilmArray[5] =
    {
        {"Matrix", 120, 1999},
        {"Inception", 148, 2010},
        {"Interstellar", 169, 2014},
        {"Shawshank", 142, 1993},
        {"Pulp", 154, 1994}
    };

    cout << "Prima di ordinare:" << endl;
    for (int i = 0; i < 5; ++i)
    {
        FilmArray[i].stampaFilm();
    }

    BubbleSort<int>(a, 5);
    BubbleSort<Impiegato>(imp, 3);
    BubbleSort<Film>(FilmArray, 5);

    cout << "\nDopo l'ordinamento dei Film:" << endl;
    for (int i = 0; i < 5; ++i)
    {
        FilmArray[i].stampaFilm();
    }

    return 0;
}
