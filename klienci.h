

#ifndef KLIENCI_H
#define KLIENCI_H



#include <stdio.h>
#include <stdlib.h>
#include "common.h"

typedef struct KlientStruktura
{

    int numer_karty;
    char* imie[MAX];
    char* nazwisko[MAX];
    char* telefon[MAX];
    char* email[MAX];

    struct KlientStruktura *poprzedni, *nastepny;

} Klient;


void wyswietl_baze_klientow();
void dodaj_klienta();
void edytuj_klienta();
void usun_klienta();
void menu_klientow();
void wczytaniepliku_klienci();
void zapispliku_klienci();
void znajdz_klienta_do_zarzadzania();
void wydrukuj_klienta(Klient* wpis);
void edytuj_imie_klienta(Klient* wpis);
void edytuj_nazwisko_klienta(Klient* wpis);
void edytuj_telefon_klienta(Klient* wpis);
void edytuj_email_klienta(Klient* wpis);
void wyswietl_baze_klientow();
Klient* wyszukaj_klienta(int numer_karty);
int znajdz_najwyzsze_ID_klienci();
void edytuj_wypozyczenia_numer_karty_abc(Klient* wpis);



#endif
