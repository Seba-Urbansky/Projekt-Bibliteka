#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "wypozyczenia.h"
#include "common.h"
// Wypożyczanie/oddawanie książek (kto wypożyczył (numer karty), którą książkę (ID), kiedy, do kiedy). 
// http://fizyka.umk.pl/~leii/wskaznikiStrukturyAiR.pdf

void menu_wypozyczen();





 Wypozyczenia *pierwsze_wypozyczenie = NULL;
 Wypozyczenia *ostatnie_wypozyczenie = NULL;



void wydrukuj_wypozyczenia(Wypozyczenia* wpis) {
    printf ("%d ", wpis->ID);
    printf ("%s ", wpis->numer_karty);
    printf ("%s ", wpis->kiedy);
    printf ("%s ", wpis->dokiedy);
    
    printf ("\n");
}





void wyswietl_kto_wypozyczyl()
{
    printf ("BAZA WYPOZYCZEN ------------------------\n");
    for (Wypozyczenia *wpis = pierwsze_wypozyczenie; NULL != wpis; wpis = wpis -> nastepny) {
        wydrukuj_wypozyczenia(wpis);
    }
    printf ("--------------------------------------\n\n");
    menu_wypozyczen();
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
        fscanf(plik, "%d %s %s %s %s", &wpis->ID, &wpis->numer_karty, &wpis->kiedy, &wpis->dokiedy);
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
        fprintf(plik, "%d %s %s %s %s\n", wpis->ID, wpis->numer_karty, wpis->kiedy, wpis->dokiedy);
    }
}

