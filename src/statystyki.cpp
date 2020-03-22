#include<iostream>
#include "statystyki.hh"
using std::cout;
using std::endl;

void inicjuj_statystyki(Stat &test){
 test.l_odp=0;
 test.l_dob=0;
}
void dodaj_dobra(Stat &test){
  test.l_dob++;
  test.l_odp++;
}
void dodaj_zla(Stat &test){
  test.l_odp++;
}
int ilosc_dobrych(Stat test){
int dobre=test.l_dob;
return dobre;
}
float procent_dobrych(Stat test){
  float procent=(test.l_dob/test.l_odp)*100;
  return procent;
}
void wyswietl_wynik(int ilosc_dobrych,float procent_dobrych){
  cout<<"Twoj wynik to: "<<ilosc_dobrych<<"dobrych odpowiedzi"<<endl;
  cout<<"Procentowy wynik dobrych odpowiedzi to: "<<procent_dobrych<<"%"<<endl;
  cout<<"Milego dnia :)"<<endl;
}
