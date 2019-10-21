#include <stdio.h>
#include <math.h>
#include <float.h>

int main(){

  double tr1_va1, tr1_va2, tr1_va3, tr2_va1, tr2_va2, tr2_va3,
          a, b, c, x, y, z;
  char tr1_ch1, tr1_ch2, tr1_ch3, tr2_ch1, tr2_ch2, tr2_ch3;
  int shodne = 0, podobne = 0;


// ========================================================================================================================================================

// Triangle 1:










































  printf("Trojuhelnik #1:\n");


  if ( scanf(" %c%c%c", &tr1_ch1, &tr1_ch2, &tr1_ch3 ) != 3 ){
    printf("Nespravny vstup.\n");
    return 1;
  };

  if ( ( scanf("%lf %lf %lf", &tr1_va1, &tr1_va2, &tr1_va3 ) !=3 ) || tr1_va1 <= 0 || tr1_va2 <= 0 || tr1_va3 <= 0 ){
    printf("Nespravny vstup.\n");
    return 1;
  };




  if ( tr1_ch1 == 'S' && tr1_ch2 == 'S' && tr1_ch3 == 'S' ){

          if ( tr1_va1 + tr1_va2 <= tr1_va3 ){
            printf("Vstup netvori trojuhelnik.\n");
            return 1;
          };




          a = tr1_va1;
          b = tr1_va2;
          c = tr1_va3;








  }
  else if ( tr1_ch1 == 'S' && tr1_ch2 == 'U' && tr1_ch3 == 'S' ){

            if (tr1_va2 >= 180){
              printf("Nespravny vstup.\n");
              return 1;
            };



            double alpha = tr1_va2 * (M_PI/180);

            a = tr1_va1;
            b = tr1_va3;
            c = sqrt( (a*a) + (b*b) - (2*a*b*cos(alpha)) );








  }
  else if ( tr1_ch1 == 'U' && tr1_ch2 == 'S' && tr1_ch3 == 'U' ){

            if ( tr1_va1 >= 180 || tr1_va3 >= 180 ){
              printf("Nespravny vstup.\n");
              return 1;
            }
            else if ( tr1_va1 + tr1_va3 >= 180 ){
              printf("Vstup netvori trojuhelnik.\n");
              return 1;
            };



            double alpha = tr1_va1 * (M_PI/180);
            double beta = tr1_va3 * (M_PI/180);
            double gama = ( 180 - (tr1_va1 + tr1_va3) ) * (M_PI/180);

            a = tr1_va2;
            b = a * (sin(alpha) / sin(gama));
            c = a * (sin(beta) / sin(gama));







  }
  else{
    printf("Nespravny vstup.\n");
    return 1;
  };




  if ( a > b ){
    double tmp = b;
    b = a;
    a = tmp;
  };

  if ( b > c ){
    double tmp = c;
    c = b;
    b = tmp;
  };

  if ( a > b ){
    double tmp = b;
    b = a;
    a = tmp;
  };


// ===========================================================================================================================================================

// Triangle 2:











































  printf("Trojuhelnik #2:\n");


  if ( scanf(" %c%c%c", &tr2_ch1, &tr2_ch2, &tr2_ch3 ) != 3 ){
    printf("Nespravny vstup.\n");
    return 1;
  };

  if ( ( scanf("%lf %lf %lf", &tr2_va1, &tr2_va2, &tr2_va3 ) !=3 ) || tr2_va1 <= 0 || tr2_va2 <= 0 || tr1_va2 <= 0 ){
    printf("Nespravny vstup.\n");
    return 1;
  };




  if ( tr2_ch1 == 'S' && tr2_ch2 == 'S' && tr2_ch3 == 'S' ){

          if ( tr2_va1 + tr2_va2 <= tr2_va3 ){
            printf("Vstup netvori trojuhelnik.\n");
            return 1;
          };




          x = tr2_va1;
          y = tr2_va2;
          z = tr2_va3;








  }
  else if ( tr2_ch1 == 'S' && tr2_ch2 == 'U' && tr2_ch3 == 'S' ){

            if (tr2_va2 >= 180){
              printf("Nespravny vstup.\n");
              return 1;
            };



            double alpha = tr2_va2 * (M_PI/180);

            x = tr2_va1;
            y = tr2_va3;
            z = sqrt( (x*x) + (y*y) - (2*x*y*cos(alpha)) );








  }
  else if ( tr2_ch1 == 'U' && tr2_ch2 == 'S' && tr2_ch3 == 'U' ){

            if ( tr2_va1 >= 180 || tr2_va3 >= 180 ){
              printf("Nespravny vstup.\n");
              return 1;
            }
            else if ( tr2_va1 + tr2_va3 >= 180 ){
              printf("Vstup netvori trojuhelnik.\n");
              return 1;
            };



            double alpha = tr2_va1 * (M_PI/180);
            double beta = tr2_va3 * (M_PI/180);
            double gama = ( 180 - (tr2_va1 + tr2_va3) ) * (M_PI/180);

            x = tr2_va2;
            y = x * (sin(alpha) / sin(gama));
            z = x * (sin(beta) / sin(gama));







  }
  else{
    printf("Nespravny vstup.\n");
    return 1;
  };


  if ( x > y ){
    double tmp = y;
    y = x;
    x = tmp;
  };

  if ( y > z ){
    double tmp = z;
    z = y;
    y = tmp;
  };

  if ( x > y ){
    double tmp = y;
    y = x;
    x = tmp;
  };



// ====================================================================================================================================================

// Next step:







































  if ( (a==x) && (b==y) && (c==z) ){
    shodne = 1;
  }
  else{
    shodne = 0;
  };

  if ( fabs( (a/x)-(b/y) ) < 1e-10 && fabs( (b/y)-(c/z) ) < 1e-10 && fabs( (a/x)-(c/z) ) < 1e-10 ){
    podobne = 1;
  }
  else{
    podobne = 0;
  };


  //printf("Triangle 1 = %0.20f %0.20f %0.20f\n", a, b, c);
  //printf("Triangle 2 = %0.20f %0.20f %0.20f\n", x, y, z);


  if ( shodne == 1 ){
    printf("Trojuhelniky jsou shodne.\n");
    return 0;
  }
  else if ( shodne == 0 && podobne == 1 ){
    printf("Trojuhelniky nejsou shodne, ale jsou podobne.\n");
    return 0;
  }
  else if ( shodne == 0 && podobne == 0 ){
    printf("Trojuhelniky nejsou shodne ani podobne.\n");
    return 0;
  };

return 0;

}
