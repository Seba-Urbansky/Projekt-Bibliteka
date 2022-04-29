

#ifndef KSIAZKI_H
#define KSIAZKI_H



#include <stdio.h>
#include <stdlib.h>
#include "common.h"

typedef struct KsiazkiStruktura
{

    int ID;
    int rok;
    int liczba_egzemplarzy;
    int liczba_wypozyczonych;
    char* tytul[MAX];
    char* autor[MAX];
    char* gatunek[MAX];
    

    struct KsiazkiStruktura *poprzedni, *nastepny;

} Ksiazki;

void wyswietl_baze_ksiazek();
void dodaj_ksiazke();
void edytuj_ksiazke();
void usun_ksiazke();
void menu_ksiazek();
void wczytaniepliku_ksiazki();
void zapispliku_ksiazki();
void ksiazka_do_zarzadzania();
void wydrukuj_ksiazke(Ksiazki* wpis);
void edytuj_tytul_ksiazki(Ksiazki* wpis);
void edytuj_gatunek_ksiazki(Ksiazki* wpis);
void edytuj_autora(Ksiazki* wpis);
void edytuj_rok(Ksiazki* wpis);
void edytuj_ID(Ksiazki* wpis);
void wyswietl_baze_ksiazek();
Ksiazki* wyszukaj_ksiazke(int ID);
int znajdz_najwyzsze_ID_ksiazki();




#endif


