#include "LZespolona.hh"
#include<iostream>
using std::cout;
using std::endl;
using std::cin;
int a;
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
/* utworz-tworzy nowa liczbe zespolona zgodnie ze specyfikacja podana
   w mainie */
LZespolona utworz(float a, float b){
  LZespolona Wynik;
  Wynik.re=a;
  Wynik.im=b;
  return Wynik;
}
void WyswietlZ(LZespolona Skl1){
  cout<<"("<<Skl1.re<<std::showpos<<Skl1.im<<std::noshowpos<<"i)";
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
LZespolona operator / (LZespolona Skl1, LZespolona Skl2){
  LZespolona Wynik;
  Wynik.re=(Skl1.re*Skl2.re+Skl1.im*Skl2.im)/(Skl2.re*Skl2.re+Skl2.im*Skl2.im);
  Wynik.im=(Skl1.im*Skl2.re-Skl1.re*Skl2.im)/(Skl2.re*Skl2.re+Skl2.im*Skl2.im);
  return Wynik;
  
}
bool operator ==(LZespolona Skl1,LZespolona Skl2){
if((Skl1.re=Skl2.re)&&(Skl1.im=Skl2.im))
return 1;
else return 0;
}
bool Wczytaj(LZespolona &Z1){
  char znak;
  cout<<"Podaj liczbe zespolona"<<endl;
  cin>>znak;
  if(znak!='(')
    return 0;
  cin>>Z1.re;
  cin>>znak;
  cin>>Z1.im;
  if(znak=='-')
    Z1.im=(-Z1.im);
  cin>>znak;
  if(znak!='i')
    return 0;
  cin>>znak;
  if(znak!=')')
    return 0;
  else  return 1;
}

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
