
#include<stdio.h>








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



























int main()
  {

    int cislo, zaklad;

    printf("Zadej cislo v desitkove soustave:\n");
    scanf("%d", &cislo);
    printf("Zadej zaklad pro prevod:\n");
    scanf("%d", &zaklad);

    convert(cislo, zaklad);
    printf("\n");


/*
      int b,n,i,r,digit,p,count=0;
      char a[100];// clrscr();



      printf("\nEnter the decimal number:\n");
     scanf("%d",&n);
      printf("\nEnter the base to be converted:\n");
    scanf("%d",&b);





      p=n;


      do{

          r=p%b;
          digit='0'+r;
          if(digit>'9')
              digit=digit+7;
          a[count]=digit;
          count++;
          p=p/b;

         }while(p!=0);



      printf("\nbase %d equivalent of num %d is ",b,n);
      for(i=count-1;i>=0;--i)
        printf("%c",a[i]);
    printf(".\n");

*/







    return 0;

  }
