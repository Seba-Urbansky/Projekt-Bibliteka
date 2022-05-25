#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ksiazki.h"
#include "common.h"
// Dodawanie/usuwanie/edycja książek (ID, tytuł, rok, autor, gatunek, liczba egzemplarzy, liczba wypożyczonych).
// http://fizyka.umk.pl/~leii/wskaznikiStrukturyAiR.pdf

Ksiazka *pierwsza_ksiazka = NULL; /*!< Wskaznik na pierwsza ksiazke w bazie */
Ksiazka *ostatnia_ksiazka = NULL; /*!< Wskaznik na ostatnia ksiazke w bazie */

/*! \fn Ksiazka *zamien(Ksiazka *a, Ksiazka *b)
    \brief

    Funkcja zamienia poprzednia ksiazke z nastepna ksiazke

    \param a
    \param b

    \return funkcja zwraca wartosc zamienionej ksiazki

*/

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

/*! \fn int policz_ksiazki()
    \brief

    Funkcja w petli przechodzi po wszystkich ksiazkach i zlicza ksiazki
    liczac kazda ksiazke po ktorej przechodzi


    \return funkcja zwraca zliczona wartosc ksiazek

*/

int policz_ksiazki()
{
    int licznik = 0;
    for (Ksiazka *wpis = pierwsza_ksiazka; NULL != wpis; wpis = wpis->nastepny)
    {
        licznik++;
    }
    return licznik;
}

/*! \fn void sortowanie(enum SortowanieKolejnosc kolejnosc, enum SortowanieAtrybut atrybut)
    \brief
    Sortowanie babelkowe \n
    Funkcja sortowania działa na dwoch petlach for, ktore przechodza po wszytskich ksiazkach
    W funkcji korzystam z dwoch zmiennych p1 oraz p2 oraz korzystam z funkcji strcasecmp
    ktora porownuje wartosci string, natomiast w funkcjach sortujacych wartosci
    liczbowe uzywam operatorow porownania ">" i "<" .


    \param kolejnosc parametr ten odpowiada za wyswietlanie w kolejnosci malejacej lub rosnacej
    \param atrybut parametr ten odpowiada za wybranie co mamy sortowac (tytul, autora, rok, gatunek, l. egzamplarzy, l.wypozyczonych)
*/

void sortowanie(enum SortowanieKolejnosc kolejnosc, enum SortowanieAtrybut atrybut)
{
    Ksiazka **h;
    int licznik = policz_ksiazki();
    int i, j;

    for (i = 0; i <= licznik; i++)
    {
        h = &pierwsza_ksiazka;

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
                    }
                    break;
                case Autor:
                    if (strcasecmp(p1->autor, p2->autor) >= 0)
                    {
                        *h = zamien(p1, p2);
                    }
                    break;
                case Rok:
                    if (p1->rok > p2->rok)
                    {
                        *h = zamien(p1, p2);
                    }
                    break;
                case Gatunek:
                    if (strcasecmp(p1->gatunek, p2->gatunek) >= 0)
                    {
                        *h = zamien(p1, p2);
                    }
                    break;
                case ID:
                    if (p1->ID > p2->ID)
                    {
                        *h = zamien(p1, p2);
                    }
                    break;

                case LiczbaEgzemplarzy:
                    if (p1->liczba_egzemplarzy > p2->liczba_egzemplarzy)
                    {
                        *h = zamien(p1, p2);
                    }
                    break;
                case LiczbaWypozyczonych:
                    if (p1->liczba_wypozyczonych > p2->liczba_wypozyczonych)
                    {
                        *h = zamien(p1, p2);
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
                    }
                    break;
                case Autor:
                    if (strcasecmp(p1->autor, p2->autor) <= 0)
                    {
                        *h = zamien(p1, p2);
                    }
                    break;
                case Rok:
                    if (p1->rok < p2->rok)
                    {
                        *h = zamien(p1, p2);
                    }
                    break;
                case Gatunek:
                    if (strcasecmp(p1->gatunek, p2->gatunek) <= 0)
                    {
                        *h = zamien(p1, p2);
                    }
                    break;
                case ID:
                    if (p1->ID < p2->ID)
                    {
                        *h = zamien(p1, p2);
                    }
                    break;
                case LiczbaEgzemplarzy:
                    if (p1->liczba_egzemplarzy < p2->liczba_egzemplarzy)
                    {
                        *h = zamien(p1, p2);
                    }
                    break;
                case LiczbaWypozyczonych:
                    if (p1->liczba_wypozyczonych < p2->liczba_wypozyczonych)
                    {
                        *h = zamien(p1, p2);
                    }
                    break;
                }
                break;
            }
            h = &(*h)->nastepny;
        }
    }
}

/*! \fn void wyszukaj_ksiazki_po_tytule()
    \brief

   Funkcja ta po podaniu wpisu przez uzytkownika, ktory wpisal tytul ksiazki ktorej szukajl
   wyszukuje dany tytul ksiazki i wyswietla ja na ekran.
   - Korzystam tutaj z fflush, ktore umozliwa mi wyszukiwanie dwuwyrazowych tytulow,
   bez tego by szukalo jednowyrazowe tytuly

*/

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

