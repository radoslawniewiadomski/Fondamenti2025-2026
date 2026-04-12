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


//////////////////////////////////////////////////
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


//////////////////////////////////////////////////
// Definizioni delle funzioni esterne

// Funzione per trovare il Film pi� vecchio nell'array

Film& trovaFilmPiuVecchio(Film* listaFilm[], int size) {
    Film FilmPiuVecchio = *listaFilm[0]; // Supponiamo il primo Film come il pi� vecchio

    for (int i = 1; i < size; i++) {
        if (listaFilm[i]->getAnno() < FilmPiuVecchio.getAnno()) {
            FilmPiuVecchio = *listaFilm[i];
        }
    }

    return FilmPiuVecchio;
}

// Funzione per trovare il Film pi� lungo nell'array

Film* trovaFilmPiuLungo(Film* listaFilm[], int size) {
    Film* FilmPiuLungo = listaFilm[0]; // Supponiamo il primo Film come il pi� lungo

    for (int i = 1; i < size; i++) {
        if (listaFilm[i]->getDurata() > FilmPiuLungo->getDurata()) {
            FilmPiuLungo = listaFilm[i];
        }
    }

    return FilmPiuLungo;
}



/////////////////////////////////////////////////////////////////////////////


int main() {
    int numFilm;

    cout << "Quanti Film vuoi inserire? ";
    cin >> numFilm;

    Film** listaFilm = new Film*[numFilm]; // Array di puntatori a Film

    // Richiesta all'utente di inserire i dati per ciascun Film
    for (int i = 0; i < numFilm; i++) {
        int lunghezzaTitolo;
        cout << "Inserisci la lunghezza del titolo del " << i + 1 << " Film: ";
        cin >> lunghezzaTitolo;

        // Allocazione dinamica della memoria per il titolo del Film
        char* titolo = new char[lunghezzaTitolo + 1];

        cout << "Inserisci il titolo del " << i + 1 << " Film: (massimo " << lunghezzaTitolo << " caratteri): ";
        cin >> titolo;

        int durata, anno;

        cout << "Inserisci la durata in minuti del " << i + 1 << " Film: ";
        cin >> durata;

        cout << "Inserisci l'anno di produzione del " << i + 1 << " Film: ";
        cin >> anno;

        listaFilm[i] = new Film(titolo, durata, anno); // Creazione del nuovo Film
        delete[] titolo; // Liberiamo la memoria allocata per il titolo
    }

    // Stampa dei Film
    for (int i = 0; i < numFilm; i++) {
        cout << "Film " << i + 1 << ":" << endl;
        listaFilm[i]->stampaFilm();
        cout << endl;
    }

    // Trova e stampa il Film pi� vecchio
    Film FilmPiuVecchio = trovaFilmPiuVecchio(listaFilm, numFilm);
    cout << "Il Film piu vecchio e: " << endl;
    FilmPiuVecchio.stampaFilm();
    cout << endl;

    // Trova e stampa il Film pi� lungo
    Film* FilmPiuLungo = trovaFilmPiuLungo(listaFilm, numFilm);
    cout << "Il Film piu lungo e: " << endl;
    FilmPiuLungo->stampaFilm();
    cout << endl;

    // Deallocazione della memoria
    for (int i = 0; i < numFilm; i++) {
        delete listaFilm[i];
    }
    delete[] listaFilm;

    return 0;
}
