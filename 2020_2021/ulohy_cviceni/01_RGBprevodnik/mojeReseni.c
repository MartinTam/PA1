#include <stdio.h>

void convert(int number, int base){

        int i, r, digit, p, count=0;
        char a[100];

        p=number;

        do{

            r=p%base;
            digit='0'+r;
            if(digit>'9')
                digit=digit+7;
            a[count]=digit;
            count++;
            p=p/base;

        }while(p!=0);

        if(count==1){
          printf("0");
        };

        for(i=count-1;i>=0;--i)
          printf("%c", a[i]);

}

int main(){

  char r, g, b, firstBracket, secondBracket, firstComma, secondComma;
  int firstNumber, secondNumber, thirdNumber;

  printf("Zadejte barvu v RGB formatu:\n");
  if ( scanf(" %c %c %c %c %d %c %d %c %d %c", &r, &g, &b, &firstBracket, &firstNumber, &firstComma, &secondNumber, &secondComma, &thirdNumber, &secondBracket) != 10 ){
    printf("Nespravny vstup.\n");
    return 1;
  };

  if(r != 'r' || g != 'g' || b != 'b' || firstBracket != '(' || secondBracket != ')' || firstComma != ',' || secondComma != ',' || secondBracket != ')'){
    printf("Nespravny vstup.\n");
    return 1;
  };

  if(firstNumber < 0 || firstNumber > 255 || secondNumber < 0 || secondNumber > 255 || thirdNumber < 0 || thirdNumber > 255){
    printf("Nespravny vstup.\n");
    return 1;
  };




  printf("#");
  convert(firstNumber, 16);
  convert(secondNumber, 16);
  convert(thirdNumber, 16);
  printf("\n");


  return 0;
}
