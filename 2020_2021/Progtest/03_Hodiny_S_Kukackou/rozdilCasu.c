#include <stdio.h>




/* ====== Funkce na zjisteni prestupneho roku ====== */

int prestupnyRok(int year){

  int prestup=0;  /* 0 = neprestup ; 1 = prestup */

      if ( year % 4 == 0 ){

        if ( year % 100 == 0 ){
          if ( year % 400 == 0 ){
            if ( year % 4000 == 0 ){
              prestup = 0;
            }else {
              prestup = 1;
            }
          }else {
            prestup = 0;
          }
        }else {
            prestup = 1;
        };

      }else {
        prestup = 0;
      };

  return prestup;
}

/* ================================================== */













/* ====== Prevod cast roku na minuty ====== */

int dateToMinute(int year, int month, int day, int hour, int minute){

  int min = 0;
  int i;

  int pocetDnu[11];

  pocetDnu[0] = 31;

  pocetDnu[2] = 31;
  pocetDnu[3] = 30;
  pocetDnu[4] = 31;
  pocetDnu[5] = 30;

  pocetDnu[6] = 31;
  pocetDnu[7] = 31;
  pocetDnu[8] = 30;
  pocetDnu[9] = 31;
  pocetDnu[10] = 30;
  pocetDnu[11] = 31;

  if ( prestupnyRok(year) == 1 ){
    pocetDnu[1] = 29;
  }else {
    pocetDnu[1] = 28;
  };

  min += ( (day-1) * 1440 ) + ( hour * 60 ) + (minute);

  for (i=0; i < (month - 1); i++){
    min += (pocetDnu[i] * 1440);
  };

  return min;
}

/* ================================================================= */













/* ====== Pocita pocet minut v letech ====== */

int minutesOfYears(int y1, int y2){

  int min=0;

  if (y1==y2){
    return min;
  };

  if (y1==y2-1){
    return min;
  };

  int i;

  for (i = (y1+1); i <= (y2-1); i++){
    if (prestupnyRok(i) == 1){
      min += 527040;
    }else {
      min += 525600;
    };
  };

  return min;
}

/* ================================================================== */













/* ====== Rozdil dvou minut ====== */

int rozdilMinut(int y1, int m1, int d1, int h1, int min1, int y2, int m2, int d2, int h2, int min2){

  int rozdil;

  if (y1==y2){
    rozdil = dateToMinute(y2, m2, d2, h2, min2) - dateToMinute(y1, m1, d1, h1, min1);
    return rozdil;
  };

  rozdil = minutesOfYears(y1, y2) + dateToMinute(y2, m2, d2, h2, min2);

  if (prestupnyRok(y1) == 1){
    int minuty = 527040 - dateToMinute(y1, m1, d1, h1, min1);
    rozdil += minuty;
  }else {
    int minuty = 525600 - dateToMinute(y1, m1, d1, h1, min1);
    rozdil += minuty;
  };

  return rozdil;
}

/* =================================================================== */























/* ====== Pocet kukani v jeden den ====== */

