#include <stdio.h>          // fgets(),
#include <string.h>         // getline(), strlen(), ...
#include <stdlib.h>         // malloc(), realloc(), free(), ...

#define ADD '+'
#define MAX 100

void foo ( const char * str ){
  // 'const' znamena read only
}

int loadInput( char * str, int * len ){

  int code;

  if ( ( code = scanf(" %10s", str) ) == EOF ){
    return EOF;
  }else if ( code != 1 ){
    return 0;
  }else{
    return 1;
  };

}

int main (void){

  char * str = (char *)malloc(sizeof(*str) * 10);
  int len = 10;

  while ( loadInput(str, &len) == 1 ){
    // ... //
  };

  if ( loadInput(str, &len) != EOF ){
    printf("Nespravny vstup.\n");
    return 1;
  };

  int number = ( len == 10 ? 1 : 2 );     // pokud v 'len' je 10, pak number=1, jinak number=2

  return 0;
}
