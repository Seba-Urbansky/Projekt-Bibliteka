

#ifndef KSIAZKI_H
#define KSIAZKI_H



#include <stdio.h>
#include <stdlib.h>
#include "common.h"

typedef struct Ksiazki
{

    int ID;
    int rok;
    int liczba_egzemplarzy;
    int liczba_wypozyczonych;
    char* tytul[MAX];
    char* autor[MAX];
    char* gatunek[MAX];
    

    struct Ksiazki *poprzedni, *nastepny;

} Ksiazki;

void wyswietl_baze_ksiazek();
void dodaj_ksiazke();
void edytuj_ksiazke();
void usun_ksiazke();
void menu_ksiazek();
void wczytaniepliku_ksiazki();
void zapispliku_ksiazki();
void ksiazka_do_zarzadzania();
void wydrukuj_ksiazke(struct Ksiazki* wpis);
void edytuj_tytul_ksiazki(struct Ksiazki* wpis);
void edytuj_gatunek_ksiazki(struct Ksiazki* wpis);
void edytuj_autora(struct Ksiazki* wpis);
void edytuj_rok(struct Ksiazki* wpis);
void edytuj_ID(struct Ksiazki* wpis);
void wyswietl_baze_ksiazek();
Ksiazki* wyszukaj_ksiazke(int ID);




#endif


