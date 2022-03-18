#include <stdio.h>
#include <stdlib.h>

void dodaj_klienta(FILE *plik){
    int k;

    printf("Nowy klient wpisz - numer karty, nazwisko, imie, telefon, E-mail) # konczy akcje\n");

while((k=getchar()) !='#') {
    fputc(k,plik);
}

}

void dodaj_ksiazke(FILE *plik2){
    int m;

    printf("Nowa ksiazka wpisz -ID, tytuł, rok, autor, gatunek, liczba egzemplarzy, liczba wypożyczonych, # konczy akcje\n" );

while((m=getchar()) !='#') {
    fputc(m,plik2);
}

}


int main() {

        FILE *plik;
        plik=fopen("/Users/sebastian/Desktop/biblioteka/klienci.txt", "w");  /* używam MAC OS wiec musialem uzyc takiej sciezki */

        FILE *plik2;
        plik=fopen("/Users/sebastian/Desktop/biblioteka/ksiazki.txt", "w");  /* używam MAC OS wiec musialem uzyc takiej sciezki */


    if(plik==NULL) {
        printf("Blad otwarcia pliku\n");
        return 0;
    }
    dodaj_klienta(plik);
    dodaj_ksiazke(plik2);
    fclose(plik);
    fclose(plik2);

    return 0;
}
