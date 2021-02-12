#include <stdio.h>

int test(int cislo){           /* 0 = bezctvercove cislo ; 1 = NENI */

    int i = 2;
    int test1 = 0;
    int test2 = 0;
    int result = 0;   /* 0 = JE ; 1 = NENI */

    if ( cislo == 1 ){
      return result;
    };

    while ( i <= cislo ){
      if ( (cislo % i) == 0 ){

        test2 = i;
          if (test2 != test1){
            test1 = i;
          }else {
             result = 1;
             break;
          };


        cislo = cislo / i;
      }else {
        i++;
      };
    };

    return result;

}

void bezctvercoveCislo(int poradi){

  int cislo=1, i=0;

  if (poradi > 20000){
    i = 19999;
    cislo = 32905;
  };

  if (poradi > 30000){
    i = 29999;
    cislo = 49337;
  };

  if (poradi > 40000){
    i = 39999;
    cislo = 65797;
  };

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
