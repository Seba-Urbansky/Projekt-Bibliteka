#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ksiazki.h"
#include "common.h"
// Dodawanie/usuwanie/edycja książek (ID, tytuł, rok, autor, gatunek, liczba egzemplarzy, liczba wypożyczonych).
// http://fizyka.umk.pl/~leii/wskaznikiStrukturyAiR.pdf

Ksiazka *pierwsza_ksiazka = NULL;
Ksiazka *ostatnia_ksiazka = NULL;

Ksiazka *zamien(Ksiazka *a, Ksiazka *b)
{
    Ksiazka *tmpNastepny = b->nastepny;
    Ksiazka *tmpPoprzedni = a->poprzedni;
    b->nastepny = a;
    b->poprzedni = tmpPoprzedni;
    a->poprzedni = b;
    a->nastepny = tmpNastepny;
    if (tmpNastepny != NULL)
    {
        tmpNastepny->poprzedni = a;
    }
    if (tmpPoprzedni != NULL)
    {
        tmpPoprzedni->nastepny = b;
    }
    if (b->poprzedni == NULL)
    {
        pierwsza_ksiazka = a;
    }
    if (a->nastepny == NULL)
    {
        ostatnia_ksiazka = a;
    }
    return b;
}

int policz_ksiazki()
{
    int licznik = 0;
    for (Ksiazka *wpis = pierwsza_ksiazka; NULL != wpis; wpis = wpis->nastepny)
    {
        licznik++;
    }
    return licznik;
}

void sortowanie(enum SortowanieKolejnosc kolejnosc, enum SortowanieAtrybut atrybut)
{
    Ksiazka **h;
    int licznik = policz_ksiazki();
    int i, j, zamieniona;

    for (i = 0; i <= licznik; i++)
    {
        h = &pierwsza_ksiazka;
        zamieniona = 0;
        for (j = 0; j < licznik - i - 1; j++)
        {
            Ksiazka *p1 = *h;
            Ksiazka *p2 = p1->nastepny;
            switch (kolejnosc)
            {
            case Rosnaca:
                switch (atrybut)
                {
                case Tytul:
                    if (strcasecmp(p1->tytul, p2->tytul) >= 0)
                    {
                        *h = zamien(p1, p2);
                        zamieniona = 1;
                    }
                    break;
                case Autor:
                    if (strcasecmp(p1->autor, p2->autor) >= 0)
                    {
                        *h = zamien(p1, p2);
                        zamieniona = 1;
                    }
                    break;
                case Rok:
                    if (p1->rok > p2->rok)
                    {
                        *h = zamien(p1, p2);
                        zamieniona = 1;
                    }
                    break;
                case Gatunek:
                    if (strcasecmp(p1->gatunek, p2->gatunek) >= 0)
                    {
                        *h = zamien(p1, p2);
                        zamieniona = 1;
                    }
                    break;
                case ID:
                    if (p1->ID > p2->ID)
                    {
                        *h = zamien(p1, p2);
                        zamieniona = 1;
                    }
                    break;

                case LiczbaEgzemplarzy:
                    if (p1->liczba_egzemplarzy > p2->liczba_egzemplarzy)
                    {
                        *h = zamien(p1, p2);
                        zamieniona = 1;
                    }
                    break;
                case LiczbaWypozyczonych:
                    if (p1->liczba_wypozyczonych > p2->liczba_wypozyczonych)
                    {
                        *h = zamien(p1, p2);
                        zamieniona = 1;
                    }
                    break;
                }
                break;
            case Malejaca:
                switch (atrybut)
                {
                case Tytul:
                    if (strcasecmp(p1->tytul, p2->tytul) <= 0)
                    {
                        *h = zamien(p1, p2);
                        zamieniona = 1;
                    }
                    break;
                case Autor:
                    if (strcasecmp(p1->autor, p2->autor) <= 0)
                    {
                        *h = zamien(p1, p2);
                        zamieniona = 1;
                    }
                    break;
                case Rok:
                    if (p1->rok < p2->rok)
                    {
                        *h = zamien(p1, p2);
                        zamieniona = 1;
                    }
                    break;
                case Gatunek:
                    if (strcasecmp(p1->gatunek, p2->gatunek) <= 0)
                    {
                        *h = zamien(p1, p2);
                        zamieniona = 1;
                    }
                    break;
                case ID:
                    if (p1->ID < p2->ID)
                    {
                        *h = zamien(p1, p2);
                        zamieniona = 1;
                    }
                    break;
                case LiczbaEgzemplarzy:
                    if (p1->liczba_egzemplarzy < p2->liczba_egzemplarzy)
                    {
                        *h = zamien(p1, p2);
                        zamieniona = 1;
                    }
                    break;
                case LiczbaWypozyczonych:
                    if (p1->liczba_wypozyczonych < p2->liczba_wypozyczonych)
                    {
                        *h = zamien(p1, p2);
                        zamieniona = 1;
                    }
                    break;
                }
                break;
            }
            h = &(*h)->nastepny;

            if (zamieniona == 0)
            {
                break;
            }
        }
    }
}

