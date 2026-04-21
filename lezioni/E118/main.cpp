#include <iostream>
#include <string>

using namespace std;

template <typename T, typename U>
class Coppia {
private:
    T primo;
    U secondo;

public:
    // Costruttore
    Coppia(T p, U s);

    // Metodo stampa
    void stampaCoppia() const;
};

// ===== IMPLEMENTAZIONE =====

template <typename T, typename U>
Coppia<T, U>::Coppia(T p, U s) : primo(p), secondo(s) {}

template <typename T, typename U>
void Coppia<T, U>::stampaCoppia() const {
    cout << "Primo elemento: " << primo
         << ", Secondo elemento: " << secondo << endl;
}

int main() {
    Coppia<int, double> coppia1(10, 3.14);
    coppia1.stampaCoppia();

    Coppia<int, const char*> coppia2(25, "Smith");
    coppia2.stampaCoppia();

    return 0;
}
