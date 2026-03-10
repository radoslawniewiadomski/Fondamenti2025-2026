#include <iostream>
using namespace std;

struct film
{
    int id;
    char* titolo;
    int durata;
    int anno;
};

int main()
{
    int n_film;
    cout << "Quanti film vuoi inserire? ";
    cin >> n_film;

    film** films = new film*[n_film];

    for (int i = 0; i < n_film; ++i)
    {
        films[i] = new film;

        films[i]->id = i + 1;

        int n;
        cout << "Quanto e' lungo il titolo del film " << i + 1 << "? ";
        cin >> n;

        films[i]->titolo = new char[n + 1];   // +1 per '\0'

        cout << "Inserisci il titolo del film " << i + 1 << ": ";
        cin >> films[i]->titolo;

        cout << "Inserisci durata (in minuti) del film " << i + 1 << ": ";
        cin >> films[i]->durata;

        cout << "Inserisci l'anno di produzione del film " << i + 1 << ": ";
        cin >> films[i]->anno;
    }

    cout << endl << "Lista dei film:" << endl;

    for (int i = 0; i < n_film; ++i)
    {
        cout << "\nFilm " << i + 1 << ":" << endl;
        cout << "Titolo: " << films[i]->titolo << endl;
        cout << "Durata: " << films[i]->durata << " minuti" << endl;
        cout << "Anno: " << films[i]->anno << endl;
    }

    int scelta;
    cout << "\nVuoi cambiare il titolo di un film? ";
    cout << "(Scegli un numero da 1 a " << n_film << ", oppure 0 per uscire): ";
    cin >> scelta;

    if (scelta == 0)
    {
        cout << "Uscita dal programma..." << endl;
    }
    else if (scelta >= 1 && scelta <= n_film)
    {
        int nuovo_n;
        cout << "Inserisci la nuova lunghezza del titolo del film " << scelta << ": ";
        cin >> nuovo_n;

        delete[] films[scelta - 1]->titolo;

        films[scelta - 1]->titolo = new char[nuovo_n + 1];

        cout << "Inserisci il nuovo titolo del film " << scelta << ": ";
        cin >> films[scelta - 1]->titolo;

        cout << endl << "Lista aggiornata dei film:" << endl;

        for (int i = 0; i < n_film; ++i)
        {
            cout << "\nFilm " << i + 1 << ":" << endl;
            cout << "Titolo: " << films[i]->titolo << endl;
            cout << "Durata: " << films[i]->durata << " minuti" << endl;
            cout << "Anno: " << films[i]->anno << endl;
        }
    }
    else
    {
        cout << "Scelta non valida!" << endl;
    }

    for (int i = 0; i < n_film; ++i)
    {
        delete[] films[i]->titolo;
        delete films[i];
    }

    delete[] films;

    return 0;
}