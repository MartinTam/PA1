#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char * removeSpaces( char * array, size_t * lastIndex ){
  char * point = &array[0];
  char * result = &array[0];

  size_t i=0, x=0;

  for(size_t c = 0; c < *lastIndex; c++){
    if(! isspace(array[c])){
      result[i] = point[x];
      x++;
      i++;
    }else{
      x++;
    };
  };

  *lastIndex = i;
  return result;
}

int isPalindrome( char * array, size_t * lastIndex ){

  size_t i=0, x=*lastIndex-1;
  int flag=0;

  for(size_t c = 0; c < *lastIndex/2; c++){
    if( array[i] == array[x] ){
      i++;
      x--;
    }else{
      flag=1;
    };
  };

  if(flag==0){
    return 1;       // Case sensitive
  };

  i=0;
  x=*lastIndex-1;
  flag=0;

  for(size_t c = 0; c < *lastIndex/2; c++){
    if( toupper(array[i]) == toupper(array[x]) ){
      i++;
      x--;
    }else{
      flag=1;
    };
  };

  if(flag==0){
    return 2;       // Case insensitive
  };

  return 0;         // NOT a palindrome
}

int main(void){

  printf("Zadejte retezec:\n");

  while(1){

    char * array = NULL;
    size_t size = 0;

    ssize_t read = getline(&array, &size, stdin);

    if((read < 0 || (strlen(array) == 0)) && feof(stdin) ){
      free(array);
      return 0;
    };

    if( (strlen(array)!=0) && feof(stdin)){
      printf("Nespravny vstup.\n");
      free(array);
      return 1;
    };


    if(array[0] == '\n'){
      printf("Nespravny vstup.\n");
      free(array);
      return 1;
    };

    size_t lastIndex = strlen(array) - 1;
    array[lastIndex] = '\0';

    size_t space=0;

    for(size_t c = 0; c < lastIndex; c++){
      if( isspace(array[c]) ){
        space++;
      };
    };


    if(space==strlen(array)){
      printf("Nespravny vstup.\n");
      free(array);
      return 1;
    };

    array = removeSpaces(array, &lastIndex);

    if(isPalindrome(array, &lastIndex) == 1){
      printf("Retezec je palindrom (case-sensitive).\n");
    }else if(isPalindrome(array, &lastIndex) == 2){
      printf("Retezec je palindrom (case-insensitive).\n");
    }else{
      printf("Retezec neni palindrom.\n");
    }

    free(array);
    array=NULL;
  };

  return 0;
}
