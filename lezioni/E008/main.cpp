#include <iostream>
using namespace std;

int main()
{
    int a = 100;
    cout << "L'indirizzo di a: " << &a << endl; // vedo quale indirizzo di memoria viene utlizzato

    // Inserisco l'indirizzo, che ho stampato nell'esecuzione precedente, sperando che sia lo stesso
    int* px = (int*)0x5ffe74;

    cout << "px contiene: " << px << endl;

    //l'indirizzo in hex
    cout << "Il valore contenuto nella locazione di memoria puntata da px: " << *px << endl;

    //pero se ci spostiamo di qualche bit nella memoria
    px = (int*)0x5ffe78;

    cout << "px contiene: " << px << endl;

    //il valore è casuale, puo essere pericoloso di stampare un valore una cella di memoria a caso, il programma si puo fermare!
        cout << "Il valore contenuto nella locazione di memoria puntata da px: " << *px << endl;

    return 0;
}
