#include <iostream>
using namespace std;

struct Film
{

    char titolo [20];
    int durata;
    int anno;
};

void stampaFilm(Film p)
{
    cout << "Titolo: " << p.titolo << endl;
    cout << "Durata: " << p.durata << " minuti" << endl;
    cout<< "Anno: " << p.anno << endl;
}

int main()
{
    Film p;
    cout << "Inserisci il titolo (max 20 char): " ;
    cin >>  p.titolo;
    cout << "Inserisci durata: ";
    cin >> p.durata;
    cout << "Inserisci anno: ";
    cin >> p.anno;
    stampaFilm(p);

    return 0;
}

