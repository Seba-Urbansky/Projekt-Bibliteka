#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 32
#include "klienci.h"
#include "common.h"

// http://fizyka.umk.pl/~leii/wskaznikiStrukturyAiR.pdf



 Klient *pierwszy_klient = NULL;
 Klient *ostatni_klient = NULL;

void wyswietl_baze_klientow()
{
    printf ("BAZA KLIENTOW ------------------------\n");
    for (Klient *wpis = pierwszy_klient; NULL != wpis; wpis = wpis -> nastepny) {
        wydrukuj_klienta(wpis);
    }
    printf ("--------------------------------------\n\n");
    
}

void dodaj_klienta()
{
    Klient *wpis = (Klient *)malloc(sizeof(Klient));

    edytuj_numeru_karty(wpis);
    edytuj_imie_klienta(wpis);
    edytuj_nazwisko_klienta(wpis);
    edytuj_telefon_klienta(wpis);
    edytuj_email_klienta(wpis);

    ostatni_klient->nastepny = wpis;
    wpis->poprzedni = ostatni_klient;
    ostatni_klient = wpis;

    
}


Klient* wyszukaj_klienta(int numer_karty) {
    for( Klient *wpis = pierwszy_klient; NULL != wpis; wpis = wpis -> nastepny) {
        if (wpis->numer_karty==numer_karty) {
            return wpis;
        } 
    }
    return NULL;
}

void wydrukuj_klienta(Klient* wpis) {
    printf ("%d ", wpis->numer_karty);
    printf ("%s ", wpis->imie);
    printf ("%s ", wpis->nazwisko);
    printf ("%s ", wpis->telefon);
    printf ("%s ", wpis->email);
    printf ("\n");
}

void edytuj_imie_klienta(Klient* wpis) {
    char imie[MAX] = "";
    printf("Podaj imie: \n");
    scanf("%s", &imie);
    if (imie == "") {
        printf("Niepoprawne imie, nie powinno byc puste.\n");
        edytuj_imie_klienta(wpis);
    } else {
        strcpy(wpis->imie, &imie);
    }
}

void edytuj_telefon_klienta(Klient* wpis) {
    printf("Podaj telefon: \n");
    scanf("%s", &wpis->telefon);
}

void edytuj_email_klienta(Klient* wpis) {
    printf("Podaj email: \n");
    scanf("%s", &wpis->email);
}

void edytuj_nazwisko_klienta(Klient* wpis) {
    printf("Podaj nazwisko: \n");
    scanf("%s", &wpis->nazwisko);
}

void edytuj_numeru_karty(Klient* wpis) {
    int numer_karty;
    printf("Podaj numer karty klienta: \n");
    scanf("%d", &numer_karty);
    Klient* wyszukany_klient = wyszukaj_klienta(numer_karty);
    if (wyszukany_klient != NULL) {
        printf("Podany numer karty juz istnieje.\n");
        edytuj_numeru_karty(wpis);
    } else {
        wpis->numer_karty = numer_karty;
    }
}


void usun_klienta(Klient* wpis) {
    Klient *poprzedni = wpis->poprzedni;
    Klient *nastepny = wpis->nastepny;
    if (poprzedni == NULL && nastepny == NULL) {
        pierwszy_klient = NULL;
        ostatni_klient = NULL;
    } else if (poprzedni == NULL && nastepny != NULL) {
        nastepny->poprzedni = NULL;
        pierwszy_klient = nastepny;
    } else if (nastepny == NULL && poprzedni != NULL) {
        poprzedni->nastepny = NULL;
        ostatni_klient = poprzedni;
    } else {
        poprzedni->nastepny = nastepny;
        nastepny->poprzedni = poprzedni;    
    }
}








/*|||||||||||||||||||||||||||||||||||||||||||||||||||||*/
/*|||||||||||||||||||||||||||||||||||||||||||||||||||||*/
/*|||||||||||||||||||||||||||||||||||||||||||||||||||||*/
//klienci

void wczytaniepliku_klienci()
{
    FILE *plik;
    plik = fopen("klienci.csv", "r");

     Klient *wpis = (Klient *)malloc(sizeof(Klient));
    Klient *poprzedni;
    while (!feof (plik))
    {
        wpis = malloc(sizeof(Klient));
        fscanf(plik, "%d %s %s %s %s", &wpis->numer_karty, &wpis->imie, &wpis->nazwisko, &wpis->telefon, &wpis->email);
        if (pierwszy_klient == NULL) {
            pierwszy_klient = wpis;
            poprzedni = wpis;
        } else if (wpis != NULL) {
            poprzedni->nastepny = wpis;
            wpis->poprzedni = poprzedni;
            poprzedni = wpis;
        }
    }
    if (wpis != NULL) {
        ostatni_klient = wpis;
    }
}

void zapispliku_klienci() {
    FILE *plik = fopen("klienci.csv", "w");
    for(Klient *wpis = pierwszy_klient; NULL != wpis; wpis = wpis -> nastepny) {
        fprintf(plik, "%d %s %s %s %s\n", wpis->numer_karty, wpis->imie, wpis->nazwisko, wpis->telefon, wpis->email);
    }
}


