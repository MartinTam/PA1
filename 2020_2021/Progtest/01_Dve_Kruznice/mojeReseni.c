#include <stdio.h>

int main(){

  double x1, y1, r1, x2, y2, r2;

  printf("Zadejte parametry kruznice #1:\n");
  if (scanf(" %lf %lf %lf", &x1, &y1, &r1) != 3 ){
    printf("Nespravny vstup.\n");
    return 1;
  };

  if(r1 <= 0){
    printf("Nespravny vstup.\n");
    return 1;
  };

  printf("Zadejte parametry kruznice #2:\n");
  if (scanf(" %lf %lf %lf", &x2, &y2, &r2) != 3 ){
    printf("Nespravny vstup.\n");
    return 1;
  };

  if(r2 <= 0){
    printf("Nespravny vstup.\n");
    return 1;
  };


  printf("OK\n");


  return 0;
}
