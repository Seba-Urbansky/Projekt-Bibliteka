


#ifndef WYPOZYCZENIA_H
#define WYPOZYCZENIA_H


#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include <time.h>


typedef struct WypozyczeniaStruktura
{
    int numer_karty;
    int ID_ksiazki;
    int ID;
    time_t kiedy;
    time_t dokiedy;

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
void edytuj_wypozyczenia_kiedy();
void edytuj_wypozyczenia_do_kiedy();
void na_dwa_tygodnie();
int zalegle_wypozyczenia();
float policz_kare(Wypozyczenia* wpis);
void oddawanie ksiazki();
void czy_klient_ma_wypozyczenia(Wypozyczenia *numer_karty)



#endif