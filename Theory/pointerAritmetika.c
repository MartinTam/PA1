int * array = 0x0004;

sizeof(int) = 4;

array + 1       =>    0x0008
array + 2       =>    0x000C
*( array + 2 )  ===   array[ 2 ]


const int       *       DAYS        // adresa = muze se menit; hodnoty = NEmuze se menit
      int const *       DAYS        // adresa = muze se menit; hodnoty = NEmuze se menit
      int       * const DAYS        // adresa = NEmuze se menit; hodnoty = muze se menit
      int const * const DAYS        // adresa = NEmuze se menit; hodnoty = NEmuze se menit
