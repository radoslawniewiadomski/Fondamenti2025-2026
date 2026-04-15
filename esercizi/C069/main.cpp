class ContoBancario {

 char* _intestatario;
 int _numeroConto;
 float _saldo;
 
 public:

 ContoBancario();
 ContoBancario(const  char* intestatario, int numeroConto, float saldo);
 ContoBancario( const ContoBancario &altro);

 ~ContoBancario(); 

 void setIntestatario(const char* intestatario);
 void setNumeroConto(int numeroConto); 
 void setSaldo(float saldo);

  char* getIntestatario()  const;
  int getNumeroConto()  const;
  float getSaldo() const;

  void trasferisci(float importo, float commissione=1.0);
  void applicaInteresse (float percentuale=2.0);
 
 void stampa();

};


////////////////////////////////////////

ContoBancario::ContoBancario(){
     _intestatario = nullptr;
     _numeroConto = 0;
     _saldo = 0.0;


}


 ContoBancario::ContoBancario(const char* intestatario, int numeroConto, float saldo){

     if(intestatario) {
        int temp = strlen(intestatario);
        _intestatario = new char [temp+1];
        strcpy(_intestatario, intestatario);
     }
 

     _numeroConto = numeroConto;
     _saldo = saldo;

 }


  ContoBancario::ContoBancario( const ContoBancario &altro){

     _numeroConto = altro._numeroConto;
     _saldo = altro._saldo;

     if( altro._intestatario) {
        int temp = strlen(altro._intestatario);
        _intestatario = new char [temp+1];
        strcpy(_intestatario, altro._intestatario);
     }

  }

   ContoBancario::~ContoBancario(){

        delete [] _intestatario;
   }


    void ContoBancario::setIntestatario(const char* intestatario){

    if(_intestatario) delete [] _intestatario;

    if(intestatario) {
        int temp = strlen(intestatario);
        _intestatario = new char [temp+1];
        strcpy(_intestatario, intestatario);
     }

    }
    
    void ContoBancario::setNumeroConto(int numeroConto){
             _numeroConto = numeroConto;
        }

    //Il saldo non può essere negativo
    void ContoBancario::setSaldo(float saldo){ 
        if (saldo>=0)
        _saldo = saldo;
        else {
            cout<<"Il saldo non puo essere negativo!"<<endl;
        }
    }


  char* ContoBancario::getIntestatario()  const { return _intestatario;}
  int ContoBancario::getNumeroConto()  const {return _numeroConto; }
  float ContoBancario::getSaldo() const {return _saldo; }

void ContoBancario::trasferisci(float importo, float commissione){

    float totale = importo + commissione;

    if(_saldo>=totale){
        _saldo =_saldo-totale;
    }
    else{
        cout<<"Il saldo non puo essere negativo!"<<endl;
    }
  }

  void ContoBancario::applicaInteresse (float percentuale){
    _saldo += _saldo*percentuale/100.0;

  }

void ContoBancario::stampa(){

cout<<"Nome: "<<_intestatario<<endl;
cout<<"Saldo: "<<_saldo<<endl;


}


int main() {
    ContoBancario conto("Mario Rossi", 12345, 1000.0f);

    // uso con parametro default
    conto.trasferisci(100);

    // uso con entrambi i parametri
    conto.trasferisci(50, 5.0f);

    // interesse default
    conto.applicaInteresse();

    cout << "\n--- DATI FINALI ---" << endl;
    conto.stampa();

    return 0;
}