#include <iostream>
using namespace std;

int main()
{
    int a =4;
    int b =8;

    int* pa=&a;
    
    cout<<"Il valore a cui punta pa "<<*pa<<endl;
    pa++; 

    cout<<"Il nuovo valore a cui punta pa "<<*pa << ", "; //Attenzione - il valore è diverso da 8!

    cout << &a << ", "<< &b;
    
    return 0;
}
