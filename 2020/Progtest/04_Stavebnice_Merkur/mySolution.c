#include <stdio.h>
#include <stdlib.h>

int ** createIntArray( int * rows, int * cols ){
  int ** array = (int **) malloc ( *rows * sizeof(*array));
  for (int r = 0; r < *rows; r++){
    array[r] = (int *) malloc ( *cols * sizeof(**array) );
    for(int c = 0; c < *cols; c++){
      array[r][c]=0;
    };
  };
  return array;
}

void freeIntArray( int ** array, int * rows ){
  for (int r = 0; r < *rows; r++){
    free(array[r]);
  };
  free(array);
}

int ** reallocRows( int ** array, int * rows, int * cols ){
  array = (int **) realloc ( array, (*rows * 2) * sizeof(int *) );
  for(int r = *rows; r < (*rows * 2); r++ ){
    array[r] = NULL;
    array[r] = (int *) malloc ( *cols );
    for(int c = 0; c < *cols; c++){
      array[r][c]=0;
    };
  };

  *rows = *rows * 2;
  return array;
}

int isTriangle(int a, int b, int c){

  if( ( (a + b) > c ) && ( (a + c) > b ) && ( (b + c) > a ) ){
    return 1;
  };

  return 0;
}



int loadInput(int * array, int * count){
  int code;

  if( (code = scanf(" %d", &array[*count])) == EOF ){
    return EOF;
  }else if (code != 1){
    return 0;
  }else if(array[*count] <= 0){
    return 0;
  }else{
    return 1;
  };
}


int main(void){

  int triangle = 0;

  int count=0;
  int array[10000];

  for(int c = 0; c < 10000; c++){
    array[c] = 1;
  };

  printf("Delky nosniku:\n");
  while(loadInput(array, &count) == 1){
    count++;
  };

  if(loadInput(array, &count) != EOF){
    printf("Nespravny vstup.\n");
    return 1;
  };

  if( (count > 10000) || (count < 3) ){
    printf("Nespravny vstup.\n");
    return 0;
  };

  int rows = 10, cols = 3, filled=0;
  int ** triangleOne = createIntArray(&rows, &cols);


  for(int a = 0; a < count; a++){
    for(int b = a + 1; b < count; b++){
      for (int c = b + 1; c < count; c++){

        int flag = 0;

        for(int i = 0; i < filled; i++){
          if( (array[a] == triangleOne[i][0]) && (array[b] == triangleOne[i][1]) && (array[c] == triangleOne[i][2]) ){
            flag = 1;
            break;
          }else if ( (array[a] == triangleOne[i][0]) && (array[c] == triangleOne[i][1]) && (array[b] == triangleOne[i][2]) ){
            flag = 1;
            break;
          }else if( (array[b] == triangleOne[i][0]) && (array[a] == triangleOne[i][1]) && (array[c] == triangleOne[i][2]) ){
            flag = 1;
            break;
          }else if( (array[b] == triangleOne[i][0]) && (array[c] == triangleOne[i][1]) && (array[a] == triangleOne[i][2]) ){
            flag = 1;
            break;
          }else if( (array[c] == triangleOne[i][0]) && (array[a] == triangleOne[i][1]) && (array[b] == triangleOne[i][2]) ){
            flag = 1;
            break;
          }else if( (array[c] == triangleOne[i][0]) && (array[b] == triangleOne[i][1]) && (array[a] == triangleOne[i][2]) ){
            flag = 1;
            break;
          }else{
            flag = 0;
          };
        };

        if(flag==0){
          if (isTriangle(array[a], array[b], array[c])){
            triangleOne[filled][0] = array[a];
            triangleOne[filled][1] = array[b];
            triangleOne[filled][2] = array[c];
            triangle++;
            filled++;
            if(filled >= rows){
              triangleOne = reallocRows(triangleOne, &rows, &cols);
            };
          };
        };

      };
    };
  };


  freeIntArray(triangleOne, &rows);
  printf("Trojuhelniku: %d\n", triangle);

  return 0;
}
