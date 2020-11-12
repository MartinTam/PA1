#include <stdio.h>
#include <stdlib.h>

typedef struct{
  char name[50];
  int points;
}TSTUDENT;

TSTUDENT * readStudents ( int * nr ){
  TSTUDENT st;
  TSTUDENT * res = NULL;
  int max = 0;

  *nr = 0;

  printf("Vysledky:\n");

  while( scanf("%49s %d", st.name, &st.points) == 2 ){

    if ( *nr == max ){
      max += 100;                                                           //    Toto cele 'if' dela realloc //
      TSTUDENT * tmp = (TSTUDENT *) malloc ( max * sizeof( *tmp ) );
      for (int i = 0; i < *nr; i++){
        tmp[i]=res[i];
      };
      free(res);
      res = tmp;
    };
    
    res[*nr] = st;
    (*nr)++;
  };

  if ( ! feof(stdin) || *nr==0 ){
    free(res);
    return NULL;
  };

  return res;
}


int main(void){

  int nr;
  TSTUDENT * list = readStudents( &nr );

  return 0;
}
