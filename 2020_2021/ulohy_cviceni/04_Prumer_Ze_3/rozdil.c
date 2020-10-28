#include <stdio.h>

int main(){

  long long a = 9223372036854775800, b = 9223372036854775800, c = -4611686018427387912;

  printf("\na/3 = %lld\n", a/3);
  printf("b/3 = %lld\n", b/3);
  printf("c/3 = %lld\n", c/3);

  long long su = a/3 + b/3 + c/3;
  printf("sum = %lld\n\n", su);

  printf("a#3 = %lld\n", a%3);
  printf("b#3 = %lld\n", b%3);
  printf("c#3 = %lld\n\n\n", c%3);

  long long mo = ((a%3 + b%3 + c%3)/3);

  long long x = (a/3 + b/3 + c/3 + (a%3 + b%3 +c%3)/3);

  printf("mod = %lld\n\n", mo);
  printf("result = %lld\n\n", x);


  printf("=============================\n");


  long double a1 =  (long double)a/3 ;
  long double b1 =  (long double)b/3 ;
  long double c1 =  (long double)c/3 ;
  long long sum = ( (long long)a1 + (long long)b1 + (long long)c1 );



  printf("\na/3 = %Lf\n", a1);
  printf("b/3 = %Lf\n", b1);
  printf("c/3 = %Lf\n", c1);
  printf("sum = %lld\n\n", sum);

  long long mod = ((a%3 + b%3 + c%3)/3);

  printf("a#3 = %lld\n", a%3);
  printf("b#3 = %lld\n", b%3);
  printf("c#3 = %lld\n\n", c%3);

  long long result = sum + mod;

  printf("mod = %lld\n\n", mod);
  printf("result = %lld\n", result);


  return 0;
}
