#include<stdio.h>
#include <string.h>


int main()
  {

    int number, base;

    int r, digit, p, count=0;
    char a[100];// clrscr();
    int vysledek;



    printf("Zadej cislo v desitkove soustave:\n");
    scanf("%d", &number);
    printf("Zadej zaklad pro prevod:\n");
    scanf("%d", &base);



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




       if (vysledek == 0){
         printf("Palindrom.\n");
       }
       else if (vysledek == 1){
         printf("Neni palindrom.\n");
       };








    return 0;

  }
