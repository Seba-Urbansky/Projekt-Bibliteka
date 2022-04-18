#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 32

// menu

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
        //todo
        printf("To na kamien milowy 2");
        break;

    case 3:
        //todo
        printf("To na kamien milowy 2");
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
    zapispliku();
    exit(0);
}

/*|||||||||||||||||||||||||||||||||||||||||||||||||||||*/
/*|||||||||||||||||||||||||||||||||||||||||||||||||||||*/
/*|||||||||||||||||||||||||||||||||||||||||||||||||||||*/
//klienci


int main() {
    
    menu();
}
