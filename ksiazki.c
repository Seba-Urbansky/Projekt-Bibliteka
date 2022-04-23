#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 32
#include "ksiazki.h"
// Dodawanie/usuwanie/edycja książek (ID, tytuł, rok, autor, gatunek, liczba egzemplarzy, liczba wypożyczonych).
// http://fizyka.umk.pl/~leii/wskaznikiStrukturyAiR.pdf



Ksiazki *poczatek = NULL;
Ksiazki *koniec = NULL;

void wyswietl_baze_ksiazek()
{
    printf ("BAZA KSIAZEK ------------------------\n");
    for (struct Ksiazki *wpis = poczatek; NULL != wpis; wpis = wpis -> nastepny) {
        wydrukuj_ksiazki(wpis);
    }
    printf ("--------------------------------------\n\n");
    menu_ksiazek();
}

void dodaj_ksiazke()
{
    struct Ksiazki *wpis = (struct Ksiazki *)malloc(sizeof(Ksiazki));

    edytuj_ID(wpis);
    edytuj_tytul_ksiazki(wpis);
    edytuj_gatunek_ksiazki(wpis);
    edytuj_autora(wpis);
    edytuj_rok(wpis);

    koniec->nastepny = wpis;
    wpis->poprzedni = koniec;
    koniec = wpis;

    menu_ksiazek();
}


struct Ksiazki* wyszukaj_ksiazke(int ID) {
    for(struct Ksiazki *wpis = poczatek; NULL != wpis; wpis = wpis -> nastepny) {
        if (wpis->ID==ID) {
            return wpis;
        } 
    }
    return NULL;
}

void wydrukuj_ksiazki(struct Ksiazki* wpis) {
    printf ("%d ", wpis->ID);
    printf ("%s ", wpis->tytul);
    printf ("%s ", wpis->autor);
    printf ("%s ", wpis->gatunek);
    
    printf ("\n");
}

void edytuj_tytul_ksiazki(struct Ksiazki* wpis) {
    char imie[MAX] = "";
    printf("Podaj tytul: \n");
    scanf("%s", &imie);
    if (imie == "") {
        printf("Niepoprawne imie, nie powinno byc puste.\n");
        edytuj_tytul_ksiazki(wpis);
    } else {
        strcpy(wpis->tytul, &imie);
    }
}

void edytuj_autora(struct Ksiazki* wpis) {
    printf("Podaj nowego autora: \n");
    scanf("%s", &wpis->autor);
}

void edytuj_rok(struct Ksiazki* wpis) {
    printf("Podaj nowy rok: \n");
    scanf("%s", &wpis->rok);
}

void edytuj_gatunek_ksiazki(struct Ksiazki* wpis) {
    printf("Podaj nowy gatunek literacki: \n");
    scanf("%s", &wpis->gatunek);
}

void edytuj_ID(struct Ksiazki* wpis) {
    int ID;
    printf("Podaj ID ksiazki \n");
    scanf("%d", &ID);
    struct Ksiazki* wyszukany_klient = wyszukaj_ksiazke(ID);
    if (wyszukany_klient != NULL) {
        printf("Podany ID ksiazki juz istnieje.\n");
        edytuj_ID(wpis);
    } else {
        wpis->ID;
    }
}


void usun_ksiazke(struct Ksiazki* wpis) {
    struct Ksiazki *poprzedni = wpis->poprzedni;
    struct Ksiazki *nastepny = wpis->nastepny;
    if (poprzedni == NULL && nastepny == NULL) {
        poczatek = NULL;
        koniec = NULL;
    } else if (poprzedni == NULL && nastepny != NULL) {
        nastepny->poprzedni = NULL;
        poczatek = nastepny;
    } else if (nastepny == NULL && poprzedni != NULL) {
        poprzedni->nastepny = NULL;
        koniec = poprzedni;
    } else {
        poprzedni->nastepny = nastepny;
        nastepny->poprzedni = poprzedni;    
    }
}

void zarzadzaj_klientem() {
    int ID;
    printf("Podaj numer ID ksiazki: \n");
    scanf("%d", &ID);
    struct Ksiazki* wpis = wyszukaj_ksiazke(ID);
    if (wpis == NULL) {
        printf("Nie znaleziono ksiazki \n");
        zarzadzaj_klientem();
    } else {
        usunedytuj_ksiazke(wpis);
    }
}

void usunedytuj_ksiazke(struct Ksiazki* wpis) {
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




void wyjscie() {
    printf("Zamykanie programu...");
    zapispliku_ksiazki();
    exit(0);
}

/*|||||||||||||||||||||||||||||||||||||||||||||||||||||*/
/*|||||||||||||||||||||||||||||||||||||||||||||||||||||*/
/*|||||||||||||||||||||||||||||||||||||||||||||||||||||*/
//klienci

void wczytaniepliku_ksiazki()
{
    FILE *plik;
    plik = fopen("ksiazki.csv", "r");

    struct Ksiazki *wpis = (struct Ksiazki *)malloc(sizeof(Ksiazki));
    struct Ksiazki *poprzedni;
    while (!feof (plik))
    {
        wpis = malloc(sizeof(Ksiazki));
        fscanf(plik, "%d %s %s %s %s", &wpis->ID, &wpis->tytul, &wpis->autor, &wpis->gatunek);
        if (poczatek == NULL) {
            poczatek = wpis;
            poprzedni = wpis;
        } else if (wpis != NULL) {
            poprzedni->nastepny = wpis;
            wpis->poprzedni = poprzedni;
            poprzedni = wpis;
        }
    }
    if (wpis != NULL) {
        koniec = wpis;
    }
}

void zapispliku_ksiazki() {
    FILE *plik = fopen("ksiazki.csv", "w");
    for(struct Ksiazki *wpis = poczatek; NULL != wpis; wpis = wpis -> nastepny) {
        fprintf(plik, "%d %s %s %s %s\n", wpis->ID, wpis->tytul, wpis->autor, wpis->gatunek);
    }
}

int main() {
    wczytaniepliku_ksiazki();
    menu_ksiazek();
}
