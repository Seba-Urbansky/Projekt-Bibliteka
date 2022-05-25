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

Wypozyczenie *pierwsze_wypozyczenie = NULL; /*!< Wskaznik na pierwsze wypozyczenie w bazie */
Wypozyczenie *ostatnie_wypozyczenie = NULL; /*!< Wskaznik na ostatnie wypozyczenie w bazie */

/*! \fn void wydrukuj_wypozyczenia(Wypozyczenie *wpis)
    \brief

    W funkcji realizowane jest drukowanie danych dotyczacych wypozyczen na ekran
    (ID(wypozyczenia), ID ksiazki, kiedy zostala wypozyczona ksiazka i do kiedy ma byc wypozyczona, kara)
    - W funkcji korzystam takze z warunku if ktory wyswietla klienta ktory ma naliczona
    kare wieksza niz 0

    \param wpis na podstawie wpisu na ekran drukowane sa dane o wypozyczeniach
*/

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

/*! \fn void wyswietl_kto_wypozyczyl()
    \brief

   W tej funkcji przechodzimy petla po wszystkich wypozyczeniach i drukujemy cala baze wypozyczen
*/

void wyswietl_kto_wypozyczyl()
{
    printf("BAZA WYPOZYCZEN ------------------------\n");
    for (Wypozyczenie *wpis = pierwsze_wypozyczenie; NULL != wpis; wpis = wpis->nastepny)
    {
        wydrukuj_wypozyczenia(wpis);
        printf("--------------------------------------\n");
    }
}

/*! \fn int czy_klient_ma_wypozyczenia(Klient *klient)
    \brief
    W petli for przechodzimy po wszystkich wypozyczeniach i jesli wpis uzytkownika
    na dany numer karty klienta jest rowny numerowi karty klienta to zwracamy
    true, w przeciwnym wypadku false.

    \param klient korzystam z parametru weryfikujacego wypozyczenia klienta
    \return Funkcja zwraca 1 jesli klient ma wypozyczenia, jesli ich nie ma funkcja zwraca 0
*/

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

/*! \fn int czy_ksiazka_jest_wypozyczona(Ksiazka *ksiazka)
    \brief
    W petli przechodze przez wszystkie wypozyczenia i jesli wpis uzytkowniaka na dane
    ID ksiazki jest rowne ID ksiazki to wtedy zwracam true w przeciwnym wypadku zwracam false

    \param ksiazka korzystam z parametru weryfikujacego wypozyczenia ksiazek
    \return Funkcja zwraca 1 jesli ksiazka jest wypozyczona, w przeciwnym wypadku zwraca 0
*/

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

/*! \fn float policz_kare(Wypozyczenie *wpis)
    \brief
    W funkcji realizowane jest obliczanie kary dla klienta.
    \param wpis
    \return Funkcja zwraca kare ktora nalezy sie klientowi biblioteki, typ float moze zwrocic liczby ulamkowe
*/

float policz_kare(Wypozyczenie *wpis)
{
    time_t teraz = time(NULL);
    long czas_zalegly = teraz - wpis->dokiedy;
    long dni_zalegle = czas_zalegly / (DZIEN);
    float kara_za_dzien = 1.8;
    return kara_za_dzien * dni_zalegle;
}
/*! \fn int zalegle_wypozyczenia()
    \brief
    W funkcji realizowane jest wyswietlanie zaleglych wypozyczen klienta.
    W petli przechodzimy po wszystkich wypozyczeniach i jesli teraz bedzie wieksze od
    wpisu uzytkownika na do kiedy jest termin oddania ksiazki to drukujemy zalegle
    wypozyczenie.

    \return Funkcja zwraca zalegajace wypozyczenia klienta
*/

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

/*! \fn int znajdz_najwyzsze_ID()
    \brief
    W funkcji realizowane jest znajdowanie najwyzszego ID w wyzyczeniach. W petli
    przechodzimy przez wszytstkie wypozyczenia i jesli wpis na ID bedzie wieksze od
    aktualnego max ID to wtedy bedzie nowe maksimum.

    \return Funkcja zwraca najwyzsze ID wypozyczenia
*/

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

/*! \fn void edytuj_wypozyczenia_ID_ksiazki(Wypozyczenie *wypozyczenie)
    \brief
    W tej funkcji edytowane jest ID ksiazki na podstawie wpisu uzytkownika.
    Natomiast jesli ksiazka jest pusta wartoscia to nie ma takiej ksiazki, w przeciwnym
    wypadku przypisujemy do wypozyczenia ID ksiazki ktore jest rowne ID wypozyczenia


    \param wypozyczenie korzystajac z parametru wypozyczenie edytowane jest ID ksiazki
*/

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

    else
    {
        wypozyczenie->ID_ksiazki = ID;
    }
}

