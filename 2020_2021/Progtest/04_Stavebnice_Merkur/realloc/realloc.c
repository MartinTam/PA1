#include <stdio.h>
#include <stdlib.h>

int ** createIntArray( int * rows, int * cols ){
  int ** array = (int **) malloc ( *rows * sizeof(*array));
  for (int r = 0; r < *rows; r++){
    array[r] = (int *) malloc ( *cols * sizeof(**array) );
  };
  return array;
}

void freeIntArray( int ** array, int * rows ){
  for (int r = 0; r < *rows; r++){
    free(array[r]);
  };
  free(array);
}

int ** reallocRows( int ** array, int * rows, int * cols ){
  array = (int **) realloc ( array, (*rows * 2) * sizeof(int *) );
  for(int r = *rows; r < (*rows * 2); r++ ){
    array[r] = NULL;
    array[r] = (int *) malloc ( *cols );
  };

  for(int i = *rows; i < (*rows * 2); i++){
    for(int x = 0; x < *cols; x++){
      array[i][x] = 0;
    };
  };

  *rows = *rows * 2;
  return array;
}

void fillArrayByZero(int ** array, int *rows, int * cols){
  for(int i = 0; i < *rows; i++){
    for(int x = 0; x < *cols; x++){
      array[i][x] = 0;
    };
  };
}

void fillArrayByOne(int ** array, int *rows, int * cols){
  for(int i = 0; i < *rows; i++){
    for(int x = 0; x < *cols; x++){
      array[i][x] = 1;
    };
  };
}

int main(void){

  int rows = 10, cols = 3;

  int ** array = createIntArray( &rows, &cols );
  fillArrayByOne(array, &rows, &cols);

  for(int r = 0; r < rows; r++){
    for(int c = 0; c < cols; c++){
      printf("%d ", array[r][c]);
    };
    printf("\n");
  };


  printf("\n");

  array = reallocRows(array, &rows, &cols);
/*
  for(int r = 0; r < rows; r++){
    for(int c = 0; c < cols; c++){
      printf("%d ", array[r][c]);
    };
    printf("\n");
  };
*/
  freeIntArray(array, &rows);

  return 0;
}
