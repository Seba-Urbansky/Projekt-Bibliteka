




#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 32

FILE *plik;

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

char *zmien_na_wielkie_litery(char str[])
{
    char temp[MAX];
    strcpy(temp, str);
    int i = 0;
    while (temp[i])
    {
        temp[i] = (toupper(temp[i]));
        i++;
    }
    return temp;
}



// Tutaj sa funkcje uzywane w innych modulach