/*! \fn void wyszukaj_ksiazki_po_autorze()
    \brief

   Funkcja ta po podaniu wpisu przez uzytkownika, ktory wpisal autora ksiazki, wyszukuje danego
   autora i wyswietla go na ekran
   - Korzystam tutaj z fflush, ktore umozliwa mi wyszukiwanie dwuwyrazowych autorow np.(Jan Kowalski),
   bez tego by szukalo jednowyrazowego autora np. (Jan)

*/

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

/*! \fn void wyszukaj_ksiazki_po_gatunku()
    \brief

   Funkcja ta po podaniu wpisu przez uzytkownika, ktory wpisal gatunek danej ksiazki, wypisuje mu
   zawartosc na ekran
   - Korzystam tutaj z fflush, ktore umozliwa mi wyszukiwanie dwuwyrazowych gatunkow (Sc Fi)
   bez tego by szukalo tylko jednowyrazowe gatunki (scfi)

*/

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

/*! \fn void wyszukaj_ksiazki_po_roku()
    \brief

   Funkcja ta po podaniu wpisu przez uzytkownika, zwraca ksiazke z roku ktory uzytkownik podal
   i zwraca ja na ekran

*/

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

/*! \fn void wyszukaj_po_liczbie_wypozyczonych()
    \brief

   Funkcja ta po podaniu przez uzytkownika liczbe wypozyczonych ksiazek, zwraca na ekran
   dane ksiazki, ktora posiada liczbe wypozyczonych ksiazek ktore uzytkownik podal przy
   wpisie

*/

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

/*! \fn void wyszukaj_po_liczbie_egzemplarzy()
    \brief

   Funkcja ta po podaniu przez uzytkownika liczby egzemplarzy ksiazek, zwraca na ekran
   dane ksiazki, ktora posiada dana liczbe egzemplarzy ksiazek ktore uzytkownik podal przy
   wpisie

*/

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

/*! \fn void wydrukuj_po_ID()
    \brief

   Drukuje na ekran dane ksiazki, po wpisie uzytkownika, ktory wpisal chciane ID ksiazki


*/

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

/*! \fn void wyswietl_baze_ksiazek()
    \brief

   Wyswietla cala baze ksiazek


*/

void wyswietl_baze_ksiazek()
{
    printf("BAZA KSIAZEK ------------------------\n");
    for (Ksiazka *wpis = pierwsza_ksiazka; NULL != wpis; wpis = wpis->nastepny)
    {
        wydrukuj_ksiazke(wpis);
        printf("--------------------------------------\n");
    }
}

/*! \fn void dodaj_ksiazke()
    \brief

   Za pomoca wpisu uzytkownika dotyczacego (ID ksiazki, tytulu ksiazki, gatunku ksiazki, autora
   roku, liczby egzemplarzy) dodaje ksiazke wedlug wpisu uzytkownika do bazy ksiazek


*/

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

/*! \fn void edytuj_liczbe_egzemplarzy(Ksiazka *wpis)
    \brief

   Wpis uzytkownika dokonuje zmiane liczby egzemplarzy danej ksiazki
    \param wpis oznacza wpis uzytkownika dokonujacego zmiany
*/

void edytuj_liczbe_egzemplarzy(Ksiazka *wpis)
{
    printf("Podaj  liczbe egzemplarzy: \n");
    scanf("%d", &wpis->liczba_egzemplarzy);
}

/*! \fn void edytuj_liczbe_wypozyczonych(Ksiazka *wpis)
    \brief

   Wpis uzytkownika dokonuje zmiane liczby wypozyczonych danej ksiazki
    \param wpis oznacza wpis uzytkownika dokonujacego zmiany
*/

void edytuj_liczbe_wypozyczonych(Ksiazka *wpis)
{
    printf("Podaj edytuj liczbe wypozyczonych: \n");
    scanf("%d", &wpis->liczba_wypozyczonych);
}

/*! \fn int znajdz_najwyzsze_ID_ksiazki()
    \brief
    Szukanie najwyzszego ID ksiazki polega na tym, ze petlo for przechodzimy po
    wszystkich ksiazkach i w warunku if sprawdzamy czy aktualne ID jest wieksze od
    aktualnego max, jesli tak to napisujemy max nowym max (aktualne ID)

    \return Funkcja zwraca ksiazke o najwyzszym ID
*/

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

/*! \fn void edytuj_ksiazki_ID_ksiazki(Ksiazka *wpis)
    \brief

   Wpis uzytkownika dokonuje zmiany ID danej ksiazki
    \param wpis oznacza wpis uzytkownika dokonujacego zmiany
*/

void edytuj_ksiazki_ID_ksiazki(Ksiazka *wpis)
{
    wpis->ID = znajdz_najwyzsze_ID_ksiazki() + 1;
}

/*! \fn Ksiazka *wyszukaj_ksiazke(int ID)
    \brief

    W tej funkcji przechodzimy petla po wszystkich ksiazkach i jesli wpis uzytownika jest
    rowny ID danej ksiazki to ksiazka jest znaleziona i jest wypisywana na ekran.


    \param ID ksiazka wyszukiwana jest po ID
*/

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

