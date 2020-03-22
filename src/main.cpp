#include <iostream>
#include "BazaTestu.hh"
#include "LZespolona.hh"
#include "WyrazenieZesp.hh"

using namespace std;



int main(int argc, char **argv)
{

  if (argc < 2) {
    cout << endl;
    cout << " Brak opcji okreslajacej rodzaj testu." << endl;
    cout << " Dopuszczalne nazwy to:  latwy, trudny." << endl;
    cout << endl;
    return 1;
  }


  BazaTestu   BazaT = { nullptr, 0, 0 };

  if (InicjalizujTest(&BazaT,argv[1]) == false) {
    cerr << " Inicjalizacja testu nie powiodla sie." << endl;
    return 1;
  }


  
  cout << endl;
  cout << " Start testu arytmetyki zespolonej: " << argv[1] << endl;
  cout << endl;

  
  WyrazenieZesp   WyrZ_PytanieTestowe;
  LZespolona Wynik;

   cout<<"Witaj na sprawdzianie z liczb zespolonych"<<endl;
    
    
   while (PobierzNastpnePytanie(&BazaT,&WyrZ_PytanieTestowe)==1) {
   cout<<"Oto twe zadanie:"<<endl;
    if(Wczytaj(WyrZ_PytanieTestowe)==1){
    cout<<Oblicz(WyrZ_PytanieTestowe);
    }
    else{
    cout<<"Jakis nieprzewidziany blad sie wkradl :("<<endl;
    cin.clear();
    cin.ignore(1000, '\n');
    }
  }
 
  cout << endl;
  cout << " Koniec testu" << endl;
  cout << endl;

}

