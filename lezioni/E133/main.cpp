#include <iostream>
using namespace std;

template <typename T>
class Esame {
private:
    double scritto;
    double orale;

public:
    // Dichiarazioni
    Esame(double s, double o);
    double votoFinale() const;
};

// ===== DEFINIZIONI =====

template <typename T>
Esame<T>::Esame(double s, double o) : scritto(s), orale(o) {}

template <typename T>
double Esame<T>::votoFinale() const {
    return T::calcola(scritto, orale);
}

class MediaSemplice {
public:
    static double calcola(double a, double b) {
        return (a + b) / 2.0;
    }
};

class MediaPesata {
public:
    static double calcola(double a, double b) {
        return a * 0.7 + b * 0.3;
    }
};



int main() {
    Esame<MediaSemplice> e1(24, 28);
    Esame<MediaPesata> e2(24, 28);

    cout << e1.votoFinale() << endl;
    cout << e2.votoFinale() << endl;
}