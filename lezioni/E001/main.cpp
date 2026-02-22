#include <iostream>
using namespace std;

int main()

{
    int x = 1;
    int& y = x;	// y è un riferimento a x

    cout << "Stampo il valore di x: " << x << endl;	// stampa 1
    cout << "Stampo il valore di y: " << y << endl;	// stampa 1

    x++;
    cout << "Stampo il valore di x: " << x << endl;	// stampa 2
    cout << "Stampo il valore di y: " << y << endl;	// stampa 2

    y++;
    cout << "Stampo il valore di x: " << x << endl;	// stampa 3
    cout << "Stampo il valore di y: " << y << endl;	// stampa 3

    return 0;
}
