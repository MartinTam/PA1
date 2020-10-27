#ifndef __PROGTEST__
#include <stdio.h>
#include <limits.h>
#include <assert.h>
#include <stdint.h>
#endif /* __PROGTEST__ */

long long avg3 ( long long a, long long b, long long c )
{
  long long result;
  long double a1 = (long double)a/3;
  long double b1 = (long double)b/3;
  long double c1 = (long double)c/3;
  long long sum = ( (long long)a1 + (long long)b1 + (long long)c1 );


  result = sum + (a%3 + b%3 + c%3)/3;



  return result;

}

#ifndef __PROGTEST__
int main (int argc, char * argv [])
{
  assert ( avg3 ( 1, 2, 3 ) == 2 );
  assert ( avg3 ( -100, 100, 30 ) == 10 );
  assert ( avg3 ( 1, 2, 2 ) == 1 );
  assert ( avg3 ( -1, -2, -2 ) == -1 );
  assert ( avg3 ( LLONG_MAX, LLONG_MAX, LLONG_MAX ) == LLONG_MAX );
  assert ( avg3 ( 9223372036854775800, 9223372036854775800, -8 ) ==6148914691236517197 );

  return 0;
}
#endif /* __PROGTEST__ */
