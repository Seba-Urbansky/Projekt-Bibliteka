

#ifndef KSIAZKI_H
#define KSIAZKI_H


#include <stdio.h>
#include <stdlib.h>

struct ksiazki
{

    int ID;
    int rok;
    int liczba_egzemplarzy;
    int liczba_wypozyczonych;
    char* tytul[MAX];
    char* autor[MAX];
    char* gatunek[MAX];
    

    struct ksiazki *poprzedni, *nastepny;

} baza;

void wyswietl_baze_ksiazek();
void dodaj_ksiazke();
void edytuj_ksiazke();
void usun_ksiazke();
void menu();
void menu_ksiazek();
void wczytaniepliku_ksiazki();
void zapispliku_ksiazki();
void ksiazka_do_zarzadzania();
void wydrukuj_ksiazki(struct ksiazki* wpis);
void edytuj_tytul_ksiazki(struct ksiazki* wpis);
void edytuj_gatunek_ksiazki(struct ksiazki* wpis);
void usunedytuj_ksiazke(struct ksiazki* wpis);
void edytuj_autora(struct ksiazki* wpis);
void edytuj_rok(struct ksiazki* wpis);
void edytuj_ID(struct ksiazki* wpis);
void wyjscie();
void wyswietl_baze_ksiazek();


#endif


