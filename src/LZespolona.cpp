#include "LZespolona.hh"
#include<iostream>
using std::cout;
using std::endl;
using std::cin;

/*!
 * Realizuje dodanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dodawania,
 *    Skl2 - drugi skladnik dodawania.
 * Zwraca:
 *    Sume dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re + Skl2.re;
  Wynik.im = Skl1.im + Skl2.im;
  return Wynik;
}

LZespolona operator - (LZespolona Skl1,LZespolona Skl2){
  LZespolona Wynik;
  Wynik.re=Skl1.re-Skl2.re;
  Wynik.im=Skl1.im-Skl2.im;
  return Wynik;
}

LZespolona operator * (LZespolona Skl1, LZespolona Skl2){
  LZespolona Wynik;
  Wynik.re=(Skl1.re*Skl2.re)-(Skl1.im*Skl2.im);
  Wynik.im=(Skl1.re*Skl2.im)+(Skl1.im*Skl2.re);
  return Wynik;
}
double dzielnik(LZespolona Skl1, LZespolona Skl2){
  double a;
  a=Skl2.re*Skl2.re+Skl2.im*Skl2.im;
  return a;
}

LZespolona operator / (LZespolona Skl1, LZespolona Skl2){
  LZespolona Wynik;
  double a;
  a=dzielnik(Skl1,Skl2);
  Wynik.re=(Skl1.re*Skl2.re+Skl1.im*Skl2.im)/a;
  Wynik.im=(Skl1.im*Skl2.re-Skl1.re*Skl2.im)/a;
  return Wynik;
  
}
bool operator ==(LZespolona Skl1,LZespolona Skl2){
if((Skl1.re==Skl2.re)&&(Skl1.im==Skl2.im))
return true;
else return false;
}

bool operator !=(LZespolona Skl1, LZespolona Skl2){
  if (Skl1==Skl2)
  return false;
  else return true;
} 
std::ostream & operator<< (std::ostream &strm, const LZespolona &Z1){
  
 strm<<"("<<Z1.re<<std::showpos<<Z1.im<<std::noshowpos<<"i)";
 return strm;
}

std::istream & operator>> (std::istream &strm, LZespolona &Z1){
  char znak;
 strm>>znak;
  if(znak!='(')
    strm.setstate(std::ios::failbit);
 strm>>Z1.re;
 strm>>znak;
 strm>>Z1.im;
 if(znak=='-')
    Z1.im=(-Z1.im);
 strm>>znak;
  if(znak!='i')
    strm.setstate(std::ios::failbit);
 strm>>znak;
  if(znak!=')')
    strm.setstate(std::ios::failbit);
  return strm;
}
