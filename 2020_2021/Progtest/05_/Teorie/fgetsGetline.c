#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void){

  char needle[100];
  char * hayHeap = NULL;
  size_t hayHeapSize = 0;                             // 'size_t' je datovy typ pro indexy (bezznamenkove)

  fgets( needle, sizeof( needle ), stdin );           // naplni pole znaky do velikosi pole a pokud bude znaku vic, tak dalsi maji smulu

  getline( &hayHeap, &hayHeapSize, stdin );           // naplni pole znaky a pokud se pole naplni, tak ji dynamicky alokuje

  return 0;
}
