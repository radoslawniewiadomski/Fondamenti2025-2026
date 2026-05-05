#include <iostream>
using namespace std;

#include "List.h"
#include "Punto.h"

int main()
{
    
  /*
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

 
*/

    List<Punto> l2; // dichiarazione di oggetto lista
    // inserimento di nodi
    l2.insertFront(Punto(10,10));
    l2.insertFront(Punto(20,20));
    l2.insertBack(Punto(120,120));
    l2.insertAfter(l2.find(Punto(20,20)),Punto(500,500));

    l2.print(); // stampa i 4 punti

   l2.removeFront();

   l2.removeBack();
  	l2.print(); // stampa: 10

    return 0;	// distruzione della lista
}
