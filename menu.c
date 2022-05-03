
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 32

#include "klienci.h"
#include "wypozyczenia.h"
#include "ksiazki.h"
#include "common.h"
#include "menu.h"
// menu calego programu
void menu()
{
    wczytaniepliku_klienci();
    wczytaniepliku_ksiazki();
    wczytaniepliku_wypozyczenia();
    menu_glowne();
}

void menu_glowne()
{
    int wybor;

    printf("Witamy w bibliotece! Co chcesz zrobic?\n\n");
    printf("1. Otwieranie bazy klientow\n");
    printf("2. Otwieranie bazy ksiazek\n");
    printf("3. Otwieranie bazy wypozyczen\n");
    printf("4. Wyjscie z programu i zapisanie danych\n\n");

    scanf("%d", &wybor);
    printf("\n");

    switch (wybor)
    {
    case 1:
        menu_klientow();
        break;

    case 2:
        menu_ksiazek();
        break;

    case 3:

        menu_wypozyczen();
        break;

    case 4:
        wyjscie();
        break;

    default:
        printf("Niepoprawna instrukcja");
        break;
    }
}

// menu glowne plikow

void menu_klientow()
{
    int wybor;

    printf("Witamy w bibliotece, baza klientow! Co chcesz zrobic?\n\n");
    printf("1. Wyswietl baze klientow\n");
    printf("2. Dodaj klienta\n");
    printf("3. Zarzadzaj klientem\n");
    printf("4. Powrot do menu\n");
    printf("5. Wyjscie z programu i zapisanie danych\n\n");

    scanf("%d", &wybor);
    printf("\n");

    switch (wybor)
    {
    case 1:
        wyswietl_baze_klientow();
        menu_klientow();
        break;
    case 2:
        dodaj_klienta();
        menu_klientow();
        break;
    case 3:
        menu_zarzadzaj_klientem();
        menu_klientow();
        break;
    case 4:
        menu_glowne();
        break;
    case 5:
        wyjscie();
        break;
    default:
        printf("Niepoprawna instrukcja");
        break;
    }
}

void menu_ksiazek()
{
    int wybor;

    printf("Witamy w bibliotece, baza ksiazek! Co chcesz zrobic?\n\n");
    printf("1. Wyswietl baze ksiazek\n");
    printf("2. Dodaj ksiazke\n");
    printf("3. Zarzadzaj ksiazkami\n");
    printf("4. Wyszukaj ksiazke po tytule\n");
    printf("5. Wyszukaj ksiazke po autorze\n");
    printf("6. Wyszukaj ksiazke po roku\n");
    printf("7. Sortuj ksiazki malejaco, po tytule\n");
    printf("8. Sortuj ksiazki rosnaco, po tytule\n");
    printf("9. Powrot do menu\n");
    printf("10. Wyjscie z programu i zapisanie danych\n\n");

    scanf("%d", &wybor);
    printf("\n");

    switch (wybor)
    {
    case 1:
        wyswietl_baze_ksiazek();
        menu_ksiazek();
        break;
    case 2:
        dodaj_ksiazke();
        menu_ksiazek();
        break;
    case 3:
        menu_zarzadzaj_ksiazkami();
        menu_ksiazek();
        break;
    case 4:
        wyszukaj_ksiazki_po_tytule();
        menu_ksiazek();
        break;
    case 5:
        wyszukaj_ksiazki_po_autorze();
        menu_ksiazek();
        break;
    case 6:
        wyszukaj_ksiazki_po_roku();
        menu_ksiazek();
        break;
    case 7:
        
        menu_ksiazek();
        break;
    case 8:
        sortowanie(num SortowanieKolejnosc Rosnaca, enum SortowanieAtrybut Tytul);
        menu_ksiazek();
        break;
    case 9:
        wyjscie();
        break;
    default:
        printf("Niepoprawna instrukcja");
        break;
    }
}

