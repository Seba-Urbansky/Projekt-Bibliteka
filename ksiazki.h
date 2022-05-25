

#ifndef KSIAZKI_H
#define KSIAZKI_H /*!< Deklaracja ksiazek  */

#include <stdio.h>
#include <stdlib.h>
#include "common.h"

/*! \fn Struktura uzywana do przechowywania danych ksiazek */
typedef struct KsiazkaStruktura 
{

    int ID;
    int rok;
    char *tytul[MAX];
    char *autor[MAX];
    char *gatunek[MAX];
    int liczba_egzemplarzy;
    int liczba_wypozyczonych;
    

    struct KsiazkaStruktura *poprzedni, *nastepny;

} Ksiazka;

/*! \fn Funkcje ksiazki
     \brief 
     Ponizej sa deklaracje funkcji dotyczace ksiazek
   
*/


void wyswietl_baze_ksiazek();
void dodaj_ksiazke();
void edytuj_ksiazke();
void usun_ksiazke();
void menu_ksiazek();
void wczytaniepliku_ksiazki();
void zapispliku_ksiazki();
void ksiazka_do_zarzadzania();
void wydrukuj_ksiazke(Ksiazka *wpis);
void edytuj_tytul_ksiazki(Ksiazka *wpis);
void edytuj_gatunek_ksiazki(Ksiazka *wpis);
void edytuj_autora(Ksiazka *wpis);
void edytuj_rok(Ksiazka *wpis);
void wyswietl_baze_ksiazek();
Ksiazka *wyszukaj_ksiazke(int ID);
int znajdz_najwyzsze_ID_ksiazki();
void edytuj_ksiazki_ID_ksiazki(Ksiazka *wpis);
void sortowanie_ksiazek_niemalejace(Ksiazka *ID);
void wyszukaj_ksiazki_po_tytule();
void wyszukaj_ksiazki_po_autorze();
void wyszukaj_ksiazki_po_roku();
Ksiazka* zamien(Ksiazka* a, Ksiazka* b);
int policz_ksiazki();
enum SortowanieKolejnosc {Rosnaca = 1, Malejaca = 0}; 
enum SortowanieAtrybut {Tytul = 0, Autor = 1, Rok = 2, Gatunek = 3, ID = 4, LiczbaEgzemplarzy = 5, LiczbaWypozyczonych = 6 };
void sortowanie(enum SortowanieKolejnosc kolejnosc, enum SortowanieAtrybut atrybut);
void edytuj_liczbe_egzemplarzy(Ksiazka *wpis);
void edytuj_liczbe_wypozyczonych(Ksiazka *wpis);
void wyszukaj_ksiazki_po_gatunku();
void wyszukaj_po_liczbie_wypozyczonych();
void wyszukaj_po_liczbie_egzemplarzy();
void wydrukuj_po_ID();


#endif
