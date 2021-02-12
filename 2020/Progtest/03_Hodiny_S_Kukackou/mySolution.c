#ifndef __PROGTEST__
#include <stdio.h>
#include <assert.h>
#endif /* __PROGTEST__ */

int prestupnyRok(int year){             /* ====== Prestupny rok ====== */

    if ( (year % 4 == 0) && (year % 100 == 0) && (year % 400 == 0) && (year % 4000 == 0) ){
      return 0;
    };
    if ( (year % 4 == 0) && (year % 100 == 0) && (year % 400 == 0) ){
      return 1;
    };
    if ( (year % 4 == 0) && (year % 100 == 0) ){
      return 0;
    };
    if ( (year % 4 == 0) ){
      return 1;                       /* 0 = neprestup ; 1 = prestup */
    };
  return 0;
}

int unor(int year){
  if (prestupnyRok(year)==1){
    return 29;
  }
  return 28;
}

int zakukej(int h){
  int zakuka = 0;
  if (h == 0){
    zakuka += 12;
    return zakuka;
  };
  if (h <= 12){
    zakuka += h;
  }else {
    zakuka += h - 12;
  };
  return zakuka;
}

int kukani(int y, int m, int d, int h, int i){

  int kukani = 0, pocatekRoku = 1600, pocatekMesice = 1, pocatekDne = 1, pocatekHodiny = 0/*, pocatekMinuty = 0*/;
  int year[] = {31, unor(y), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  while (pocatekRoku < y){
    if ( prestupnyRok(pocatekRoku) == 1 ){
      kukani += 65880;
    }else {
      kukani += 65700;
    };
    pocatekRoku++;
  };

  while ( pocatekMesice < m ){
    kukani += 180*year[pocatekMesice-1];
    pocatekMesice++;
  };

  while ( pocatekDne < d ){
    kukani += 180;
    pocatekDne++;
  };

  while ( pocatekHodiny < h ){
    kukani += zakukej(pocatekHodiny) + 1;
    pocatekHodiny++;
  };

  if ( (i >= 0) && (i < 30) ){
    kukani += zakukej(h);
  }else if (i >= 30){
    kukani += zakukej(h) + 1;
  };

  return kukani;
}


int doba(int y1, int m1, int d1, int h1, int i1, int y2, int m2, int d2, int h2, int i2){

  int pocatekMesice = 1, mesic1 = 0, mesic2 = 0;

  int year1[] = {31, unor(y1), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int year2[] = {31, unor(y2), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  while (pocatekMesice < m1){
    mesic1 += year1[pocatekMesice - 1] * 24 * 60;
    pocatekMesice++;
  };

  pocatekMesice = 1;

  while (pocatekMesice < m2){
    mesic2 += year2[pocatekMesice - 1] * 24 * 60;
    pocatekMesice++;
  };

  int pocatekRoku = 1600, rok1 = 0, rok2 = 0;

  while (pocatekRoku < y1){
    if (prestupnyRok(pocatekRoku) == 1){
      rok1 += 366 * 24 * 60;
    }else {
      rok1 += 365 * 24 * 60;
    };
    pocatekRoku++;
  };

  pocatekRoku = 1600;

  while (pocatekRoku < y2){
    if (prestupnyRok(pocatekRoku) == 1){
      rok2 += 366 * 24 * 60;
    }else {
      rok2 += 365 * 24 * 60;
    };
    pocatekRoku++;
  };

  int doba1 = rok1 + mesic1 + (d1*24*60) + (h1 * 60) + i1;
  int doba2 = rok2 + mesic2 + (d2*24*60) + (h2 * 60) + i2;
  int doba = doba2 - doba1;
  return doba;
}

int validDate(int y1, int m1, int d1, int h1, int i1, int y2, int m2, int d2, int h2, int i2){
  int year1[] = {31, unor(y1), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int year2[] = {31, unor(y2), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  if (  (y1 < 1600) || (y2 < 1600) || (m1 < 1) || (m1 > 12) || (m2 < 1) || (m2 > 12)
        || (d1 < 1) || (d1 > year1[m1-1]) || (d2 < 1) || (d2 > year2[m2-1])
        || (h1 < 0) || (h1 > 23) || (h2 < 0) || (h2 > 23) || (i1 < 0) || (i1 > 59)
        || (i2 < 0) || (i2 > 59)){
    return 1;
  };

  if (doba(y1, m1, d1, h1, i1, y2, m2, d2, h2, i2) < 0){
    return 1;
  };

  return 0;
}

int cuckooClock ( int y1, int m1, int d1, int h1, int i1,
                  int y2, int m2, int d2, int h2, int i2, long long int * cuckoo )
{

  if (validDate(y1, m1, d1, h1, i1, y2, m2, d2, h2, i2) == 1){
    return 0;
  };

  if ( (y1==y2) && (m1==m2) && (d1==d2) && (h1==h2) && (i1==i2) && (i1==0) ){
    * cuckoo = (long long int)(zakukej(h1));
    return 1;
  }else if ( (y1==y2) && (m1==m2) && (d1==d2) && (h1==h2) && (i1==i2) && (i1==30) ){
    * cuckoo = 1;
    return 1;
  }else if (i1 == 0){
    * cuckoo = (long long int)( kukani(y2, m2, d2, h2, i2) - kukani(y1, m1, d1, h1, i1) + zakukej(h1) );
    return 1;
  }else if (i1 == 30){
    * cuckoo = (long long int)( kukani(y2, m2, d2, h2, i2) - kukani(y1, m1, d1, h1, i1) + 1 );
    return 1;
  }else {
    * cuckoo = (long long int)( kukani(y2, m2, d2, h2, i2) - kukani(y1, m1, d1, h1, i1) );
    return 1;
  };
  return 0;
}



#ifndef __PROGTEST__
int main ( int argc, char * argv [] )
{
  long long int cuckoo;

  assert ( cuckooClock ( 2013, 10,  1, 13, 15,
                         2013, 10,  1, 18, 45, &cuckoo ) == 1 && cuckoo == 26 );
  assert ( cuckooClock ( 2013, 10,  1, 13, 15,
                         2013, 10,  2, 11, 20, &cuckoo ) == 1 && cuckoo == 165 );
  assert ( cuckooClock ( 2013,  1,  1, 13, 15,
                         2013, 10,  5, 11, 20, &cuckoo ) == 1 && cuckoo == 49845 );
  assert ( cuckooClock ( 2012,  1,  1, 13, 15,
                         2012, 10,  5, 11, 20, &cuckoo ) == 1 && cuckoo == 50025 );
  assert ( cuckooClock ( 1900,  1,  1, 13, 15,
                         1900, 10,  5, 11, 20, &cuckoo ) == 1 && cuckoo == 49845 );
  assert ( cuckooClock ( 2013, 10,  1,  0,  0,
                         2013, 10,  1, 12,  0, &cuckoo ) == 1 && cuckoo == 102 );
  assert ( cuckooClock ( 2013, 10,  1,  0, 15,
                         2013, 10,  1,  0, 25, &cuckoo ) == 1 && cuckoo == 0 );
  assert ( cuckooClock ( 2013, 10,  1, 12,  0,
                         2013, 10,  1, 12,  0, &cuckoo ) == 1 && cuckoo == 12 );
  assert ( cuckooClock ( 2013, 11,  1, 12,  0,
                         2013, 10,  1, 12,  0, &cuckoo ) == 0 );
  assert ( cuckooClock ( 2013, 10, 32, 12,  0,
                         2013, 11, 10, 12,  0, &cuckoo ) == 0 );
  assert ( cuckooClock ( 2100,  2, 29, 12,  0,
                         2100,  2, 29, 12,  0, &cuckoo ) == 0 );
  assert ( cuckooClock ( 2400,  2, 29, 12,  0,
                         2400,  2, 29, 12,  0, &cuckoo ) == 1 && cuckoo == 12 );

  return 0;
}
#endif /* __PROGTEST__ */
