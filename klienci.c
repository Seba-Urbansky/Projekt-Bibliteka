#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 32
#include "klienci.h"
#include "common.h"

// http://fizyka.umk.pl/~leii/wskaznikiStrukturyAiR.pdf

Klient *pierwszy_klient = NULL;
Klient *ostatni_klient = NULL;

void wyswietl_baze_klientow()
{
    printf("BAZA KLIENTOW ------------------------\n");
    for (Klient *wpis = pierwszy_klient; NULL != wpis; wpis = wpis->nastepny)
    {
        wydrukuj_klienta(wpis);
    }
    printf("--------------------------------------\n\n");
}

void dodaj_klienta()
{
    Klient *wpis = (Klient *)malloc(sizeof(Klient));

    edytuj_wypozyczenia_numer_karty_abc(wpis);
    edytuj_imie_klienta(wpis);
    edytuj_nazwisko_klienta(wpis);
    edytuj_telefon_klienta(wpis);
    edytuj_email_klienta(wpis);

    if (pierwszy_klient == NULL)
    {
        pierwszy_klient = wpis;
        ostatni_klient = wpis;
    }

    else
    {
        ostatni_klient->nastepny = wpis;
        wpis->poprzedni = ostatni_klient;
        ostatni_klient = wpis;
    }
}
int znajdz_najwyzsze_ID_klienci()
{
    int max = 0;
    for (Klient *wpis = pierwszy_klient; NULL != wpis; wpis = wpis->nastepny)
    {
        if (wpis->numer_karty > max)
        {
            max = wpis->numer_karty;
        }
    }
    return max;
}

void edytuj_wypozyczenia_numer_karty_abc(Klient *wpis)
{
    wpis->numer_karty = znajdz_najwyzsze_ID_klienci() + 1;
}

Klient *wyszukaj_klienta(int numer_karty)
{
    for (Klient *wpis = pierwszy_klient; NULL != wpis; wpis = wpis->nastepny)
    {
        if (wpis->numer_karty == numer_karty)
        {
            return wpis;
        }
    }
    return NULL;
}

void wydrukuj_klienta(Klient *wpis)
{
    printf("%-12s | %d \n", "Numer Karty", wpis->numer_karty);
    printf("%-12s | %d \n", "Imie", wpis->imie);
    printf("%-12s | %d \n", "Nazwisko", wpis->nazwisko);
    printf("%-12s | %d \n", "Telefon", wpis->telefon);
    printf("%-12s | %d \n", "Email", wpis->email);
    printf("\n");

}

void edytuj_imie_klienta(Klient *wpis)
{
    char imie[MAX] = "";
    printf("Podaj imie: \n");
    scanf("%s", &imie);
    if (imie == "")
    {
        printf("Niepoprawne imie, nie powinno byc puste.\n");
        edytuj_imie_klienta(wpis);
    }
    else
    {
        strcpy(wpis->imie, &imie);
    }
}

void edytuj_telefon_klienta(Klient *wpis)
{
    printf("Podaj telefon: \n");
    scanf("%s", &wpis->telefon);
}

void edytuj_email_klienta(Klient *wpis)
{
    printf("Podaj email: \n");
    scanf("%s", &wpis->email);
}

void edytuj_nazwisko_klienta(Klient *wpis)
{
    printf("Podaj nazwisko: \n");
    scanf("%s", &wpis->nazwisko);
}


void usun_klienta(Klient *wpis)
{
    Klient *poprzedni = wpis->poprzedni;
    Klient *nastepny = wpis->nastepny;
    if (poprzedni == NULL && nastepny == NULL)
    {
        pierwszy_klient = NULL;
        ostatni_klient = NULL;
    }
    else if (poprzedni == NULL && nastepny != NULL)
    {
        nastepny->poprzedni = NULL;
        pierwszy_klient = nastepny;
    }
    else if (nastepny == NULL && poprzedni != NULL)
    {
        poprzedni->nastepny = NULL;
        ostatni_klient = poprzedni;
    }
    else
    {
        poprzedni->nastepny = nastepny;
        nastepny->poprzedni = poprzedni;
    }
}


void wczytaniepliku_klienci()
{
    FILE *plik;
    plik = fopen("klienci.csv", "r");

    Klient *wpis = (Klient *)malloc(sizeof(Klient));
    Klient *poprzedni;

    if (!czy_plik_jest_pusty(plik))
    {
        while (!feof(plik))
        {
            wpis = malloc(sizeof(Klient));
            fscanf(plik, "%d %s %s %s %s", &wpis->numer_karty, &wpis->imie, &wpis->nazwisko, &wpis->telefon, &wpis->email);

            if (pierwszy_klient == NULL)
            {
                pierwszy_klient = wpis;
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
            ostatni_klient = wpis;
        }
    }
}

void zapispliku_klienci()
{
    FILE *plik = fopen("klienci.csv", "w");
    for (Klient *wpis = pierwszy_klient; NULL != wpis; wpis = wpis->nastepny)
    {
        fprintf(plik, "%d %s %s %s %s", wpis->numer_karty, wpis->imie, wpis->nazwisko, wpis->telefon, wpis->email);
        if (wpis->nastepny != NULL)
        {
            fprintf(plik, "\n");
        }
        
    }
    fclose(plik);
}
