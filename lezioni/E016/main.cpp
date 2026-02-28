#include <iostream>
using namespace std;

//ATTENZIONE: FILE CONTIENE UN ERRORE

int main()
{
    char* a;

    cin>>a; // ERRORE: rischio di usare un spazio della memoria non allocato

    cout << a << "Fine";


    /*

    char b[20];

    cin>>b;

    cout << b << "Fine";

    */

    return 0;

}
