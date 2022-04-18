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



int main()
{


}