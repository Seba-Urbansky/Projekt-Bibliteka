
#ifndef COMMON_H
#define COMMON_H /*!< Deklaracja common */
#define MAX 32  /*!< Deklaracja maksymalnej dlugosci tekstu  */

#include <stdio.h>
#include <stdlib.h>

#define GODZINA 3600 /*!< Deklaracja godziny w sekundach */
#define DZIEN 24 * GODZINA /*!< Deklaracja dnia w sekundach */
#define TYDZIEN 7 * DZIEN /*!< Deklaracja tygodnia w sekundach */

/*! \fn Funkcje  
     \brief 
     Tutaj sa funkcje uzywane w innych modulach
   
*/
 

int czy_plik_jest_pusty(FILE* plik);


#endif