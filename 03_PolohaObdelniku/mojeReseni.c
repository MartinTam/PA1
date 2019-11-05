#ifndef __PROGTEST__
#include <stdio.h>
#include <assert.h>
#define RECT_NO_OVERLAP 0
#define RECT_OVERLAP    1
#define RECT_A_IN_B     2
#define RECT_B_IN_A     3
#define RECT_ERROR    (-1)
#endif /* __PROGTEST__ */







int pointInsideRectang(int a, int b, int c1, int c2, int d1, int d2){
  if ( c1 > c2 ){
    double tmp = c2;
    c2 = c1;
    c1 = tmp;
  };

  if ( d1 > d2 ){
    double tmp = d2;
    d2 = d1;
    d1 = tmp;
  };

  if ((a > c1) && (a < c2) && (b > d1) && (b < d2)){
    return 0;
  }
  else{
    return 1;
  };
}


int rectangleInAnother( int a, int b, int c, int d, int e, int f, int g, int h){
  if (pointInsideRectang(a, c, e, f, g, h) == 0 &&
      pointInsideRectang(b, c, e, f, g, h) == 0 &&
      pointInsideRectang(a, d, e, f, g, h) == 0 &&
      pointInsideRectang(b, d, e, f, g, h) == 0){
        return 0;
      }
      else{
        return 1;
      };
}












int rectanglePosition ( int ax1, int ay1,
                        int ax2, int ay2,
                        int bx1, int by1,
                        int bx2, int by2 )
{

  if (rectangleInAnother(ax1, ay1, ax2, ay2, bx1, by1, bx2, by2) == 0){
      return RECT_A_IN_B;
  };
  if (rectangleInAnother(bx1, by1, bx2, by2, ax1, ay1, ax2, ay2) == 0){
      return RECT_B_IN_A;
  };





}














#ifndef __PROGTEST__
int main ( int argc, char * argv [] )
{
  assert ( rectanglePosition ( 0, 0, 50, 20,
                               10, 5, 75, 40 ) == RECT_OVERLAP );
  assert ( rectanglePosition ( 0, 20, 50, 0,
                               75, 40, 10, 5 ) == RECT_OVERLAP );
  assert ( rectanglePosition ( 0, 0, 50, 20,
                               -100, 100, 100, 90 ) == RECT_NO_OVERLAP );
  assert ( rectanglePosition ( 0, 0, 50, 20,
                               50, -100, 100, 100 ) == RECT_NO_OVERLAP );
  assert ( rectanglePosition ( 0, 0, 10, 10,
                               2, 8, 4, 6 ) == RECT_B_IN_A );
  assert ( rectanglePosition ( 2, 6, 3, 7,
                               1, 5, 4, 8 ) == RECT_A_IN_B );
  assert ( rectanglePosition ( 1, 6, 3, 7,
                               1, 5, 4, 8 ) == RECT_OVERLAP );
  assert ( rectanglePosition ( 0, 0, 1, 1,
                               1, 0, 0, 1 ) == RECT_OVERLAP );
  assert ( rectanglePosition ( 0, 0, 50, 20,
                               50, -100, 100, -100 ) == RECT_ERROR );
  return 0;
}
#endif /* __PROGTEST__ */
