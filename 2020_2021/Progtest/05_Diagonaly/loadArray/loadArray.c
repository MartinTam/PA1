#include <stdio.h>
#include <stdlib.h>

char ** createCharArray( int * rows, int * cols ){
  char ** array = (char **) malloc ( *rows * sizeof(*array));
  for (int r = 0; r < *rows; r++){
    array[r] = (char *) malloc ( *cols * sizeof(**array) );
    for (int c = 0; c < *cols; c++){                              /* ADD */
      array[r][c] = '*';
    };
  };
  return array;
}

char ** reallocCharArray( char ** array, int * rows, int * cols ){

  array = (char **) realloc ( array, (*rows * 2) * sizeof(char *) );
  for(int r = *rows; r < (*rows * 2); r++ ){
    array[r] = NULL;
    array[r] = (char *) malloc ( *cols * 2 );
    for (int c = 0; c < *cols * 2; c++){
      array[r][c] = '*';
    };
  };

  for(int r = 0; r < *rows; r++){
    array[r] = (char *) realloc ( array[r], *cols * 2 );
    for(int c = *cols; c < *cols * 2; c++){
      array[r][c]='*';
    };
  };
  *rows = *rows * 2;
  *cols = *cols * 2;
  return array;
}

void freeCharArray( char ** array, int * rows ){
  for (int r = 0; r < *rows; r++){
    free(array[r]);
  };
  free(array);
}

char ** loadDiagonal( int * rowsDiagonal, int * colsDiagonal ){
  char ** diagonal = createCharArray(rowsDiagonal, colsDiagonal);

  char c;
  int charCount=0, rowCount=0, colCount=0, firstRow=0, flag=0;

  do{
      c = fgetc(stdin);
      diagonal[0][colCount] = c;
      colCount++;
      if(colCount >= *rowsDiagonal){
        diagonal = reallocCharArray(diagonal, rowsDiagonal, colsDiagonal);
      };
      charCount++;
  }while(c!='\n');

  if(charCount==0){
    freeCharArray(diagonal, rowsDiagonal);
    return NULL;
  };

  firstRow = charCount;
  charCount = 0;

  for(int c = 0; c < firstRow; c++){
    if( (diagonal[0][c] != '\\') && (diagonal[0][c] != '/') ){
      flag = 1;
    };
  };



  return diagonal;
}

void printCharArray(char ** array, int * rows, int * cols){
  for (int r = 0; r < *rows; r++){
    for (int c = 0; c < *cols; c++){
      printf("%c", array[r][c]);
    };
    printf("\n");
  };
  printf("\n");
}

int main(void){

  int rowsDiagonal=10, colsDiagonal=10;

  char ** diagonal = loadDiagonal(&rowsDiagonal, &colsDiagonal);
  if (diagonal == NULL){
    printf("Nespravny vstup.\n");
    return 1;
  };

  printCharArray(diagonal, &rowsDiagonal, &colsDiagonal);
  freeCharArray(diagonal, &rowsDiagonal);

  return 0;
}
