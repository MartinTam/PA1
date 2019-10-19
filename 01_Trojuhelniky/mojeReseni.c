#include <stdio.h>

int main(){

  // double a1, b1, c1, a2, b2, c2, t1u1, t1u2, t2u1, t2u2;
  // char t1s1, t1s2, t1s3, t2s1, t2s2, t2s3;

  double tr1_va1, tr1_va2, tr1_va3, tr2_va1, tr2_va2, tr2_va3;
  char tr1_ch1, tr1_ch2, tr1_ch3, tr2_ch1, tr2_ch2, tr2_ch3;








// ========================================================================================================================================================

// Triangle 1:




  printf("Trojuhelnik #1:\n");


  if ( scanf(" %c%c%c %lf %lf %lf", &tr1_ch1, &tr1_ch2, &tr1_ch3, &tr1_va1, &tr1_va2, &tr1_va3) != 6 ){
    printf("Nespravny vstup.\n");
    return 1;
  };




  if ( tr1_ch1 != 'S' || tr1_ch1 != 'U' || tr1_ch2 != 'S' || tr1_ch2 != 'U' || tr1_ch3 != 'S' || tr1_ch3 != 'U' || tr1_va1 <= 0 ||
        tr1_va2 <= 0 || tr1_va3 <= 0 ){
    printf("Nespravny vstup.\n");
    return 1;
  };






  if ( tr1_ch1 == 'S' && tr1_ch2 == 'S' && tr1_ch3 == 'S' ){

            if ( tr1_va1 > tr1_va2 ){
              double tmp = tr1_va1;
              tr1_va1 = tr1_va2;
              tr1_va2 = tmp;
            };

            if ( tr1_va2 > tr1_va3 ){
              double tmp = tr1_va2;
              tr1_va2 = tr1_va3;
              tr1_va3 = tmp;
            };



                      if ( tr1_va1 + tr1_va2 <= tr1_va3 ){
                        printf("Vstup netvori trojuhelnik.\n");
                        return 1;
                      };

  }
  else if ( tr1_ch1 == 'S' && tr1_ch2 == 'U' && tr1_ch3 == 'S' ){

            if (tr1_va2 >= 180){
              printf("Nespravny vstup.\n");
              return 1;
            };


  }
  else if ( tr1_ch1 == 'U' && tr1_ch2 == 'S' && tr1_ch3 == 'U' ){

            if ( tr1_va1 >= 180 || tr1_va3 >= 180 ){
              printf("Nespravny vstup.\n");
              return 1;
            }
            else if ( tr1_va1 + tr1_va3 >= 180 ){
              printf("Vstup netvori trojuhelnik.\n");
            };

  }
  else{
    printf("Nespravny vstup.\n");
    return 1;
  };










// ===========================================================================================================================================================

// Triangle 2:




  printf("Trojuhelnik #2:\n");


  if ( scanf(" %c%c%c %lf %lf %lf", &tr2_ch1, &tr2_ch2, &tr2_ch3, &tr2_va1, &tr2_va2, &tr2_va3) != 6 ){
    printf("Nespravny vstup.\n");
    return 1;
  };




  if ( tr2_ch1 != 'S' || tr2_ch1 != 'U' || tr2_ch2 != 'S' || tr2_ch2 != 'U' || tr2_ch3 != 'S' || tr2_ch3 != 'U' || tr2_va1 <= 0 ||
        tr2_va2 <= 0 || tr2_va3 <= 0 ){
    printf("Nespravny vstup.\n");
    return 1;
  };




  if ( tr2_ch1 == 'S' && tr2_ch2 == 'S' && tr2_ch3 == 'S' ){

                if ( tr2_va1 > tr2_va2 ){
                  double tmp = tr2_va1;
                  tr2_va1 = tr2_va2;
                  tr2_va2 = tmp;
                };

                if ( tr2_va2 > tr2_va3 ){
                  double tmp = tr2_va2;
                  tr2_va2 = tr2_va3;
                  tr2_va3 = tmp;
                };



                          if ( tr2_va1 + tr2_va2 <= tr2_va3 ){
                            printf("Vstup netvori trojuhelnik.\n");
                            return 1;
                          };


  }
  else if ( tr2_ch1 == 'S' && tr2_ch2 == 'U' && tr2_ch3 == 'S' ){

                if (tr2_va2 >= 180){
                  printf("Nespravny vstup.\n");
                  return 1;
                };

  }
  else if ( tr2_ch1 == 'U' && tr2_ch2 == 'S' && tr2_ch3 == 'U' ){

                if ( tr2_va1 >= 180 || tr2_va3 >= 180 ){
                  printf("Nespravny vstup.\n");
                  return 1;
                }
                else if ( tr2_va1 + tr2_va3 >= 180 ){
                  printf("Vstup netvori trojuhelnik.\n");
                };

  }
  else{
    printf("Nespravny vstup.\n");
    return 1;
  };









// ====================================================================================================================================================

// Next step:








  return 0;
}
