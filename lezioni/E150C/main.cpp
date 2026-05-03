#include <iostream>
using namespace std;

#include "List.h"
int main()
{
    List<int> l; // dichiarazione di oggetto lista

    // inserimento di nodi
   cout<<"Inserimento di nodi"<<endl; 

    l.insertFront(10);
    l.insertFront(20);
    l.insertBack(120);
    l.insertAfter(l.find(20), 500);
    l.print(); // stampa: 20, 500, 10, 120

   cout<<"\nRimozione di nodi"<<endl; 

  // rimozione di nodi
	l.removeAt(l.find(20));
	l.print(); // stampa: 10

  l.removeFront();
	l.print(); // stampa: 10

  l.removeBack();
	l.print(); // stampa: 10

  return 0;	// distruzione della lista
}
