

#ifndef KSIAZKI_H
#define KSIAZKI_H

#include <stdio.h>
#include <stdlib.h>
#include "common.h"
typedef struct KsiazkaStruktura
{

    int ID;
    int rok;
    char *tytul[MAX];
    char *autor[MAX];
    char *gatunek[MAX];

    struct KsiazkaStruktura *poprzedni, *nastepny;

} Ksiazka;

void wyswietl_baze_ksiazek();
void dodaj_ksiazke();
void edytuj_ksiazke();
void usun_ksiazke();
void menu_ksiazek();
void wczytaniepliku_ksiazki();
void zapispliku_ksiazki();
void ksiazka_do_zarzadzania();
void wydrukuj_ksiazke(Ksiazka *wpis);
void edytuj_tytul_ksiazki(Ksiazka *wpis);
void edytuj_gatunek_ksiazki(Ksiazka *wpis);
void edytuj_autora(Ksiazka *wpis);
void edytuj_rok(Ksiazka *wpis);
void wyswietl_baze_ksiazek();
Ksiazka *wyszukaj_ksiazke(int ID);
int znajdz_najwyzsze_ID_ksiazki();
void edytuj_ksiazki_ID_ksiazki(Ksiazka *wpis);
void sortowanie_ksiazek_niemalejace();
void wyszukiwanie_ksiazek();
void wyszukaj_tytul();
void wyszukaj_autora();
void wyszukaj_rok();


#endif
