#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Program demonstruje praci s retezci v C. Ze zadaneho retezce odstrani 
 * zbytecne mezery (sekvence mezer jsou nahrazeny jednou mezerou).
 * Navic odrizne vsechny mezery na zacaku a na konci retezce.
 */

/*---------------------------------------------------------------------------*/
/** Odstrani odradkovani z konce retezce (pokud tam je). Odstraneni = prepis
 * binarni nulou.
 *
 * @param[in,out] x retezec k odstraneni odradkovani
 */
void  removeLF    ( char * x )
{
  int l = strlen ( x );
  if ( l > 0 && x[l-1] == '\n' ) 
    x[l-1] = 0;
}
/*---------------------------------------------------------------------------*/
/** Funkce provadi vlastni odstraneni mezer. Uprava retezce je provedena
 * primo v zadanem retezci (retezec je inout).
 *
 * @param[in,out] str vstupni retezec, ktery je funkci upraven
 */
void  stripSpaces ( char * str )
{
  char * dst, * src;
  int    inSpaces;

  /* dst ukazuje misto v retezci, kam bnudeme zapisovat "sklepane" znaky
   * inSpaces je priznak, zda jsme uprostred sekvence mezer nebo mimo mezery
   */
  inSpaces = 1;
  dst     = str;
  src     = str;
  while ( *src )
  {
    if ( inSpaces )
    { 
      /* kopirujeme vse krome mezer */
      if ( *src != ' ' )
      {
        *dst++ = *src;
        inSpaces = 0;
      }
    }
    else
    {
      /* mimo mezery kopirujeme vse. Pokud ale 
       * vidime mezeru, zkopirujeme ji (jedna mezera) a prepneme 
       * se do rezimu 'uprostred mezer'
       */
      *dst++ = *src;
      if ( *src == ' ' ) 
        inSpaces = 1;
    } 
    src ++;
  }
  /* retezec skoncil po sekvenci mezer. Tedy jednu mezeru s teto sekvence jsme jiz do 
   * vysledku zkopirovali. Abychom odrizli zbytecne mezery na konci, vratime se o 1 
   * znak zpet. Ale pozor, vyjimka: pokud byl na vstupu prazdny retezec, zadnou mezeru 
   * jsme dovystupu nedali a bylo by spatne se vracet. 
   */
  if ( inSpaces && dst > str ) 
    dst --; 
  /* ukoncujici binarni nula - konec retezce
   */ 
  *dst = 0;
}
/*---------------------------------------------------------------------------*/
int main ( int argc, char * argv [] )
{
  char text[200];

  printf ( "Zadejte text:\n" );
  /* nahrazujeme do konce vstupu */
  while ( fgets ( text, sizeof ( text ), stdin ) != NULL )
  {                 
    /* fgets nacte cely radek vstupu, vcetne pripadneho odradkovani.
     * odradkovani odstranime
     */
    removeLF ( text );
    stripSpaces ( text );
    printf ( ">%s<\n", text );
  }
  if ( ! feof ( stdin ) )
  {
    printf ( "Nespravny vstup.\n" );
    return 1;
  }
  return 0;
}
