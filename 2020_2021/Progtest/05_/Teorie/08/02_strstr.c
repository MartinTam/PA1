#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* Program ukazuje praci s retezci - vyhledavani retezce v jinem retezci. 
 * pouziva naivni algoritmus (zkusi vsechny moznosti)
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
/** Porovnani dvou retezcu s1 a s2 o delce len znaku. Porovnava se bez rozliseni
 * mala/velka pismena. Vlastni retezce s1 a s2 mohou byt delsi nez len znaku,
 * funkce se nestara o skutecnou delku. Za smerodatnou povazuje informaci predanou
 * v len.
 *
 * @param[in] s1 retezec #1
 * @param[in] s2 retezec #2
 * @param[in] len pocet porovnavanych znaku
 * @return 0 pro neshodu, 1 shoda 
 */
int compare       ( char * s1, char * s2, int len )
{
  while ( len -- )
    if ( toupper ( *s1 ) != toupper ( *s2 ) )
      return 0;
    else
    {
      s1++;
      s2++;
    }
  return 1;
}
/*---------------------------------------------------------------------------*/
/** Hledani vzorku (pattern) v textu. Funguje naivnim zpusobem - na kazde pozici
 * zkusime k textu prilozit vzorek a porovnat je. Pokud nedojde ke shode,
 * posuneme se v textu o jednu pozici dale.
 *
 * @param[in] pattern hledany text (vzorek)
 * @param[in] text prohledavany text (text)
 * @return ukazatel do prohledavaneho textu, kde se nachazi vyskyt vzorku, NULL
 *  pokud vzorek nebyl nalezen.
 */
char * strcasestr ( char * pattern, char * text )
{
  int patternLen = strlen ( pattern );

  while ( * text )
  {
    if ( compare ( text, pattern, patternLen ) ) 
      return text;
    text ++;
  }
  return NULL;
}
/*---------------------------------------------------------------------------*/
int main ( int argc, char * argv [] )
{
  char pattern[200], text[200], * where;

  printf ( "Zadejte hledany vzorek:\n" );
  /* pouzivame fgets - nacteni cele radky do retezcove promenne.
   * Nepouzivejte gets !
   */
  if ( fgets ( pattern, sizeof ( pattern ), stdin ) == NULL )
  {
    printf ( "Nespravny vstup.\n" );
    return 1;
  }
  /* fgets precte retezec i s koncem radky \n - odstranit */
  removeLF ( pattern );

  printf ( "Zadejte prohledavany text:\n" );
  while ( 1 )
  {
    /* vstup cteme do EOF */
    if ( fgets ( text, sizeof ( text ), stdin ) == NULL ) 
      break;
  
    where = strcasestr ( pattern, text );
    if ( where )
    {
      printf ( "Vzorek je obsazen - pozice vyskytu: %d", (int)(where - text) );
      while ( 1 )
      {
        /* dalsi vyskyt hledame od pozice where + 1 */
        where = strcasestr ( pattern, where + 1 );
        if ( ! where ) break;
        printf ( ", %d", (int)(where - text) );
      }
      printf ( "\n" );
    }
    else
      printf ( "Vzorek neni obsazen.\n" );
  }
  if ( ! feof ( stdin ) )
   {
     printf ( "Nespravny vstup.\n" );
     return 1;
   }
  return 0;
}
