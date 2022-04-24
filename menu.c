
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 32

#include "klienci.h"
#include "wypozyczenia.h"
#include "ksiazki.h"
#include "common.h"




// menu glowne plikow

void menu_klientow()
{
    int wybor;

    printf("Witamy w bibliotece, baza klientow! Co chcesz zrobic?");
    printf("\n\n");
    printf("1. Wyswietl baze klientow");
    printf("\n");
    printf("2. Dodaj klienta");
    printf("\n");
    printf("3. Zarzadzaj klientem");
    printf("\n");
    printf("4. Powrot do menu");
    printf("\n");
    printf("5. Wyjscie z programu i zapisanie danych");
    printf("\n\n");

    scanf("%d", &wybor);
    printf("\n");

    switch (wybor) {
    case 1:
        wyswietl_baze_klientow();
        break;
    case 2:
        dodaj_klienta();
        break;
    case 3:
        zarzadzaj_klientem();
        break;
    case 4:
        menu();
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

    printf("Witamy w bibliotece, baza ksiazek! Co chcesz zrobic?");
    printf("\n\n");
    printf("1. Wyswietl baze ksiazek");
    printf("\n");
    printf("2. Dodaj ksiazke");
    printf("\n");
    printf("3. Zarzadzaj ksiazkami");
    printf("\n");
    printf("4. Powrot do menu");
    printf("\n");
    printf("5. Wyjscie z programu i zapisanie danych");
    printf("\n\n");

    scanf("%d", &wybor);
    printf("\n");

    switch (wybor) {
    case 1:
        wyswietl_baze_ksiazek();
        break;
    case 2:
        dodaj_ksiazke();
        break;
    case 3:
        zarzadzaj_klientem();
        break;
    case 4:
        menu();
        break;
    case 5:
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

    printf("Witamy w bibliotece, baza wypozyczen! Co chcesz zrobic?");
    printf("\n\n");
    printf("1. Wyswietl baze wypozyczen");
    printf("\n");
    printf("2. Dodaj wypozyczenie");
    printf("\n");
    printf("3. Zarzadzaj wypozyczeniami");
    printf("\n");
    printf("4. Powrot do menu");
    printf("\n");
    printf("5. Wyjscie z programu i zapisanie danych");
    printf("\n\n");

    scanf("%d", &wybor);
    printf("\n");

    switch (wybor) {
    case 1:
        wyswietl_baze_klientow();
        break;
    case 2:
        dodaj_klienta();
        break;
    case 3:
        zarzadzaj_klientem();
        break;
    case 4:
        menu();
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


void zarzadzaj_klientem() {
    int numer_karty;
    printf("Podaj numer karty klienta: \n");
    scanf("%d", &numer_karty);
     Klient* wpis = wyszukaj_klienta(numer_karty);
    if (wpis == NULL) {
        printf("Nie znaleziono klienta \n");
        zarzadzaj_klientem();
    } else {
        usunedytuj_klient(wpis);
    }
}

void usunedytuj_klient(Klient* wpis) {
    int wybor;

    printf("Witamy w Zarzadzaniu Klientem \n\n");
    printf("1. Wydrukuj klienta \n");
    printf("2. Edytuj imie \n");
    printf("3. Edytuj nazwisko \n");
    printf("4. Usun klienta\n");
    printf("5. Wyjscie z programu i zapisanie danych\n");
    scanf("%d", &wybor);
    printf("\n");

    switch (wybor) {
    case 1:
        wydrukuj_klienta(wpis);
        usunedytuj_klient(wpis);
        break;
    case 2:
        edytuj_imie_klienta(wpis);
        usunedytuj_klient(wpis);
        break;
    case 3:
        edytuj_nazwisko_klienta(wpis);
        usunedytuj_klient(wpis);
        break;
    case 4:
        usun_klienta(wpis);
        menu_klientow();
        break;
    case 5:
        wyjscie();
        break;
    default:
        printf("Niepoprawna instrukcja");
        break;
    }
}

void zarzadzaj_ksiazkami() {
    int ID;
    printf("Podaj numer ID ksiazki: \n");
    scanf("%d", &ID);
    Ksiazki* wpis = wyszukaj_ksiazke(ID);
    if (wpis == NULL) {
        printf("Nie znaleziono ksiazki \n");
        zarzadzaj_ksiazkami();
    } else {
        usunedytuj_ksiazke(wpis);
    }
}


void usunedytuj_ksiazke(Ksiazki* wpis) {
    int wybor;

    printf("Witamy w Zarzadzaniu Ksiazkami \n\n");
    printf("1. Wydrukuj ksiazki \n");
    printf("2. Edytuj tytul ksiazki \n");
    printf("3. Edytuj gatunek ksiazki\n");
    printf("4. Usun ksiazke\n");
    printf("5. Wyjscie z programu i zapisanie danych\n");
    scanf("%d", &wybor);
    printf("\n");

    switch (wybor) {
    case 1:
        wydrukuj_ksiazki(wpis);
        usunedytuj_ksiazke(wpis);
        break;
    case 2:
        edytuj_tytul_ksiazki(wpis);
        usunedytuj_ksiazke(wpis);
        break;
    case 3:
        edytuj_gatunek_ksiazki(wpis);
        usunedytuj_ksiazke(wpis);
        break;
    case 4:
        usun_ksiazke(wpis);
        menu_ksiazek();
        break;
    case 5:
        wyjscie();
        break;
    default:
        printf("Niepoprawna instrukcja");
        break;
    }
}


