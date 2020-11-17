#include <stdio.h>
#include <stdlib.h>

char ** createCharArray( int * rows, int * cols ){
  char ** array = (char **) malloc ( *rows * sizeof(*array));
  for (int r = 0; r < *rows; r++){
    array[r] = (char *) malloc ( *cols * sizeof(**array) );
  };
  return array;
}

void fillBefore( char ** array, int * rows, int * cols ){
  for (int r = 0; r < *rows; r++){
    for (int c = 0; c < *cols; c++){
      array[r][c] = 'X';
    };
  };
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

char ** reallocCharArray( char ** array, int * rows, int * cols ){

  array = (char **) realloc ( array, (*rows * 2) * sizeof(char *) );
  for(int r = *rows; r < (*rows * 2); r++ ){
    array[r] = NULL;
    array[r] = (char *) malloc ( *cols * 2 );
    for (int c = 0; c < *cols * 2; c++){
      array[r][c] = '.';
    };
  };

  for(int r = 0; r < *rows; r++){
    array[r] = (char *) realloc ( array[r], *cols * 2 );
    for(int c = *cols; c < *cols * 2; c++){
      array[r][c]='.';
    };
  };
  *rows = *rows * 2;
  *cols = *cols * 2;
  return array;
}

char ** reallocRows( char ** array, int * rows, int * cols ){
  array = (char **) realloc ( array, (*rows * 2) * sizeof(char *) );
  for(int r = *rows; r < (*rows * 2); r++ ){
    array[r] = NULL;
    array[r] = (char *) malloc ( *cols );
    for (int c = 0; c < *cols; c++){
      array[r][c] = '.';
    };
  };
  *rows = *rows * 2;
  return array;
}

char ** reallocCols( char ** array, int * rows, int * cols ){
  for(int r = 0; r < *rows; r++){
    array[r] = (char *) realloc ( array[r], *cols * 2 );
    for(int c = *cols; c < *cols * 2; c++){
      array[r][c]='.';
    };
  };
  *cols = *cols * 2;
  return array;
}

int main(void){
  int rows = 5, cols = 5;

  char ** before = createCharArray( &rows, &cols );

  fillBefore(before, &rows, &cols);
  printCharArray(before, &rows, &cols);
/*
  before = reallocRows(before, &rows, &cols);
  printCharArray(before, &rows, &cols);
*/
  before = reallocCols(before, &rows, &cols);
  printCharArray(before, &rows, &cols);

  freeCharArray(before, &rows);

  return 0;
}