int kukaniJedenDen(int h1, int min1, int h2, int min2){

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

/* =================================================================== */

















/* ====== Zjisteni nasledujiciho dne ====== */

int nasledujiciDen(int y1, int m1, int d1, int y2, int m2, int d2){

  int pocetDnu[11];

  pocetDnu[0] = 31;

  pocetDnu[2] = 31;
  pocetDnu[3] = 30;
  pocetDnu[4] = 31;
  pocetDnu[5] = 30;

  pocetDnu[6] = 31;
  pocetDnu[7] = 31;
  pocetDnu[8] = 30;
  pocetDnu[9] = 31;
  pocetDnu[10] = 30;
  pocetDnu[11] = 31;

  if ( prestupnyRok(y1) == 1 ){
    pocetDnu[1] = 29;
  }else {
    pocetDnu[1] = 28;
  };

  int nextYear, nextMonth, nextDay;

  if ( d1 < (pocetDnu[m1-1]) ){
    nextYear = y1;
    nextMonth = m1;
    nextDay = d1 + 1;
  };

  if ( (m1 == 12) && (d1 == 31) ){
    nextYear = y1 + 1;
    nextMonth = 1;
    nextDay = 1;
  };

  if ( d1 == pocetDnu[m1 - 1] ){
    nextYear = y1;
    nextMonth = m1 + 1;
    nextDay = 1;
  };

  if ( (nextYear == y2) && (nextMonth == m2) && (nextDay == d2) ){
    return 0;                                                             /* 0 = Dva dny po sobe! */
  }else {
    return 1;                                                             /* 1 = Nejsou po sobe! */
  };

}

/* ================================================================= */













/* ====== Pocet dnu mezi ====== */

int pocetDnuMezi(int y1, int m1, int d1, int y2, int m2, int d2){

  int pocet = 0;

  if ( (y1==y2) && (m1==m2) && (d1==d2) ){
    return pocet;
  };

  int nextYear = y1, nextMonth = m1, nextDay = d1;


  while (nasledujiciDen( nextYear, nextMonth, nextDay, y2, m2, d2 ) != 0){

                    int pocetDnu[11];

                    pocetDnu[0] = 31;

                    pocetDnu[2] = 31;
                    pocetDnu[3] = 30;
                    pocetDnu[4] = 31;
                    pocetDnu[5] = 30;

                    pocetDnu[6] = 31;
                    pocetDnu[7] = 31;
                    pocetDnu[8] = 30;
                    pocetDnu[9] = 31;
                    pocetDnu[10] = 30;
                    pocetDnu[11] = 31;

                    if ( prestupnyRok(nextYear) == 1 ){
                      pocetDnu[1] = 29;
                    }else {
                      pocetDnu[1] = 28;
                    };



                    if ( nextDay < (pocetDnu[nextMonth-1]) ){
                      nextDay = nextDay + 1;
                    }else if ( (nextMonth == 12) && (nextDay == 31) ){
                      nextYear = nextYear + 1;
                      nextMonth = 1;
                      nextDay = 1;
                    }else if ( nextDay == pocetDnu[nextMonth - 1] ){
                      nextMonth = nextMonth + 1;
                      nextDay = 1;
                    };

                    pocet++;

  };

  return pocet;
}

/* ================================================================ */












/* ====== Rozdeleni pripadu (dny) ====== */

int pripady(int y1, int m1, int d1, int y2, int m2, int d2){

  if ( (y1 == y2) && (m1 == m2) && (d1 == d2) ){                /* 0 = Ten samy den */
    return 0;
  };

  if (nasledujiciDen(y1, m1, d1, y2, m2, d2) == 0){             /* 1 = Dva dny po sobe */
    return 1;
  };

  return 2;                                                     /* 2 = Nekolik dnu mezi */
}

/* ================================================================== */








/* ====== Osetrovani vstupu ====== */
int osetreniVstupu(int y1, int m1, int d1, int h1, int i1, int y2, int m2, int d2, int h2, int i2){

                if ( (y1 < 1600) || (y2 < 1600) ){
                  return 0;
                };
                if ( (m1 < 1) || (m1 > 12) || (m2 < 1) || (m2 > 12) ){
                  return 0;
                };

                int pocetDnu[11];

                pocetDnu[0] = 31;

                pocetDnu[2] = 31;
                pocetDnu[3] = 30;
                pocetDnu[4] = 31;
                pocetDnu[5] = 30;

                pocetDnu[6] = 31;
                pocetDnu[7] = 31;
                pocetDnu[8] = 30;
                pocetDnu[9] = 31;
                pocetDnu[10] = 30;
                pocetDnu[11] = 31;

                if ( prestupnyRok(y1) == 1 ){
                  pocetDnu[1] = 29;
                  if ( (d1 < 1) || (d1 > pocetDnu[m1-1]) ){
                    return 0;
                  };
                }else {
                  pocetDnu[1] = 28;
                  if ( (d1 < 1) || (d1 > pocetDnu[m1-1]) ){
                    return 0;
                  };
                };

                if ( prestupnyRok(y2) == 1 ){
                  pocetDnu[1] = 29;
                  if ( (d2 < 1) || (d2 > pocetDnu[m2-1]) ){
                    return 0;
                  };
                }else {
                  pocetDnu[1] = 28;
                  if ( (d2 < 1) || (d2 > pocetDnu[m2-1]) ){
                    return 0;
                  };
                };

                if ( (h1 < 0) || (h1 > 23) || (h2 < 0) || (h2 > 23) || (i1 < 0) || (i1 > 59) || (i2 < 0) || (i2 > 59) ){
                  return 0;
                };

                if (rozdilMinut(y1, m1, d1, h1, i1, y2, m2, d2, h2, i2) < 0){
                  return 0;
                };

                return 1;
}
/* ================================================================= */








int main(){

  int y1=1832, m1=1, d1=1, h1=13, min1=21,
      y2=1832, m2=1, d2=1, h2=13, min2=21;


  if (pripady(y1, m1, d1, y2, m2, d2) == 0){
    printf("Kukani = %d\n", kukaniJedenDen(h1, min1, h2, min2));
  };

  if (pripady(y1, m1, d1, y2, m2, d2) == 1){
    printf("Kukani = %d\n", kukaniJedenDen(h1, min1, 23, 59) + kukaniJedenDen(0, 0, h2, min2));
  };

  if (pripady(y1, m1, d1, y2, m2, d2) == 2){
    printf("Kukani = %d\n", kukaniJedenDen(h1, min1, 23, 59) + kukaniJedenDen(0, 0, h2, min2) + (180*pocetDnuMezi(y1, m1, d1, y2, m2, d2)) );
  };


  int rozdil = rozdilMinut(y1, m1, d1, h1, min1, y2, m2, d2, h2, min2);
  printf("Rozdil minut = %d\n", rozdil);



  return 0;
}








assert ( cuckooClock ( 1832, 1, 12, 0, 0, 1832, 12, 31, 0, 0, &cuckoo ) == 1 && cuckoo == 63732);
assert ( cuckooClock ( 1832, 1, 17, 0, 0, 1832, 12, 31, 0, 0, &cuckoo ) == 1 && cuckoo == 62832);
