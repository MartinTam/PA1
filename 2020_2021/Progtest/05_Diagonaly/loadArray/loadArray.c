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

char ** loadDiagonal( int * rowsDiagonal, int * colsDiagonal, int * rowsNewDiagonal, int * colsNewDiagonal ){
  char ** diagonal = createCharArray(rowsDiagonal, colsDiagonal);

  char c;
  int row=0, col=0, charCount=0, firstRow=0;

  do{

      do{

        c = fgetc(stdin);

        if(c == '\n'){
          break;
        };
        diagonal[row][col] = c;
        col++;
        charCount++;

      }while ( 1 );

      if ( (charCount != 0) && (charCount != firstRow) && (firstRow != 0) ){
        return NULL;
      };

      if ( (charCount == 0) && (c == '\n') && (firstRow == 0) ){
        return NULL;
      };

      if ( (charCount != 0) && (firstRow == 0)){
        firstRow = charCount;
      };

      if ( (charCount == 0) && (c == '\n') && (firstRow != 0) ){
        *rowsNewDiagonal = row;
        *colsNewDiagonal = firstRow;
        break;
      };

      for (int i = 0; i < firstRow; i++){
        if( ( diagonal[row][i] != '\\') && ( diagonal[row][i] != '/' ) ){
          return NULL;
        };
      };



      row++;
      col = 0;
      charCount = 0;
  }while ( 1 );

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

  int rowsDiagonal=100, colsDiagonal=100, rowsNewDiagonal=0, colsNewDiagonal=0;

  char ** diagonal = loadDiagonal( &rowsDiagonal, &colsDiagonal, &rowsNewDiagonal, &colsNewDiagonal );
  if (diagonal == NULL){
    printf("Nespravny vstup.\n");
    return 1;
  };

  printCharArray(diagonal, &rowsNewDiagonal, &colsNewDiagonal);
  freeCharArray(diagonal, &rowsDiagonal);

  return 0;
}
