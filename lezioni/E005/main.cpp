#include <iostream>

using namespace std;

int main()
{

    int x = 10;

    int* px = &x;

    cout << x << endl;// stampa 10

    cout << px << endl;// stampa un indirizzo

    cout << &px << endl;// stampa un altro indirizzo

    return 0;
}
