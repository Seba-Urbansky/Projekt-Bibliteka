
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
    printf("4. Wyszukiwanie ksiazek\n");
    printf("5. Sortowanie ksiazek\n");
    printf("6. Powrot do menu\n");
    printf("7. Wyjscie z programu i zapisanie danych\n\n");

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
        menu_ksiazek_wyszukiwania();
        menu_ksiazek();
        break;
    case 5:
        menu_ksiazek_sortowania();
        menu_ksiazek();
        break;

    case 6:
        menu_glowne();
        break;

    case 7:
        wyjscie();
        break;
    default:
        printf("Niepoprawna instrukcja");
        break;
    }
}

void menu_ksiazek_wyszukiwania()
{
    int wybor;
    printf("1. Wyszukaj ksiazke po gatunku\n");
    printf("2. Wyszukaj ksiazke po tytule\n");
    printf("3. Wyszukaj ksiazke po autorze\n");
    printf("4. Wyszukaj ksiazke po roku\n");
    printf("5. Wyszukaj ksiazke po ID\n");
    printf("6. Wyszukaj ksiazke po liczbie egzemplarzy\n");
    printf("7. Wyszukaj ksiazke po liczbie wypozyczonych\n");

    scanf("%d", &wybor);
    printf("\n");

    switch (wybor)
    {
    case 1:
        wyszukaj_ksiazki_po_gatunku();
        menu_ksiazek();
        break;
    case 2:
        wyszukaj_ksiazki_po_tytule();
        menu_ksiazek();
        break;
    case 3:
        wyszukaj_ksiazki_po_autorze();
        menu_ksiazek();
        break;
    case 4:
        wyszukaj_ksiazki_po_roku();
        menu_ksiazek();
        break;
    case 5:
        wydrukuj_po_ID();
        menu_ksiazek();
        break;
    case 6:
        wyszukaj_po_liczbie_egzemplarzy();
        menu_ksiazek();
        break;
    case 7:
        wyszukaj_po_liczbie_wypozyczonych();
        menu_ksiazek();
        break;
    }
}

