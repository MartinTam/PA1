#include <stdio.h>
#include <stdlib.h>
#define ROWS 4
#define COLUMNS 10

void printArray(char arr[][COLUMNS]){

  int i, e;

  for (i=0; i < ROWS; i++){
    for (e=0; e < COLUMNS; e++){
      printf("%c", arr[i][e]);
    };
    printf("\n");
  };
}

int pocetMin(int i, int e, char minovePole[][COLUMNS]){

  int pocetMin = 0, y, w;

  for (y=(i-1); y <= (i+1); y++){
    for (w = (e-1); w <= (e+1); w++){
      if(y==i && w==e){
        pocetMin += 0;
      };
      if(y >= 0 && y <= ROWS && w >= 0 && w <= (COLUMNS - 1) && minovePole[y][w] == '*'){
          pocetMin += 1;
      };
    };
  };
  return pocetMin;
}

int main(){

  int i, e;

  char minovePole[ROWS][COLUMNS];

  for (i=0; i < ROWS; i++){
    for (e=0; e < COLUMNS ; e++){
      minovePole[i][e] = '.';
    };
  };

  minovePole[0][5] = '*';
  minovePole[1][2] = '*';
  minovePole[1][5] = '*';
  minovePole[2][5] = '*';
  minovePole[2][8] = '*';
  minovePole[3][2] = '*';

  printArray(minovePole);




/*
  char ** vypocet = (char **)malloc(ROWS * sizeof(char *));
  for (i=0; i<ROWS; i++){
         vypocet[i] = (char *)malloc(COLUMNS * sizeof(char));
  };

  for (i = 0; i < ROWS; i++){
    for (e = 0; e < COLUMNS; e++){
        vypocet[i][e] = '.';
    };
  };

*/



  char vypocet[ROWS][COLUMNS];

  for (i=0; i < ROWS; i++){
    for (e=0; e < COLUMNS ; e++){
      vypocet[i][e] = '.';
    };
  };

  for (i=0; i < ROWS; i++){
    for (e=0; e < COLUMNS; e++){

            if (minovePole[i][e] == '*'){
              vypocet[i][e] = '*';
            }else {

                  if (pocetMin(i, e, minovePole) == 0){
                    vypocet[i][e] = '.';
                  }else {
                      char str[2];
                      sprintf(str, "%d", pocetMin(i, e, minovePole));
                      vypocet[i][e] = str[0];

                  };
            };
      };
    };

  printf("\n");

  printArray(vypocet);

/*
  for (i=0; i < ROWS; i++){
    for (e=0; e < COLUMNS; e++){
      printf("%c", vypocet[i][e]);
    };
    printf("\n");
  };

  free(vypocet);
*/
  return 0;
}
