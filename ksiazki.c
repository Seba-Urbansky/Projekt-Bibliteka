#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ksiazki.h"
#include "common.h"
// Dodawanie/usuwanie/edycja książek (ID, tytuł, rok, autor, gatunek, liczba egzemplarzy, liczba wypożyczonych).
// http://fizyka.umk.pl/~leii/wskaznikiStrukturyAiR.pdf

Ksiazka *pierwsza_ksiazka = NULL;
Ksiazka *ostatnia_ksiazka = NULL;

void wyszukiwanie_ksiazek(Ksiazka *wpis)
{
    printf("Wyniki wyszukiwania: \n");
    printf("Wyszukany tutul:  \n", wyszukaj_ksiazki_po_tytule(wpis->tytul));
    printf("Wyszukany autor:  \n", wyszukaj_autora(wpis->autor));
    printf("Wyszukany rok:  \n", wyszukaj_rok(wpis->rok));
}

char wyszukaj_ksiazki_po_tytule(Ksiazka *wpis)
{
    char tytul[MAX] = "";
    printf("Podaj tytul: \n");
    scanf("%s", tytul);
    for (Ksiazka *wpis = pierwsza_ksiazka; NULL != wpis; wpis = wpis->nastepny)
    {
        if (strcasestr(wpis->tytul, tytul) != NULL) {
            wydrukuj_ksiazke(wpis);
        }
    }
}



char wyszukaj_ksiazki_po_autorze(Ksiazka *wpis)
{
    char autor[MAX] = "";
    printf("Podaj autora: \n");
    scanf("%s", autor);
    for (Ksiazka *wpis = pierwsza_ksiazka; NULL != wpis; wpis = wpis->nastepny)
    {
        if (strcasestr(wpis->autor, autor) != NULL) {
            wydrukuj_ksiazke(wpis);
        }
    }
}

int wyszukaj_ksiazki_po_roku(Ksiazka *wpis)
{
    int rok;
    printf("Podaj rok: \n");
    scanf("%s", rok);
    for (Ksiazka *wpis = pierwsza_ksiazka; NULL != wpis; wpis = wpis->nastepny)
    {
        if (strcasestr(rok == wpis->rok, rok) != NULL) {
            wydrukuj_ksiazke(wpis);
        }
    }
}


void sortowanie_ksiazek_niemalejace(Ksiazka *ID)
{
    
}

void wyswietl_baze_ksiazek()
{
    printf("BAZA KSIAZEK ------------------------\n");
    for (Ksiazka *wpis = pierwsza_ksiazka; NULL != wpis; wpis = wpis->nastepny)
    {
        wydrukuj_ksiazke(wpis);
        printf("--------------------------------------\n");
    }
}

void dodaj_ksiazke()
{
    Ksiazka *wpis = (Ksiazka *)malloc(sizeof(Ksiazka));

    edytuj_ksiazki_ID_ksiazki(wpis);
    edytuj_tytul_ksiazki(wpis);
    edytuj_gatunek_ksiazki(wpis);
    edytuj_autora(wpis);
    edytuj_rok(wpis);

    if (pierwsza_ksiazka == NULL)
    {

        pierwsza_ksiazka = wpis;
        ostatnia_ksiazka = wpis;
    }

    else
    {
        ostatnia_ksiazka->nastepny = wpis;
        wpis->poprzedni = ostatnia_ksiazka;
        ostatnia_ksiazka = wpis;
    }
}

int znajdz_najwyzsze_ID_ksiazki()
{
    int max = 0;
    for (Ksiazka *wpis = pierwsza_ksiazka; NULL != wpis; wpis = wpis->nastepny)
    {
        if (wpis->ID > max)
        {
            max = wpis->ID;
        }
    }
    return max;
}

void edytuj_ksiazki_ID_ksiazki(Ksiazka *wpis)
{
    wpis->ID = znajdz_najwyzsze_ID_ksiazki() + 1;
}

Ksiazka *wyszukaj_ksiazke(int ID)
{
    for (Ksiazka *wpis = pierwsza_ksiazka; NULL != wpis; wpis = wpis->nastepny)
    {
        if (wpis->ID == ID)
        {
            return wpis;
        }
    }
    return NULL;
}

void wydrukuj_ksiazke(Ksiazka *wpis)
{
    printf("%-20d | %d \n", "ID", wpis->ID);
    printf("%-20s | %s \n", "Tytul", wpis->tytul);
    printf("%-20s | %s \n", "Autor", wpis->autor);
    printf("%-20s | %s \n", "Gatunek", wpis->gatunek);
    printf("%-20s | %d \n", "Rok", wpis->rok);
}

void edytuj_tytul_ksiazki(Ksiazka *wpis)
{
    char tytul[MAX] = " ";
    printf("Podaj nowy tytul: \n");
    scanf("%s", &tytul);
    if (tytul == " ")
    {
        printf("Niepoprawny tytul, nie powinno byc puste.\n");
        edytuj_tytul_ksiazki(wpis);
    }
    else
    {
        strcpy(wpis->tytul, &tytul);
    }
}

void edytuj_autora(Ksiazka *wpis)
{
    printf("Podaj nowego autora: \n");
    scanf("%s", &wpis->autor);
}

void edytuj_rok(Ksiazka *wpis)
{
    printf("Podaj nowy rok: \n");
    scanf("%d", &wpis->rok);
}

void edytuj_gatunek_ksiazki(Ksiazka *wpis)
{
    printf("Podaj nowy gatunek literacki: \n");
    scanf("%s", &wpis->gatunek);
}

void usun_ksiazke(Ksiazka *wpis)
{
    Ksiazka *poprzedni = wpis->poprzedni;
    Ksiazka *nastepny = wpis->nastepny;
    if (poprzedni == NULL && nastepny == NULL)
    {
        pierwsza_ksiazka = NULL;
        ostatnia_ksiazka = NULL;
    }
    else if (poprzedni == NULL && nastepny != NULL)
    {
        nastepny->poprzedni = NULL;
        pierwsza_ksiazka = nastepny;
    }
    else if (nastepny == NULL && poprzedni != NULL)
    {
        poprzedni->nastepny = NULL;
        ostatnia_ksiazka = poprzedni;
    }
    else
    {
        poprzedni->nastepny = nastepny;
        nastepny->poprzedni = poprzedni;
    }
}

void wczytaniepliku_ksiazki()
{
    FILE *plik;
    plik = fopen("ksiazki.csv", "r");

    Ksiazka *wpis = (Ksiazka *)malloc(sizeof(Ksiazka));
    Ksiazka *poprzedni;

    if (!czy_plik_jest_pusty(plik))
    {

        while (!feof(plik))
        {

            wpis = (Ksiazka *)malloc(sizeof(Ksiazka));
            fscanf(plik, "%[^;];%[^;];%[^;];%d;%d\n", wpis->gatunek, wpis->tytul, wpis->autor, &wpis->ID, &wpis->rok);

            if (pierwsza_ksiazka == NULL)
            {
                pierwsza_ksiazka = wpis;
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
            ostatnia_ksiazka = wpis;
        }
    }
}

void zapispliku_ksiazki()
{
    FILE *plik = fopen("ksiazki.csv", "w");
    for (Ksiazka *wpis = pierwsza_ksiazka; NULL != wpis; wpis = wpis->nastepny)
    {
        fprintf(plik, "%s;%s;%s;%d;%d", wpis->gatunek, wpis->tytul, wpis->autor, wpis->ID, wpis->rok);
        if (wpis->nastepny != NULL)
        {
            fprintf(plik, "\n");
        }
    }
    fclose(plik);
}
