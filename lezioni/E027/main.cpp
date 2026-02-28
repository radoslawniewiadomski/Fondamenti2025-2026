#include <iostream>
using namespace std;


//funzione aggiunge 1 a ogni elemento di un array


//versione "array" - primo semestre

void add1(int a [], int size) {
    for (int i=0; i<size; i++)
        a[i] +=1;
}


//versione "array" - indice è un puntatore
/*
void add1(int a [], int size)
{
    for (int* pi=a; pi<a+size; pi++)
        (*pi)+=1;
}
*/


//solo puntatori
/*
void add1(int* a, int size)
{
    for (int* pi=a; pi<a+size; pi++)
        (*pi)+=1;
}
*/

int main()
{

    int s[] = {1,2,3,4,5};
    add1(s,5);

    for (int i=0; i<5; i++)
        cout << s[i]<< ", ";
    return 0;
}
