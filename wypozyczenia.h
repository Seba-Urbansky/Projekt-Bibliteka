


#ifndef WYPOZYCZENIA_H
#define WYPOZYCZENIA_H


#include <stdio.h>
#include <stdlib.h>


struct wypozyczenia
{

    int numer_karty;
    int ID;
    char* kiedy[MAX];
    char* dokiedy[MAX];
    

    struct wypozyczenia *poprzedni, *nastepny;

} baza2;




void wyswietl_kto_wypozyczyl();
void ID_ksiazki();
void kiedy();
void do_kiedy();
void wydrukuj_wypozyczenia();





#endif