#include <stdio.h>
#include <math.h>
#include <float.h>

int main(){

  // double a1, b1, c1, a2, b2, c2, t1u1, t1u2, t2u1, t2u2;
  // char t1s1, t1s2, t1s3, t2s1, t2s2, t2s3;

  double tr1_va1, tr1_va2, tr1_va3, tr2_va1, tr2_va2, tr2_va3;
  char tr1_ch1, tr1_ch2, tr1_ch3, tr2_ch1, tr2_ch2, tr2_ch3;
  int shodne = 0, podobne = 0;








// ========================================================================================================================================================

// Triangle 1:




  printf("Trojuhelnik #1:\n");


  if ( scanf(" %c%c%c", &tr1_ch1, &tr1_ch2, &tr1_ch3 ) != 3 ){
    printf("Nespravny vstup.\n");
    return 1;
  };

  if ( scanf("%lf %lf %lf", &tr1_va1, &tr1_va2, &tr1_va3 ) !=3 ){
    printf("Nespravny vstup.\n");
    return 1;
  };




//  if ( tr1_ch1 != 'S' || tr1_ch1 != 'U' || tr1_ch2 != 'S' || tr1_ch2 != 'U' || tr1_ch3 != 'S' || tr1_ch3 != 'U' || tr1_va1 <= 0 ||
//        tr1_va2 <= 0 || tr1_va3 <= 0 ){
//    printf("Nespravny vstup.\n");
//    return 1;
//  };



  if ( tr1_va1 <= 0 || tr1_va2 <= 0 || tr1_va3 <= 0 ){
    printf("Nespravny vstup.\n");
    return 1;
  };




  if ( tr1_ch1 == 'S' && tr1_ch2 == 'S' && tr1_ch3 == 'S' ){




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
              return 1;
            };

  }
  else{                                                                             // mozna zbytecny !!!
    printf("Nespravny vstup.\n");
    return 1;
  };










// ===========================================================================================================================================================

// Triangle 2:




  printf("Trojuhelnik #2:\n");


  if ( scanf(" %c%c%c", &tr2_ch1, &tr2_ch2, &tr2_ch3 ) != 3 ){
    printf("Nespravny vstup.\n");
    return 1;
  };

  if ( scanf("%lf %lf %lf", &tr2_va1, &tr2_va2, &tr2_va3 ) !=3 ){
    printf("Nespravny vstup.\n");
    return 1;
  };




//  if ( tr2_ch1 != 'S' || tr2_ch1 != 'U' || tr2_ch2 != 'S' || tr2_ch2 != 'U' || tr2_ch3 != 'S' || tr2_ch3 != 'U' || tr2_va1 <= 0 ||
//        tr2_va2 <= 0 || tr2_va3 <= 0 ){
//    printf("Nespravny vstup.\n");
//    return 1;
//  };



if ( tr2_va1 <= 0 || tr2_va2 <= 0 || tr1_va2 <= 0 ){
  printf("Nespravny vstup.\n");
  return 1;
};



  if ( tr2_ch1 == 'S' && tr2_ch2 == 'S' && tr2_ch3 == 'S' ){



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
                  return 1;
                };

  }
  else{                                                                     // mozna zbytecny !!!
    printf("Nespravny vstup.\n");
    return 1;
  };









// ====================================================================================================================================================

// Next step:



//  printf("%c%c%c %lf %lf %lf\n", tr1_ch1, tr1_ch2, tr1_ch3, tr1_va1, tr1_va2, tr1_va3);
//  printf("%c%c%c %lf %lf %lf\n", tr2_ch1, tr2_ch2, tr2_ch3, tr2_va1, tr2_va2, tr2_va3);



