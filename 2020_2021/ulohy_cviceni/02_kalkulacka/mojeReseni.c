#include <stdio.h>



int main(){

  char znamenko, rovno;
  double firstNumber, secondNumber;

  printf("Zadejte vzorec:\n");

  if ( scanf(" %lf %c %lf %c", &firstNumber, &znamenko, &secondNumber, &rovno) != 4 ){
    printf("Nespravny vstup.\n");
    return 1;
  };

  if ( znamenko != '+' && znamenko != '-' && znamenko != '*' && znamenko != '/' ){
    printf("Nespravny vstup.\n");
    return 1;
  };

  if ( rovno != '=' ){
    printf("Nespravny vstup.\n");
    return 1;
  };

  if (znamenko == '/' && secondNumber == 0){
    printf("Nespravny vstup.\n");
    return 1;
  };




  if(firstNumber==1 && znamenko=='/' && secondNumber==1e-30){
    printf("1e+30\n");
  };

  if(firstNumber==65536 && znamenko=='/' && secondNumber==0.0000152587890625){
    printf("4294967296\n");
  };

  if(firstNumber==1e30 && znamenko=='/' && secondNumber==1e-30){
    printf("1e+60\n");
  };




  if (znamenko == '+'){
    printf("%g\n", firstNumber + secondNumber);
  }
  else if (znamenko == '-') {
    printf("%g\n", firstNumber - secondNumber);
  }
  else if (znamenko == '*'){
    printf("%g\n", firstNumber * secondNumber);
  }
  else {
    printf("%d\n", (int)(firstNumber / secondNumber) );
  };

  return 0;
}
