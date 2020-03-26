#include <iostream>
#include "BazaTestu.hh"
#include "LZespolona.hh"
#include "WyrazenieZesp.hh"
#include "statystyki.hh"

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
  LZespolona Wynik_Podany;
  LZespolona Wynik_Poprawny;
  Stat test;
  float dobre;
  double procent;
   cout<<"Witaj na sprawdzianie z liczb zespolonych"<<endl;
    
  inicjuj_statystyki(test);
  
   while (PobierzNastpnePytanie(&BazaT,&WyrZ_PytanieTestowe)==1) {
    cout<<"Oto twe zadanie:"<<endl;
    cout<<WyrZ_PytanieTestowe;
    Wynik_Poprawny=Oblicz(WyrZ_PytanieTestowe);
    cout<<"Podaj poprawna odpowiedz"<<endl;
    for(int i=0;i<3;i++){
    cin>>Wynik_Podany;
    if(cin.fail()){
       cout<<"Blad. Podaj odpowiedz ponownie"<<endl;
       cin.clear();
       cin.ignore(1000, '\n');
    } 
    else break;
    }
    if(Wynik_Podany==Wynik_Poprawny)
      dodaj_dobra(test);
    else if(Wynik_Podany!=Wynik_Poprawny) 
      dodaj_zla(test);
  }
  dobre=policz_dobra(test);
  procent=policz_procent(test,dobre);
  wyswietl_wynik(dobre,procent);
  cout << endl;
  cout << " Koniec testu" << endl;
  cout << endl;

}

