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
  cout<<"Poprawna odpowiedz"<<endl;
}
void dodaj_zla(Stat &test){
  test.l_odp++;
  cout<<"Zla odpowiedz"<<endl;
}
float policz_dobra(Stat &test){
  float dobre=test.l_dob;
  return dobre;
}
double policz_procent(Stat &test,float policz_dobra){
  double procent=(policz_dobra/test.l_odp)*100;
  return procent;
}
void wyswietl_wynik(float policz_dobra,double policz_procent){
  cout<<"Twoj wynik to: "<<policz_dobra<<" dobrych odpowiedzi"<<endl;
  cout<<"Procentowy wynik dobrych odpowiedzi to: "<<policz_procent<<"%"<<endl;
  cout<<"Milego dnia :)"<<endl;
}
