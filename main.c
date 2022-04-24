#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 32

#include "klienci.h"
#include "wypozyczenia.h"
#include "ksiazki.h"
#include "common.h"
// menu

// cale polecenie projektu
// Biblioteka. Dodawanie/usuwanie/edycja klientów (numer karty, nazwisko, imię, telefon, E-mail). Dodawanie/usuwanie/edycja książek (ID, tytuł, rok, autor, gatunek, liczba egzemplarzy, liczba wypożyczonych). 
//Wypożyczanie/oddawanie książek (kto wypożyczył (numer karty), którą książkę (ID), kiedy, do kiedy). Wyświetlanie książek z możliwością sortowania niemalejącego/nierosnącego po dowolnym polu.
// Wyszukiwanie książek. Przypominanie o zaległych zwrotach z automatycznym naliczaniem kar umownych. Zapisywanie/wczytywanie danych o klientach, książkach i wypożyczeniach do/z plików. Wykorzystanie list.



void menu();

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
