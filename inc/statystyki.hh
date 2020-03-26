#ifndef STATYSTYKI_HH
#define STATYSTYKI_HH


struct Stat{ /*pole potrzebne do stworzenia wynikow i statystyk */
int l_odp;
int l_dob;
};

void inicjuj_statystyki(Stat &test);
void dodaj_dobra(Stat &test);
void dodaj_zla(Stat &test);
float policz_dobra(Stat &test);
double policz_procent(Stat &test,float policz_dobra);
void wyswietl_wynik(float policz_dobra,double policz_procent);
#endif
