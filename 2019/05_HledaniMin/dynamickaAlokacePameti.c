
int a;  // promenna 'a'

&a      // adresa promenne 'a'

int *p_a;   // vytvoreni libovolneho pointeru

p_a = &a;   // definuji, ze pointer ukazuje na promennou 'a'

p_a         // pracuji s adresou v pameti

*p_a        // pracuji s promennou a


//==================================================================================

void prohod(int *p_a, int *p_b)
{
    int pomocna = *p_a;
    *p_a = *p_b;
    *p_b = pomocna;
}

int main(int argc, char** argv) {
    int cislo1 = 15;
    int cislo2 = 8;
    prohod(&cislo1, &cislo2);           // predavani referenci
}


//==================================================================================





int main(int argc, char** argv) {
    int *p_i;
    printf("Pokouším se alokovat paměť pro 100 intů.\n");
    // Alokace 100 krát velikosti intu
    p_i = (int *) malloc(sizeof(int) * 100);                    // alokace pameti, 'p_i' bude obsahovat adresu prvniho bloku nasledovany 100 inty

    // Kontrola úspěšnosti alokace
    if (p_i == NULL)
    {
        printf("Nedostatek paměti.\n");
        exit(1);
    }

    // Uvolnění paměti
    printf("Uvolňuji paměť.\n");
    free(p_i);
    p_i = NULL; // Pro jistotu vynullujeme ukazatel
    return (EXIT_SUCCESS);
}



//==================================================================================


int *p_i, *p_paty;
// Alokace 100 krát velikosti intu
p_i = (int *) malloc(sizeof(int) * 100);
if (p_i == NULL)
{
        printf("Nedostatek paměti.\n");
        exit(1);
}

// Výpočet adresy pátého prvku
p_paty = p_i + 4;                                           // vytvoreni pointeru na 5. blok intu

// Uložení hodnoty na pátý prvek
*p_paty = 56;                                               // dosazeni hodnoty do tohoto bloku

// Uvolnění paměti
free(p_i);
p_i = NULL;

//==================================================================================


printf("Prvek, na který ukazuje p_paty je v poli na indexu %d.", p_paty - p_i);             // vysledek je 4; odecitani pointeru (ve stejnem bloku!!!)


//==================================================================================



if (p_paty > p_i)                                           // porovnavani pointeru
{
        printf("p_paty je v paměti až za p_i");
}


//==================================================================================


int *p_pozice;
for (p_pozice = p_i; p_pozice < p_i + 100; p_pozice++)      // naplneni pameoveho bloku 100 intu nulami
{
        *p_pozice = 0;
}

//==================================================================================



int i;
for (i = 0; i < 100; i++)                                    // totez
{
        p_i[i] = 0;
}


//==================================================================================



sizeof(*p_i);                       // velikost prvniho bloku pameti se 100 inty
sizeof(p_i)                         // velikost ukazatele samotneho

sizeof(char*) == sizeof(int*)       // velikost ukazatele je vzdy stejny; pro 32bit = 4B; pro 64bit = 8B


//==================================================================================




char buffer[101];                                               // vytvoreni bolku pameti presne dlouhy pro jmeno
printf("Zadej jméno: ");
// Načtení jména do pomocné paměti
scanf(" %100[^\n]", buffer);
// Vytvoření dynamického řetězce
char* jmeno = (char *) malloc(strlen(buffer) + 1);
// Nastavení hodnoty
strcpy(jmeno, buffer);

printf("Jmenuješ se %s", jmeno);
// Uvolnění paměti
free(jmeno);




//==================================================================================



char * p;       // taky pointeru

char ** p;      // pointer na pointeru

(int *) p;      // pretypovani pointeru na int
