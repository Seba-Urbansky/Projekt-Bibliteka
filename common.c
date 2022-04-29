




#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 32


int czy_plik_jest_pusty(File* plik) 
{
    fseek(plik, 0, SEEK_END);
    if (ftell(fp) == 0)
    {
        return 1;
    }
    fseek(plik, 0, SEEK_SET);
    return 0;
}

// Tutaj sa funkcje uzywane w innych modulach






