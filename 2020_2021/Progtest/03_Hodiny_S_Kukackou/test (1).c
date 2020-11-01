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

int kukaniJedenDen(int h1, int min1, int h2, int min2){       /* ====== Pocet kukani v jeden den ====== */

  int kukani = 0, i;

  while (h1 <= h2){
      if (h1 == h2){
        for (i=min1; i <= min2; i++){
            if (i == 0){
                      if (h1 > 12){
                        kukani += (h1 - 12);
                      };
                      if (h1 <= 12){
                        kukani += (h1);
                      };
                      if (h1 == 0){
                        kukani += 12;
                      };
            };
            if (i == 30){
              kukani += 1;
            };
          };
          break;
      };
      for (i=min1; i < 59; i++){
        if (i == 0){
                  if (h1 > 12){
                    kukani += (h1 - 12);
                  };
                  if (h1 <= 12){
                    kukani += (h1);
                  };
                  if (h1 == 0){
                    kukani += 12;
                  };
        };
        if (i == 30){
          kukani += 1;
        };
      };
      min1 = 0;
      h1++;
  };
  return kukani;
}

int pocetDnuMezi(int y1, int m1, int d1, int y2, int m2, int d2){

  int pocet = 0, same = 0;

  if ( (y1==y2) && (m1==m2) && (d1==d2) ){
    return pocet;
  };
  while ( same == 0 ){
      int pocetDnu[] = {31, unor(y1), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

      if ( d1 < (pocetDnu[m1-1]) ){
        d1 = d1 + 1;
      }else if ( (m1 == 12) && (d1 == 31) ){
        y1 = y1 + 1;
        m1 = 1;
        d1 = 1;
      }else if ( d1 == pocetDnu[m1 - 1] ){
        m1 = m1 + 1;
        d1 = 1;
      };

      if ( (y1==y2) && (m1==m2) && (d1==d2) ){
        same = 1;
        break;
      };
      pocet++;
  };
  return pocet;
}

int kukaniRoky(int y1, int y2){

  int kukaniRok = 0;
  int start = y1 + 1;

  while (start != y2){
    if (prestupnyRok(start) == 1){
      kukaniRok += 65880;
    }else {
      kukaniRok += 65700;
    };
    start++;
  };
  return kukaniRok;
}

int doba(int y1, int m1, int d1, int h1, int i1, int y2, int m2, int d2, int h2, int i2){

  int dny1;
  if ((m1==1) && (d1==1)){
    dny1 = 0;
  }else {
    dny1 = (pocetDnuMezi(y1, 1, 1, y1, m1, d1) + 1) * 24 * 60;
  };

  int dny2;
  if ((m2==1) && (d2==1)){
    dny2 = 0;
  }else {
    dny2 = (pocetDnuMezi(y2, 1, 1, y2, m2, d2) + 1) * 24 * 60;
  };

  int doba1 = y1 + dny1 + (h1 * 60) + i1;
  int doba2 = y2 + dny2 + (h2 * 60) + i2;
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
  if ( (y1==y2) && (m1==m2) && (d1==d2) ){
    * cuckoo = (long long int)( kukaniJedenDen(h1, i1, h2, i2) ) ;
    return 1;
  }else if ( (y1==y2) || (y1==y2-1) ){
    * cuckoo = (long long int)( kukaniJedenDen(h1, i1, 23, 59) + kukaniJedenDen(0, 0, h2, i2) + 180*pocetDnuMezi(y1, m1, d1, y2, m2, d2) );
    return 1;
  }else {
    * cuckoo = (long long int)( 180*( pocetDnuMezi(y1, m1, d1, y1, 12, 31) + 1 ) + 180*( pocetDnuMezi(y2, 1, 1, y2, m2, d2) + 1 ) + kukaniRoky(y1, y2) 
                                + kukaniJedenDen(h1, i1, 23, 59) + kukaniJedenDen(0, 0, h2, i2));
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
