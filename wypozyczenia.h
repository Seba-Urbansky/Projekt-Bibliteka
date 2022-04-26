


#ifndef WYPOZYCZENIA_H
#define WYPOZYCZENIA_H


#include <stdio.h>
#include <stdlib.h>
#include "common.h"


typedef struct Wypozyczenia
{

    int numer_karty;
    int ID;
    int kiedy;
    int dokiedy;
    

    struct Wypozyczenia *poprzedni, *nastepny;

} Wypozyczenia;




void wyswietl_kto_wypozyczyl();
void ID_ksiazki();
void kiedy();
void do_kiedy();
void wydrukuj_wypozyczenia();
void zapispliku_wypozyczenia();
void wczytaniepliku_wypozyczenia();



#endif