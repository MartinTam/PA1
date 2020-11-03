#include <stdio.h>

void rotacePoJednomKladny(int array[], int arrayLen){
  int tmp = array[arrayLen-1];
  int i;

  for (i=arrayLen-1; i > 0; i--){
    array[i] = array[i-1];
  };
  array[0] = tmp;
}

void rotacePoJednomZaporny(int array[], int arrayLen){
  int tmp = array[0];
  int i;

  for (i=0; i < arrayLen - 1; i++){
    array[i] = array[i+1];
  };
  array[arrayLen-1] = tmp;
}


void rotace(int array[], int arrayLen, int rotateBy){

  int i;

  if (rotateBy > 0){
    for (i=0; i < rotateBy; i++){
      rotacePoJednomKladny(array, arrayLen);
    };
  };

  if (rotateBy < 0){
    for (i=rotateBy; i < 0; i++){
      rotacePoJednomZaporny(array, arrayLen);
    };
  };

}

int main(){

  int pole[5] = {1,2,3,4,5};
  int velikost = 5;
  int i;

  printf("pole[%d] = { ", velikost);
  for(i=0; i<velikost; i++){
    printf("%d ", pole[i]);
  };
  printf("}\n");

  rotace(pole, velikost, 0);

  i = 0;

  printf("pole[%d] = { ", velikost);
  for(i=0; i<velikost; i++){
    printf("%d ", pole[i]);
  };
  printf("}\n");

  return 0;
}
