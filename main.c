#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 32

#include "klienci.h"
#include "wypozyczenia.h"
#include "ksiazki.h"
// menu

// cale polecenie projektu
// Biblioteka. Dodawanie/usuwanie/edycja klientów (numer karty, nazwisko, imię, telefon, E-mail). Dodawanie/usuwanie/edycja książek (ID, tytuł, rok, autor, gatunek, liczba egzemplarzy, liczba wypożyczonych). 
//Wypożyczanie/oddawanie książek (kto wypożyczył (numer karty), którą książkę (ID), kiedy, do kiedy). Wyświetlanie książek z możliwością sortowania niemalejącego/nierosnącego po dowolnym polu.
// Wyszukiwanie książek. Przypominanie o zaległych zwrotach z automatycznym naliczaniem kar umownych. Zapisywanie/wczytywanie danych o klientach, książkach i wypożyczeniach do/z plików. Wykorzystanie list.

void menu_klientow();
void menu_ksiazek();
void menu_wypozyczen();
void zarzadzaj_klientem();
void menu();


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



void menu()
{
    int wybor;

    printf("Witamy w bibliotece! Co chcesz zrobic?");
    printf("\n\n");
    printf("1. Otwieranie bazy klientow");
    printf("\n");
    printf("2. Otwieranie bazy ksiazek");
    printf("\n");
    printf("3. Otwieranie bazy wypozyczen");
    printf("\n");
    printf("4. Wyjscie z programu i zapisanie danych");
    printf("\n\n");

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

void wyjscie() {
    printf("Zamykanie programu...");
    zapispliku_klienci();
    exit(0);
}

/*|||||||||||||||||||||||||||||||||||||||||||||||||||||*/
/*|||||||||||||||||||||||||||||||||||||||||||||||||||||*/
/*|||||||||||||||||||||||||||||||||||||||||||||||||||||*/
//klienci


int main() {
    
    menu();
}
