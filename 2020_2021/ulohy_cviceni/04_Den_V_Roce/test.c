#ifndef __PROGTEST__
#include <stdio.h>
#include <assert.h>
#endif /* __PROGTEST__ */

int dateToIndex(int day, int month, int year, int *idx) {

  int prestup=0, i;  /* 0 = neprestup ; 1 = prestup */
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

    if (prestup == 1){
      pocetDnu[1] = 29;
    }else {
      pocetDnu[1] = 28;
    };


    if ( year < 2000 ) {
      return 0;
    };

    if ( (month < 1) || (month > 12) ){
      return 0;
    };

    if ( (day < 1) || (day > pocetDnu[month-1]) ){
      return 0;
    };

    *idx=0;

    for (i=0; i<(month-1); i++){
      *idx += pocetDnu[i];
    };

    *idx += day;

    return 1;
}

#ifndef __PROGTEST__
int main (int argc, char * argv []) {
    int idx;
    assert(dateToIndex( 1,  1, 2000, &idx) == 1 && idx == 1);
    assert(dateToIndex( 1,  2, 2000, &idx) == 1 && idx == 32);
    assert(dateToIndex(29,  2, 2000, &idx) == 1 && idx == 60);
    assert(dateToIndex(29,  2, 2001, &idx) == 0);
    assert(dateToIndex( 1, 12, 2000, &idx) == 1 && idx == 336);
    assert(dateToIndex(31, 12, 2000, &idx) == 1 && idx == 366);
    assert(dateToIndex( 1,  1, 1999, &idx) == 0);
    assert(dateToIndex( 6,  7, 3600, &idx) == 1 && idx == 188);
    assert(dateToIndex(29,  2, 3600, &idx) == 1 && idx == 60);
    assert(dateToIndex(29,  2, 4000, &idx) == 0);
    return 0;
}
#endif /* __PROGTEST__ */
