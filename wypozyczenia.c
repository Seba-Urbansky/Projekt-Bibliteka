#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "wypozyczenia.h"
#include "common.h"
#include "klienci.h"
#include "wypozyczenia.h"
#include "ksiazki.h"
#include <time.h>

// Wypożyczanie/oddawanie książek (kto wypożyczył (numer karty), którą książkę (ID), kiedy, do kiedy).
// http://fizyka.umk.pl/~leii/wskaznikiStrukturyAiR.pdf

// automatyczne zapisywanie ID w ksiazkach i klientach //

Wypozyczenie *pierwsze_wypozyczenie = NULL;
Wypozyczenie *ostatnie_wypozyczenie = NULL;

void wydrukuj_wypozyczenia(Wypozyczenie *wpis)
{
    float kara = policz_kare(wpis);
    printf("%-20s | %d \n", "ID", wpis->ID);
    printf("%-20s | %d \n", "ID Ksiazki", wpis->ID_ksiazki);
    printf("%-20s | %s", "Do kiedy", ctime(&wpis->dokiedy));
    printf("%-20s | %s", "Kiedy", ctime(&wpis->kiedy));
    if (kara > 0)
    {
        printf("%-20s | %.2f PLN\n", "Kara", kara);
    }
    printf("Ksiazka ---------------------\n");
    Ksiazka *ksiazka = wyszukaj_ksiazke(wpis->ID_ksiazki);
    wydrukuj_ksiazke(ksiazka);
    printf("Klient ----------------------\n");
    Klient *klient = wyszukaj_klienta(wpis->numer_karty);
    wydrukuj_klienta(klient);
}

void wyswietl_kto_wypozyczyl()
{
    printf("BAZA WYPOZYCZEN ------------------------\n");
    for (Wypozyczenie *wpis = pierwsze_wypozyczenie; NULL != wpis; wpis = wpis->nastepny)
    {
        wydrukuj_wypozyczenia(wpis);
        printf("--------------------------------------\n");
    }
}

void oddawanie_ksiazki(Wypozyczenie *wpis)
{
    if (wpis->ID_ksiazki == NULL)
    {
        printf("Ksiazka oddana\n");
    }
    else
    {
        printf("Klient nie oddal ksiazki\n");
    }
}

int czy_klient_ma_wypozyczenia(Klient *klient)
{
    for (Wypozyczenie *wpis = pierwsze_wypozyczenie; NULL != wpis; wpis = wpis->nastepny)
    {
        if (wpis->numer_karty == klient->numer_karty)
        {

            return 1;
        }
    }
    return 0;
}

int czy_ksiazka_jest_wypozyczona(Ksiazka *ksiazka)
{
    for (Wypozyczenie *wpis = pierwsze_wypozyczenie; NULL != wpis; wpis = wpis->nastepny)
    {
        if (wpis->ID_ksiazki == ksiazka->ID)
        {
            return 1;
        }
    }
    return 0;
}

float policz_kare(Wypozyczenie *wpis)
{
    time_t teraz = time(NULL);
    long czas_zalegly = teraz - wpis->dokiedy;
    long dni_zalegle = czas_zalegly / (DZIEN);
    float kara_za_dzien = 1.8;
    return kara_za_dzien * dni_zalegle;
}

int zalegle_wypozyczenia()
{
    time_t teraz = time(NULL);
    printf("ZALEGLE WYPOZYCZENIA ------------------------\n");
    for (Wypozyczenie *wpis = pierwsze_wypozyczenie; NULL != wpis; wpis = wpis->nastepny)
    {
        if (teraz > wpis->dokiedy)
        {
            wydrukuj_wypozyczenia(wpis);
            printf("--------------------------------------\n");
        }
    }
}

int znajdz_najwyzsze_ID()
{
    int max = 0;
    for (Wypozyczenie *wpis = pierwsze_wypozyczenie; NULL != wpis; wpis = wpis->nastepny)
    {
        if (wpis->ID > max)
        {
            max = wpis->ID;
        }
    }
    return max;
}