void wyszukaj_ksiazki_po_tytule()
{
    char tytul[MAX] = "";
    printf("Podaj tytul ksiazki: \n");
    fflush(stdin);
    scanf("%[^\n]%*c", &tytul);
    for (Ksiazka *wpis = pierwsza_ksiazka; NULL != wpis; wpis = wpis->nastepny)
    {
        if (strcasestr(wpis->tytul, tytul) != NULL)
        {
            wydrukuj_ksiazke(wpis);
            printf("--------------------------------------\n");
        }
    }
}

void wyszukaj_ksiazki_po_autorze()
{
    char autor[MAX] = "";
    printf("Podaj autora ksiazki: \n");
    fflush(stdin);
    scanf("%[^\n]%*c", &autor);
    printf("--------------------------------------\n");
    for (Ksiazka *wpis = pierwsza_ksiazka; NULL != wpis; wpis = wpis->nastepny)
    {
        if (strcasestr(wpis->autor, autor) != NULL)
        {
            wydrukuj_ksiazke(wpis);
            printf("--------------------------------------\n");
        }
    }
}

void wyszukaj_ksiazki_po_gatunku()
{
    char gatunek[MAX] = "";
    printf("Podaj gatunek ksiazki: \n");
    fflush(stdin);
    scanf("%[^\n]%*c", &gatunek);
    for (Ksiazka *wpis = pierwsza_ksiazka; NULL != wpis; wpis = wpis->nastepny)
    {
        if (strcasestr(wpis->gatunek, gatunek) != NULL)
        {
            wydrukuj_ksiazke(wpis);
            printf("--------------------------------------\n");
        }
    }
}

void wyszukaj_ksiazki_po_roku()
{
    int rok;
    printf("Podaj rok: \n");
    scanf("%d", &rok);
    for (Ksiazka *wpis = pierwsza_ksiazka; NULL != wpis; wpis = wpis->nastepny)
    {
        if (rok == wpis->rok)
        {
            wydrukuj_ksiazke(wpis);
            printf("--------------------------------------\n");
        }
    }
}

void wyszukaj_po_liczbie_wypozyczonych()
{
    int liczba_wypozyczonych;
    printf("Podaj liczbe wypozyczonych: \n");
    scanf("%d", &liczba_wypozyczonych);
    for (Ksiazka *wpis = pierwsza_ksiazka; NULL != wpis; wpis = wpis->nastepny)
    {
        if (liczba_wypozyczonych == wpis->liczba_wypozyczonych)
        {
            wydrukuj_ksiazke(wpis);
            printf("--------------------------------------\n");
        }
    }
}

void wyszukaj_po_liczbie_egzemplarzy()
{
    int liczba_egzemplarzy;
    printf("Podaj liczbe egzemplarzy: \n");
    scanf("%d", &liczba_egzemplarzy);
    for (Ksiazka *wpis = pierwsza_ksiazka; NULL != wpis; wpis = wpis->nastepny)
    {
        if (liczba_egzemplarzy == wpis->liczba_egzemplarzy)
        {
            wydrukuj_ksiazke(wpis);
            printf("--------------------------------------\n");
        }
    }
}

void wydrukuj_po_ID()
{
    int ID;
    printf("Podaj ID ksiazki: \n");
    scanf("%d", &ID);
    for (Ksiazka *wpis = pierwsza_ksiazka; NULL != wpis; wpis = wpis->nastepny)
    {
        if (ID == wpis->ID)
        {
            wydrukuj_ksiazke(wpis);
            printf("--------------------------------------\n");
        }
    }
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
    edytuj_liczbe_egzemplarzy(wpis);

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

void edytuj_liczbe_egzemplarzy(Ksiazka *wpis)
{
    printf("Podaj nowa liczbe egzemplarzy: \n");
    scanf("%d", &wpis->liczba_egzemplarzy);
}

void edytuj_liczbe_wypozyczonych(Ksiazka *wpis)
{
    printf("Podaj edytuj liczbe wypozyczonych: \n");
    scanf("%d", &wpis->liczba_wypozyczonych);
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
    printf("%-20s | %d \n", "ID", wpis->ID);
    printf("%-20s | %s \n", "Tytul", wpis->tytul);
    printf("%-20s | %s \n", "Autor", wpis->autor);
    printf("%-20s | %s \n", "Gatunek", wpis->gatunek);
    printf("%-20s | %d \n", "Rok", wpis->rok);
    printf("%-20s | %d \n", "Liczba egzemplarzy", wpis->liczba_egzemplarzy);
    printf("%-20s | %d \n", "Liczba wypozyczonych", wpis->liczba_wypozyczonych);
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
            fscanf(plik, "%[^;];%[^;];%[^;];%d;%d;%d;%d\n", &wpis->gatunek, &wpis->tytul, &wpis->autor, &wpis->ID, &wpis->rok, &wpis->liczba_egzemplarzy,
                   &wpis->liczba_wypozyczonych);

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
        fprintf(plik, "%s;%s;%s;%d;%d;%d;%d", wpis->gatunek, wpis->tytul, wpis->autor, wpis->ID, wpis->rok, wpis->liczba_egzemplarzy, wpis->liczba_wypozyczonych);
        if (wpis->nastepny != NULL)
        {
            fprintf(plik, "\n");
        }
    }
    fclose(plik);
}
