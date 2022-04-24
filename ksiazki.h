

#ifndef KSIAZKI_H
#define KSIAZKI_H
#define MAX 32


#include <stdio.h>
#include <stdlib.h>

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
void wydrukuj_ksiazki(struct KsiazkiStruktura* wpis);
void edytuj_tytul_ksiazki(struct KsiazkiStruktura* wpis);
void edytuj_gatunek_ksiazki(struct KsiazkiStruktura* wpis);
void edytuj_autora(struct KsiazkiStruktura* wpis);
void edytuj_rok(struct KsiazkiStruktura* wpis);
void edytuj_ID(struct KsiazkiStruktura* wpis);
void wyswietl_baze_ksiazek();



#endif


