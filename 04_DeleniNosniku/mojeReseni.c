#include <stdio.h>
#define ARRAY_MAX 500000

int readInput (int * array, int max, int count){
  int i = 0;
  int err;

  printf ("Zadejte delky:\n");
  while ( ( err = scanf("%d", array + i) ) == 1){

    if (array[i] <= 0 || array[i] > max){
      return 0;
    };
    i++;
    count += count;
  }
  if (err == EOF){
    return 1;
  }
  else if (err != EOF){
    return 0;
  };
  return 0;
}

int main(){
  int delky[ARRAY_MAX];
  int cnt = 0;
  int i;

  if ( ! readInput(delky, ARRAY_MAX, cnt)){
    printf("Nespravny vstup.\n");
    return 1;
  };

  readInput(delky, ARRAY_MAX, cnt);
  for (i=0; i<cnt; i++){
    printf("%d ", delky[i]);
  };



  return 0;
}
