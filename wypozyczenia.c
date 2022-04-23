#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 32
#include "wypozyczenia.h"
// Wypożyczanie/oddawanie książek (kto wypożyczył (numer karty), którą książkę (ID), kiedy, do kiedy). 
// http://fizyka.umk.pl/~leii/wskaznikiStrukturyAiR.pdf

void menu_wypozyczen();





struct WypozyczeniaStruktura *poczatek = NULL;
struct WypozyczeniaStruktura *koniec = NULL;



void wydrukuj_wypozyczenia(struct WypozyczeniaStruktura* wpis) {
    printf ("%d ", wpis->ID);
    printf ("%s ", wpis->numer_karty);
    printf ("%s ", wpis->kiedy);
    printf ("%s ", wpis->dokiedy);
    
    printf ("\n");
}



void wyswietl_kto_wypozyczyl()
{
    printf ("BAZA WYPOZYCZEN ------------------------\n");
    for (struct WypozyczeniaStruktura *wpis = poczatek; NULL != wpis; wpis = wpis -> nastepny) {
        wydrukuj_wypozyczenia(wpis);
    }
    printf ("--------------------------------------\n\n");
    menu_klientow();
}


int main()
{


}