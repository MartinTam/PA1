#ifndef __PROGTEST__
#include <stdio.h>
#include <assert.h>
#define RECT_NO_OVERLAP 0
#define RECT_OVERLAP    1
#define RECT_A_IN_B     2
#define RECT_B_IN_A     3
#define RECT_ERROR    (-1)
#endif /* __PROGTEST__ */

int error(int x1, int y1, int x2, int y2){
  if ((x1==x2) || (y1==y2)){
    return 1;
  }
  else
    return 0;
}

int pointInsideRectang(int x, int y, int x1, int y1, int x2, int y2){

  if ( x1 > x2 ){
    double tmp = x2;
    x2 = x1;
    x1 = tmp;
  };

  if ( y1 > y2 ){
    double tmp = y2;
    y2 = y1;
    y1 = tmp;
  };

  if ((x>x1) && (x<x2) && (y>y1) && (y<y2)){
    return 1;
  }
  else
    return 0;
}

int inOver(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2){
  int result = pointInsideRectang(ax1, ay1, bx1, by1, bx2, by2) +
                pointInsideRectang(ax2, ay1, bx1, by1, bx2, by2) +
                pointInsideRectang(ax1, ay2, bx1, by1, bx2, by2) +
                pointInsideRectang(ax2, ay2, bx1, by1, bx2, by2);

  if (result == 4){
    return 1; // obdelnik A lezi uvnitr B
  }
  else if ((result == 1) || (result == 2)){
    return 2; // obdelniky se prekryvaji
  }
  else
    return 0;
}

int rectanglePosition ( int ax1, int ay1,
                        int ax2, int ay2,
                        int bx1, int by1,
                        int bx2, int by2 )
{


  if ( ax1 > ax2 ){
    double tmp = ax2;
    ax2 = ax1;
    ax1 = tmp;
  };

  if ( ay1 > ay2 ){
    double tmp = ay2;
    ay2 = ay1;
    ay1 = tmp;
  };

  if ( bx1 > bx2 ){
    double tmp = bx2;
    bx2 = bx1;
    bx1 = tmp;
  };

  if ( by1 > by2 ){
    double tmp = by2;
    by2 = by1;
    by1 = tmp;
  };



    if (error(ax1, ay1, ax2, ay2) || error(bx1, by1, bx2, by2)){
      return RECT_ERROR;
    }
    else if (inOver(ax1, ay1, ax2, ay2, bx1, by1, bx2, by2) == 1){
      return RECT_A_IN_B;
    }
    else if (inOver(bx1, by1, bx2, by2, ax1, ay1, ax2, ay2) == 1){
      return RECT_B_IN_A;
    }
    else if ((ax1==bx1) && (ay1==by1) && (ax2==bx2) && (ay2==by2)){
      return RECT_OVERLAP;
    }
    else if ( ( (bx1<ax1) && (ax1<bx2) && (by2<=ay2) && (ay1<=by1) ) ||
              ( (bx1<ax2) && (ax2<bx2) && (by2<=ay2) && (ay1<=by1) ) ||
              ( (ax1<bx1) && (bx1<ax2) && (ay2<=by2) && (by1<=ay1) ) ||
              ( (ax1<bx2) && (bx2<ax2) && (ay2<=by2) && (by1<=ay1) ) ){
                return RECT_OVERLAP;
              }
    else if (inOver(ax1, ay1, ax2, ay2, bx1, by1, bx2, by2) == 2 || inOver(bx1, by1, bx2, by2, ax1, ay1, ax2, ay2) == 2){
      return RECT_OVERLAP;
    }
    else if ( ( (bx1<=ax1) && (ax2<=bx2) && (by1<=ay1) && (ay2<=by2) ) ||
              ( (ax1<=bx1) && (bx2<=ax2) && (ay1<=by1) && (by2<=ay2) ) ){
                return RECT_OVERLAP;
    }
    else if ( ( (ax1<bx1) && (bx1<ax2) && (ax2<=bx2) && (ay1==by1) && (ay2==by2) ) ||
            ( (ax2>bx2) && (bx1<=ax1) && (ax1<bx2) && (ay1==by1) && (ay2==by2) ) ||
            ( (bx1<ax1) && (bx2<=ax2) && (ax1<bx2) && (by1==ay1) && (ay2==by2) ) ||
            ( (ax2<bx2) && (bx1<ax2) && (ax1<=bx1) && (by1==ay1) && (ay2==by2) ) ||

            ( (ay1<by1) && (by1<ay2) && (ay2<=by2) && (ax1==bx1) && (ax2==bx2) ) ||
            ( (ay2>by2) && (by1<=ay1) && (ay1<by2) && (ax1==bx1) && (ax2==bx2) ) ||
            ( (ay1>by1) && (by2<=ay2) && (ay1<by2) && (ax1==bx1) && (ax2==bx2) ) ||
            ( (ay2<by2) && (by1<ay2) && (ay2<=by2) && (ax1==bx1) && (ax2==bx2) )){
              return RECT_OVERLAP;
    }
    else
      return RECT_NO_OVERLAP;



}





#ifndef __PROGTEST__
int main ( int argc, char * argv [] )
//int main(void)
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