void edytuj_wypozyczenia_numer_karty(Wypozyczenie *wpis)
{
    int numer_karty;
    printf("Podaj ID klienta:\n");
    scanf("%d", &numer_karty);
    if (wyszukaj_klienta(numer_karty) == NULL)
    {
        printf("Podane klient nie istnieje.\n");
        edytuj_wypozyczenia_numer_karty(wpis);
    }
    else
    {
        wpis->numer_karty = numer_karty;
    }
}

int zwroc_wypozyczenie(Wypozyczenie *wpis)
{
    int ID;
    int numer_karty;
    printf("Podaj numer karty klienta:\n");
    scanf("%d", &numer_karty);
   
     printf("Podaj ID ksiazki\n");
    scanf("%d", &ID);
   
    for (Wypozyczenie *wpis = pierwsze_wypozyczenie; NULL != wpis; wpis = wpis->nastepny)
    {
        wpis=wpis->ID;
        return wpis;
    }
   
    float kara = policz_kare(wpis);
    return kara;
    

}

void edytuj_wypozyczenia_ID_ksiazki(Wypozyczenie *wypozyczenie)
{
    int ID;
    printf("Podaj ID ksiazki:\n");
    scanf("%d", &ID);
    Ksiazka *ksiazka = wyszukaj_ksiazke(ID);
    if (ksiazka == NULL)
    {
        printf("Ksiazka nie istnieje.\n");
    }
    else if (czy_ksiazka_jest_wypozyczona(ksiazka))
    {
        printf("Ksiazka jest juz wypozyczona\n");
    }
    else
    {
        wypozyczenie->ID_ksiazki = ID;
    }
}

void edytuj_wypozyczenia_ID(Wypozyczenie *wpis)
{
    wpis->ID = znajdz_najwyzsze_ID() + 1;
}

void dodaj_wypozyczenie()
{
    Wypozyczenie *wpis = (Wypozyczenie *)malloc(sizeof(Wypozyczenie));

    edytuj_wypozyczenia_ID_ksiazki(wpis);
    edytuj_wypozyczenia_numer_karty(wpis);
    edytuj_wypozyczenia_ID(wpis);

    edytuj_wypozyczenia_do_kiedy(wpis);
    edytuj_wypozyczenia_kiedy(wpis);

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

    Wypozyczenie *wpis = (Wypozyczenie *)malloc(sizeof(Wypozyczenie));

    Wypozyczenie *poprzedni;

    if (!czy_plik_jest_pusty(plik))
    {

        while (!feof(plik))
        {
           wpis = (Wypozyczenie *) malloc(sizeof(Wypozyczenie));
            if (czy_plik_jest_pusty(plik))
            {
                return;
            }
        
            fscanf(plik, "%d %d %d %d %d", &wpis->ID_ksiazki, &wpis->ID, &wpis->numer_karty, &wpis->kiedy, &wpis->dokiedy);

            if (pierwsze_wypozyczenie == NULL)
            {
                pierwsze_wypozyczenie = wpis;
                poprzedni = wpis;
            }

            else if (wpis != NULL)
            {
                poprzedni->nastepny = wpis;
                wpis->poprzedni = poprzedni;
                poprzedni = wpis;
            }
        }
        if (wpis != NULL)
        {
            ostatnie_wypozyczenie = wpis;
        }
    }
}

void edytuj_wypozyczenia_kiedy(Wypozyczenie *wpis)
{
    wpis->kiedy = time(NULL);
}

void edytuj_wypozyczenia_do_kiedy(Wypozyczenie *wpis)
{
    wpis->dokiedy = time(NULL) + 2 * TYDZIEN;
}

void zapispliku_wypozyczenia()
{

    FILE *plik = fopen("wypozyczenia.csv", "w");
    for (Wypozyczenie *wpis = pierwsze_wypozyczenie; NULL != wpis; wpis = wpis->nastepny)
    {

        fprintf(plik, "%d %d %d %d %d", wpis->ID_ksiazki, wpis->ID, wpis->numer_karty, wpis->kiedy, wpis->dokiedy);
        if (wpis->nastepny != NULL)
        {
            fprintf(plik, "\n");
        }
    }
    fclose(plik);
}
