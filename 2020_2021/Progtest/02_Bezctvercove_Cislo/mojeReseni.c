#include <stdio.h>

int test(int cislo){

  if ( cislo == 1 ){
    return 0;
  };

  

  return 0;
}

void bezctvercoveCislo(int poradi){

  int cislo=1, i=0;

  while( i <= poradi ){
    if( test(cislo) == 0 ){
      i++;
    };
    if ( i == poradi ){
      break;
    };
    cislo++;
  };


  printf("= %d\n", cislo);
}


int main(){

  int poradi, err;

  printf("Poradi:\n");
  while ((err = scanf(" %d", &poradi)) == 1){

    if(poradi <= 0){
      printf("Nespravny vstup.\n");
      return 1;
    };

    bezctvercoveCislo(poradi);

  };

  if(err != EOF){
    printf("Nespravny vstup.\n");
    return 1;
  };

  return 0;
}