void menu_ksiazek_sortowania()
{
    int wybor;

    printf("1. Sortuj ksiazki malejaco, po tytule\n");
    printf("2. Sortuj ksiazki rosnaco, po tytule\n");
    printf("3. Sortuj ksiazki malejaco, po autorze\n");
    printf("4. Sortuj ksiazki rosnaco, po autorze\n");
    printf("5. Sortuj ksiazki malejaco, po roku\n");
    printf("6. Sortuj ksiazki rosnaco, po roku\n");
    printf("7. Sortuj ksiazki malejaco, po gatunku\n");
    printf("8. Sortuj ksiazki rosnaco, po gatunku\n");
    printf("9. Sortuj ksiazki malejaco, po ID\n");
    printf("10. Sortuj ksiazki rosnaco, po ID\n");
    printf("11. Sortuj ksiazki malejaco, po liczbie egzemplarzy\n");
    printf("12. Sortuj ksiazki rosnaco, po liczbie egzemplarzy\n");
    printf("13. Sortuj ksiazki malejaco, po liczbie wypozyczonych\n");
    printf("14. Sortuj ksiazki rosnaco, po liczbie wypozyczonych\n");
    printf("15. Powrot do menu ksiazek\n");

    scanf("%d", &wybor);
    printf("\n");

    switch (wybor)
    {
    case 1:
        sortowanie(Malejaca, Tytul);
        wyswietl_baze_ksiazek();
        menu_ksiazek();
        break;
    case 2:
        sortowanie(Rosnaca, Tytul);
        wyswietl_baze_ksiazek();
        menu_ksiazek();
        break;
    case 3:
        sortowanie(Malejaca, Autor);
        wyswietl_baze_ksiazek();
        menu_ksiazek();
        break;
    case 4:
        sortowanie(Rosnaca, Autor);
        wyswietl_baze_ksiazek();
        menu_ksiazek();
        break;
    case 5:
        sortowanie(Malejaca, Rok);
        wyswietl_baze_ksiazek();
        menu_ksiazek();
        break;
    case 6:
        sortowanie(Rosnaca, Rok);
        wyswietl_baze_ksiazek();
        menu_ksiazek();
        break;
    case 7:
        sortowanie(Malejaca, Gatunek);
        wyswietl_baze_ksiazek();
        menu_ksiazek();
        break;
    case 8:
        sortowanie(Rosnaca, Gatunek);
        wyswietl_baze_ksiazek();
        menu_ksiazek();
        break;
    case 9:
        sortowanie(Malejaca, ID);
        wyswietl_baze_ksiazek();
        menu_ksiazek();
        break;
    case 10:
        sortowanie(Rosnaca, ID);
        wyswietl_baze_ksiazek();
        menu_ksiazek();
        break;
    case 11:
        sortowanie(Malejaca, LiczbaEgzemplarzy);
        wyswietl_baze_ksiazek();
        menu_ksiazek();
        break;
    case 12:
        sortowanie(Rosnaca, LiczbaEgzemplarzy);
        wyswietl_baze_ksiazek();
        menu_ksiazek();
        break;
    case 13:
        sortowanie(Malejaca, LiczbaWypozyczonych);
        wyswietl_baze_ksiazek();
        menu_ksiazek();
        break;
    case 14:
        sortowanie(Rosnaca, LiczbaWypozyczonych);
        wyswietl_baze_ksiazek();
        menu_ksiazek();
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
        menu_wypozyczen();
        break;
    case 5:
        menu_glowne();
        break;
    case 6:
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
    printf("4. Edytuj email klienta \n");
    printf("5. Edytuj numer telefonu klienta \n");
    printf("6. Edytuj numer karty klienta \n");
    printf("7. Usun klienta\n");
    printf("8. Powrot\n");
    printf("9. Wyjscie z programu i zapisanie danych\n");
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
        edytuj_email_klienta(klient);
        menu_klienta(klient);
        break;
    case 5:
        edytuj_telefon_klienta(klient);
        menu_klienta(klient);
        break;
    case 6:
        edytuj_wypozyczenia_numer_karty_abc(klient);
        menu_klienta(klient);
        break;
    case 7:
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
    case 8:
        menu_klientow();
        break;
    case 9:
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
    printf("2. Edytuj ID Ksiazki \n");
    printf("3. Edytuj autora \n");
    printf("4. Edytuj tytul ksiazki \n");
    printf("5. Edytuj gatunek ksiazki\n");
    printf("6. Edytuj rok ksiazki \n");
    printf("7. Edytuj liczbe egzemplarzy \n");
    printf("8. Usun ksiazke\n");
    printf("9. Powrot\n");
    printf("10. Wyjscie z programu i zapisanie danych\n");
    scanf("%d", &wybor);
    printf("\n");

    switch (wybor)
    {
    case 1:
        wydrukuj_ksiazke(ksiazka);
        menu_ksiazki(ksiazka);
        break;
    case 2:
        edytuj_ksiazki_ID_ksiazki(ksiazka);
        menu_ksiazki(ksiazka);
        break;
    case 3:
        edytuj_autora(ksiazka);
        menu_ksiazki(ksiazka);
        break;
    case 4:
        edytuj_tytul_ksiazki(ksiazka);
        menu_ksiazki(ksiazka);
        break;
    case 5:
        edytuj_gatunek_ksiazki(ksiazka);
        menu_ksiazki(ksiazka);
        break;
    case 6:
        edytuj_rok(ksiazka);
        menu_ksiazki(ksiazka);
        break;
    case 7:
        edytuj_liczbe_egzemplarzy(ksiazka);
        menu_ksiazki(ksiazka);
        break;
    case 8:
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
    case 9:
        menu_ksiazek();
        break;
    case 10:
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
