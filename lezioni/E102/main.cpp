#include <iostream>
#include <cstring>

using namespace std;

class Libro {
    char* _autore;
    char* _titolo;
    int _anno;

public:
    // Costruttori
    Libro();
    Libro(const char* autore, const char* titolo, int anno);
    Libro(const Libro& other);              // costruttore di copia
    Libro& operator=(const Libro& other);   // operatore di assegnazione

    // Distruttore
    ~Libro();

    // Metodi di accesso
    const char* getAutore() const;
    void setAutore(const char* autore);
    const char* getTitolo() const;
    void setTitolo(const char* titolo);
    int getAnno() const;
    void setAnno(int anno);

    void stampa() const;
};

class Libreria {
    int _id;
    Libro* _libri;
    int _numLibri;

public:
    // Costruttore
    Libreria(int id);

    // Distruttore
    ~Libreria();

    // Metodo per inserire un libro nella libreria
    void inserisciLibro(const Libro& libro);

    // Metodo per ottenere il numero di libri nella libreria
    int getNumLibri() const;

    void stampaLibri() const;

Libro* trovaLibroPiuVecchio() const;

};


// =========================
// Definizioni classe Libro
// =========================

Libro::Libro() : _autore(nullptr), _titolo(nullptr), _anno(0) {}

Libro::Libro(const char* autore, const char* titolo, int anno) : _anno(anno) {
    _autore = new char[strlen(autore) + 1];
    strcpy(_autore, autore);

    _titolo = new char[strlen(titolo) + 1];
    strcpy(_titolo, titolo);
}

Libro::Libro(const Libro& other) : _anno(other._anno) {
    if (other._autore != nullptr) {
        _autore = new char[strlen(other._autore) + 1];
        strcpy(_autore, other._autore);
    } else {
        _autore = nullptr;
    }

    if (other._titolo != nullptr) {
        _titolo = new char[strlen(other._titolo) + 1];
        strcpy(_titolo, other._titolo);
    } else {
        _titolo = nullptr;
    }
}

Libro& Libro::operator=(const Libro& other) {
    if (this != &other) {
        delete[] _autore;
        delete[] _titolo;

        _anno = other._anno;

        if (other._autore != nullptr) {
            _autore = new char[strlen(other._autore) + 1];
            strcpy(_autore, other._autore);
        } else {
            _autore = nullptr;
        }

        if (other._titolo != nullptr) {
            _titolo = new char[strlen(other._titolo) + 1];
            strcpy(_titolo, other._titolo);
        } else {
            _titolo = nullptr;
        }
    }

    return *this;
}

Libro::~Libro() {
    delete[] _autore;
    delete[] _titolo;
}

const char* Libro::getAutore() const {
    return _autore;
}

void Libro::setAutore(const char* autore) {
    delete[] _autore;
    _autore = new char[strlen(autore) + 1];
    strcpy(_autore, autore);
}

const char* Libro::getTitolo() const {
    return _titolo;
}

void Libro::setTitolo(const char* titolo) {
    delete[] _titolo;
    _titolo = new char[strlen(titolo) + 1];
    strcpy(_titolo, titolo);
}

int Libro::getAnno() const {
    return _anno;
}

void Libro::setAnno(int anno) {
    _anno = anno;
}

void Libro::stampa() const {
    cout << "Autore: " << _autore << endl;
    cout << "Titolo: " << _titolo << endl;
    cout << "Anno: " << _anno << endl;
}


// ============================
// Definizioni classe Libreria
// ============================

Libreria::Libreria(int id) : _id(id), _libri(nullptr), _numLibri(0) {}

Libreria::~Libreria() {
    delete[] _libri;
}

void Libreria::inserisciLibro(const Libro& libro) {
    Libro* temp = new Libro[_numLibri + 1];

    for (int i = 0; i < _numLibri; ++i) {
        temp[i] = _libri[i];   // usa operator=
    }

    temp[_numLibri] = libro;   // usa operator=

    delete[] _libri;
    _libri = temp;
    _numLibri++;
}

int Libreria::getNumLibri() const {
    return _numLibri;
}

void Libreria::stampaLibri() const {
    for (int i = 0; i < _numLibri; ++i) {
        cout << "Libro " << i + 1 << ":" << endl;
        _libri[i].stampa();
        cout << endl;
    }
}


Libro* Libreria::trovaLibroPiuVecchio() const
{
    if (_numLibri == 0)
    {
        return nullptr; // Se la libreria � vuota, restituisce nullptr
    }

    Libro* libroPiuVecchio = &_libri[0]; // Supponiamo il primo libro come il pi� vecchio

    for (int i = 1; i < _numLibri; ++i)
    {
        if (_libri[i].getAnno() < libroPiuVecchio->getAnno())
        {
            libroPiuVecchio = &_libri[i];
        }
    }

    return libroPiuVecchio;
}




int main()
{
    int numLibri;

    cout << "Quanti libri contiene la libreria? ";
    cin >> numLibri;

    Libreria libreria(1); // Creiamo una libreria con ID 1

    for (int i = 0; i < numLibri; ++i)
    {
        char autore[100];
        char titolo[100];
        int anno;

        cout << "Inserisci autore del libro " << i + 1 << ": ";
        cin >> autore;

        cout << "Inserisci titolo del libro " << i + 1 << ": ";
        cin >> titolo;

        cout << "Inserisci anno di stampa del libro " << i + 1 << ": ";
        cin >> anno;

        Libro libro(autore, titolo, anno);
        libreria.inserisciLibro(libro);
    }

    cout << "La libreria contiene " << libreria.getNumLibri() << " libri." << endl;

    // Troviamo e stampiamo il libro pi� vecchio nella libreria
    const Libro* libroPiuVecchio = libreria.trovaLibroPiuVecchio();
    if (libroPiuVecchio != nullptr)
    {
        cout << "Il libro piu vecchio nella libreria e:" << endl;
        cout << "Autore: " << libroPiuVecchio->getAutore() << endl;
        cout << "Titolo: " << libroPiuVecchio->getTitolo() << endl;
        cout << "Anno di stampa: " << libroPiuVecchio->getAnno() << endl;
    }
    else
    {
        cout << "La libreria e vuota." << endl;
    }

    return 0;
}
