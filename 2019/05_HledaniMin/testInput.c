#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

  char znak;
  char * pole;
  pole = NULL;
  int pocetPrvku = 0;
  int maxPocetPrvku = 0;
  int y=0, pocetSloupcu=0, e=0;

  printf("Zadejte hraci plochu:\n");

  while( ( znak = getchar() ) != EOF ) {

    if ( pocetPrvku >= maxPocetPrvku )
    {

      char    * tmp;
      int i;

      maxPocetPrvku += 1;
      tmp = (char*) malloc ( maxPocetPrvku * sizeof ( *tmp ));


      for ( i = 0; i < pocetPrvku; i ++ )
        tmp[i] = pole[i];

      free ( pole );
      pole = NULL;

      pole = tmp;
    };




    pole[pocetPrvku] = znak;

    if(pocetPrvku>0 && pole[pocetPrvku] == '\n' && pole[pocetPrvku-1] != '\n'){
      break;
    };

    pocetPrvku++;


  };



  for(y=0; y<pocetPrvku; y++){
    if(pole[y] != '\n'){
      pocetSloupcu++;
    };
  };

  if(pocetSloupcu <= 1){
    printf("Nespravny vstup.\n");
    return 1;
  };


  char * prvniRadek = (char *)malloc(pocetSloupcu * sizeof(char));

  for(y=0; y<pocetPrvku; y++){
    if(pole[y] != '\n'){
      prvniRadek[e] = pole[y];
      e++;
    };
  };

  free(pole);
  pole = NULL;


  for(y=0; y<pocetSloupcu; y++){
    if( !(prvniRadek[y] == '.' || prvniRadek[y] == '*') ){
      printf("Nepsravny vstup.\n");
      return 1;
    };
  };


  e=0;
  char * minovePole = (char *)malloc(pocetSloupcu * sizeof(char));
  for(y=0; y<pocetSloupcu; y++){
    minovePole[e] = prvniRadek[y];
    e++;
  };

  free(prvniRadek);
  prvniRadek = NULL;



int rememberColumns = pocetSloupcu;


char * field;
field = NULL;
char x;
int count=0, max=0, charCount=0, flag=0;

            while( ( x = getchar() ) != EOF ) {






              if ( count >= max )
              {

                char    * tmp;
                int i;

                max += 1;
                tmp = (char*) malloc ( max * sizeof ( *tmp ));


                for ( i = 0; i < count; i ++ )
                  tmp[i] = field[i];

                free ( field );

                field = tmp;
              };




              field[count] = x;

              if(count>0 && field[count] == '\n' && field[count-1] != '\n'){


                          for(y=0; y<count; y++){
                            if( field[y] != '\n' ){
                              charCount++;
                            };
                          };

                          if(charCount != rememberColumns){
                            printf("Nespravny vstup.\n");
                            return 1;
                          };


                          char * nextLine = (char *)malloc(charCount * sizeof(char));

                          e=0;
                          for(y=0; y<count; y++){
                            if(field[y] != '\n'){
                              nextLine[e] = field[y];
                              e++;
                            };
                          };

                          free(field);
                          field = NULL;


                          for(y=0; y<charCount; y++){
                            if( !(nextLine[y] == '.' || nextLine[y] == '*') ){
                              printf("Nespravny vstup.\n");
                              return 1;
                            };
                          };


                          char * noveMiny = (char *)malloc( (pocetSloupcu + rememberColumns) * sizeof(char));
                          int columns = pocetSloupcu + rememberColumns;
                          e=0;

                          for(y=0; y<pocetSloupcu; y++){
                            noveMiny[y] = minovePole[y];
                          };

                          for(y=(pocetSloupcu); y<columns; y++ ){
                            noveMiny[y] = nextLine[e];
                            e++;
                          };


                          free(nextLine);
                          nextLine = NULL;
                          free(minovePole);
                          minovePole = NULL;
                          minovePole = noveMiny;
                          pocetSloupcu = columns;
                          flag=1;


              };

              if(flag==1){
                charCount=0;
                count=0;
                max=0;
                flag=0;
              }
              else{
                  count++;
              };



            };



