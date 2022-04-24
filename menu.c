
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
    int wybor;

    printf("Witamy w bibliotece! Co chcesz zrobic?\n\n");
    printf("1. Otwieranie bazy klientow\n");
    printf("2. Otwieranie bazy ksiazek\n");
    printf("3. Otwieranie bazy wypozyczen\n");
    printf("4. Wyjscie z programu i zapisanie danych\n\n");
    

    scanf("%d\n", &wybor);
  

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
   

    scanf("%d\n", &wybor);
   

    switch (wybor) {
    case 1:
        wyswietl_baze_klientow();
        break;
    case 2:
        dodaj_klienta();
        break;
    case 3:
        menu_zarzadzaj_klientem();
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

    printf("Witamy w bibliotece, baza ksiazek! Co chcesz zrobic?\n\n");
    printf("1. Wyswietl baze ksiazek\n");
    printf("2. Dodaj ksiazke\n");
    printf("3. Zarzadzaj ksiazkami\n");
    printf("4. Powrot do menu\n");
    printf("5. Wyjscie z programu i zapisanie danych\n\n");


    scanf("%d\n", &wybor);


    switch (wybor) {
    case 1:
        wyswietl_baze_ksiazek();
        break;
    case 2:
        dodaj_ksiazke();
        break;
    case 3:
        menu_zarzadzaj_klientem();
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

    printf("Witamy w bibliotece, baza wypozyczen! Co chcesz zrobic?\n\n");
    printf("1. Wyswietl baze wypozyczen\n");
    printf("2. Dodaj wypozyczenie\n");
    printf("3. Zarzadzaj wypozyczeniami\n");
    printf("4. Powrot do menu\n");
    printf("5. Wyjscie z programu i zapisanie danych\n\n");

    scanf("%d\n", &wybor);
    

    switch (wybor) {
    case 1:
        wyswietl_baze_klientow();
        break;
    case 2:
        dodaj_klienta();
        break;
    case 3:
        menu_zarzadzaj_klientem();
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


void menu_zarzadzaj_klientem() {
    int numer_karty;
    printf("Podaj numer karty klienta: \n");
    scanf("%d", &numer_karty);
     Klient* wpis = wyszukaj_klienta(numer_karty);
    if (wpis == NULL) {
        printf("Nie znaleziono klienta \n");
        menu_zarzadzaj_klientem();
    } else {
        menu_usunedytuj_klient(wpis);
    }
}

void menu_usunedytuj_klient(Klient* wpis) {
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
        menu_usunedytuj_klient(wpis);
        break;
    case 2:
        edytuj_imie_klienta(wpis);
        menu_usunedytuj_klient(wpis);
        break;
    case 3:
        edytuj_nazwisko_klienta(wpis);
        menu_usunedytuj_klient(wpis);
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

void menu_zarzadzaj_ksiazkami() {
    int ID;
    printf("Podaj numer ID ksiazki: \n");
    scanf("%d", &ID);
    Ksiazki* wpis = wyszukaj_ksiazke(ID);
    if (wpis == NULL) {
        printf("Nie znaleziono ksiazki \n");
        menu_zarzadzaj_ksiazkami();
    } else {
        menu_usunedytuj_ksiazke(wpis);
    }
}


void menu_usunedytuj_ksiazke(Ksiazki* wpis) {
    int wybor;

    printf("Witamy w Zarzadzaniu Ksiazkami \n\n");
    printf("1. Wydrukuj ksiazki \n");
    printf("2. Edytuj tytul ksiazki \n");
    printf("3. Edytuj gatunek ksiazki\n");
    printf("4. Usun ksiazke\n");
    printf("5. Wyjscie z programu i zapisanie danych\n");
    scanf("%d\n", &wybor);
   

    switch (wybor) {
    case 1:
        wydrukuj_ksiazke(wpis);
        menu_usunedytuj_ksiazke(wpis);
        break;
    case 2:
        edytuj_tytul_ksiazki(wpis);
        menu_usunedytuj_ksiazke(wpis);
        break;
    case 3:
        edytuj_gatunek_ksiazki(wpis);
        menu_usunedytuj_ksiazke(wpis);
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



