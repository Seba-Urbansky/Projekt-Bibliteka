#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 32
#include "klienci.h"
#include "common.h"

// http://fizyka.umk.pl/~leii/wskaznikiStrukturyAiR.pdf

Klient *pierwszy_klient = NULL;
Klient *ostatni_klient = NULL;

/*! \fn void wyswietl_baze_klientow()
     \brief Funkcja wyswietl_baze_klientow wyswietla dane klientow z pliku
*/

void wyswietl_baze_klientow()
{
    printf("BAZA KLIENTOW ------------------------\n");
    for (Klient *wpis = pierwszy_klient; NULL != wpis; wpis = wpis->nastepny)
    {
        wydrukuj_klienta(wpis);
        printf("--------------------------------------\n");
    }
}

/*! \fn void dodaj_klienta()
    \brief Funkcja dodaj_klienta dodaje nowego klienta do bazy danych
    \brief Jesli nie ma klientow w bazie to tworzymy nowego klienta
    \brief w przeciwnym wypadku wpis uzytkownika dodaje nastepnego klienta do bazy klientow
*/

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

/*! \fn int znajdz_najwyzsze_ID_klienci()
     \brief Funkcja wyszukuje w pliku ID klienta o najwyzszej wartosci
     \brief jesli wpis uzytkownika jest wiekszy od aktualnego max, to nastepuje nowe maksimum
    \param (brak parametru)
    \return Zwracane jest najwyzsze ID klienta
*/

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

/*! \fn void edytuj_wypozyczenia_numer_karty_abc(Klient *wpis)
     \brief wpis uzytkownika jest przypisywany do numeru karty ktory jest rowny
     \brief najwyzszemu ID klienta + 1
    \param wpis pobierany jest parametr z wpisu uzytkownika, ktory chce cos edytowac
*/

void edytuj_wypozyczenia_numer_karty_abc(Klient *wpis)
{
    wpis->numer_karty = znajdz_najwyzsze_ID_klienci() + 1;
}

/*! \fn Klient *wyszukaj_klienta(int numer_karty)
     \brief przechodzimy w petli przez wszystkich klientow
     \brief jesli wpis uzytkownika szukajacego numeru_karty jest rowny szukanemu numerowi karty zwroc wpis
     \brief jezeli uzytkownik nic nie wpisze nie zwracaj niczego
    \param numer_karty dany klient wyszukiwany jest po numerze karty
    \return Funkcja zwraca szukanego klienta
*/

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

/*! \fn void wydrukuj_klienta(Klient *wpis)
     \brief Funkcja wydrukowuje na ekran numer_karty, imie, nazwisko,
     \brief , telefon, email klienta
    \param wpis Dane klienta sa wydrukowywane na podstawie wpisu klienta
*/

void wydrukuj_klienta(Klient *wpis)
{
    printf("%-20s | %d \n", "Numer Karty", wpis->numer_karty);
    printf("%-20s | %s \n", "Imie", wpis->imie);
    printf("%-20s | %s \n", "Nazwisko", wpis->nazwisko);
    printf("%-20s | %s \n", "Telefon", wpis->telefon);
    printf("%-20s | %s \n", "Email", wpis->email);
}

/*! \fn void edytuj_imie_klienta(Klient *wpis)
     \brief Funkcja edytuje dane imie klienta na podstawie wpisu uzytkownika
    \param wpis na podstawie parametru wpisu uzytkownika edytowane jest biezace imie
*/

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

/*! \fn void edytuj_telefon_klienta(Klient *wpis)
     \brief Funkcja edytuje dane telefonu klienta na podstawie wpisu uzytkownika
    \param wpis na podstawie parametru wpisu uzytkownika edytowany jest biezacy telefon
*/

void edytuj_telefon_klienta(Klient *wpis)
{
    printf("Podaj telefon: \n");
    scanf("%s", &wpis->telefon);
}

/*! \fn void edytuj_email_klienta(Klient *wpis)
     \brief Funkcja edytuje email klienta na podstawie wpisu uzytkownika
    \param wpis na podstawie parametru wpisu uzytkownika edytowany jest biezacy email uzytkownika
*/

void edytuj_email_klienta(Klient *wpis)
{
    printf("Podaj email: \n");
    scanf("%s", &wpis->email);
}

/*! \fn void edytuj_nazwisko_klienta(Klient *wpis)
     \brief Funkcja edytuje nazwisko klienta na podstawie wpisu uzytkownika
    \param wpis na podstawie parametru wpisu uzytkownika edytowane jest biezace nazwisko klienta
*/

void edytuj_nazwisko_klienta(Klient *wpis)
{
    printf("Podaj nazwisko: \n");
    scanf("%s", &wpis->nazwisko);
}

/*! \fn void usun_klienta(Klient *wpis)
     \brief w pierwszym warunku jesli pierwszy i nastepny klient maja puste wartosci
     \brief oznacza to ze nie ma co usuwac i do pierwszego i ostatniego klienta przypisujemy 
     \brief puste wartosci bo nie ma co usuwac
     \brief w drugim warunku jesli poprzedni klient ma pusta wartosc, a nastepny ma jakas wartosc
     \brief to usuwamy pierwszego klienta
     \brief w trzecim warunku jesli nastepny klient ma pusta wartosc, a poprzedni ma jakas wartosc
     \brief to usuwamy ostatniego klienta
      \brief w czwartym warunku jesli nastepny i poprzedni klient maja jakas wartosc
     \brief to usuwamy klienta ktorego chcemy usunac
    \param wpis na podstawie parametru wpisu uzytkownika usuwany jest klient
*/

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
            wpis = (Klient *)malloc(sizeof(Klient));
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
