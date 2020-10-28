#include <stdio.h>

int main(){

  int year, prestup = 0;  /* 0 = neprestup ; 1 = prestup */

  if ( scanf(" %d", &year) != 1 ){
    printf("Nespravny vstup.\n");
    return 1;
  };

  if ( year < 2000 ) {
    printf("Nespravny vstup.\n");
    return 1;
  };

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
    printf("Rok %d je prestupni.\n", year);
  }else {
    printf("Rok %d je NEprestupni.\n", year);
  };

  return 0;
}
