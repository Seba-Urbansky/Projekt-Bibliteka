


#ifndef WYPOZYCZENIA_H
#define WYPOZYCZENIA_H


#include <stdio.h>
#include <stdlib.h>
#include "common.h"


typedef struct WypozyczeniaStruktura
{
    int numer_karty;
    int ID_ksiazki;
    int ID;
    int kiedy;
    int dokiedy;

    struct WypozyczeniaStruktura *poprzedni, *nastepny;

} Wypozyczenia;




void wyswietl_kto_wypozyczyl();
void ID_ksiazki();
void kiedy();
void do_kiedy();
void wydrukuj_wypozyczenia();
void zapispliku_wypozyczenia();
void wczytaniepliku_wypozyczenia();
void edytuj_wypozyczenia_ID_ksiazki(Wypozyczenia* wpis);
void edytuj_wypozyczenia_numer_karty(Wypozyczenia* wpis);
int znajdz_najwyzsze_ID();
void edytuj_wypozyczenia_ID(Wypozyczenia* wpis);
void dodaj_wypozyczenie();
void ustaw_ID_nowego_wypozyczenia();



#endif