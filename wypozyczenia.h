


#ifndef WYPOZYCZENIA_H
#define WYPOZYCZENIA_H


#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "klienci.h"
#include "ksiazki.h"
#include <time.h>


typedef struct WypozyczeniaStruktura
{
    int numer_karty;
    int ID_ksiazki;
    int ID;
    time_t kiedy;
    time_t dokiedy;

    struct WypozyczeniaStruktura *poprzedni, *nastepny;

} Wypozyczenie;




void wyswietl_kto_wypozyczyl();
void ID_ksiazki();
void kiedy();
void do_kiedy();
void wydrukuj_wypozyczenia();
void zapispliku_wypozyczenia();
void wczytaniepliku_wypozyczenia();
void edytuj_wypozyczenia_ID_ksiazki(Wypozyczenie *wypozyczenie);
void edytuj_wypozyczenia_numer_karty(Wypozyczenie* wpis);
int znajdz_najwyzsze_ID();
void edytuj_wypozyczenia_ID(Wypozyczenie* wpis);
void dodaj_wypozyczenie();
void ustaw_ID_nowego_wypozyczenia();
void edytuj_wypozyczenia_kiedy(Wypozyczenie *wpis);
void edytuj_wypozyczenia_do_kiedy(Wypozyczenie  *wpis);
void na_dwa_tygodnie();
int zalegle_wypozyczenia();
float policz_kare(Wypozyczenie* wpis);
void oddawanie_ksiazki(Wypozyczenie *wpis);
int czy_klient_ma_wypozyczenia(Klient *klient);
int czy_ksiazka_jest_wypozyczona(Ksiazka *ID_ksiazki);
void zwroc_wypozyczenie();


#endif