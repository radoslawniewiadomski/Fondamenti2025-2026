#include <iostream>    
#include <cstring>     

using namespace std;  

int main()
{
    char s1[256];     // array di caratteri per memorizzare la prima stringa (max 255 + '\0')
    char s2[256];     // array di caratteri per memorizzare la seconda stringa
    char* ps3;        // puntatore che conterrà la stringa risultante dalla concatenazione

    cout << "Inserire due stringhe: ";   
    cin >> s1 >> s2;  // legge due stringhe da tastiera (si fermano allo spazio)

    int dim1 = strlen(s1);  // calcola la lunghezza della prima stringa
    int dim2 = strlen(s2);  // calcola la lunghezza della seconda stringa

    ps3 = new char[dim1+dim2+1]; // allocazione dinamica di memoria
                                 // +1 serve per il carattere di fine stringa '\0'

    if (ps3 == 0) return -1;     // controllo se l'allocazione è fallita

    strcpy(ps3, s1);   // copia la stringa s1 dentro ps3
    strcat(ps3, s2);   // aggiunge (concatena) s2 alla fine di ps3

    cout << "Stringa concatenata: " << ps3 << endl; // stampa la stringa risultante

    delete[] ps3;      // libera la memoria allocata dinamicamente

    return 0;         
}
