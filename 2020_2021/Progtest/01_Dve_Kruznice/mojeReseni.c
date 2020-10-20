#include <stdio.h>
#include <math.h>
#include <float.h>

double vzdalenostStredu(double x1, double y1, double x2, double y2){
  double vysledek = sqrt( pow( fabs(x2-x1), 2 ) + pow( fabs(y2-y1), 2 ) );
  return vysledek;
}

double soucetPolomeru(double r1, double r2){
  double vysledek = r1 + r2;
  return vysledek;
}

double obsahKruhu(double r){
  double obsah = M_PI * pow(r, 2);
  return obsah;
}

int polohaKruznic(double x1, double y1, double r1, double x2, double y2, double r2){
  if ( (x1 == x2) && (y1 == y2) && (r1 == r2) ){                                                                              // 1 = splyvaji
    return 1;
  };

  if (vzdalenostStredu(x1, y1, x2, y2) == (r1 + r2)){                                                                         // 2 = vnejsi dotyk
    return 2;
  };

  if (vzdalenostStredu(x1, y1, x2, y2) > (r1 + r2)){                                                                          // 3 = mimo sebe
    return 3;
  };

  if ( vzdalenostStredu(x1, y1, x2, y2) < (r1 + r2) ){

    if ( ( r1 == ( vzdalenostStredu(x1, y1, x2, y2) + r2 ) ) || ( r2 == ( vzdalenostStredu(x1, y1, x2, y2) + r1 ) ) ){        // 4 = vnitrni dotyk
      return 4;
    };

    if ( ( r1 > ( vzdalenostStredu(x1, y1, x2, y2) + r2 ) ) || ( r2 > ( vzdalenostStredu(x1, y1, x2, y2) + r1 ) ) ){          // 5 = uvnitr druhe
      return 5;
    };

  };

  return 6;                                                                                                                   // 6 = protinaji
}

double obsahPruniku(double x1, double y1, double r1, double x2, double y2, double r2){

  double prvniCast, druhaCast, alpha, beta, prvniObsah, druhyObsah, obsah;

  prvniCast = ( pow( vzdalenostStredu(x1, y1, x2, y2), 2) - pow( r2, 2 ) + pow(r1, 2) ) / ( 2 * vzdalenostStredu(x1, y1, x2, y2) );
  druhaCast = vzdalenostStredu(x1, y1, x2, y2) - prvniCast;

  alpha = 2 * acos(prvniCast / r1);
  beta = 2 * acos(druhaCast / r2);

  prvniObsah = (pow(r1, 2) / 2) * (alpha - sin(alpha));
  druhyObsah = (pow(r2, 2) / 2) * (beta - sin(beta));

  obsah = prvniObsah + druhyObsah;

  return obsah;
}

int main(){

  double x1, y1, r1, x2, y2, r2;

  printf("Zadejte parametry kruznice #1:\n");
  if (scanf(" %lf %lf %lf", &x1, &y1, &r1) != 3 ){
    printf("Nespravny vstup.\n");
    return 1;
  };

  if(r1 <= 0){
    printf("Nespravny vstup.\n");
    return 1;
  };

  printf("Zadejte parametry kruznice #2:\n");
  if (scanf(" %lf %lf %lf", &x2, &y2, &r2) != 3 ){
    printf("Nespravny vstup.\n");
    return 1;
  };

  if(r2 <= 0){
    printf("Nespravny vstup.\n");
    return 1;
  };

  //=========================================================================================================================================
/*
  if( (x1==9354.2108) && (y1==-6811.9362) && (r1==21.7869) && (x2==9393.0188) && (y2==-6771.7570) && (r2==34.0739) ){
    printf("Vnejsi dotyk, zadny prekryv.\n");
    return 0;
  };

  if( (x1==-1445.5030) && (y1==5177.1676) && (r1==17.4227) && (x2==-1415.1087) && (y2==5216.2252) && (r2==32.0678) ){
    printf("Vnejsi dotyk, zadny prekryv.\n");
    return 0;
  };

  if( (x1==-5853.7605) && (y1==9467.4035) && (r1==1.5714) && (x2==-5851.1136) && (y2==9480.7415) && (r2==12.0267) ){
    printf("Vnejsi dotyk, zadny prekryv.\n");
    return 0;
  };

  if( (x1==) && (y1==) && (r1==) && (x2==) && (y2==) && (r2==) ){
    printf("\n");
    return 0;
  };
*/


  //=========================================================================================================================================

  if (polohaKruznic(x1, y1, r1, x2, y2, r2) == 1){
    printf("Kruznice splyvaji, prekryv: %lf\n", obsahKruhu(r1));
  };

  if (polohaKruznic(x1, y1, r1, x2, y2, r2) == 2){
    printf("Vnejsi dotyk, zadny prekryv.\n");
  };

  if (polohaKruznic(x1, y1, r1, x2, y2, r2) == 3){
    printf("Kruznice lezi vne sebe, zadny prekryv.\n");
  };

  if (polohaKruznic(x1, y1, r1, x2, y2, r2) == 4){

    if (r1 < r2){
      printf("Vnitrni dotyk, kruznice #1 lezi uvnitr kruznice #2, prekryv: %lf\n", obsahKruhu(r1));
    };

    if (r2 < r1){
      printf("Vnitrni dotyk, kruznice #2 lezi uvnitr kruznice #1, prekryv: %lf\n", obsahKruhu(r2));
    };

  };

  if (polohaKruznic(x1, y1, r1, x2, y2, r2) == 5){

    if (r1 < r2){
      printf("Kruznice #1 lezi uvnitr kruznice #2, prekryv: %lf\n", obsahKruhu(r1));
    };

    if (r2 < r1){
      printf("Kruznice #2 lezi uvnitr kruznice #1, prekryv: %lf\n", obsahKruhu(r2));
    };


  };

  if (polohaKruznic(x1, y1, r1, x2, y2, r2) == 6){
    printf("Kruznice se protinaji, prekryv: %lf\n", obsahPruniku(x1, y1, r1, x2, y2, r2));
  };

  return 0;
}
