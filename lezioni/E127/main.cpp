#include <iostream>
#include <cstring>
using namespace std;

class Film
{
    char* titolo;
    int durata;
    int anno;

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

    // Operator<<
    friend ostream& operator<<(ostream& os, const Film& film);

    // Operator>>
    friend istream& operator>>(istream& is, Film& film);

    void stampaFilm() const;
};

// =========================
// Costruttori
// =========================

Film::Film()
{
    titolo = new char[4];
    strcpy(titolo, "N/D");
    durata = 0;
    anno = 0;
}

Film::Film(const char* titolo, int durata, int anno)
{
    this->titolo = new char[strlen(titolo) + 1];
    strcpy(this->titolo, titolo);
    this->durata = durata;
    this->anno = anno;
}

Film::Film(const Film& otherFilm)
{
    titolo = new char[strlen(otherFilm.titolo) + 1];
    strcpy(titolo, otherFilm.titolo);
    durata = otherFilm.durata;
    anno = otherFilm.anno;
}

// =========================
// Distruttore
// =========================

Film::~Film()
{
    delete[] titolo;
}

// =========================
// Metodi
// =========================

const char* Film::getTitolo() const
{
    return titolo;
}

void Film::setTitolo(const char* titolo)
{
    delete[] this->titolo;
    this->titolo = new char[strlen(titolo) + 1];
    strcpy(this->titolo, titolo);
}

int Film::getDurata() const
{
    return durata;
}

void Film::setDurata(int durata)
{
    this->durata = durata;
}

int Film::getAnno() const
{
    return anno;
}

void Film::setAnno(int anno)
{
    this->anno = anno;
}

void Film::stampaFilm() const
{
    cout << "Titolo: " << titolo << endl;
    cout << "Durata: " << durata << " minuti" << endl;
    cout << "Anno: " << anno << endl;
}

// =========================
// Operatore <<
// =========================

ostream& operator<<(ostream& os, const Film& film)
{
    os << "Titolo: " << film.titolo
       << ", Durata: " << film.durata
       << " minuti, Anno: " << film.anno;
    return os;
}

// =========================
// Operatore >>
// =========================

istream& operator>>(istream& is, Film& film)
{
    char temp[100];

    is >> temp;

    delete[] film.titolo;    // evitare memory leak

    film.titolo = new char[strlen(temp) + 1];
    strcpy(film.titolo, temp);

    is >> film.durata >> film.anno;

    return is;
}

// =========================
// MAIN
// =========================

int main()
{
    Film film1("Matrix", 120, 1999);
    cout << "Film 1: " << film1 << endl;

    Film film2;
    cout << "Inserisci titolo durata anno (es: Matrix 120 1999): ";
    cin >> film2;

    cout << "Film 2: " << film2 << endl;

    return 0;
}