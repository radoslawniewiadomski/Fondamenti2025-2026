#include <iostream>
using namespace std;

//Questo codice contiene un errore!!
int main()
{
    int a [] = {1,2,3};
    int b [] = {4,5,6};

    a=b;   //ERRORE - non è permesso di modificare a

    //a++; //ERRORE  - non è permesso di modificare a

    return 0;
}
