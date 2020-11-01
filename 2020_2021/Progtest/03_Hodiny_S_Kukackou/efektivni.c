#include <stdio.h>

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

int main(){

  int y1=1600, m1=1, d1=1, h1=0, i1=0,
      y2=4000, m2=12, d2=31, h2=23, i2=59;

  if (validDate(y1, m1, d1, h1, i1, y2, m2, d2, h2, i2) == 1){
    printf("Nespravny vstup.\n");
    return 1;
  };

  if ( (y1==y2) && (m1==m2) && (d1==d2) ){
    printf("Kukani = %d\n", kukaniJedenDen(h1, i1, h2, i2));
  }else {
    printf("Kukani = %d\n", kukaniJedenDen(h1, i1, 23, 59) + kukaniJedenDen(0, 0, h2, i2) + 180*pocetDnuMezi(y1, m1, d1, y2, m2, d2));
  };


  return 0;
}
