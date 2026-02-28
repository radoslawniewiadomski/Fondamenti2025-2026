#include <iostream>
using namespace std;

//Attenzione: questo programma si compila ma contiene un errore logico
int main() {
   int* p [3];

   for (int i=0;i < 3; i++){
     
     int temp;// questa variabile locale viene distrutta e ricreata ogni iterazione
     
     //cout<<"indirizzo di temp: "<<&temp<<endl;
     cin >> temp;
     p[i] = &temp;
 }

   for (int i=0;i < 3; i++){
        cout << *p[i];
   }

   cout<<endl;

   for (int i=0;i < 3; i++){
        cout << p[i]<<", ";
   }

   cout<<endl;

}
