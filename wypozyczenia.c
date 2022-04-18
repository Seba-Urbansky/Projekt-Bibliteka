#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 32

// Wypożyczanie/oddawanie książek (kto wypożyczył (numer karty), którą książkę (ID), kiedy, do kiedy). 
// http://fizyka.umk.pl/~leii/wskaznikiStrukturyAiR.pdf

void menu_wypozyczen();



struct wypozyczenia
{

    int numer_karty;
    int ID;ś
    char* kiedy[MAX];
    char* dokiedy[MAX];
    

    struct wypozyczenia *poprzedni, *nastepny;

} baza;

struct wypozyczenia *poczatek = NULL;
struct wypozyczenia *koniec = NULL;

void wyswietl_kto_wypozyczyl();
void ID_ksiazki();
void kiedy();
void do_kiedy();
void wydrukuj_wypozyczenia();

void wydrukuj_ksiazki(struct wypozyczenia* wpis) {
    printf ("%d ", wpis->ID);
    printf ("%s ", wpis->numer_karty);
    printf ("%s ", wpis->kiedy);
    printf ("%s ", wpis->dokiedy);
    
    printf ("\n");
}



void wyswietl_kto_wypozyczyl()
{
    printf ("BAZA WYPOZYCZEN ------------------------\n");
    for (struct wypozyczenia *wpis = poczatek; NULL != wpis; wpis = wpis -> nastepny) {
        wydrukuj_wypozyczenia(wpis);
    }
    printf ("--------------------------------------\n\n");
    menu_klientow();
}


int main()
{


}