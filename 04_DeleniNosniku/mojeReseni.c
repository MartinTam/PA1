#include <stdio.h>
#include <stdlib.h>
#define ARRAY_MAX 500000

int intSortProc ( int * a, int * b )
{
  return ( *b < *a ) - ( *a < *b );
}

int main(){
  int i=0, e, plus = 0, err, pocetPrvku = 0;
  int array[ARRAY_MAX];
  long long int celkovySoucet = 0;

  printf("Zadejte delky:\n");

  while ( ( err = scanf("%d", &array[i++]) ) == 1){
    pocetPrvku++;
  };
  if (err != EOF){
    printf("Nespravny vstup.\n");
    return 1;
  };

  pocetPrvku += 1;

  if (pocetPrvku == 1){
    printf("Nespravny vstup.\n");
    return 1;
  };

  for (i=0; i<(pocetPrvku - 1); i++){
    if (array[i] <= 0 || array[i] > ARRAY_MAX){
      printf("Nespravny vstup.\n");
      return 1;
    };
  };

  for (i=0; i<(pocetPrvku - 1); i++){
    celkovySoucet += array[i];
  };

  if (pocetPrvku == 2){
    printf("Cena za deleni: 0\n");
    return 0;
  };

  for (e=0; e<(pocetPrvku - 3); e++){
    qsort ( array, pocetPrvku - 1, sizeof ( *array ), (int(*)(const void *, const void *))intSortProc );
    plus = array[e] + array[e+1];
    celkovySoucet += plus;
    array[e+1] = plus;
  };

  printf("Cena za deleni: %lld\n", celkovySoucet);

  return 0;
}
