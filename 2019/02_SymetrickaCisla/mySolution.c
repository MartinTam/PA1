#include <stdio.h>

void convert(int number, int base){

        int i, r, digit, p, count=0;
        char a[100];

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
          printf("%c", a[i]);

}

int symetrickeCislo(int number, int base){

        int r, digit, p, count=0;
        char a[100];
        int vysledek;

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

       int i = count -1;
       int minus = i;

       if (i == 0){
         vysledek = 0;
         return vysledek;
       };

         for (i = count -1; i > (i/2); --i){
           if (a[i] == a[i-minus]){
             vysledek = 0;
           }
           else if (a[i] != a[i-minus]){
             vysledek = 1;
             break;
           };
           minus = minus -2;
         };

       return vysledek;     // 0 - symetricky; 1 - neni symetricky
}

int pocetSymetrickychCisel(int zaklad, int from, int to){
      int pocet = 0;
      int i;
      for(i = from; i <= to; i++){
        if(symetrickeCislo(i, zaklad) == 0){
          pocet = pocet + 1;
        };
      };
      return pocet;
}

void vypisSymetrickychCisel(int zaklad, int from, int to){
      int i;
      for (i = from; i <= to; i++){
        if(symetrickeCislo(i, zaklad) == 0){
          printf("%d = ", i);
          convert(i, zaklad);
          printf(" (%d)\n", zaklad);
        };
      };
}

int main(){

  char vystup;
  int zaklad, from, to, err;

  printf("Vstupni intervaly:\n");

      while ( (err = scanf(" %c", &vystup)) == 1){

                if (vystup == 'c' || vystup == 'l'){
                    if ( (scanf("%d %d %d", &zaklad, &from, &to) != 3) || zaklad < 2 || zaklad > 36 || from < 0 || from > to ){
                    printf("Nespravny vstup.\n");
                    return 1;
                  };
                  if(vystup == 'c'){
                    printf("Celkem: %d\n", pocetSymetrickychCisel(zaklad, from, to));
                  };

                  if (vystup == 'l'){
                    vypisSymetrickychCisel(zaklad, from, to);
                  };
                }
                else{
                  printf("Nespravny vstup.\n");
                  return 1;
                };

      };

      if (err != EOF){
        printf("Nespravny vstup.\n");
        return 1;
      };

  return 0;
}
