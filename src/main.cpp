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

  Stat test;
  WyrazenieZesp   WyrZ_PytanieTestowe;
  LZespolona Wynik_Poprawny;
  LZespolona Wynik_Podany;
  int dobre;
  float procent;

   cout<<"Witaj na sprawdzianie z liczb zespolonych"<<endl;
   inicjuj_statystyki(test);
  while (PobierzNastpnePytanie(&BazaT,&WyrZ_PytanieTestowe)==1) {
    cout<<"Oto twoje zadanie:"<<endl;
    Wyswietl(WyrZ_PytanieTestowe);
    Oblicz(WyrZ_PytanieTestowe)=Wynik_Poprawny;
    if (Wczytaj(Wynik_Podany)==0)
    for(int i=1;i<3;i++){ 
    cout<<"Blad! Prosze wprowadzic liczbe ponownie"<<endl;
    if (Wczytaj(Wynik_Podany)==0)
    continue;
    else break;
    }
   if ((Wynik_Podany==Wynik_Poprawny)==0){
    cout<<"Bledny wynik :("<<endl;
    dodaj_zla(test);
    }
    else if((Wynik_Podany==Wynik_Poprawny)==1){
    cout<<"Poprawny wynik :)"<<endl;
    dodaj_dobra(test);
    }

  }
  dobre=ilosc_dobrych(test);
  procent=procent_dobrych(test);
  wyswietl_wynik(dobre,procent);
  cout << endl;
  cout << " Koniec testu" << endl;
  cout << endl;

}

