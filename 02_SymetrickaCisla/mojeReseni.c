#include <stdio.h>
#include <math.h>

// Prevod cisla z desitkove do jine soustavy:

void convert(int number, int base){

  int i, r, digit, p, count=0;
  char a[100];// clrscr();

  p=number;

  do{

      r=p%base;
      digit='0'+r;
      if(digit>'9')
          digit=digit+39;
      a[count]=digit;
      count++;
      p=p/base;

     }while(p!=0);

  for(i=count-1;i>=0;--i)
     printf("%c",a[i]);
}






int main(){
  /*
  char vystup;
  int zaklad, from, to;
  */













  /*
  printf("Vstupni intervaly:\n");

  // OSETRENI VSTUPU:

  if (scanf(" %c", &vystup) != 1){
    printf("Nespravny vstup.\n");
    return 1;
  };

  if (vystup == 'c' || vystup == 'l'){

    if ( (scanf("%d %d %d", &zaklad, &from, &to) != 3) || zaklad < 2 || zaklad > 36 || from < 0 || from > to ){
      printf("Nespravny vstup.\n");
      return 1;
    };

    printf("Dobre.\n");

  }
  else{
    printf("Nespravny vstup.\n");
  };
  */






  return 0;
}
