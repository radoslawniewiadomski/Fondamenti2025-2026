#include <iostream>
using namespace std;

class Punto
{
    //2 attibuti privati
    double _x;
    double _y;

public:
    //costruttori
    Punto();
    Punto(double x, double y);

    //distruttore
    ~Punto();

    //modificatori
    void setX(double x);
    void setY(double y);

    //selettori
    double getX() const;
    double getY() const;

    //operatori sovracaricati
    Punto& operator++();
    Punto operator++(int);

    //altri metodi
    void stampaPunto() const;
};


//definizione dei metodi

//costruttore "default"
Punto::Punto()
{
    _x = -1;
    _y = -1;
}

//costruttore con dei parametri
Punto::Punto(double x, double y)
{
    _x = x;
    _y = y;
}

void Punto::setX(double x)
{
    _x = x;
}

void Punto::setY(double y)
{
    _y = y;
}

double Punto::getX() const
{
    return _x;
}

double Punto::getY() const
{
    return _y;
}

void Punto::stampaPunto() const
{
    cout << "Coordinate del punto: (" << _x << ", " << _y << ")" << endl;
}

//distruttore che non fa niente utile
Punto::~Punto()
{
    cout << "Sono distruttore" << endl;
}

// incremento prefisso
Punto& Punto::operator++()
{
    _x += 1.0;
    _y += 1.0;
    return *this;
}

// incremento postfisso
Punto Punto::operator++(int)
{
    Punto temp(*this);
    _x += 1.0;
    _y += 1.0;
    return temp;
}

int main()
{
    Punto p(3.0, 2.0);

    cout<<"\n punto p: ";
    p.stampaPunto();

    Punto q = p++;

    cout<<"\n punto p: ";
    p.stampaPunto();

    cout<<"\n punto q: ";
    q.stampaPunto();

    Punto r = ++p;
    cout<<"\n punto p: ";

    p.stampaPunto();

    cout<<"\n punto r: ";
    r.stampaPunto();

    return 0;
}
