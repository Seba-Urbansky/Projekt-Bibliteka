

#ifndef KLIENCI_H
#define KLIENCI_H


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

#endif