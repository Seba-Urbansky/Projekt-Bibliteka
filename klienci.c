#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 32
#include "klienci.h"

// http://fizyka.umk.pl/~leii/wskaznikiStrukturyAiR.pdf



struct klient *poczatek = NULL;
struct klient *koniec = NULL;


{
    printf ("BAZA KLIENTOW ------------------------\n");
    for (struct klient *wpis = poczatek; NULL != wpis; wpis = wpis -> nastepny) {
        wydrukuj_klienta(wpis);
    }
    printf ("--------------------------------------\n\n");
    menu_klientow();
}

void dodaj_klienta()
{
    struct klient *wpis = (struct klient *)malloc(sizeof(baza));

    edytuj_numeru_karty(wpis);
    edytuj_imie_klienta(wpis);
    edytuj_nazwisko_klienta(wpis);
    edytuj_telefon_klienta(wpis);
    edytuj_email_klienta(wpis);

    koniec->nastepny = wpis;
    wpis->poprzedni = koniec;
    koniec = wpis;

    menu_klientow();
}


struct klient* wyszukaj_klienta(int numer_karty) {
    for(struct klient *wpis = poczatek; NULL != wpis; wpis = wpis -> nastepny) {
        if (wpis->numer_karty==numer_karty) {
            return wpis;
        } 
    }
    return NULL;
}

void wydrukuj_klienta(struct klient* wpis) {
    printf ("%d ", wpis->numer_karty);
    printf ("%s ", wpis->imie);
    printf ("%s ", wpis->nazwisko);
    printf ("%s ", wpis->telefon);
    printf ("%s ", wpis->email);
    printf ("\n");
}

void edytuj_imie_klienta(struct klient* wpis) {
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

void edytuj_telefon_klienta(struct klient* wpis) {
    printf("Podaj telefon: \n");
    scanf("%s", &wpis->telefon);
}

void edytuj_email_klienta(struct klient* wpis) {
    printf("Podaj email: \n");
    scanf("%s", &wpis->email);
}

void edytuj_nazwisko_klienta(struct klient* wpis) {
    printf("Podaj nazwisko: \n");
    scanf("%s", &wpis->nazwisko);
}

void edytuj_numeru_karty(struct klient* wpis) {
    int numer_karty;
    printf("Podaj numer karty klienta: \n");
    scanf("%d", &numer_karty);
    struct klient* wyszukany_klient = wyszukaj_klienta(numer_karty);
    if (wyszukany_klient != NULL) {
        printf("Podany numer karty juz istnieje.\n");
        edytuj_numeru_karty(wpis);
    } else {
        wpis->numer_karty = numer_karty;
    }
}


void usun_klienta(struct klient* wpis) {
    struct klient *poprzedni = wpis->poprzedni;
    struct klient *nastepny = wpis->nastepny;
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
    int numer_karty;
    printf("Podaj numer karty klienta: \n");
    scanf("%d", &numer_karty);
    struct klient* wpis = wyszukaj_klienta(numer_karty);
    if (wpis == NULL) {
        printf("Nie znaleziono klienta \n");
        zarzadzaj_klientem();
    } else {
        usunedytuj_klient(wpis);
    }
}

void usunedytuj_klient(struct klient* wpis) {
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



void wyjscie() {
    printf("Zamykanie programu...");
    zapispliku_klienci();
    exit(0);
}

/*|||||||||||||||||||||||||||||||||||||||||||||||||||||*/
/*|||||||||||||||||||||||||||||||||||||||||||||||||||||*/
/*|||||||||||||||||||||||||||||||||||||||||||||||||||||*/
//klienci

void wczytaniepliku_klienci()
{
    FILE *plik;
    plik = fopen("klienci.csv", "r");

    struct klient *wpis = (struct klient *)malloc(sizeof(baza));
    struct klient *poprzedni;
    while (!feof (plik))
    {
        wpis = malloc(sizeof(baza));
        fscanf(plik, "%d %s %s %s %s", &wpis->numer_karty, &wpis->imie, &wpis->nazwisko, &wpis->telefon, &wpis->email);
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

void zapispliku_klienci() {
    FILE *plik = fopen("klienci.csv", "w");
    for(struct klient *wpis = poczatek; NULL != wpis; wpis = wpis -> nastepny) {
        fprintf(plik, "%d %s %s %s %s\n", wpis->numer_karty, wpis->imie, wpis->nazwisko, wpis->telefon, wpis->email);
    }
}

int main() {
    wczytaniepliku_klienci();
    menu();
}
