


#ifndef WYPOZYCZENIA_H
#define WYPOZYCZENIA_H


#include <stdio.h>
#include <stdlib.h>


struct WypozyczeniaStruktura
{

    int numer_karty;
    int ID;
    char* kiedy[MAX];
    char* dokiedy[MAX];
    

    struct WypozyczeniaStruktura *poprzedni, *nastepny;

} Wypozyczenia;




void wyswietl_kto_wypozyczyl();
void ID_ksiazki();
void kiedy();
void do_kiedy();
void wydrukuj_wypozyczenia();





#endif