#include "WyrazenieZesp.hh"
#include "LZespolona.hh"
#include<iostream>
using std::cout;
using std::endl;
using std::cin;
/*
 * Tu nalezy zdefiniowac funkcje, ktorych zapowiedzi znajduja sie
 * w pliku naglowkowym.
 */
void Wyswietl(WyrazenieZesp  WyrZ){
    WyswietlZ(WyrZ.Arg1);
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
   WyswietlZ(WyrZ.Arg2);
   cout<<endl;
}
LZespolona Oblicz(WyrazenieZesp  WyrZ){
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