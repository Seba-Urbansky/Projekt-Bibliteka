//header


#ifndef HEADER_H
#define HEADER_H


#include <stdio.h>
#include <stdlib.h>

struct klient
{

    int numer_karty;
    char* imie[MAX];
    char* nazwisko[MAX];
    char* telefon[MAX];
    char* email[MAX];

    struct klient *poprzedni, *nastepny;

} baza;

struct wypozyczenia
{

    int numer_karty;
    int ID;ś
    char* kiedy[MAX];
    char* dokiedy[MAX];
    

    struct wypozyczenia *poprzedni, *nastepny;

} baza;

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

// funkcje klientow
void wyswietl_baze_klientow();
void dodaj_klienta();
void edytuj_klienta();
void usun_klienta();
void menu();
void menu_klientow();
void wczytaniepliku();
void zapispliku();
void znajdz_klienta_do_zarzadzania();
void wydrukuj_klienta(struct klient* wpis);
void edytuj_imie_klienta(struct klient* wpis);
void edytuj_nazwisko_klienta(struct klient* wpis);
void usunedytuj_klient(struct klient* wpis);
void edytuj_telefon_klienta(struct klient* wpis);
void edytuj_email_klienta(struct klient* wpis);
void edytuj_numeru_karty(struct klient* wpis);
void wyjscie();
void wyswietl_baze_klientow()

//funkcje ksiazek

void wyswietl_baze_ksiazek();
void dodaj_ksiazke();
void edytuj_ksiazke();
void usun_ksiazke();
void menu();
void menu_ksiazek();
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

// funkcje wypozyczen



void wyswietl_kto_wypozyczyl();
void ID_ksiazki();
void kiedy();
void do_kiedy();
void wydrukuj_wypozyczenia();





#endif