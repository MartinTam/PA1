#include <stdio.h>
#define ARRAY_MAX 500000

int main(){

  int array[20];
  int i=0;

  printf("Zadejte delky:\n");
  while ( ( err = scanf("%d", &array[i++]) ) == 1){

  };
  if (err != EOF){
    printf("Nespravny vstup.\n");
    return 1;
  };

  printf("\n");

  for (i=0; i<20; i++){
    printf("%d\n", array[i]);
  };



  return 0;
}
