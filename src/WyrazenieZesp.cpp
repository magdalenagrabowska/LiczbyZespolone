#include "WyrazenieZesp.hh"
#include "LZespolona.hh"
#include<iostream>
using std::endl;
using std::cout;
using std::cin;
/* 
 * Tu nalezy zdefiniowac funkcje, ktorych zapowiedzi znajduja sie
 * w pliku naglowkowym.
 */
void Wyswietl(WyrazenieZesp  WyrZ){
    cout<<WyrZ.Arg1;
    if(WyrZ.Op==Operator::Op_Dodaj){
       cout<<"+";
        }
    else if(WyrZ.Op==Operator::Op_Odejmij){
       cout<<"-";
        }
    else if(WyrZ.Op==Operator::Op_Mnoz){
        cout<<"*";
        }
    else if(WyrZ.Op==Operator::Op_Dziel){
        cout<<"/";
        }
   cout<<WyrZ.Arg2;
   cout<<endl;
}
std::istream &operator>> (std::istream &strm, WyrazenieZesp &WZ) {
  strm>>WZ.Arg1;
  if(strm.fail())
  return strm;
  WczytajOper();
  strm>>WZ.Arg2;
  if(strm.fail())
  return strm;
}
bool Wczytaj(WyrazenieZesp &WZ){
    cin>>WZ;
    return 1;
}
Operator WczytajOper(){
  char tmp;
  cin>>tmp;
  switch(tmp){
  case '+':{
    return Op_Dodaj;
    break;}
  case '-':{
    return Op_Odejmij;
    break;}
  case '*':{
    return Op_Mnoz;
    break;}
  case '/':{
    return Op_Dziel;
    break;}
  default:{
  cout<<"Nierozpoznane dzialanie"<<endl;
  return Op_Dodaj;  }
  }
}
LZespolona Oblicz(WyrazenieZesp WyrZ){
    LZespolona Wynik;
    switch(WyrZ.Op){
        case Operator::Op_Dodaj:
        {
          Wynik=WyrZ.Arg1+WyrZ.Arg2;
          return Wynik;
          break;
        }
         case Operator::Op_Odejmij:
        {
         Wynik=WyrZ.Arg1-WyrZ.Arg2;
         return Wynik;
         break;
        }
         case Operator::Op_Mnoz:
        {
         Wynik=WyrZ.Arg1*WyrZ.Arg2;
         return Wynik;
         break;
        }
         case Operator::Op_Dziel:
        {
         Wynik=WyrZ.Arg1/WyrZ.Arg2;
         return Wynik;
         break;
        }
        default:
       cout<<"Nierozpoznane dzialanie"<<endl;
        Wynik.re=0;
        Wynik.im=0;
        return Wynik;
        break;
    }
}