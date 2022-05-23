



#ifndef MENU_H
#define MENU_H
#define MAX 32

#include <stdio.h>
#include <stdlib.h>
#include "klienci.h"
#include "wypozyczenia.h"
#include "ksiazki.h"
#include "common.h"

/*! \fn Funkcje menu
     \brief 
     Ponizej sa deklaracje funkcji dotyczace menu
   
*/

void menu();
void menu_klientow();
void menu_glowne();
void menu_ksiazek();
void menu_wypozyczen();
void menu_klienta(Klient* klient);
void menu_zarzadzaj_klientem();
void menu_ksiazki(Ksiazka* ksiazka);
void menu_ksiazek_sortowania();
void menu_ksiazek_wyszukiwania();
void menu_zarzadzaj_ksiazkami();

void wyjscie();





#endif