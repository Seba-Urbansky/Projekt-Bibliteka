#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "wypozyczenia.h"
#include "common.h"
#include "klienci.h"
#include "wypozyczenia.h"
#include "ksiazki.h"

// Wypożyczanie/oddawanie książek (kto wypożyczył (numer karty), którą książkę (ID), kiedy, do kiedy).
// http://fizyka.umk.pl/~leii/wskaznikiStrukturyAiR.pdf

// automatyczne zapisywanie ID w ksiazkach i klientach //

Wypozyczenia *pierwsze_wypozyczenie = NULL;
Wypozyczenia *ostatnie_wypozyczenie = NULL;

void wydrukuj_wypozyczenia(Wypozyczenia *wpis)
{
    Klient *klient = wyszukaj_klienta(wpis->numer_karty);
    wydrukuj_klienta(klient);
    printf("%d ", wpis->ID);
    printf("%d ", wpis->ID_ksiazki);
    printf("%d ", wpis->numer_karty);
    printf("%d ", wpis->kiedy);
    printf("%d ", wpis->dokiedy);
    printf("\n ");
}

void wyswietl_kto_wypozyczyl()
{
    printf("BAZA WYPOZYCZEN ------------------------\n");
    for (Wypozyczenia *wpis = pierwsze_wypozyczenie; NULL != wpis; wpis = wpis->nastepny)
    {
        wydrukuj_wypozyczenia(wpis);
    }
    printf("--------------------------------------\n\n");
}

int znajdz_najwyzsze_ID()
{
    int max = 0;
    for (Wypozyczenia *wpis = pierwsze_wypozyczenie; NULL != wpis; wpis = wpis->nastepny)
    {
        if (wpis->ID > max)
        {
            max = wpis->ID;
        }
    }
    return max;
}

void edytuj_wypozyczenia_numer_karty(Wypozyczenia *wpis)
{
    int ID;
    printf("Podaj ID klienta:\n");
    scanf("%d", &ID);
    if (wyszukaj_klienta(ID) == NULL)
    {
        printf("Podane klient nie istnieje.\n");
        edytuj_wypozyczenia_numer_karty(wpis);
    }
    else
    {
        wpis->ID_ksiazki = ID;
    }
}

void edytuj_wypozyczenia_ID_ksiazki(Wypozyczenia *wpis)
{
    int ID;
    printf("Podaj ID ksiazki:\n");
    scanf("%d", &ID);
    if (wyszukaj_ksiazke(ID) == NULL)
    {
        printf("Ksiazka nie istnieje.\n");
    }
    else
    {
        wpis->ID_ksiazki = ID;
    }
}

void edytuj_wypozyczenia_ID(Wypozyczenia *wpis)
{
    wpis->ID = znajdz_najwyzsze_ID() + 1;
}

void dodaj_wypozyczenie()
{
    Wypozyczenia *wpis = (Wypozyczenia *)malloc(sizeof(Wypozyczenia));

    edytuj_wypozyczenia_ID_ksiazki(wpis);
    edytuj_wypozyczenia_numer_karty(wpis);
    edytuj_wypozyczenia_ID(wpis);
    if (pierwsze_wypozyczenie == NULL)
    {
        pierwsze_wypozyczenie = wpis;
        ostatnie_wypozyczenie = wpis;
    }

    else
    {

        ostatnie_wypozyczenie->nastepny = wpis;
        wpis->poprzedni = ostatnie_wypozyczenie;
        ostatnie_wypozyczenie = wpis;
    }
}

void wczytaniepliku_wypozyczenia()
{
    FILE *plik;
    plik = fopen("wypozyczenia.csv", "r");

    Wypozyczenia *wpis = (Wypozyczenia *)malloc(sizeof(Wypozyczenia));
    Wypozyczenia *poprzedni;

    while (!feof(plik))
    {

        wpis = malloc(sizeof(Wypozyczenia));
        fscanf(plik, "%d %d %d %d %d", &wpis->ID_ksiazki, &wpis->ID, &wpis->numer_karty, &wpis->kiedy, &wpis->dokiedy);

        if (pierwsze_wypozyczenie == NULL)
        {
            pierwsze_wypozyczenie = wpis;
            poprzedni = wpis;
        }
    }

    if (wpis != NULL)
    {
        poprzedni->nastepny = wpis;
        wpis->poprzedni = poprzedni;
        poprzedni = wpis;
    }

    else
    {
        ostatnie_wypozyczenie->nastepny = wpis;
        wpis->poprzedni = ostatnie_wypozyczenie;
        ostatnie_wypozyczenie = wpis;
    }
}

void zapispliku_wypozyczenia()
{

    Wypozyczenia *wpis = (Wypozyczenia *)malloc(sizeof(Wypozyczenia));
    FILE *plik = fopen("wypozyczenia.csv", "w");

    for (Wypozyczenia *wpis = pierwsze_wypozyczenie; NULL != wpis; wpis = wpis->nastepny)
    {

        fprintf(plik, "%d %d %d %d %d", wpis->ID_ksiazki, wpis->ID, wpis->numer_karty, wpis->kiedy, wpis->dokiedy);
    }

    if (wpis->nastepny != NULL)
    {
        fprintf(plik, "\n");
    }
    while (!feof(plik))
    {
        fclose(plik);
    }
}
