#include <stdio.h>
#include <stdlib.h> // malloc(), realloc(), free()

/* Creating the result array and fill it with zeros */
int ** createResult(int * rows, int * cols){
  int ** array = (int **) malloc ( *rows * sizeof(*array) );

  for (int i = 0; i < *rows; i++){
    array[i] = (int *) calloc ( *cols , sizeof(**array) );
  };

  return array;
}

/* Free result array */
void freeResult(int ** result, int * rows){
  for (int i = 0; i < *rows; i++){
    free(result[i]);
  };
  free(result);
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

int main(void){

  int rows = 10,
      cols = 30;

  int ** result = createResult(&rows, &cols);
  printResult(result, &rows, &cols);
  freeResult(result, &rows);

  return 0;
}
