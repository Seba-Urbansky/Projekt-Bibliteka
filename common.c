




#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 32

FILE *plik;

/************************************************************
Funkcja czy_plik_jest_pusty sprawdza czy plik ma pusta zawartosc.
Funkcja zwraca 0 w przypadku, gdy plik jest pusty, a zwraca 1 gdy plik jest pelny.
*************************************************************/


/*! \fn int czy_plik_jest_pusty(FILE* plik)  
     \brief Funkcja czy_plik_jest_pusty sprawdza czy plik ma pusta zawartosc.
    \param plik przekazuje parametr do pliku
    \return  Funkcja zwraca 0 w przypadku, gdy plik jest pusty, a zwraca 1 gdy plik jest pelny.
*/
 
int czy_plik_jest_pusty(FILE* plik) 
{
    fseek(plik, 0, SEEK_END);
    if (ftell(plik) == 0)
    {
        return 1;
    }
    fseek(plik, 0, SEEK_SET);
    return 0;
}




// Tutaj sa funkcje uzywane w innych modulach






