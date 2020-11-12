#include <stdio.h>
#include <stdlib.h>

#define ROWS 3  // radky
#define COLS 2  // sloupce

void foo ( int mat[][COLS], int ROWS ){
  // 1. Pouze staticky alokovane + 4. Radky dynamicky, sloupce staticky
}

void foo ( int ** mat, int rows, int cols ){
  // 2. Pouze dynamicky alokovane + 3. Radky staticky, sloupce dynamicky
}

int main(void){

  int mat[ROWS][COLS];                                                                    // 1. Pouze staticky alokovane


  int ** mat = (int **) malloc ( rows * sizeof( *mat ) );                                 // 2. Pouze dynamicky alokovana

  for ( int i = 0; i < rows; i++ ){
    mat[i] = (int *) malloc ( cols * sizeof( **mat ) )
  };

  for ( int i = 0; i < rows; i++ ){
    free(mat[i]);
  };
  free(mat);


  int * mat[ROWS];                                                                        // 3. Radky staticky, sloupce dynamicky

  for ( int i = 0; i < ROWS; i++ ){
    mat[i] = (int *) malloc ( cols * sizeof( **mat ) );
  };

  for ( int i = 0; i < ROWS; i++ ){
    free(mat[i]);
  };


  int (*mat)[COLS];                                                                       // 4. Radky dynamicky, sloupce staticky
  mat = (int(*)[COLS]) malloc ( rows * sizeof( *mat ) );
  free(mat);

  return 0;
}
