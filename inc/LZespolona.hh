#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH
#include<iostream>
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


/*
 * Dalej powinny pojawic sie zapowiedzi definicji przeciazen operatorow
 */

/*przeciazenie operacji na liczbach zespolonych */
LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2);
LZespolona operator - (LZespolona Skl1, LZespolona Skl2);
LZespolona operator * (LZespolona Skl1, LZespolona Skl2);
LZespolona operator / (LZespolona Skl1, LZespolona Skl2);
/*operatory porownania */
bool operator ==(LZespolona Skl1,LZespolona Skl2);
bool operator !=(LZespolona Skl1, LZespolona Skl2);
double dzielnik(LZespolona Skl1, LZespolona Skl2);
/*operacje wejscia-wyjscia */
std::ostream & operator<<(std::ostream &strm, const LZespolona &Z1);
std::istream & operator >>(std::istream &strm, LZespolona &Z1);



#endif
