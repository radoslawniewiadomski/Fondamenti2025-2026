#include <iostream>
using namespace std;

int main() {

    int a = 3;

    int* p1 = &a;      // p1 contiene l'indirizzo di a

    int** p2 = &p1;    // p2 contiene l'indirizzo di p1

    cout << "p1 (indirizzo di a): " << p1 << ", p2 (indirizzo di p1): " << p2 << endl;

    cout << "*p1 (valore di a): " << *p1 << ", *p2 (contenuto di p1, cioè indirizzo di a): " << *p2 << endl;

    cout << "**p2 (valore di a tramite doppia dereferenziazione): " << **p2 << endl;

    **p2 = 5;   // modifica il valore di a attraverso p2

    cout << "Nuovo valore di a: " << **p2 << endl;

    return 0;
}