#ifndef __PROGTEST__
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#endif /* __PROGTEST__ */

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


void rotateArray ( int array [], int arrayLen, int rotateBy )
{
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

#ifndef __PROGTEST__
/*
int identicalArrays ( const int a[], const int b[], int cnt )
{

}
*/
int main (int argc, char * argv [])
{
  int in0 []  = { 1, 2, 3, 4, 5 };
  int out0 [] = { 5, 1, 2, 3, 4 };

  int in1 []  = { 1, 2, 3, 4, 5 };
  int out1 [] = { 2, 3, 4, 5, 1 };

  int in2 []  = { 1, 2, 3, 4, 5, 6 };
  int out2 [] = { 4, 5, 6, 1, 2, 3 };

  int in3 []  = { 1, 2, 3, 4, 5, 6, 7 };
  int out3 [] = { 3, 4, 5, 6, 7, 1, 2 };

  int in4 []  = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
  int out4 [] = { 2, 3, 4, 5, 6, 7, 8, 9, 1 };

  rotateArray ( in0, 5, 1 );
  assert ( identicalArrays ( in0, out0, 5 ) );
  rotateArray ( in1, 5, -1 );
  assert ( identicalArrays ( in1, out1, 5 ) );
  rotateArray ( in2, 6, -3 );
  assert ( identicalArrays ( in2, out2, 6 ) );
  rotateArray ( in3, 7, 12 );
  assert ( identicalArrays ( in3, out3, 7 ) );
  rotateArray ( in4, 9, -100 );
  assert ( identicalArrays ( in4, out4, 9 ) );
  return 0;
}
#endif /* __PROGTEST__ */
