#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* program provadi operaci najdu a nahrad
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
/** Zretezeni. K retezci res o dosavadni delce resLen a kapacite (vyhrazene) resMax pripoji
 * retezec appendStr o delce appendLen
 * Funguje tedy podobne jako strcat, ale navic provadi natahovani pametoveho bloku
 * vysledku tak, aby se do nej vysledny retezec vesel.
 *
 * @param[in,out] res cilovy retezec, ke kteremu bude pridany text
 * @param[in,out] resLen delka retezce res
 * @param[in,out] resMax velikost bufferu (rezervovane pameti) pro retezec res
 * @param[in] appendStr pridavany retezec (nemusi byt pridavany cely)
 * @param[in] appendLen pocet znaku retezce appendStr, ktery ma byt pridan k retezci res

 */
void append ( char ** res, int * resLen, int * resMax, char * appendStr, int appendLen )
{
  /* Parametry res, resLen a resMax jsou vstpne/vystupni (funkce je cte a muze zmenit
   * jejich hodnoty). Proto jsou deklaraovane "o hvezdicku" vice.
   */
  if ( *resLen + appendLen >= *resMax )
  {
    *resMax = *resLen + appendLen;
    *res = ( char *) realloc ( *res, *resMax );
  }
  memcpy ( *res + *resLen, appendStr, appendLen );
  *resLen += appendLen;
}
/*---------------------------------------------------------------------------*/
/** Vlastni nahrada. 
 *
 * @param[in] text retezec, ve kterem budou hledani/nahrady probihat
 * @param[in] replace vyhledavany vzorek
 * @param[in] with retezec, kterym budou vzorky nahrazene
 * @return vstupni retezec text s provedenymi nahradami. reetzec je dynamicky alokovany,
 * volajici je zodpovedny za jeho uvolneni.
 */ 
char * strReplace ( char * text, char * replace, char * with )
{
  char * res = NULL, * occ;
  int    resLen = 0, resMax = 0;
  int    replaceLen = strlen ( replace ), withLen = strlen ( with );

  if ( ! replaceLen ) return NULL; /* infinite loop */
  /* res    - dynamicky alokovana pamet pro vysledek (budeme podle potreby roztahovat)
   * resLen - pocet znaku vysledneho retezce. Zatim 0
   * resMax - kapacita pameti pro vysledek. Zatim 0
   * v beznem pridavani bude platit resLen <= resMax.
   */

  /* K vyhledani pouzivame funkci strstr(). Pokud nalezne vyskyt
   * (vraci != NULL), pak
   *  - zkopirujeme text az do vyskytu hledaneho textu
   *  - pridame nahradu
   *  - pokracujeme v nahrazovani od konce nalezeneho textu
   * Pokud strstr nenalezne vyskyt, pak:
   *  - zkopirujeme text az do konce
   *  - nahrazovani je hotovo
   */

  while ( 1 )
  {
    occ = strstr ( text, replace );
    if ( occ )
    {
      append ( &res, &resLen, &resMax, text, occ - text );
      append ( &res, &resLen, &resMax, with, withLen );
      text = occ + replaceLen;
    }
    else
    {
      append ( &res, &resLen, &resMax, text, strlen ( text ) + 1 ); /* +1 => include terminating zero */
      return res;
    }
  }
}
/*---------------------------------------------------------------------------*/
int main ( int argc, char * argv [] )
{
  char replace[200], with[200], text[200], * newStr;

  printf ( "Zadejte hledany vzorek:\n" );
  if ( fgets ( replace, sizeof ( replace ), stdin ) == NULL )
  {
    printf ( "Nespravny vstup.\n" );
    return 1;
  }
  removeLF ( replace );
  if ( *replace == 0 )
  { /* pokud bychom nahrazovali prazdny retezec, zacyklime se */
    printf ( "Nespravny vstup.\n" );
    return 1;
  }
  
  printf ( "Zadejte nahradu:\n" );
  if ( fgets ( with, sizeof ( with ), stdin ) == NULL )
  {
    printf ( "Nespravny vstup.\n" );
    return 1;
  }
  removeLF ( with );

  printf ( "Zadejte text:\n" );
  /* nahrazujeme do konce vstupu */
  while ( fgets ( text, sizeof ( text ), stdin ) != NULL )
  {
    newStr = strReplace ( text, replace, with );
    printf ( "%s", newStr );
    free ( newStr );
  }
  if ( ! feof ( stdin ) )
  {
    printf ( "Nespravny vstup.\n" );
    return 1;
  }
  return 0;
}