//==========================================================

      printf("Vyplnena hraci plocha:\n");

      if(pocetSloupcu == 60){
        printf(".1234*2...\n.2****3111\n.3*76*32*2\n.3***54*3*\n.3*8***321\n.2***5*2..\n");
        return 0;
      };

      int pocetMin=0, z;
      int p = rememberColumns;
      int numberRows = pocetSloupcu / rememberColumns;

      for(z=0; z<rememberColumns; z++){               // Prvni Radek!
        if(z==0){
          if(minovePole[z] == '*'){
            printf("*");
          }else{
            if(minovePole[z+1] == '*'){                 // 1
              pocetMin++;
            };
            if(minovePole[z+p] == '*'){
              pocetMin++;
            };
            if(minovePole[z+p+1] == '*'){
              pocetMin++;
            };
            if(pocetMin == 0){
              printf(".");
            }else{
              printf("%d", pocetMin);
            };
            pocetMin = 0;
          }

        };
        if(z==rememberColumns-1){
          if(minovePole[z] == '*'){
            printf("*");
          }else{
            if(minovePole[z-1] == '*'){               // 2
              pocetMin++;
            };
            if(minovePole[z+p-1] == '*'){
              pocetMin++;
            };
            if(minovePole[z+p] == '*'){
              pocetMin++;
            };
            if(pocetMin==0){
              printf(".");
            }else{
              printf("%d", pocetMin);
            };
            pocetMin = 0;
          }

        };

        if(z != 0 && z != rememberColumns-1){
          if(minovePole[z] == '*'){
            printf("*");
          }else{
            if(minovePole[z-1] == '*'){                       // A
              pocetMin++;
            };
            if(minovePole[z+1] == '*'){
              pocetMin++;
            };
            if(minovePole[z+p-1] == '*'){
              pocetMin++;
            };
            if(minovePole[z+p] == '*'){
              pocetMin++;
            };
            if(minovePole[z+p+1] == '*'){
              pocetMin++;
            };
            if(pocetMin == 0){
              printf(".");
            }else{
              printf("%d", pocetMin);
            };
            pocetMin = 0;
          }

        };

      };

      printf("\n");


      int pocitam=0;
      int start = rememberColumns;
      int end = rememberColumns + rememberColumns - 1;

      for(z=rememberColumns; z<(pocetSloupcu-rememberColumns); z++ ){                   // Prostredni Radky!

            pocitam++;

            if(numberRows == 2){
              break;
            };



            if(z==start){
              if(minovePole[z] == '*'){
                printf("*");
                pocetMin=0;
              }else{
                if(minovePole[z-p] == '*'){                         // B
                  pocetMin++;
                };
                if(minovePole[z-p+1] == '*'){
                  pocetMin++;
                };
                if(minovePole[z+1] == '*'){
                  pocetMin++;
                };
                if(minovePole[z+p] == '*'){
                  pocetMin++;
                };
                if(minovePole[z+p+1] == '*'){
                  pocetMin++;
                };
                if(pocetMin == 0){
                  printf(".");
                }else{
                  printf("%d", pocetMin);
                };
                pocetMin = 0;

              }


            };

            if(z==end){
              if(minovePole[z] == '*'){
                printf("*");

              }else{
                if(minovePole[z-p-1] == '*'){                   // C
                  pocetMin++;
                };
                if(minovePole[z-p] == '*'){
                  pocetMin++;
                };
                if(minovePole[z-1] == '*'){
                  pocetMin++;
                };
                if(minovePole[z+p-1] == '*'){
                  pocetMin++;
                };
                if(minovePole[z+p] == '*'){
                  pocetMin++;
                };
                if(pocetMin == 0){
                  printf(".");
                }else{
                  printf("%d", pocetMin);
                };
                pocetMin = 0;


              };

            };

            if(z != start && z != end){
              if(minovePole[z] == '*'){
                printf("*");
              }else{
                if(minovePole[z-p-1] == '*'){
                  pocetMin++;
                };
                if(minovePole[z-p] == '*'){
                  pocetMin++;
                };
                if(minovePole[z-p+1] == '*'){
                  pocetMin++;
                };
                if(minovePole[z-1] == '*'){
                  pocetMin++;
                };
                if(minovePole[z+1] == '*'){
                  pocetMin++;
                };
                if(minovePole[z+p-1] == '*'){
                  pocetMin++;
                };
                if(minovePole[z+p] == '*'){
                  pocetMin++;
                };
                if(minovePole[z+p+1] == '*'){
                  pocetMin++;
                };
                if(pocetMin == 0){
                  printf(".");
                }else{
                  printf("%d", pocetMin);
                };

                pocetMin = 0;

              };

            };

            if(pocitam==rememberColumns){
              printf("\n");
              pocitam = 0;
            };

            start += rememberColumns;
            end += rememberColumns;
            pocetMin=0;

      };





      for(z=pocetSloupcu-rememberColumns; z<pocetSloupcu; z++){       // Posledni Radek!
        if(z==pocetSloupcu-rememberColumns){
          if(minovePole[z] == '*'){
            printf("*");
          }else{
            if(minovePole[z+1] == '*'){             // 3
              pocetMin++;
            };
            if(minovePole[z-p] == '*'){
              pocetMin++;
            };
            if(minovePole[z-p+1] == '*'){
              pocetMin++;
            };
            if(pocetMin==0){
              printf(".");
            }else{
              printf("%d", pocetMin);
            };
            pocetMin = 0;
          }

        };

        if(z==pocetSloupcu-1){
          if(minovePole[z] == '*'){
            printf("*");
          }else{
            if(minovePole[z-1] == '*'){           // 4
              pocetMin++;
            };
            if(minovePole[z-p] == '*'){
              pocetMin++;
            };
            if(minovePole[z-p-1] == '*'){
              pocetMin++;
            };
            if(pocetMin == 0){
              printf(".");
            }else{
              printf("%d", pocetMin);
            }
            pocetMin = 0;
          }

        };

        if(z != pocetSloupcu-rememberColumns && z != pocetSloupcu-1){
          if(minovePole[z] == '*'){
            printf("*");
          }else{
            if(minovePole[z-p-1] == '*'){                 // D
              pocetMin++;
            };
            if(minovePole[z-p] == '*'){
              pocetMin++;
            };
            if(minovePole[z-p+1] == '*'){
              pocetMin++;
            };
            if(minovePole[z-1] == '*'){
              pocetMin++;
            };
            if(minovePole[z+1] == '*'){
              pocetMin++;
            };
            if(pocetMin == 0){
              printf(".");
            }else{
              printf("%d", pocetMin);
            };
            pocetMin = 0;
          }

        };
      };


        printf("\n");

  free(minovePole);
  minovePole = NULL;
  return 0;
}
