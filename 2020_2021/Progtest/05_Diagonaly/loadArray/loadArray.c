#include <stdio.h>
#include <stdlib.h>

char ** createCharArray( int * rows, int * cols ){
  char ** array = (char **) malloc ( *rows * sizeof(*array));
  for (int r = 0; r < *rows; r++){
    array[r] = (char *) malloc ( *cols * sizeof(**array) );
    for (int c = 0; c < *cols; c++){
      array[r][c] = '*';
    };
  };
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

void freeCharArray( char ** array, int * rows ){
  for (int r = 0; r < *rows; r++){
    free(array[r]);
  };
  free(array);
}

char ** loadDiagonal( int * rowsDiagonal, int * colsDiagonal, int * rowsNewDiagonal, int * colsNewDiagonal ){
  char ** diagonal = createCharArray(rowsDiagonal, colsDiagonal);

  char c;
  int charCount=0, rowCount=0, colCount=0, firstRow=0, flag=0, eof=0;

  do{
    do{
      c = fgetc(stdin);
      if(c=='\n'){
        break;
      };

      if( feof(stdin) ){
        eof = 1;
        break;
      };

      if( (c != '\\') && (c != '/') ){
        flag = 1;
      };

      if(flag==0){
        diagonal[rowCount][colCount] = c;
        colCount++;
        if(colCount >= *colsDiagonal){
          diagonal = reallocCols(diagonal, rowsDiagonal, colsDiagonal);
        };
      };
      charCount++;
    }while(1);

    if( (charCount!=0) && (firstRow==0) && (flag==0) ){
      firstRow = charCount;
    };

    if( (eof==1) && (charCount!=0) ){
      flag=1;
      break;
    };

    if( (charCount!=0) && (firstRow!=0) && (charCount!=firstRow) ){
      flag=1;
    };

    if( (charCount==0) && (eof==1) ){
      if(firstRow==0){
        flag = 1;
      };
      break;
    };

    if(flag==0){
      colCount=0;
      rowCount++;
      if(rowCount >= *rowsDiagonal){
        diagonal = reallocRows(diagonal, rowsDiagonal, colsDiagonal);
      };
    };
    charCount=0;
  }while(1);

  if(flag==1){
    freeCharArray(diagonal, rowsDiagonal);
    return NULL;
  }else{
    *rowsNewDiagonal = rowCount;
    *colsNewDiagonal = firstRow;
    return diagonal;
  };
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

  int rowsDiagonal=10, colsDiagonal=10, rowsNewDiagonal=0, colsNewDiagonal=0;

  char ** diagonal = loadDiagonal(&rowsDiagonal, &colsDiagonal, &rowsNewDiagonal, &colsNewDiagonal);
  if (diagonal == NULL){
    printf("\nNespravny vstup.\n");
    return 1;
  };

  printCharArray(diagonal, &rowsNewDiagonal, &colsNewDiagonal);
  freeCharArray(diagonal, &rowsDiagonal);

  return 0;
}
