#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(void){



  do{
    char * array = NULL;
    size_t size = 0;


    getline(&array, &size, stdin);

    printf("%zu\n", strlen(array));

    free(array);
  }while(! feof(stdin));



  return 0;
}
