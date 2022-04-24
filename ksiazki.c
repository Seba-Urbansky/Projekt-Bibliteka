#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ksiazki.h"
#include "common.h"
// Dodawanie/usuwanie/edycja książek (ID, tytuł, rok, autor, gatunek, liczba egzemplarzy, liczba wypożyczonych).
// http://fizyka.umk.pl/~leii/wskaznikiStrukturyAiR.pdf



Ksiazki *poczatek = NULL;
Ksiazki *koniec = NULL;

void wyswietl_baze_ksiazek()
{
    printf ("BAZA KSIAZEK ------------------------\n");
    for (Ksiazki *wpis = poczatek; NULL != wpis; wpis = wpis -> nastepny) {
        wydrukuj_ksiazke(wpis);
    }
    printf ("--------------------------------------\n\n");
   
}

void dodaj_ksiazke()
{
    Ksiazki *wpis = (Ksiazki *)malloc(sizeof(Ksiazki));

    edytuj_ID(wpis);
    edytuj_tytul_ksiazki(wpis);
    edytuj_gatunek_ksiazki(wpis);
    edytuj_autora(wpis);
    edytuj_rok(wpis);

    koniec->nastepny = wpis;
    wpis->poprzedni = koniec;
    koniec = wpis;

   
}


Ksiazki* wyszukaj_ksiazke(int ID) {
    for(Ksiazki *wpis = poczatek; NULL != wpis; wpis = wpis -> nastepny) {
        if (wpis->ID==ID) {
            return wpis;
        } 
    }
    return NULL;
}

void wydrukuj_ksiazke(Ksiazki* wpis) {
    printf ("%d ", wpis->ID);
    printf ("%s ", wpis->tytul);
    printf ("%s ", wpis->autor);
    printf ("%s ", wpis->gatunek);
    
    printf ("\n");
}

void edytuj_tytul_ksiazki(Ksiazki* wpis) {
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

void edytuj_autora(Ksiazki* wpis) {
    printf("Podaj nowego autora: \n");
    scanf("%s", &wpis->autor);
}

void edytuj_rok(Ksiazki* wpis) {
    printf("Podaj nowy rok: \n");
    scanf("%s", &wpis->rok);
}

void edytuj_gatunek_ksiazki(Ksiazki* wpis) {
    printf("Podaj nowy gatunek literacki: \n");
    scanf("%s", &wpis->gatunek);
}

void edytuj_ID(Ksiazki* wpis) {
    int ID;
    printf("Podaj ID ksiazki \n");
    scanf("%d", &ID);
     Ksiazki* wyszukany_klient = wyszukaj_ksiazke(ID);
    if (wyszukany_klient != NULL) {
        printf("Podany ID ksiazki juz istnieje.\n");
        edytuj_ID(wpis);
    } else {
        wpis->ID;
    }
}


void usun_ksiazke(Ksiazki* wpis) {
    Ksiazki *poprzedni = wpis->poprzedni;
    Ksiazki *nastepny = wpis->nastepny;
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







/*|||||||||||||||||||||||||||||||||||||||||||||||||||||*/
/*|||||||||||||||||||||||||||||||||||||||||||||||||||||*/
/*|||||||||||||||||||||||||||||||||||||||||||||||||||||*/
//klienci

void wczytaniepliku_ksiazki()
{
    FILE *plik;
    plik = fopen("ksiazki.csv", "r");

    Ksiazki *wpis = (Ksiazki *)malloc(sizeof(Ksiazki));
    Ksiazki *poprzedni;
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
    for(Ksiazki *wpis = poczatek; NULL != wpis; wpis = wpis -> nastepny) {
        fprintf(plik, "%d %s %s %s %s\n", wpis->ID, wpis->tytul, wpis->autor, wpis->gatunek);
    }
}


