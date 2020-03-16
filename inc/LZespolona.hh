#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH

/*!
 *  Plik zawiera definicje struktury LZesplona oraz zapowiedzi
 *  przeciazen operatorow arytmetycznych dzialajacych na tej 
 *  strukturze.
 */


/*!
 * Modeluje pojecie liczby zespolonej
 */
struct  LZespolona {
  double   re;    /*! Pole repezentuje czesc rzeczywista. */
  double   im;    /*! Pole repezentuje czesc urojona. */
};
struct Stat{ /*pole potrzebne do stworzenia wynikow i statystyk */
int l_odp;
int l_dob;
};

/*
 * Dalej powinny pojawic sie zapowiedzi definicji przeciazen operatorow
 */


LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2);
LZespolona operator - (LZespolona Skl1, LZespolona Skl2);
LZespolona operator * (LZespolona Skl1, LZespolona Skl2);
LZespolona operator / (LZespolona Skl1, LZespolona Skl2);
bool operator ==(LZespolona Skl1,LZespolona Skl2);
/*operacje wejscia-wyjscia */
bool Wczytaj(LZespolona &Z1);
LZespolona utworz(float a, float b);
void WyswietlZ (LZespolona Skl1);
/* operacje statystyk */
void inicjuj_statystyki(Stat &test);
void dodaj_dobra(Stat &test);
void dodaj_zla(Stat &test);
int ilosc_dobrych(Stat test);
float procent_dobrych(Stat test);
void wyswietl_wynik(int ilosc_dobrych,float procent_dobrych);
#endif
