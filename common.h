
#ifndef COMMON_H
#define COMMON_H
#define MAX 32

#include <stdio.h>
#include <stdlib.h>

typedef struct Common
{

    int fp;
    int fseek;
    int ftell;
    

    struct Common *poprzedni, *nastepny;

} File;

int czy_plik_jest_pusty(struct File* plik);


#endif