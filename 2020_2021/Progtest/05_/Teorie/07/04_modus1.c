/* Program nacte seznam studentu. Kazdy student ma zadane jmeno (max 49 znaku) a pocet 
 * ziskanych bodu. Program nalezne modus (nejcastejsi hodnotu poctu bodu) a vypise studenty,
 * kteri tohoto hodnoceni dosahli.
 *
 * Protoze pocet studentu na vstupu neni dopredu znamy, musi program prizpusobovat velikost pole 
 * v prubehu nacitani vstupu (natahovani pole).
 *
 * Nejcastejsich hodnot muze byt vice (vice stejne cetnych), program pracuje pouze s jednou z nich.
 *
 * Program demonstruje pouziti struktur, nacitani do pole a zmenu velikosti pole (natahovani).
 *
 * V teto verzi program pracuje spravne, ale je pouzit naivni algoritmus hledani a neefektivni 
 * natahovani pole.
 */
 
#include <stdio.h>
#include <stdlib.h>  /* malloc, free */
#include <string.h>  /* strncpy */

typedef struct TStudent
{
  char m_Name[50]; /* 49 znaku + ukoncujici 0 */
  int  m_Points;
} TSTUDENT; 

/*-----------------------------------------------------------------------------------------------*/
/** Funkce nacte zadana vstupni data do dynamicky alokovaneho pole.
 *  @param[out] n pocet nactenych studentu
 *  @return dynamicky alokovane pole s nactenymi studenty, NULL pro chybu
 *  @note vracene alokovane pole je potreba uvolnit pomoci free ()
 */
TSTUDENT * readStudents ( int * n )
{
  /* zatim nic nealokujeme, alokovat budeme az v okamziku, kdy to bude doopravdy potreba */
  TSTUDENT * data = NULL;
  char name[50];
  int points, res;
  
  *n = 0;

  /* %49s - nacte se maximalne 49 znaku jmena + ukoncujici 0
   * scanf tedy nikdy nebude psat mimo meze promenne name
   */
  while ( (res = scanf ( "%49s %d", name, &points ) ) == 2 )
  {
    /* Podarilo se nacist, je potreba vytvorit prostor v poli:
     *  - alokujeme nove pole vetsi o 1 prvek
     *  - zkopirujeme obsah
     *  - uvolnime puvodni mensi pole
     *  - prehodime odkazy
     */
    TSTUDENT * tmp = (TSTUDENT *) malloc ( (*n+1) * sizeof ( *tmp )); 
    int i;
    for ( i = 0; i < *n; i ++ )
      tmp[i] = data[i]; /* kopirujeme cele struktury najednou */
    free ( data );
    data = tmp;
    
    /* ulozime nove nacteneho studenta */
    /* bezpecne kopirovani jmena - s omezenim max delky  */
    strncpy ( data[ *n ] . m_Name, name, sizeof ( data[ *n ] . m_Name ) );
    data[ *n ] . m_Points = points;
    (*n)++; /* nefunguje *n++ (posouva ukazatel), funguje ++*n; */
  }
  
  if ( res != EOF ) 
  { /* chyba nacitani, napr. spatny format cisla */
    free ( data );
    return NULL; /* indikace chyby */
  } 
  return data; /* ok nacteno */
}
/*-----------------------------------------------------------------------------------------------*/
/** Funkce nalezne modus poctu bodu v predanem poli studentu. Pokud existuje vice moznosti (vice 
 *   hodnot se stejnou cetnosti), funkce pouzije prvni takovou hodnotu.
 *  @param[in] data pole s vyplnenymi studenty
 *  @param[in] n pocet studentu v predanem poli
 *  @return nalezeny modus 
 *  @note naivni implementace pracuje v kvadratickem case, vstupni pole musi mit alespon 1 prvek
 */
int findModus ( TSTUDENT * data, int n )
{
  int maxCnt = 0, modus, i, j;
 
  for ( i = 0; i < n; i ++ )
  {
    int cnt = 0;
    
    /* nalezneme pocet vyskytu hodnoty data[i] . m_Points 
     * toto provedeme pro kazdoeho studenta v poli,
     * maximum poctu vyskytu si ukladame.
     * Neefektivita je zrejma, napr pro hodnoty { 1, 3, 2, 5, 2, 3, 2 }
     * budeme pocitat pocty vyskytu cisla 2 celkem 3x, ale druhy a treti vypocet je zbytecny.
     */
    for ( j = 0; j < n; j ++ )
      if ( data[i] . m_Points == data[j] . m_Points )
        cnt ++;
    
    if ( cnt > maxCnt )
    {
      maxCnt = cnt;
      modus = data[i] . m_Points;
    }
  }
  return modus;    
}
/*-----------------------------------------------------------------------------------------------*/
/** Funkce zobrazi studenty, kteri dosahli prave zadanehopoctu bodu.
 * @param[in] data pole se studenty
 * @param[in] n pocet studentu v poli
 * @param[in] modus filtr na pocet bodu (zobrazi studenty s timto poctem bodu
 * @note funcke nic nevraci, pouze zobrazuje na stdout
 */
void printStudents ( TSTUDENT * data, int n, int modus )
{
  int i;
  
  for ( i = 0; i < n; i ++ )
    if ( data[i] . m_Points == modus )
      printf ( "%s\n", data[i] . m_Name );
} 
/*-----------------------------------------------------------------------------------------------*/
int main ( void )
{
  int n, modus;
  TSTUDENT * data; 
 
  printf ( "Vysledky:\n" );
  data = readStudents ( &n );
  if ( ! data )
  {
    printf ( "Nespravny vstup.\n" );
    return 1;
  }
  modus = findModus ( data, n );
  printf ( "Modus: %d\n", modus );
  printStudents ( data, n, modus );
  free ( data );
  return 0; 
}
