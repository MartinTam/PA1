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












int main(){

  int y1=2012, m1=1, d1=1, h1=0, min1=0,
      y2=2012, m2=1, d2=1, h2=23, min2=59;

  int rozdil = rozdilMinut(y1, m1, d1, h1, min1, y2, m2, d2, h2, min2);

  printf("Rozdil minut = %d\n", rozdil);

  int kukani = kukaniJedenDen(h1, min1, h2, min2);

  printf("Kukani za jeden den = %d\n", kukani);



  return 0;
}
