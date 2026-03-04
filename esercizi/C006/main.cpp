#include <iostream>
using namespace std;


int main() {
    int a, b, c;

    // Input dei tre numeri
    cout << "Inserisci tre numeri: ";
   
    cin >> a >> b >> c;
    cout << a << ", "<< b << ", "<< c << endl;

    // Riferimento al massimo
    int& max = (a > b) ? (a > c ? a : c) : (b > c ? b : c);

    // Stampa del massimo valore
    cout << "Il numero massimo e: " << max << endl;

    max++;
    cout << a << ", "<< b << ", "<< c << endl;

    return 0;
}

