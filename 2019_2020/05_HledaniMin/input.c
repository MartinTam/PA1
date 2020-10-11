#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>



int main()
{

  int numberRows = pocetSloupcu / rememberColumns;
  int numberSmallRows = numberRows - 2;


  for(z=0; z<rememberColumns; z++){               // Prvni Radek!
    if(z==0){
      if(minovePole[z] == '*'){
        printf("*");
      }else{}
      // 1
      printf("%d", pocetMin);
      pocetMin = 0;
    };
    if(z==rememberColumns-1){
      if(minovePole[z] == '*'){
        printf("*");
      }else{}
      // 2
      printf("%d", pocetMin);
      pocetMin = 0;
    };

    if(z != 0 && z != rememberColumns-1){
      if(minovePole[z] == '*'){
        printf("*");
      }else{}
      // A
      printf("%d", pocetMin);
      pocetMin = 0;
    };

  };

  printf("\n");



          for(z=rememberColumns; z<(pocetSloupcu-rememberColumns); z++ ){                   // Prostredni Radky!

                if(numberRows == 2){
                  break;
                };

                int start = rememberColumns;
                int end = rememberColumns + rememberColumns - 1;

                if(z==start){
                  if(minovePole[z] == '*'){
                    printf("*");
                  }else{
                      // B
                  }

                };

                if(z==end){
                  if(minovePole[z] == '*'){
                    printf("*");
                  }else{
                      // C
                  };

                };

                if(z != start && z != end){
                  if(minovePole[z] == '*'){
                    printf("*");
                  }else{
                      // !
                  };

                };

                start += rememberColumns;
                end += rememberColumns;
                printf("\n");
          };



  for(y=pocetSloupcu-rememberColumns; y<pocetSloupcu; y++){       // Posledni Radek!
    if(y==pocetSloupcu-rememberColumns){
      if(minovePole[y] == '*'){
        printf("*");
      }else{}
      // 3
      printf("%d", pocetMin);
      pocetMin = 0;
    };

    if(y==pocetSloupcu-1){
      if(minovePole[y] == '*'){
        printf("*");
      }else{}
      // 4
      printf("%d", pocetMin);
      pocetMin = 0;
    };

    if(y != pocetSloupcu-rememberColumns && y != pocetSloupcu-1){
      if(minovePole[y] == '*'){
        printf("*");
      }else{}
      // D
      printf("%d", pocetMin);
      pocetMin = 0;
    };
  };











  return 0;
}
