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

void wyswietl_baze_klientow()
{
    struct klient *wpis = poczatek;
    printf ("BAZA KLIENTOW ------------------------\n");
    for (; NULL != wpis ; wpis = wpis -> nastepny) {
        printf ("%d ", wpis->numer_karty);
        printf ("%s ", wpis->imie);
        printf ("%s ", wpis->nazwisko);
        printf ("%s ", wpis->telefon);
        printf ("%s ", wpis->email);
        printf ("\n");
    }
    printf ("--------------------------------------\n\n");
    menu_klientow();
}

void dodaj_klienta()
{

    struct klient *wpis = (struct klient *)malloc(sizeof(baza));


    printf("Podaj numer karty: \n");
    scanf("%s",&wpis->numer_karty);

    printf("Podaj imie: \n");
    scanf("%s",&wpis->imie);

    printf("Podaj nazwisko: \n");
    scanf("%s",&wpis->nazwisko);

    printf("Podaj telefon: \n");
    scanf("%s",&wpis->telefon);

    printf("Podaj email: \n");
    scanf("%s",&wpis->email);

    koniec->nastepny = wpis;
    wpis->poprzedni = koniec;
    koniec = wpis;

    printf("Koniec: %s\n", koniec->imie);

    menu_klientow();
}


id_klienta(){
    int id;

printf("Podaj id klienta");
scanf("%d", id);


return id;
}

wydrukuj_klienta(){}
usuw_edytowanie_klienta(){}
void znajdz_klienta_do_zarzadzania() {
   // wyszukaj klienta
  Id = wyszukaj_klienta()
  usunedytuj_klient(id)
}

void usunedytuj_klient()
{
    int wybor;

    printf("Witamy w Edycji");
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

    switch (wybor)
    {
 


    case 1:
        wydrukuj_klienta();
        break;

    case 2:
       usuw_edytowanie_klienta();
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
    printf("3. Edytuj klienta");
    printf("\n");
    printf("4. Usun klienta");
    printf("\n");
    printf("5. Powrot do menu");
    printf("\n");
    printf("6. Wyjscie z programu");
    printf("\n\n");

    scanf("%d", &wybor);
    printf("\n");

    switch (wybor)
    {
    case 1:
        wyswietl_baze_klientow();
        break;

    case 2:
        dodaj_klienta();
        break;

    case 3:
        edytuj_klienta();
        break;

    case 4:
        usun_klienta();

        break;

    case 5:
        menu();
        break;

    case 6:
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

void zapispliku(struct klient *wezel)
{
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
