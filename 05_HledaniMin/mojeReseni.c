#include <stdio.h>



int main(){

  int i, e, pocetMin = 0, y, w;

  char minovePole[4][10];

  for (i=0; i < 4; i++){
    for (e=0; e < 10 ; e++){
      minovePole[i][e] = '.';
    };
  };

  minovePole[0][5] = '*';
  minovePole[1][2] = '*';
  minovePole[1][5] = '*';
  minovePole[2][5] = '*';
  minovePole[2][8] = '*';
  minovePole[3][2] = '*';

  for (i=0; i < 4; i++){
    for (e=0; e < 10; e++){
      printf("%c", minovePole[i][e]);
    };
    printf("\n");
  };





  char vypocet[4][10];

  for (i=0; i < 4; i++){
    for (e=0; e < 10 ; e++){
      vypocet[i][e] = '.';
    };
  };



  for (i=0; i < 4; i++){
    for (e=0; e < 10; e++){

      if (minovePole[i][e] == '*'){
        vypocet[i][e] = '*';
      }else {

            for (y=(i-1); y <= (i+1); y++){
              for (w = (e-1); w <= (e+1); w++){
                if(y==i && w==e){
                  pocetMin += 0;
                };
                if(y >= 0 && y <= 4 && w >= 0 && w <= 9 && minovePole[y][w] == '*'){
                    pocetMin += 1;
                };
              };
            };

            if (pocetMin == 0){
              vypocet[i][e] = '.';

            }else {
                char str[2];
                sprintf(str, "%d", pocetMin);
                vypocet[i][e] = str[0];
                pocetMin = 0;
            };
      };
    };
  };

  printf("\n");

  for (i=0; i < 4; i++){
    for (e=0; e < 10; e++){
      printf("%c", vypocet[i][e]);
    };
    printf("\n");
  };

  return 0;
}