/*! \fn void edytuj_wypozyczenia_numer_karty(Wypozyczenie *wpis)
    \brief
   Na poczatku funkcji na podstawie wpisu uzytkownika edytowane jest ID klienta
   ktory ma wypozyczenie.
   - Jesli numer_karty ma pusta wartosc to znaczy ze nie ma takiego klienta i on
   nie istnieje, w przeciwnym wypadku dla wpisu uzytkownika edytowany jest numer
   karty klienta

    \param wpis na podstawie tego parametru edytowany jest numer karty danego wypozyczenia
*/

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

/*! \fn void zwroc_wypozyczenie()
    \brief
   Na poczatku funkcji odpowiedzialnej za zwracanie wypozyczen na poczatku uzytkownik
   podaje numer karty klienta oraz podaje ID ksiazki ktora chce zwrocic.
   W petli przechodzimy przez wszystkie wypozyczenia.
   - Jesli numer karty jest rowny wpisowi uzytkownika oraz jesli ID ksiazki jest rowne
   wpisowi uzytkownika
   - Natomiast jesli funkcja policz kare policzy kare wieksza niz 0 to wtedy w zwracaniu wypozyczenia
   powinna  byc napisana kara dla danego uzytkownika
   - Na koncu uzywamy funkcji do usuwania wypozyczen do ususniecia wypozyczenia

*/

void zwroc_wypozyczenie()
{

    int numer_karty;
    int ID_ksiazki;
    printf("Podaj numer karty klienta:\n");
    scanf("%d", &numer_karty);

    printf("Podaj ID ksiazki\n");
    scanf("%d", &ID_ksiazki);

    for (Wypozyczenie *wpis = pierwsze_wypozyczenie; NULL != wpis; wpis = wpis->nastepny)
    {
        if (numer_karty == wpis->numer_karty && ID_ksiazki == wpis->ID_ksiazki)
        {
            if (policz_kare(wpis) > 0)
            {
                printf("Uzytkownik powinien zwrocic % .2f PLN\n", policz_kare(wpis));
            }
            usun_wypozyczenie(wpis);
            printf("Ksiazka zostala zwrocona\n");
            break;
        }
    }
}

/*! \fn void usun_wypozyczenie(Wypozyczenie *wpis)
    \brief
    - Jesli poprzedni i nastepny element maja puste wartosci to pierwsze i ostatnie
    wypozyczenie ma miec puste wartosci
    - Natomiast jesli poprzedni element ma pusta wartosc a nastepny ma jakas wartosc
    to poprzedni element ma pusta wartosc oraz pierwsze wypozyczenie jest rowne nastepnemu
    elementowi
    - Natomiast jesli nastepny element ma pusta wartosc a natomiast poprzedni ma jakas
    wartosc to wtedy nastepny element ma pusta wartosc oraz ostatnie wypozyczenie jest
    rowne poprzedniemu elementowi
    - W przeciwnym wypadku nastepny element jest rowny wskaznikowi na nastepny element, a
    poprzedni wskaznikowi na poprzedni element.



   \param wpis wpis uzytkownika decyduje ktore wypozyczenie ma byc usuniete

*/

void usun_wypozyczenie(Wypozyczenie *wpis)
{
    Wypozyczenie *poprzedni = wpis->poprzedni;
    Wypozyczenie *nastepny = wpis->nastepny;
    if (poprzedni == NULL && nastepny == NULL)
    {
        pierwsze_wypozyczenie = NULL;
        ostatnie_wypozyczenie = NULL;
    }
    else if (poprzedni == NULL && nastepny != NULL)
    {
        nastepny->poprzedni = NULL;
        pierwsze_wypozyczenie = nastepny;
    }
    else if (nastepny == NULL && poprzedni != NULL)
    {
        poprzedni->nastepny = NULL;
        ostatnie_wypozyczenie = poprzedni;
    }
    else
    {
        poprzedni->nastepny = nastepny;
        nastepny->poprzedni = poprzedni;
    }

    Ksiazka *ksiazka = wyszukaj_ksiazke(wpis->ID_ksiazki);
    if (ksiazka->liczba_wypozyczonych > 0)
    {
        ksiazka->liczba_wypozyczonych--;
    }
}

