#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 32

#include "klienci.h"
#include "wypozyczenia.h"
#include "ksiazki.h"
#include "common.h"
#include "menu.h"

// cale polecenie projektu
// Biblioteka. Dodawanie/usuwanie/edycja klientów (numer karty, nazwisko, imię, telefon, E-mail). Dodawanie/usuwanie/edycja książek (ID, tytuł, rok, autor, gatunek, liczba egzemplarzy, liczba wypożyczonych). 
//Wypożyczanie/oddawanie książek (kto wypożyczył (numer karty), którą książkę (ID), kiedy, do kiedy). Wyświetlanie książek z możliwością sortowania niemalejącego/nierosnącego po dowolnym polu.
// Wyszukiwanie książek. Przypominanie o zaległych zwrotach z automatycznym naliczaniem kar umownych. Zapisywanie/wczytywanie danych o klientach, książkach i wypożyczeniach do/z plików. Wykorzystanie list.



int main() {
    
    menu();
}
