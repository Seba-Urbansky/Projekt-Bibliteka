#include <stdio.h>
#include <stdlib.h>

#define MAX 32

// to jest milestone1 wiec nie bedzie tu nic o ksiazkach i wypozyczeniach
// a jezeli bedzie to niedzialajace

// http://fizyka.umk.pl/~leii/wskaznikiStrukturyAiR.pdf

struct klient{

    int numer_karty;
    char imie[MAX];
    char nazwisko[MAX];
    char telefon[MAX];
    char email[MAX];

    struct klient *poprzedni, *nastepny;

}baza;

struct klient *wpis;
struct klient *poczatek = NULL;
struct klient *koniec = NULL;

void menu_klientow() {
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

switch (wybor) {
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

void menu() {
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

switch (wybor) {
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
exit(0);
}

/*|||||||||||||||||||||||||||||||||||||||||||||||||||||*/
/*|||||||||||||||||||||||||||||||||||||||||||||||||||||*/
/*|||||||||||||||||||||||||||||||||||||||||||||||||||||*/
//klienci

void wyswietl_baze_klientow() {

FILE *plik;
plik = fopen("klienci.txt", "r");
//puts(sizeof(klient));
if (!plik) {

while (!feof (plik)) {
wpis = malloc(sizeof(baza));

fscanf(plik, "%d", wpis->numer_karty);
fscanf(plik, "%s", wpis->imie);
fscanf(plik, "%s", wpis->nazwisko);
fscanf(plik, "%s", wpis->telefon);
fscanf(plik, "%s", wpis->email);

wpis -> nastepny = NULL;
}
}

fclose(plik);
menu_klientow();
}


void dodaj_klienta() {

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

}
void edytuj_klienta() {;}
void usun_klienta() {;}


int main() {
menu();
}
