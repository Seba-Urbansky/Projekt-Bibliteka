#include <stdio.h>
#include <stdlib.h>

#define MAX 32

// to jest milestone1 wiec nie bedzie tu nic o ksiazkach i wypozyczeniach
// a jezeli bedzie to niedzialajace

// http://fizyka.umk.pl/~leii/wskaznikiStrukturyAiR.pdf

struct klient
{

    int numer_karty;
    char imie[MAX];
    char nazwisko[MAX];
    char telefon[MAX];
    char email[MAX];

    struct klient *poprzedni, *nastepny;

} baza;

struct klient *poczatek = NULL;
struct klient *koniec = NULL;

void wyswietl_baze_klientow();
void dodaj_klienta();
void edytuj_klienta();
void usun_klienta();
void menu();
void menu_klientow();
void wyjscie();
void wczytaniepliku();
void znajdz_klienta_do_zarzadzania();
void wydrukuj_klienta(struct klient* wpis);
void usunedytuj_klient(struct klient* wpis);

void wyswietl_baze_klientow()
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

    printf("Podaj numer karty: \n");
    scanf("%d", &wpis->numer_karty);
    printf("Podaj imie: \n");
    scanf("%s", &wpis->imie);
    printf("Podaj nazwisko: \n");
    scanf("%s", &wpis->nazwisko);
    printf("Podaj telefon: \n");
    scanf("%s", &wpis->telefon);
    printf("Podaj email: \n");
    scanf("%s", &wpis->email);

    koniec->nastepny = wpis;
    wpis->poprzedni = koniec;
    koniec = wpis;

    menu_klientow();
}


struct klient* wyszukaj_klienta() {
    int numer_karty;
    printf("Podaj numer karty klienta: \n");
    scanf("%d", &numer_karty);

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

void edytuj_imie_klienta(struct klient* wpis){}

void edytuj_nazwisko_klienta(struct klient* wpis){}

void usun_klienta(struct klient* wpis){}

void zarzadzaj_klientem() {
  struct klient* wpis = wyszukaj_klienta();
  usunedytuj_klient(wpis);
}

void usunedytuj_klient(struct klient* wpis) {
    int wybor;

    printf("Witamy w Zarzadzaniu Klientem");
    printf("\n\n");
   
    printf("1. Wydrukuj klienta");
    printf("\n");
    printf("2. Edytuj imie");
    printf("\n\n");
    printf("3. Edytuj nazwisko");
    printf("\n\n");
    printf("4. Usun klienta");
    printf("\n\n");

    scanf("%d", &wybor);
    printf("\n");

    switch (wybor) {
    case 1:
        wydrukuj_klienta(wpis);
        usunedytuj_klient(wpis);
        break;
    case 2:
        edytuj_imie_klienta(wpis);
        break;
    case 3:
        edytuj_nazwisko_klienta(wpis);
        break;
    case 4:
        usun_klienta(wpis);
        break;
    default:
        printf("Niepoprawna instrukcja");
        break;
    }
}

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
    printf("5. Wyjscie z programu");
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
    printf("4. Wyjscie z programu");
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

void wyjscie()
{
    printf("Zamykanie programu...");
    exit(0);
}

/*|||||||||||||||||||||||||||||||||||||||||||||||||||||*/
/*|||||||||||||||||||||||||||||||||||||||||||||||||||||*/
/*|||||||||||||||||||||||||||||||||||||||||||||||||||||*/
//klienci

void wczytaniepliku()
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

void zapispliku(struct klient *wezel) {
    FILE *plik;
    plik = fopen("klienci.csv", "r");

    while (!feof (plik))
    {
        struct klient *wpis = malloc(sizeof(baza));

        fprintf(plik, "%d", wpis->numer_karty);
        fprintf(plik, "%s", wpis->imie);
        fprintf(plik, "%s", wpis->nazwisko);
        fprintf(plik, "%s", wpis->telefon);
        fprintf(plik, "%s", wpis->email);

        wpis -> nastepny = NULL;
    }
}


int main()
{
    wczytaniepliku();
    printf("Poczatek: %s\n", poczatek->imie);
    printf("Nastepny: %s\n", poczatek->nastepny->imie);
    printf("Koniec: %s\n", koniec->imie);
    menu();
}
