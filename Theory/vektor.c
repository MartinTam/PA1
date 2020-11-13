/*  _____ _______         _                      _              
 * |_   _|__   __|       | |                    | |             
 *   | |    | |_ __   ___| |___      _____  _ __| | __  ___ ____
 *   | |    | | '_ \ / _ \ __\ \ /\ / / _ \| '__| |/ / / __|_  /
 *  _| |_   | | | | |  __/ |_ \ V  V / (_) | |  |   < | (__ / / 
 * |_____|  |_|_| |_|\___|\__| \_/\_/ \___/|_|  |_|\_(_)___/___|
 * 
 * IT ZPRAVODAJSTVÍ  <>  PROGRAMOVÁNÍ  <>  HW A SW  <>  KOMUNITA
 * 
 * Tento zdrojový kód je součástí výukových seriálů na 
 * IT sociální síti WWW.ITNETWORK.CZ	
 *	
 * Kód spadá pod licenci prémiového obsahu a vznikl díky podpoře
 * našich členů. Je určen pouze pro osobní užití a nesmí být šířen.
 */

#include <stdio.h>
#include <stdlib.h>

#define VYCHOZI_KAPACITA 10;

// Struktura pro snažší předávání parametrů vektoru
typedef struct {
    int pocet; // Počet obsazených prvků
    int kapacita; // Délka pole prvků
    int* pole; // Pole prvků
} VEKTOR;

// TODO: V článku zmínit že by byla velká chyba udělat VEKTOR vektor; pak & a pak to vrátit
// Vytvoří nový vektor a vrátí ukazatel na něj
VEKTOR *vytvor_vektor()
{
    VEKTOR *p_vektor = (VEKTOR *) malloc(sizeof(VEKTOR));
    p_vektor->kapacita = VYCHOZI_KAPACITA;
    p_vektor->pole = (int *) malloc(sizeof(int) * p_vektor->kapacita);
    p_vektor->pocet = 0;
    return p_vektor;
}

// Uvolní paměť po vektoru
void uvolni_vektor(VEKTOR *p_vektor)
{
    free(p_vektor->pole);
    free(p_vektor);
}

// Zvětší vektor na dvojnásobek jeho velikosti
void zvetsi_vektor(VEKTOR *p_vektor)
{    
    int* nove_pole = realloc(p_vektor->pole, sizeof(int) * (p_vektor->kapacita * 2));
    if (nove_pole != NULL)
    {
        p_vektor->kapacita *= 2;
        p_vektor->pole = nove_pole;
    }
    else
    {
        printf("Chyba - Nedostatek paměti.");
        exit(1);
    }
}

// Přidá nový prvek na konec vektoru
void pridej_do_vektoru(VEKTOR *p_vektor, int hodnota)
{
    // Pokud je pole plné, zvětšíme ho
    if (p_vektor->pocet == p_vektor->kapacita)
        zvetsi_vektor(p_vektor);
    p_vektor->pole[p_vektor->pocet] = hodnota;
    p_vektor->pocet++;    
}

// Uloží prvek na daný index ve vektoru
void uloz_do_vektoru(VEKTOR *p_vektor, int index, int hodnota)
{
    p_vektor->pole[index] = hodnota;
}

// Načte prvek z vektoru na daném indexu 
int nacti_z_vektoru(VEKTOR *p_vektor, int index)
{
    return p_vektor->pole[index];
}

int main(int argc, char** argv) {
    // Vytvoření vektoru
    VEKTOR *p_vektor = vytvor_vektor(p_vektor);
    
    // Zkouška vektoru - přidáme do něj 1000 prvků
    int i;
    for (i = 0; i < 1000; i++)
    {
        pridej_do_vektoru(p_vektor, i); // Přidá na konec pole číslo i
    }
    
    // Nyní prvky z vektoru vypíšeme
    for (i = 0; i < 1000; i++)
    {
        printf("%d ", nacti_z_vektoru(p_vektor, i));
    }
    
    // Vypišme prvek veprostřed
    printf("\n\n%d", nacti_z_vektoru(p_vektor, p_vektor->pocet/2));
    
    // Uvolnění vektoru
    uvolni_vektor(p_vektor);
    return (EXIT_SUCCESS);
}