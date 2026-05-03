
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

    // overload operatori
    Punto& operator=(const Punto& other);      // assegnazione
    bool operator==(const Punto& other) const; // confronto

    // output stream (friend necessario per accedere ai privati)
    friend std::ostream& operator<<(std::ostream& os, const Punto& p);
};

