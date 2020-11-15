#include <stdio.h>

/* Creating the result array and fill it with zeros */
int ** createResult(int * rows, int * cols){
  int ** array = (int **) malloc ( *rows * sizeof(*array) );

  for (int i = 0; i < *rows; i++){
    array[i] = (int *) calloc ( *cols , sizeof(**array) );
  };

  return array;
}

/* Filling the result array with results */
void fillResult( char ** diagonal, char ** mask, int ** result, int * rowsDiagonal, int * colsDiagonal ){

  for(int r = 0; r < *rowsDiagonal; r++){
    for(int c = 0; c < *colsDiagonal; c++){

      if ( diagonal[r][c] == '\\' ){
        if( mask[r][c] == '#' ){
          result[r][c] += 1;
        };
        if( mask[r+1][c+1] == '#' ){
          result[r+1][c+1] += 1;
        };
      };

      if ( diagonal[r][c] == '/' ){
        if( mask[r][c+1] == '#' ){
          result[r][c+1] += 1;
        };
        if( mask[r+1][c] == '#' ){
          result[r+1][c] += 1;
        };
      };

    };
  };
}

/* Print result array */
void printResult(int ** result, int * rows, int *cols){
  for (int r = 0; r < *rows; r++){
    for (int c = 0; c < *cols; c++){
      printf("%d", result[r][c]);
    };
    printf("\n");
  };
  printf("\n");
}

/* Free result array */
void freeResult(int ** result, int * rows){
  for (int i = 0; i < *rows; i++){
    free(result[i]);
  };
  free(result);
}

int main(void){
  int rowsDiagonal, colsDiagonal;

  char ** diagonal;
  if (diagonal = NULL){
    printf("Nespravny vstup.\n");
    return 1;
  };

  int rows = rowsDiagonal + 1,
      cols = colsDiagonal + 1;

  char ** mask;
  if (mask = NULL){
    printf("Nespravny vstup.\n");
    return 1;
  };

  int ** result = createResult( &rows, &cols );
  fillResult( diagonal, mask, result, &rowsDiagonal, &colsDiagonal );
  printResult( result, &rows, &cols );
  freeResult(result, &rows);

  return 0;
}
