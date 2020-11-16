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

void freeCharArray( char ** array, int * rows ){
  for (int r = 0; r < *rows; r++){
    free(array[r]);
  };
  free(array);
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
        if(col >= *colsDiagonal){
          diagonal = reallocCharArray(diagonal, rowsDiagonal, colsDiagonal);
        };
        charCount++;

      }while ( 1 );

      if ( (charCount != 0) && (charCount != firstRow) && (firstRow != 0) ){
        freeCharArray(diagonal, rowsDiagonal);
        return NULL;
      };

      if ( (charCount == 0) && (c == '\n') && (firstRow == 0) ){
        freeCharArray(diagonal, rowsDiagonal);
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
          freeCharArray(diagonal, rowsDiagonal);
          return NULL;
        };
      };

      row++;
      if(row >= *rowsDiagonal){
        diagonal = reallocCharArray(diagonal, rowsDiagonal, colsDiagonal);
      };
      col = 0;
      charCount = 0;
  }while ( 1 );

  return diagonal;
}

char ** loadMask( int * rows, int * cols ){
  char ** mask = createCharArray(rows, cols);

  char c;

  int mainRows = *rows, mainCols = *cols;

  int charCount=0, rowCount=0, colCount=0;

  do{
    do{
      c = fgetc(stdin);
      if(c == '\n'){
        break;
      };

      if(charCount < mainCols){
        mask[rowCount][colCount] = c;
        colCount++;
      };

      charCount++;

    }while(1);

    if( (charCount==0) && (c == '\n') ){
      freeCharArray(mask, rows);
      return NULL;
    };

    if(charCount > mainCols){
      freeCharArray(mask, rows);
      return NULL;
    };

    colCount = 0;
    rowCount++;

    if(rowCount >= mainRows){
      break;
    };

    charCount = 0;

  }while(1);

  for(int r = 0; r < mainRows; r++){
    for (int c = 0; c < mainCols; c++){
      if( (mask[r][c] != '#') && ( mask[r][c] != '.' ) ){
        freeCharArray(mask, rows);
        return NULL;
      };
    };
  };

  return mask;
}

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
void printResult(int ** result, int * rows, int *cols, char ** mask){
  for (int r = 0; r < *rows; r++){
    for (int c = 0; c < *cols; c++){
      if(mask[r][c]=='#'){
        printf("%d", result[r][c]);
      }else{
        printf(".");
      };
    };
    printf("\n");
  };
}

/* Free result array */
void freeResult(int ** result, int * rows){
  for (int i = 0; i < *rows; i++){
    free(result[i]);
  };
  free(result);
}

int main(void){
  int rowsDiagonal = 100, colsDiagonal = 100, rowsNewDiagonal = 0, colsNewDiagonal = 0;

  printf("Vypln:\n");
  char ** diagonal = loadDiagonal( &rowsDiagonal, &colsDiagonal, &rowsNewDiagonal, &colsNewDiagonal );
  if (diagonal == NULL){
    printf("Nespravny vstup.\n");
    return 1;
  };

  int rows = rowsNewDiagonal + 1,
      cols = colsNewDiagonal + 1;

  printf("Maska:\n");
  char ** mask = loadMask(&rows, &cols);
  if (mask == NULL){
    printf("Nespravny vstup.\n");
    freeCharArray(diagonal, &rowsDiagonal);
    return 1;
  };

  int ** result = createResult( &rows, &cols );
  fillResult( diagonal, mask, result, &rowsNewDiagonal, &colsNewDiagonal );
  printResult( result, &rows, &cols, mask );
  freeResult(result, &rows);
  freeCharArray(diagonal, &rowsDiagonal);
  freeCharArray(mask, &rows);

  return 0;
}
