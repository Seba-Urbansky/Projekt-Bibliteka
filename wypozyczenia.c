#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 32
#include "wypozyczenia.h"
#include "common.h"
// Wypożyczanie/oddawanie książek (kto wypożyczył (numer karty), którą książkę (ID), kiedy, do kiedy). 
// http://fizyka.umk.pl/~leii/wskaznikiStrukturyAiR.pdf

void menu_wypozyczen();





 Wypozyczenia *poczatek = NULL;
 Wypozyczenia *koniec = NULL;



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
    for (Wypozyczenia *wpis = poczatek; NULL != wpis; wpis = wpis -> nastepny) {
        wydrukuj_wypozyczenia(wpis);
    }
    printf ("--------------------------------------\n\n");
    menu_wypozyczen();
}

