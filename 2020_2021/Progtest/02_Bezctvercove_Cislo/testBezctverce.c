#include <stdio.h>
#include <math.h>

void bezctvercoveCislo(int cislo){

  int i = sqrt(cislo);

  while ( i >= 2 ){
    if ( (cislo % i) == 0 ){
      bezctvercoveCislo(i);
      bezctvercoveCislo(cislo/i);
    };
    i--;
  };

  printf("%d ", cislo);
}


int main(){

  int cislo, err;

  while ( ( err = scanf(" %d", &cislo) ) == 1 ){

    if (cislo <= 0){
      printf("Nespravny vstup.\n");
      return 1;
    };

    bezctvercoveCislo(cislo);
    printf("\n");

  };

  if(err != EOF){
    printf("Nespravny vstup.\n");
    return 1;
  };


  return 0;
}
