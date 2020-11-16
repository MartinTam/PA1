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

void printCharArray(char ** array, int * rows, int * cols){
  for (int r = 0; r < *rows; r++){
    for (int c = 0; c < *cols; c++){
      printf("%c", array[r][c]);
    };
    printf("\n");
  };
  printf("\n");
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











int main(void){

  int rows = 2, cols = 2;

  printf("Maska:\n");
  char ** mask = loadMask(&rows, &cols);
  if(mask == NULL){
    printf("Nespravny vstup.\n");
    return 1;
  };

  printf("\n");
  printCharArray(mask, &rows, &cols);
  freeCharArray(mask, &rows);

  return 0;
}
