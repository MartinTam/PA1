#include <stdio.h>
#include <stdlib.h>

char ** createCharArray( int * rows, int * cols ){
  char ** array = (char **) malloc ( *rows * sizeof(*array));
  for (int r = 0; r < *rows; r++){
    array[r] = (char *) malloc ( *cols * sizeof(**array) );
  };
  return array;
}

void freeCharArray( char ** array, int * rows ){
  for (int r = 0; r < *rows; r++){
    free(array[r]);
  };
  free(array);
}

void printCharArray( char ** array, int * rows, int * cols ){
  for (int r = 0; r < *rows; r++){
    for (int c = 0; c < *cols; c++){
      printf("%c", array[r][c]);
    }
    printf("\n");
  }
  printf("\n");
}

void ** reallocCharArray( char ** array, int * rows, int * cols ){
  char ** tmp = (char **) 
}

int main(void){
  int rows = 5, cols = 5;

  char ** before = createCharArray( &rows, &cols );
  printCharArray(before, &rows, &cols);
  freeCharArray(before, &rows, &cols);

  return 0;
}
