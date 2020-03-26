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
std::ostream & operator<< (std::ostream &strm, const WyrazenieZesp &Z1){
    strm<<Z1.Arg1;
    if(strm.fail())
    return strm;
    if(Z1.Op==Operator::Op_Dodaj){
       strm<<"+";
        }
    else if(Z1.Op==Operator::Op_Odejmij){
       strm<<"-";
        }
    else if(Z1.Op==Operator::Op_Mnoz){
        strm<<"*";
        }
    else if(Z1.Op==Operator::Op_Dziel){
        strm<<"/";
        }
      if (strm.fail())
      return strm;
   strm<<Z1.Arg2;
   if(strm.fail())
   return strm;
   strm<<endl;
}

std::istream &operator>> (std::istream &strm, WyrazenieZesp &WZ) {
  strm>>WZ.Arg1;
  if(strm.fail())
  return strm;
  strm>>WZ.Op;
  if(strm.fail())
  return strm;
  strm>>WZ.Arg2;
  if(strm.fail())
 return strm;
}
std::istream &operator>> (std::istream &strm, Operator &Op){
  char tmp;
  strm>>tmp;
  switch(tmp){
  case '+':{
    Op=Op_Dodaj;
    break;}
  case '-':{
    Op=Op_Odejmij;
    break;}
  case '*':{
    Op=Op_Mnoz;
    break;}
  case '/':{
    Op=Op_Dziel;
    break;}
  default:{
  strm.setstate(std::ios::failbit);  
  }
  }
 return strm;
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