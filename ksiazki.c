#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ksiazki.h"
#include "common.h"
// Dodawanie/usuwanie/edycja książek (ID, tytuł, rok, autor, gatunek, liczba egzemplarzy, liczba wypożyczonych).
// http://fizyka.umk.pl/~leii/wskaznikiStrukturyAiR.pdf

Ksiazki *pierwsza_ksiazka = NULL;
Ksiazki *ostatnia_ksiazka = NULL;

void wyswietl_baze_ksiazek()
{
    printf("BAZA KSIAZEK ------------------------\n");
    for (Ksiazki *wpis = pierwsza_ksiazka; NULL != wpis; wpis = wpis->nastepny)
    {
        wydrukuj_ksiazke(wpis);
    }
    printf("--------------------------------------\n\n");
}

void dodaj_ksiazke()
{
    Ksiazki *wpis = (Ksiazki *)malloc(sizeof(Ksiazki));

    edytuj_ksiazki_ID_ksiazki(wpis);
    edytuj_ID(wpis);
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
    for (Ksiazki *wpis = pierwsza_ksiazka; NULL != wpis; wpis = wpis->nastepny)
    {
        if (wpis->ID > max)
        {
            max = wpis->ID;
        }
    }
    return max;
}

void edytuj_ksiazki_ID_ksiazki(Ksiazki *wpis)
{
    wpis->ID = znajdz_najwyzsze_ID_ksiazki() + 1;
}

Ksiazki *wyszukaj_ksiazke(int ID)
{
    for (Ksiazki *wpis = pierwsza_ksiazka; NULL != wpis; wpis = wpis->nastepny)
    {
        if (wpis->ID == ID)
        {
            return wpis;
        }
    }
    return NULL;
}

void wydrukuj_ksiazke(Ksiazki *wpis)
{
    printf("%d ", wpis->ID);
    printf("%s ", wpis->tytul);
    printf("%s ", wpis->autor);
    printf("%s ", wpis->gatunek);

    printf("\n");
}

void edytuj_tytul_ksiazki(Ksiazki *wpis)
{
    char imie[MAX] = "";
    printf("Podaj tytul: \n");
    scanf("%s", &imie);
    if (imie == "")
    {
        printf("Niepoprawny tytul, nie powinno byc puste.\n");
        edytuj_tytul_ksiazki(wpis);
    }
    else
    {
        strcpy(wpis->tytul, &imie);
    }
}

void edytuj_autora(Ksiazki *wpis)
{
    printf("Podaj nowego autora: \n");
    scanf("%s", &wpis->autor);
}

void edytuj_rok(Ksiazki *wpis)
{
    printf("Podaj nowy rok: \n");
    scanf("%s", &wpis->rok);
}

void edytuj_gatunek_ksiazki(Ksiazki *wpis)
{
    printf("Podaj nowy gatunek literacki: \n");
    scanf("%s", &wpis->gatunek);
}

void usun_ksiazke(Ksiazki *wpis)
{
    Ksiazki *poprzedni = wpis->poprzedni;
    Ksiazki *nastepny = wpis->nastepny;
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

    Ksiazki *wpis = (Ksiazki *)malloc(sizeof(Ksiazki));
    Ksiazki *poprzedni;

    if (!czy_plik_jest_pusty(plik))
    {

        while (!feof(plik))
        {

            wpis = malloc(sizeof(Ksiazki));
            fscanf(plik, "%[^;];%[^;];%[^;];%d\n", wpis->gatunek, wpis->tytul, wpis->autor, &wpis->ID);

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
    for (Ksiazki *wpis = pierwsza_ksiazka; NULL != wpis; wpis = wpis->nastepny)
    {
        fprintf(plik, "%s;%s;%s;%d", wpis->gatunek, wpis->tytul, wpis->autor, wpis->ID);
        if (wpis->nastepny != NULL)
        {
            fprintf(plik, "\n");
        }
        
    }
    fclose(plik);
}
