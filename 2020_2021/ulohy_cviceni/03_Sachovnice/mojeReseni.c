#include <stdio.h>

void prvniAposledniRadek(int pocetPoli_krat_velikostPole){                        // Funkce pro vypis prvniho a posledniho radku (ramecek) sachovnice.

  int i;

  printf("+");
  for( i = 0 ; i < pocetPoli_krat_velikostPole ; i++ ){
    printf("-");
  };
  printf("+\n");
}

void sachovnice(int x, int pole){                                                 // Funkce pro vypis cele vnitrni sachovnice.

  int a, b, pocetPoliNaRadek=0, c, pocetZnaku=0, pocetRadku=0;

  while (pocetRadku < pole){

            for( c = 0 ; c < x ; c++ ){
              printf("|");

              while( pocetPoliNaRadek < pole ){

                while( pocetZnaku < x){

                  for( a = 0 ; a < x ; a++ ){
                    printf(" ");
                  };
                  pocetPoliNaRadek++;

                  if(pocetPoliNaRadek == pole){
                    break;
                  };

                  for( b = 0 ; b < x ; b++ ){
                    printf("X");
                  };
                  pocetPoliNaRadek++;
                  if(pocetPoliNaRadek == pole){
                    break;
                  };
                };

              };

              printf("|\n");
              pocetPoliNaRadek=0;
            };

      pocetRadku++;
      pocetZnaku=0;

      if (pocetRadku == pole){
        break;
      };

            for( c = 0 ; c < x ; c++ ){
              printf("|");

              while( pocetPoliNaRadek < pole ){

                while( pocetZnaku < x){

                  for( a = 0 ; a < x ; a++ ){
                    printf("X");
                  };
                  pocetPoliNaRadek++;

                  if(pocetPoliNaRadek == pole){
                    break;
                  };

                  for( b = 0 ; b < x ; b++ ){
                    printf(" ");
                  };
                  pocetPoliNaRadek++;
                  if(pocetPoliNaRadek == pole){
                    break;
                  };
                };

              };

              printf("|\n");
              pocetPoliNaRadek=0;
            };
        pocetRadku++;
        if (pocetRadku == pole){
          break;
        };
    };
}

int main(){

  int pocetPoli, velikostPole, nasobek;

  printf("Zadejte pocet poli:\n");
  if ( (scanf(" %d", &pocetPoli) != 1) || pocetPoli <= 0 ){
    printf("Nespravny vstup.\n");
    return 1;
  };

  printf("Zadejte velikost pole:\n");
  if ( (scanf(" %d", &velikostPole) != 1) || velikostPole <= 0 ){
    printf("Nespravny vstup.\n");
    return 1;
  };

  nasobek = pocetPoli * velikostPole;

  prvniAposledniRadek(nasobek);
  sachovnice(velikostPole, pocetPoli);
  prvniAposledniRadek(nasobek);

  return 0;
}
