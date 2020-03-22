#ifndef STATYSTYKI_HH
#define STATYSTYKI_HH


struct Stat{ /*pole potrzebne do stworzenia wynikow i statystyk */
int l_odp;
int l_dob;
};

void inicjuj_statystyki(Stat &test);
void dodaj_dobra(Stat &test);
void dodaj_zla(Stat &test);
int ilosc_dobrych(Stat test);
float procent_dobrych(Stat test);
void wyswietl_wynik(int ilosc_dobrych,float procent_dobrych);
#endif
