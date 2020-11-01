#ifndef __PROGTEST__
#include <stdio.h>
#include <assert.h>
#endif /* __PROGTEST__ */


int prestupnyRok(int year){       /* === Funkce na zjisteni prestuoneho roku === */

  int prestup=0, i;  /* 0 = neprestup ; 1 = prestup */

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

int datumNaMinuty(int year, int month, int day, int hour, int minute){      /* === Funkce na prevod datumu do minuty === */

  int min = year * ;

  return min;
}

int cuckooClock ( int y1, int m1, int d1, int h1, int i1,
                  int y2, int m2, int d2, int h2, int i2, long long int * cuckoo )
{
  /* todo */
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
