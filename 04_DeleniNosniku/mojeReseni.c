#include <stdio.h>
#include <stdlib.h>
#define ARRAY_MAX 500000

int intSortProc ( int * a, int * b )
{
  return ( *b < *a ) - ( *a < *b );
}


int main(){
  int celkovySoucet = 0;
  int array[ARRAY_MAX];
  int i, e;
  int plus = 0;
  int err;
  int pocetPrvku = 0;


  while ( ( err = scanf("%d", &array[i++]) ) == 1){
    pocetPrvku++;
  };
  if (err != EOF){
    printf("Nespravny vstup.\n");
    return 1;
  };


  for (i=0; i<11; i++){
    celkovySoucet += array[i];
  };

  for (e=0; e<9; e++){
    qsort ( array, 11, sizeof ( *array ), (int(*)(const void *, const void *))intSortProc );
    plus = array[e] + array[e+1];
    celkovySoucet += plus;
    array[e] = 0;
    array[e+1] = plus;
  };

  printf("Cena za deleni: %d\n", celkovySoucet);

  return 0;
}
