#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "wypozyczenia.h"
#include "common.h"
#include "klienci.h"
#include "wypozyczenia.h"
// Wypożyczanie/oddawanie książek (kto wypożyczył (numer karty), którą książkę (ID), kiedy, do kiedy). 
// http://fizyka.umk.pl/~leii/wskaznikiStrukturyAiR.pdf

Wypozyczenia *pierwsze_wypozyczenie = NULL;
Wypozyczenia *ostatnie_wypozyczenie = NULL;

void wydrukuj_wypozyczenia(Wypozyczenia* wpis) 
{
    Klient* klient = wyszukaj_klienta(wpis->numer_karty);
    wydrukuj_klienta(klient);
    printf ("%d ", wpis->ID);
    printf("%d", wpis->ID_ksiazki)
    printf ("%d ", wpis->numer_karty);
    printf ("%d ", wpis->kiedy);
    printf ("%d ", wpis->dokiedy);
    printf ("\n");
}

void wyswietl_kto_wypozyczyl()
{
    printf ("BAZA WYPOZYCZEN ------------------------\n");
    for (Wypozyczenia *wpis = pierwsze_wypozyczenie; NULL != wpis; wpis = wpis -> nastepny) {
        wydrukuj_wypozyczenia(wpis);
    }
    printf ("--------------------------------------\n\n");
}
// Napisz funkcje ktora automatycznie ustawia ID nowego wypozyczenia
// 

void dodaj_wypozyczenie() 
{
     Wypozyczenia *wpis = (Wypozyczenia *)malloc(sizeof(Wypozyczenia));

    edytuj_ID(wpis);
    edytuj_wypozyczenie_numer_ksiazki(wpis);
    

    ostatnie_wypozyczenie->nastepny = wpis;
    wpis->poprzedni = ostatnie_wypozyczenie;
    ostatnie_wypozyczenie = wpis;

}

void wczytaniepliku_wypozyczenia()
{
    FILE *plik;
    plik = fopen("wypozyczenia.csv", "r");

    Wypozyczenia *wpis = (Wypozyczenia *)malloc(sizeof(Wypozyczenia));
    Wypozyczenia *poprzedni;
    while (!feof (plik))
    {
        wpis = malloc(sizeof(Wypozyczenia));
        fscanf(plik, "%d %d %d %d", &wpis->ID, &wpis->numer_karty, &wpis->kiedy, &wpis->dokiedy);
        if (pierwsze_wypozyczenie == NULL) {
            pierwsze_wypozyczenie = wpis;
            poprzedni = wpis;
        } else if (wpis != NULL) {
            poprzedni->nastepny = wpis;
            wpis->poprzedni = poprzedni;
            poprzedni = wpis;
        }
    }
    if (wpis != NULL) {
        ostatnie_wypozyczenie = wpis;
    }
}

void zapispliku_wypozyczenia() {
      FILE *plik = fopen("wypozyczenia.csv", "w");
    for(Wypozyczenia *wpis = pierwsze_wypozyczenie; NULL != wpis; wpis = wpis -> nastepny) {
        fprintf(plik, "%d %d %d %d %d\n", wpis->ID, wpis->numer_karty, wpis->kiedy, wpis->dokiedy);
    }
}

