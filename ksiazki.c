#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 32

// Dodawanie/usuwanie/edycja książek (ID, tytuł, rok, autor, gatunek, liczba egzemplarzy, liczba wypożyczonych).
// http://fizyka.umk.pl/~leii/wskaznikiStrukturyAiR.pdf

struct ksiazki
{

    int ID;
    int rok;
    int liczba_egzemplarzy;
    int liczba_wypozyczonych;
    char* tytul[MAX];
    char* autor[MAX];
    char* gatunek[MAX];
    

    struct ksiazki *poprzedni, *nastepny;

} baza;

struct ksiazki *poczatek = NULL;
struct ksiazki *koniec = NULL;

void wyswietl_baze_ksiazek();
void dodaj_ksiazke();
void edytuj_ksiazke();
void usun_ksiazke();
void menu();
void menu_klientow();
void wczytaniepliku();
void zapispliku();
void ksiazka_do_zarzadzania();
void wydrukuj_ksiazki(struct ksiazki* wpis);
void edytuj_tytul_ksiazki(struct ksiazki* wpis);
void edytuj_gatunek_ksiazki(struct ksiazki* wpis);
void usunedytuj_ksiazke(struct ksiazki* wpis);
void edytuj_autora(struct ksiazki* wpis);
void edytuj_rok(struct ksiazki* wpis);
void edytuj_ID(struct ksiazki* wpis);
void wyjscie();
void wyswietl_baze_ksiazek()
{
    printf ("BAZA KLIENTOW ------------------------\n");
    for (struct ksiazki *wpis = poczatek; NULL != wpis; wpis = wpis -> nastepny) {
        wydrukuj_ksiazki(wpis);
    }
    printf ("--------------------------------------\n\n");
    menu_klientow();
}

void dodaj_ksiazke()
{
    struct ksiazki *wpis = (struct ksiazki *)malloc(sizeof(baza));

    edytuj_ID(wpis);
    edytuj_tytul_ksiazki(wpis);
    edytuj_gatunek_ksiazki(wpis);
    edytuj_autora(wpis);
    edytuj_rok(wpis);

    koniec->nastepny = wpis;
    wpis->poprzedni = koniec;
    koniec = wpis;

    menu_klientow();
}


struct ksiazki* wyszukaj_klienta(int numer_karty) {
    for(struct ksiazki *wpis = poczatek; NULL != wpis; wpis = wpis -> nastepny) {
        if (wpis->numer_karty==numer_karty) {
            return wpis;
        } 
    }
    return NULL;
}

void wydrukuj_ksiazki(struct ksiazki* wpis) {
    printf ("%d ", wpis->numer_karty);
    printf ("%s ", wpis->tytul);
    printf ("%s ", wpis->autor);
    printf ("%s ", wpis->gatunek);
    printf ("%s ", wpis->email);
    printf ("\n");
}

void edytuj_tytul_ksiazki(struct ksiazki* wpis) {
    char imie[MAX] = "";
    printf("Podaj imie: \n");
    scanf("%s", &imie);
    if (imie == "") {
        printf("Niepoprawne imie, nie powinno byc puste.\n");
        edytuj_tytul_ksiazki(wpis);
    } else {
        strcpy(wpis->tytul, &imie);
    }
}

void edytuj_autora(struct ksiazki* wpis) {
    printf("Podaj telefon: \n");
    scanf("%s", &wpis->autor;
}

void edytuj_rok(struct ksiazki* wpis) {
    printf("Podaj email: \n");
    scanf("%s", &wpis->rok);
}

void edytuj_gatunek_ksiazki(struct ksiazki* wpis) {
    printf("Podaj nazwisko: \n");
    scanf("%s", &wpis->gatunek);
}

void edytuj_ID(struct ksiazki* wpis) {
    int ID;
    printf("Podaj numer karty klienta: \n");
    scanf("%d", &ID);
    struct ksiazki* wyszukany_klient = wyszukaj_klienta(ID);
    if (wyszukany_klient != NULL) {
        printf("Podany numer karty juz istnieje.\n");
        edytuj_ID(wpis);
    } else {
        wpis->numer_karty = ID;
    }
}


void usun_ksiazke(struct ksiazki* wpis) {
    struct ksiazki *poprzedni = wpis->poprzedni;
    struct ksiazki *nastepny = wpis->nastepny;
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
    struct ksiazki* wpis = wyszukaj_klienta(numer_karty);
    if (wpis == NULL) {
        printf("Nie znaleziono klienta \n");
        zarzadzaj_klientem();
    } else {
        usunedytuj_ksiazke(wpis);
    }
}

void usunedytuj_ksiazke(struct ksiazki* wpis) {
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

void menu_klientow()
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

void wczytaniepliku()
{
    FILE *plik;
    plik = fopen("ksiazki.csv", "r");

    struct ksiazki *wpis = (struct ksiazki *)malloc(sizeof(baza));
    struct ksiazki *poprzedni;
    while (!feof (plik))
    {
        wpis = malloc(sizeof(baza));
        fscanf(plik, "%d %s %s %s %s", &wpis->numer_karty, &wpis->tytul, &wpis->autor, &wpis->gatunek, &wpis->email);
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

void zapispliku() {
    FILE *plik = fopen("ksiazki.csv", "w");
    for(struct ksiazki *wpis = poczatek; NULL != wpis; wpis = wpis -> nastepny) {
        fprintf(plik, "%d %s %s %s %s\n", wpis->numer_karty, wpis->tytul, wpis->autor, wpis->gatunek, wpis->email);
    }
}

int main() {
    wczytaniepliku();
    menu();
}
