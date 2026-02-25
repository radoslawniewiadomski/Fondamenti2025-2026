#include <iostream>
using namespace std;

int main() {
    char lettera1, lettera2, lettera3;

    cout << "Inserisci tre lettere: ";
    cin >> lettera1 >> lettera2 >> lettera3;

    // Puntatori
    char* ptr1 = &lettera1;
    char* ptr2 = &lettera2;
    char* ptr3 = &lettera3;

    char* middle;

    // Verifica quale lettera è quella "in mezzo"
    if ( (*ptr1 >= *ptr2 && *ptr1 <= *ptr3) || 
         (*ptr1 >= *ptr3 && *ptr1 <= *ptr2) ) {
        middle = ptr1;
    }
    else if ( (*ptr2 >= *ptr1 && *ptr2 <= *ptr3) || 
              (*ptr2 >= *ptr3 && *ptr2 <= *ptr1) ) {
        middle = ptr2;
    }
    else {
        middle = ptr3;
    }

    cout << "La lettera in mezzo nell'ordine alfabetico è: " 
         << *middle << endl;

    return 0;
}