// SSS vs SSS:

  if ( tr1_ch1 == 'S' && tr1_ch2 == 'S' && tr1_ch3 == 'S' &&  tr2_ch1 == 'S' && tr2_ch2 == 'S' && tr2_ch3 == 'S' ){

      // Serazeni delek stran tr1:

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

              if ( tr1_va1 > tr1_va2 ){
                double tmp = tr1_va1;
                tr1_va1 = tr1_va2;
                tr1_va2 = tmp;
              };



        // Serazeni delek stran tr2:

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

              if ( tr2_va1 > tr2_va2 ){
                double tmp = tr2_va1;
                tr2_va1 = tr2_va2;
                tr2_va2 = tmp;
              };




    // Shodnost:

      if ( tr1_va1 == tr2_va1 && tr1_va2 == tr2_va2 && tr1_va3 == tr2_va3 ){
        shodne = 1;
      }
      else{
        shodne = 0;
      };

    // Podobnost:

    if (   (tr1_va1 / tr2_va1) - (tr1_va2 / tr2_va2)  < 0.001  &&
           (tr1_va1 / tr2_va1) - (tr1_va3 / tr2_va3)  < 0.0001  &&
            (tr1_va2 / tr2_va2) - (tr1_va3 / tr2_va3)  < 0.0001 ){
        podobne = 1;
      }
      else{
        podobne = 0;
      };

    // Vypis:

                  if ( shodne == 1 && podobne == 1 ){
                    printf("Trojuhelniky jsou shodne.\n");
                    return 0;
                  }
                  else if ( shodne == 1 && podobne == 0 ){
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



  };




// SUS vs SUS:


if ( tr1_ch1 == 'S' && tr1_ch2 == 'U' && tr1_ch3 == 'S' &&  tr2_ch1 == 'S' && tr2_ch2 == 'U' && tr2_ch3 == 'S' ){

  // Prevod uhlu na radiany:

    double alpha = tr1_va2 * (M_PI/180);
    double omega = tr2_va2 * (M_PI/180);

  // Vypocet vsech stran:

    double a = tr1_va1;
    double b = tr1_va3;
    double c = sqrt( (a*a) + (b*b) - (2*a*b*cos(alpha)) );

    double x = tr2_va1;
    double y = tr2_va3;
    double z = sqrt( (x*x) + (y*y) - (2*x*y*cos(omega)) );

  // Serazeni stran:


                            // Serazeni delek stran tr1:

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



                              // Serazeni delek stran tr2:

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





  // Shodnost:

          if ( a==x && b==y && c==z ){
            shodne = 1;
          }
          else {
            shodne = 0;
          };

  // Podobnost:

        if ( ((a/x) == (b/y)) && ((b/y) == (c/z)) && ((a/x) == (c/z)) ){
          podobne = 1;
        }
        else {
          podobne = 0;
        };

  // Vypis:

        if ( shodne == 1 && podobne == 1 ){
          printf("Trojuhelniky jsou shodne.\n");
          return 0;
        }
        else if ( shodne == 1 && podobne == 0 ){
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


};












// USU vs USU:

      if ( tr1_ch1 == 'U' && tr1_ch2 == 'S' && tr1_ch3 == 'U' &&  tr2_ch1 == 'U' && tr2_ch2 == 'S' && tr2_ch3 == 'U' ){



        // Urceni vsech uhlu:


              double alph = tr1_va1;
              double bet = tr1_va3;
              double gam = 180 - (alph + bet);

              double epsilo = tr2_va1;
              double omeg = tr2_va3;
              double delt = 180 - (epsilo + omeg);

        // Na radiany:

              double alpha = alph * (M_PI/180);
              double beta = bet * (M_PI/180);
              double gama = gam * (M_PI/180);

              double epsilon = epsilo * (M_PI/180);
              double omega = omeg * (M_PI/180);
              double delta = delt * (M_PI/180);

        // Vypocet vsech stran:

              double a = tr1_va2;
              double b = a * (sin(alpha)/sin(beta));
              double c = a * (sin(gama)/sin(beta));

              double x = tr2_va2;
              double y = x * (sin(epsilon)/sin(omega));
              double z = x * (sin(delta)/sin(omega));



              // Serazeni delek uhlu tr1:

                      if ( alph > bet ){
                        double tmp = bet;
                        bet = alph;
                        alph = tmp;
                      };

                      if ( bet > gam ){
                        double tmp = gam;
                        gam = bet;
                        bet = tmp;
                      };

                      if ( alph > bet ){
                        double tmp = bet;
                        bet = alph;
                        alph = tmp;
                      };



                // Serazeni delek uhlu tr2:

                      if ( epsilo > omeg ){
                        double tmp = omeg;
                        omeg = epsilo;
                        epsilo = tmp;
                      };

                      if ( omeg > delt ){
                        double tmp = delt;
                        delt = omeg;
                        omeg = tmp;
                      };

                      if ( epsilo > omeg ){
                        double tmp = omeg;
                        omeg = epsilo;
                        epsilo = tmp;
                      };











        // Serazeni delek stran tr1:

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



          // Serazeni delek stran tr2:

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














          // Shodnost:

                if ( (a == x) && (b==y) && (c==z) ){
                  shodne = 1;
                }
                else{
                  shodne = 0;
                };

          // Podobnost:

                if ( (alph == epsilo) && (bet == omeg) && (gam == delt) ){
                  podobne = 1;
                }
                else{
                  podobne = 0;
                };


          // Vypis:

          //  printf("Triangle 1 = %f %f %f\n", a, b, c);
          //  printf("Triangle 2 = %f %f %f\n", x, y, z);


                if ( shodne == 1 && podobne == 1 ){
                  printf("Trojuhelniky jsou shodne.\n");
                  return 0;
                }
                else if ( shodne == 1 && podobne == 0 ){
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






      };






// SSS vs SUS:


      if ( tr1_ch1 == 'S' && tr1_ch2 == 'S' && tr1_ch3 == 'S' &&  tr2_ch1 == 'S' && tr2_ch2 == 'U' && tr2_ch3 == 'S' ){

            // Prevod uhlu u triangle2 na radiany:

                  double tmp = tr2_va2 * (M_PI/180);
                  tr2_va2 = tmp;




            // Vypocet treti strany u triangle2:

                  double z = sqrt( (tr2_va1*tr2_va1) + (tr2_va3*tr2_va3) - (2*tr2_va1*tr2_va3*cos(tr2_va2)) );


            // Serazeni stran:



                                                  // Serazeni delek stran tr1:

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

                                                          if ( tr1_va1 > tr1_va2 ){
                                                            double tmp = tr1_va1;
                                                            tr1_va1 = tr1_va2;
                                                            tr1_va2 = tmp;
                                                          };



                                                    // Serazeni delek stran tr2:

                                                          if ( tr2_va1 > z ){
                                                            double tmp = tr2_va1;
                                                            tr2_va1 = z;
                                                            z = tmp;
                                                          };

                                                          if ( z > tr2_va3 ){
                                                            double tmp = z;
                                                            z = tr2_va3;
                                                            tr2_va3 = tmp;
                                                          };

                                                          if ( tr2_va1 > z ){
                                                            double tmp = tr2_va1;
                                                            tr2_va1 = z;
                                                            z = tmp;
                                                          };




            // Shodnost:

                  if ( (tr1_va1 == tr2_va1) && (tr1_va2 == z) && (tr1_va3 == tr2_va3) ){
                    shodne = 1;
                  }
                  else{
                    shodne = 0;
                  };


            // Podobnost:

                  if ( ( (tr1_va1/tr2_va1) == (tr1_va2/z) ) && ( (tr1_va2/z) == (tr1_va3/tr2_va3) ) && ( (tr1_va1/tr2_va1) == (tr1_va3/tr2_va3) ) ){
                    podobne = 1;
                  }
                  else{
                    podobne = 0;
                  };


            // Vypis:


                    if ( shodne == 1 && podobne == 1 ){
                      printf("Trojuhelniky jsou shodne.\n");
                      return 0;
                    }
                    else if ( shodne == 1 && podobne == 0 ){
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







      };














// SUS vs SSS:


      if ( tr1_ch1 == 'S' && tr1_ch2 == 'U' && tr1_ch3 == 'S' &&  tr2_ch1 == 'S' && tr2_ch2 == 'S' && tr2_ch3 == 'S' ){


        // Prevod uhlu u triangle2 na radiany:

              double tmp = tr1_va2 * (M_PI/180);
              tr1_va2 = tmp;


        // Vypocet treti strany u triangle2:

              double z = sqrt( (tr1_va1*tr1_va1) + (tr1_va3*tr1_va3) - (2*tr1_va1*tr1_va3*cos(tr1_va2)) );


        // Serazeni stran:



                                              // Serazeni delek stran tr1:

                                                      if ( tr1_va1 > z ){
                                                        double tmp = tr1_va1;
                                                        tr1_va1 = z;
                                                        z = tmp;
                                                      };

                                                      if ( z > tr1_va3 ){
                                                        double tmp = z;
                                                        z = tr1_va3;
                                                        tr1_va3 = tmp;
                                                      };

                                                      if ( tr1_va1 > z ){
                                                        double tmp = tr1_va1;
                                                        tr1_va1 = z;
                                                        z = tmp;
                                                      };



                                                // Serazeni delek stran tr2:

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

                                                      if ( tr2_va1 > tr2_va2 ){
                                                        double tmp = tr2_va1;
                                                        tr2_va1 = tr2_va2;
                                                        tr2_va2 = tmp;
                                                      };

                    // Shodnost:

                          if ( (tr1_va1 == tr2_va1) && (z == tr2_va2) && (tr1_va3 == tr2_va3) ){
                            shodne = 1;
                          }
                          else{
                            shodne = 0;
                          };

                    // Podobnost:

                          if ( ( (tr1_va1/tr2_va1) == (z/tr2_va2) ) && ( (z/tr2_va2) == (tr1_va3/tr2_va3) ) && ( (tr1_va1/tr2_va1) == (tr1_va3/tr2_va3) ) ){
                            podobne = 1;
                          }
                          else{
                            podobne = 0;
                          };



                    // Vypis:


                            if ( shodne == 1 && podobne == 1 ){
                              printf("Trojuhelniky jsou shodne.\n");
                              return 0;
                            }
                            else if ( shodne == 1 && podobne == 0 ){
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



      };








  // SSS vs USU:


        if ( tr1_ch1 == 'S' && tr1_ch2 == 'S' && tr1_ch3 == 'S' &&  tr2_ch1 == 'U' && tr2_ch2 == 'S' && tr2_ch3 == 'U' ){


              // Dopocitavani 3. uhlu v triangle2:

                    double j = 180 - (tr2_va1 + tr2_va3);

              // Prevod uhlu na radiany:

                    double alpha = tr2_va1 * (M_PI / 180);
                    double beta = tr2_va3 * (M_PI / 180);
                    double gama = j * (M_PI / 180);


              // Dopocitavani stran u triangle2:

                    double y = tr2_va2 * (sin(alpha)/sin(gama));
                    double z = tr2_va2 * (sin(beta)/sin(gama));
                    double x = tr2_va2;


              // Serazeni stran:

                                                // Serazeni delek stran tr1:


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

                                                        if ( tr1_va1 > tr1_va2 ){
                                                          double tmp = tr1_va1;
                                                          tr1_va1 = tr1_va2;
                                                          tr1_va2 = tmp;
                                                        };


                                                // Serazeni delek stran tr2:

                                                        if ( z > y ){
                                                          double tmp = z;
                                                          z = y;
                                                          y = tmp;
                                                        };

                                                        if ( y > x ){
                                                          double tmp = y;
                                                          y = x;
                                                          x = tmp;
                                                        };

                                                        if ( z > y ){
                                                          double tmp = z;
                                                          z = y;
                                                          y = tmp;
                                                        };

                // Shodnost:


                            if ( tr1_va1 == z && tr1_va2 == y && tr1_va3 == x ){
                              shodne = 1;
                            }
                            else{
                              shodne = 0;
                            };




                // Podobnost:


                            if ( ( (tr1_va1/z) == (tr1_va2/y) ) && ( (tr1_va2/y) == (tr1_va3/x) ) && ( (tr1_va1/z) == (tr1_va3/x) ) ){
                              podobne = 1;
                            }
                            else{
                              podobne = 0;
                            };


                // Vypis:



                            if ( shodne == 1 && podobne == 1 ){
                              printf("Trojuhelniky jsou shodne.\n");
                              return 0;
                            }
                            else if ( shodne == 1 && podobne == 0 ){
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

        };






// USU vs SSS:


        if ( tr1_ch1 == 'U' && tr1_ch2 == 'S' && tr1_ch3 == 'U' &&  tr2_ch1 == 'S' && tr2_ch2 == 'S' && tr2_ch3 == 'S' ){

          // Dopocitavani 3. uhlu v triangle1:

                double j = 180 - (tr1_va1 + tr1_va3);


          // Prevod uhlu na radiany:

                double alpha = tr1_va1 * (M_PI / 180);
                double beta = tr1_va3 * (M_PI / 180);
                double gama = j * (M_PI / 180);


          // Dopocitavani stran u triangle1:

                double y = tr1_va2 * (sin(alpha)/sin(gama));
                double z = tr1_va2 * (sin(beta)/sin(gama));
                double x = tr1_va2;


          // Serazeni stran:

                                            // Serazeni delek stran tr1:


                                                    if ( z > y ){
                                                      double tmp = z;
                                                      z = y;
                                                      y = tmp;
                                                    };

                                                    if ( y > x ){
                                                      double tmp = y;
                                                      y = x;
                                                      x = tmp;
                                                    };

                                                    if ( z > y ){
                                                      double tmp = z;
                                                      z = y;
                                                      y = tmp;
                                                    };







                                            // Serazeni delek stran tr2:


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

                                                    if ( tr2_va1 > tr2_va2 ){
                                                      double tmp = tr2_va1;
                                                      tr2_va1 = tr2_va2;
                                                      tr2_va2 = tmp;
                                                    };




                        // Shodnost:


                                    if ( tr2_va1 == z && tr2_va2 == y && tr2_va3 == x ){
                                      shodne = 1;
                                    }
                                    else{
                                      shodne = 0;
                                    };

                        // Podobnost:


                                    if ( ( (tr2_va1/z) == (tr2_va2/y) ) && ( (tr2_va2/y) == (tr2_va3/x) ) && ( (tr2_va1/z) == (tr2_va3/x) ) ){
                                      podobne = 1;
                                    }
                                    else{
                                      podobne = 0;
                                    };

                        // Vypis:



                                    if ( shodne == 1 && podobne == 1 ){
                                      printf("Trojuhelniky jsou shodne.\n");
                                      return 0;
                                    }
                                    else if ( shodne == 1 && podobne == 0 ){
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


        };












// SUS vs USU:


          if ( tr1_ch1 == 'S' && tr1_ch2 == 'U' && tr1_ch3 == 'S' &&  tr2_ch1 == 'U' && tr2_ch2 == 'S' && tr2_ch3 == 'U' ){

                  // Prevod uhlu na radiany:

                      // Triangle1:

                          double uhel_tr1 = tr1_va2 * ( M_PI / 180 );

                      // Triangle2:

                          double tretiUhel = 180 - (tr2_va1 + tr2_va3);       // Vypocet 3.uhlu v triangle2

                          double gama = tretiUhel * ( M_PI / 180 );
                          double alpha = tr2_va1 * ( M_PI / 180 );
                          double beta = tr2_va3 * ( M_PI / 180 );



                  // Vypocet 3.strany v triangle1:

                      double c = sqrt( (tr1_va1 * tr1_va1) + ( tr1_va3 * tr1_va3 ) - ( 2 * tr1_va1 * tr1_va3 * cos(uhel_tr1) ) );

                  // Vypocet zbylych 2 stran v triangle2:

                      double y = tr2_va2 * ( sin(alpha) / sin(gama) );
                      double z = tr2_va2 * (sin(beta) / sin(gama));
                      double x = tr2_va2;





                      // Serazeni stran:

                                                        // Serazeni delek stran tr1:


                                                                if ( tr1_va1 > tr1_va3 ){
                                                                  double tmp = tr1_va3;
                                                                  tr1_va3 = tr1_va1;
                                                                  tr1_va1 = tmp;
                                                                };

                                                                if ( tr1_va3 > c ){
                                                                  double tmp = c;
                                                                  c = tr1_va3;
                                                                  tr1_va3 = tmp;
                                                                };

                                                                if ( tr1_va1 > tr1_va3 ){
                                                                  double tmp = tr1_va3;
                                                                  tr1_va3 = tr1_va1;
                                                                  tr1_va1 = tmp;
                                                                };







                                                        // Serazeni delek stran tr2:


                                                                if ( z > x ){
                                                                  double tmp = x;
                                                                  x = z;
                                                                  z = tmp;
                                                                };

                                                                if ( x > y ){
                                                                  double tmp = y;
                                                                  y = x;
                                                                  x = tmp;
                                                                };

                                                                if ( z > x ){
                                                                  double tmp = x;
                                                                  x = z;
                                                                  z = tmp;
                                                                };








                  // Shodnost:


                      if ( tr1_va1 == z && tr1_va3 == x && c == y ){
                        shodne = 1;
                      }
                      else{
                        shodne = 0;
                      };


                  // Podobnost:


                      if ( ( (tr1_va1 / z) == (tr1_va3 / x) ) && ( (tr1_va3 / x) == (c / y) ) && ( (tr1_va1 / z) == (c / y) ) ){
                        podobne = 1;
                      }
                      else{
                        podobne = 0;
                      };



                  // Vypis:





                      if ( shodne == 1 && podobne == 1 ){
                        printf("Trojuhelniky jsou shodne.\n");
                        return 0;
                      }
                      else if ( shodne == 1 && podobne == 0 ){
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



          };





// USU vs SUS


        if ( tr1_ch1 == 'U' && tr1_ch2 == 'S' && tr1_ch3 == 'U' &&  tr2_ch1 == 'S' && tr2_ch2 == 'U' && tr2_ch3 == 'S' ){

        // Prevod uhlu na radiany:

            // Triangle2:

                double uhel_tr2 = tr2_va2 * ( M_PI / 180 );

            // Triangle1:

                double tretiUhel = 180 - (tr1_va1 + tr1_va3);       // Vypocet 3.uhlu v triangle1

                double gama = tretiUhel * ( M_PI / 180 );
                double alpha = tr1_va1 * ( M_PI / 180 );
                double beta = tr1_va3 * ( M_PI / 180 );


            // Vypocet 3.strany v triangle2:

                double c = sqrt( (tr2_va1 * tr2_va1) + ( tr2_va3 * tr2_va3 ) - ( 2 * tr2_va1 * tr2_va3 * cos(uhel_tr2) ) );

            // Vypocet zbylych 2 stran v triangle1:

                double y = tr1_va2 * ( sin(alpha) / sin(gama) );
                double z = tr1_va2 * (sin(beta) / sin(gama));
                double x = tr1_va2;


                // Serazeni stran:

                                                  // Serazeni delek stran tr2:


                                                          if ( tr2_va1 > tr2_va3 ){
                                                            double tmp = tr2_va3;
                                                            tr2_va3 = tr2_va1;
                                                            tr2_va1 = tmp;
                                                          };

                                                          if ( tr2_va3 > c ){
                                                            double tmp = c;
                                                            c = tr2_va3;
                                                            tr2_va3 = tmp;
                                                          };

                                                          if ( tr2_va1 > tr2_va3 ){
                                                            double tmp = tr2_va3;
                                                            tr2_va3 = tr2_va1;
                                                            tr2_va1 = tmp;
                                                          };







                                                  // Serazeni delek stran tr1:


                                                          if ( z > x ){
                                                            double tmp = x;
                                                            x = z;
                                                            z = tmp;
                                                          };

                                                          if ( x > y ){
                                                            double tmp = y;
                                                            y = x;
                                                            x = tmp;
                                                          };

                                                          if ( z > x ){
                                                            double tmp = x;
                                                            x = z;
                                                            z = tmp;
                                                          };


                      // Shodnost:


                          if ( tr2_va1 == z && tr2_va3 == x && c == y ){
                            shodne = 1;
                          }
                          else{
                            shodne = 0;
                          };

                      // Podobnost:


                      if ( ( (tr2_va1 / z) - (tr2_va3 / x) ) < 0.1 &&
                            ( (tr2_va3 / x) - (c / y) ) < 0.1 &&
                            ( (tr2_va1 / z) - (c / y) ) < 0.1 ){
                            podobne = 1;
                          }
                          else{
                            podobne = 0;
                          };



                      // Vypis:


                          // printf("Triangle 1 = %0.15f %0.15f %0.15f\n", z, x, y);
                          // printf("Triangle 2 = %0.15f %0.15f %0.15f\n", tr2_va1, tr2_va3, c);


                          if ( shodne == 1 && podobne == 1 ){
                            printf("Trojuhelniky jsou shodne.\n");
                            return 0;
                          }
                          else if ( shodne == 1 && podobne == 0 ){
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



            }


  return 0;
}
