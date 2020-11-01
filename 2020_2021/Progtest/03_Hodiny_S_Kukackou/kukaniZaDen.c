#include <stdio.h>

int zakukej(int h){
  int zakuka = 0;
  if (h == 0){
    zakuka += 12;
    return zakuka;
  };
  if (h <= 12){
    zakuka += h;
  }else {
    zakuka += h - 12;
  };
  return zakuka;
}

int kukaniZaDen(int h1, int i1, int h2, int i2){

  int kukani = 0;
  int start = h1 + 1;

  if (h1==h2){
    if ( i1==0 ){
      kukani += zakukej(h1);
    };
    if ( (i1 <= 30) && (i2 >= 30) ){
      kukani += 1;
    };
    return kukani;
  }else {
    if (i1==0){
      kukani += zakukej(h1) + 1;
    }else if (i1 <= 30){
      kukani += 1;
    };
    if (start == h2){
      kukani += zakukej(h2);
    }else {
        while ( start < h2){
          kukani += zakukej(start) + 1;
          start++;
          if (start == h2){
            kukani += zakukej(h2);
            break;
          };
        };
    };
    if (i2 >= 30){
      kukani += 1;
    };
  };
  return kukani;
}

int main(){

  int h1=13, i1=15, h2=18, i2=45;

  printf("Kukani = %d\n", kukaniZaDen(h1, i1, h2, i2));

  return 0;
}