/*! \fn void edytuj_wypozyczenia_ID(Wypozyczenie *wpis)
    \brief
   Funkcja korzysta z wyszukania najwyzszego ID + 1 a nastepnie wpis uzytkownika edytuje
   ID wypozyczenia

   \param wpis ID wypozyczenia jest edytowane na podstawie wpisu

*/

void edytuj_wypozyczenia_ID(Wypozyczenie *wpis)
{
    wpis->ID = znajdz_najwyzsze_ID() + 1;
}

/*! \fn dodaj_wypozyczenie()
    \brief
   Najpierw korzystamy z funkcji edycji wypozyczenia ID ksiazki
   - Jesli liczba wypozyczonych jest mniejsza od liczby egzemplarzy to wtedy dodajemy
   ksiazki do liczby wypozyczonych
   - W przeciwnym wypadku wszystkim wypadku wszystkei egzemplarze sa wypozyczone
   - Korzystam z funkcji do edycji (numeru karty, ID, kiedy ksiazka zostala wypozyczona
   i do kiedy)
   - Natomiast jesli pierwsze wypozyczenie ma pusta wartosc to pierwsze i ostatnie
   wypozyczenie jest rowne wpisowi uzytkownika, w przeciwnym wypadku wpis uzytkownika
   dotyczy ostatniego wypozyczenia

*/

void dodaj_wypozyczenie()
{
    Wypozyczenie *wpis = (Wypozyczenie *)malloc(sizeof(Wypozyczenie));

    edytuj_wypozyczenia_ID_ksiazki(wpis);

    Ksiazka *ksiazka = wyszukaj_ksiazke(wpis->ID_ksiazki);
    if (ksiazka->liczba_wypozyczonych < ksiazka->liczba_egzemplarzy)
    {

        ksiazka->liczba_wypozyczonych++;
    }
    else
    {
        printf("Wszystkie eksemplarze ksiazki sa wypozyczone\n");
        return;
    }

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

/*! \fn void wczytaniepliku_wypozyczenia()
    \brief
   W tej funkcji wcztujemy dane z pliku wypozyczenia.csv
   - Sprawdzamy czy zawartosc pliku nie jest pusta
   - I w while wczytujemy (ID ksiazki, ID, kiedy ksiazka jest wypozyczona i do kiedy)
   - Jesli pierwsze wypozyczenie ma pusta wartosc to poprzedni element jest rowny wpisowi
   - Natomiast jesli wpis ma jakas wartosc to wpis jest rowny wskaznikowi na poprzedniego na 
   nastepny element, poprzedni element jest rowny wpisowi na poprzedni i wpis jest rowny
   poprzedniemu wypozyczeniu
   - Jesli wpis nie ma pustej wartosci to wtedy ostatnie wypozyczenie jest rowne wpisowi uzytkownika

*/


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
            wpis = (Wypozyczenie *)malloc(sizeof(Wypozyczenie));

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

/*! \fn void edytuj_wypozyczenia_kiedy(Wypozyczenie *wpis)
    \brief
    W tej funkcji mozemy edytowac kiedy uzytkownik wypozyczyl dana ksiazke.
    Wpis uzytkownika zmienia wartosc kiedy ksiazka zostala wypozyczona
   \param wpis na podstawie wpisu uzytkownika ustawiamy wartosc kiedy ksiazka zostala wypozyczona
*/

void edytuj_wypozyczenia_kiedy(Wypozyczenie *wpis)
{
    wpis->kiedy = time(NULL);
}

/*! \fn void edytuj_wypozyczenia_do_kiedy(Wypozyczenie *wpis)
    \brief
    W  tej funkcji mozemy edytowac do kiedy uzytkownik wypozyczyl dana ksiazke.
    Wpis uzytkownika zmienia wartosc do kiedy ksiazka zostala wypozyczona.
    \param wpis na podstawie wpisu uzytkownika ustawiamy wartosc do kiedy ksiazka zostala wypozyczona
   
*/

void edytuj_wypozyczenia_do_kiedy(Wypozyczenie *wpis)
{
    wpis->dokiedy = time(NULL) + 2 * TYDZIEN;
}

/*! \fn void zapispliku_wypozyczenia()
    \brief
    Przechodzimy petla po wszystkich wypozyczeniach.
    Zapisujemy do pliku wartosci (ID Ksiazki, ID wypozyczenia, kiedy ksiazka zostala wypozyczona
    i kiedy jest termin jej oddania)
    - Jesli wpis na nastepny element nie jest pusty to drukuj zawartosc pliku.
   
*/

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
