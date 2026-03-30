#include <iostream>
using namespace std;

template <typename T>
bool eTra(T valore, T minimo, T massimo) {
    return (valore >= minimo && valore <= massimo);
}

int main() {

    cout << eTra(5, 1, 10) << endl;        // true
    cout << eTra(2.5, 3.0, 6.0) << endl;   // false
    cout << eTra('c', 'a', 'f') << endl;   // true

    return 0;
}