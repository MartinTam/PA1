#include <stdio.h>

int main(void){

  printf("ml' nob:\n");
  int vstup;

  if( (scanf("%d", &vstup) != 1) || (vstup < 1) || (vstup > 5) ){
    printf("luj\n");
    return 0;
  };



  switch(vstup)

    {
      case 1:
        printf("Qapla'\nnoH QapmeH wo' Qaw'lu'chugh yay chavbe'lu' 'ej wo' choqmeH may' DoHlu'chugh lujbe'lu'.\n");
        break;
      case 2:
        printf("Qapla'\nQu' buSHa'chugh SuvwI', batlhHa' vangchugh, qoj matlhHa'chugh, pagh ghaH SuvwI''e'.\n");
        break;
      case 3:
        printf("Qapla'\nqaStaHvIS wa' ram loS SaD Hugh SIjlaH qetbogh loD.\n");
        break;
      case 4:
        printf("Qapla'\nHa'DIbaH DaSop 'e' DaHechbe'chugh yIHoHQo'.\n");
        break;
      case 5:
        printf("Qapla'\nleghlaHchu'be'chugh mIn lo'laHbe' taj jej.\n");
        break;
    }


  return 0;
}