void menu_wypozyczen()
{
    int wybor;

    printf("Witamy w bibliotece, baza wypozyczen! Co chcesz zrobic?\n\n");
    printf("1. Wyswietl baze wypozyczen\n");
    printf("2. Dodaj wypozyczenie\n");
    printf("3. Wyswietl zalegle wypozyczenia\n");
    printf("4. Zwroc wypozyczenie\n");
    printf("5. Powrot do menu\n");
    printf("6. Wyjscie z programu i zapisanie danych\n\n");

    scanf("%d", &wybor);
    printf("\n");

    switch (wybor)
    {
    case 1:
        wyswietl_kto_wypozyczyl();
        menu_wypozyczen();
        break;

    case 2:
        dodaj_wypozyczenie();
        menu_wypozyczen();
        break;

    case 3:
        zalegle_wypozyczenia();
        menu_wypozyczen();
        break;

    case 4:
        zwroc_wypozyczenie();
        menu_glowne();
        break;
    case 5:
        wyjscie();
        break;
    default:
        printf("Niepoprawna instrukcja");
        break;
    }
}

// menu do edycji + zarzadzanie

void menu_zarzadzaj_klientem()
{
    int numer_karty;
    printf("Podaj numer karty klienta: \n");
    scanf("%d", &numer_karty);
    Klient *wpis = wyszukaj_klienta(numer_karty);
    if (wpis == NULL)
    {
        printf("Nie znaleziono klienta \n");
        menu_zarzadzaj_klientem();
    }
    else
    {
        menu_klienta(wpis);
    }
}

void menu_klienta(Klient *klient)
{
    int wybor;

    printf("Witamy w Zarzadzaniu Klientem \n\n");
    printf("1. Wydrukuj klienta \n");
    printf("2. Edytuj imie \n");
    printf("3. Edytuj nazwisko \n");
    printf("4. Usun klienta\n");
    printf("5. Powrot\n");
    printf("6. Wyjscie z programu i zapisanie danych\n");
    scanf("%d", &wybor);
    printf("\n");

    switch (wybor)
    {
    case 1:
        wydrukuj_klienta(klient);
        menu_klienta(klient);
        break;
    case 2:
        edytuj_imie_klienta(klient);
        menu_klienta(klient);
        break;
    case 3:
        edytuj_nazwisko_klienta(klient);
        menu_klienta(klient);
        break;
    case 4:
        if (czy_klient_ma_wypozyczenia(klient))
        {
            printf("Klient powinien oddac wypozyczone ksiazki\n");
            menu_klienta(klient);
        }
        else
        {
            usun_klienta(klient);
            menu_klientow();
        }
        break;
    case 5:
        menu_klientow();
        break;
    case 6:
        wyjscie();
        break;
    default:
        printf("Niepoprawna instrukcja");
        break;
    }
} 

void menu_zarzadzaj_ksiazkami()
{
    int ID;
    printf("Podaj numer ID ksiazki: \n");
    scanf("%d", &ID);
    Ksiazka *wpis = wyszukaj_ksiazke(ID);
    if (wpis == NULL)
    {
        printf("Nie znaleziono ksiazki \n");
        menu_zarzadzaj_ksiazkami();
    }
    else
    {
        menu_ksiazki(wpis);
    }
}

void menu_ksiazki(Ksiazka *ksiazka)
{
    int wybor;

    printf("Witamy w Zarzadzaniu Ksiazkami \n\n");
    printf("1. Wydrukuj ksiazki \n");
    printf("2. Edytuj tytul ksiazki \n");
    printf("3. Edytuj gatunek ksiazki\n");
    printf("4. Usun ksiazke\n");
    printf("5. Powrot\n");
    printf("6. Wyjscie z programu i zapisanie danych\n");
    scanf("%d", &wybor);
    printf("\n");

    switch (wybor)
    {
    case 1:
        wydrukuj_ksiazke(ksiazka);
        menu_ksiazki(ksiazka);
        break;
    case 2:
        edytuj_tytul_ksiazki(ksiazka);
        menu_ksiazki(ksiazka);
        break;
    case 3:
        edytuj_gatunek_ksiazki(ksiazka);
        menu_ksiazki(ksiazka);
        break;
    case 4:
        if (czy_ksiazka_jest_wypozyczona(ksiazka))
        {
            printf("Ksiazka powinna zostac zwrocona przed usunieciem\n");
            menu_ksiazki(ksiazka);
        }
        else
        {
            usun_ksiazke(ksiazka);
            menu_ksiazek();
        }
        break;
    case 5:
        menu_ksiazek();
        break;
    case 6:
        wyjscie();
        break;
    default:
        printf("Niepoprawna instrukcja");
        break;
    }
}

void wyjscie()
{
    printf("Zamykanie programu...");
    zapispliku_ksiazki();
    zapispliku_klienci();
    zapispliku_wypozyczenia();
    exit(0);
}