/*! \fn void wydrukuj_ksiazke(Ksiazka *wpis)
    \brief

   W tej funkcji drukujemy wszystkie dane ksiazki (ID, Tytul, Autora, Rok, Liczbe egzemplarzy,
   Liczbe wypozyczonych) oraz wyswietlamy te dane na ekranie.


    \param wpis parametr do wydruku wszystkich danych ksiazki
*/

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

/*! \fn void edytuj_tytul_ksiazki(Ksiazka *wpis)
    \brief

    W tej funkcji uzytkownik edytuje tytul danej ksiazki.
    - Dzieki fflush uzytkownik moze edytowac rowniez dwuwyrazowe tytuly, bez tego bylby
    w stanie edytowac jednowyrazowe tytuly.

    \param wpis edytuje tytul ksiazki po wpisie uzytkownika
*/

void edytuj_tytul_ksiazki(Ksiazka *wpis)
{
    char tytul[MAX] = " ";
    printf("Podaj tytul: \n");
    fflush(stdin);
    scanf("%[^\n]%*c", &tytul);
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

/*! \fn void edytuj_autora(Ksiazka *wpis)
    \brief

    W tej funkcji uzytkownik edytuje autora danej ksiazki
    - Dzieki fflush uzytkownik moze edytowac rowniez dwuwyrazowego autora np. (Jan Kowalski na
    Bartek Bartkalski), bez fflush mozliwe byloby edytowanie jednowyrazowego autora (Jan na Bartek)
    lub (Nowakowski na Urbanski)

    \param wpis edytuje tytul ksiazki po wpisie uzytkownika
*/

void edytuj_autora(Ksiazka *wpis)
{
    printf("Podaj autora: \n");
    fflush(stdin);
    scanf("%[^\n]%*c", &wpis->autor);
}

/*! \fn void edytuj_rok(Ksiazka *wpis)
    \brief

    W tej funkcji za pomoca wpisu uzytkownika mozemy zmienic rok danej ksiazki
    przykladowo z 1999 na 2004.

    \param wpis na podstawie wpisu zmieniany jest rok danej ksiazki
*/

void edytuj_rok(Ksiazka *wpis)
{
    printf("Podaj rok: \n");
    scanf("%d", &wpis->rok);
}

/*! \fn void edytuj_gatunek_ksiazki(Ksiazka *wpis)
    \brief

    W tej funkcji edytowany jest gatunek danej ksiazki np(romans na fantasty).
    - dzieki fflush mozemy edytowac nawet dwuwyrazowe gatunki ksiazek

    \param wpis zmienia gatunek ksiazki
*/

void edytuj_gatunek_ksiazki(Ksiazka *wpis)
{
    printf("Podaj gatunek literacki: \n");
    fflush(stdin);
    scanf("%[^\n]%*c", &wpis->gatunek);
}

/*! \fn void usun_ksiazke(Ksiazka *wpis)
    \brief

     - W pierwszym warunku jesli poprzednia i nastepna ksiazka maja puste wartosci
      oznacza to ze nie ma co usuwac i do pierwszej i ostatniej ksiazki przypisujemy
      puste wartosci bo nie ma co usuwac
    - W drugim warunku jesli poprzednia ksiazka ma pusta wartosc,
      a nastepna ma jakas wartosc to usuwamy pierwsza ksiazke
    - W trzecim warunku jesli nastepna ksiazka ma pusta wartosc, a poprzednia ma jakas wartosc
      to usuwamy ostatnia ksiazke
    - W czwartym warunku jesli nastepna i poprzednia ksiazka maja jakas wartosd
      to usuwamy ksiazke ktora chcemy usunac

    \param wpis usuwa ksiazke na podstawie wpisu uzytkownika
*/

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

/*! \fn void wczytaniepliku_ksiazki()
    \brief

    Wczytujemy z pliku ksiazki.csv korzystajac z petli while wszystkie dane na ktore wskazuje
    wpis (gatunek, tytul, autor, ID, rok, liczba egzemplarzy, liczba wypozyczonych).
    - W pierwszym if korzystamy z funkcji sprawdzajcej czy plik nie jest pusty
    - Jesli pierwsza ksiazka ma pusta wartosc to jest ona rowna wpisowi na pierwsza ksiazke
    oraz poprzednia ksiazke
    - Natomiast jesli wpis nie jest pusty to wtedy wpis jest rowny nastepnemu elementowi oraz
   poprzedni jest rowny wpisowi na poprzednia ksiazke
   - I na koncu jesli wpis nie jest pusty to wtedy ostatnia ksiazka jest rowna wpisowi

*/

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

/*! \fn void zapispliku_ksiazki()
    \brief
    Prechodzimy w petli przez wszystkie ksiazki  i zapisujemy do pliku wszystkie ksiazki na ktore wskazuje
    wpis (gatunek, tytul, autor, ID, rok, liczba egzemplarzy, liczba wypozyczonych)
    - Jesli wpis na nastepny element nie jest pusty to wtedy zapisujemy do pliku
*/

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
