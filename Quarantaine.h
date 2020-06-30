#ifndef QUARANTAINE_H_INCLUDED
#define QUARANTAINE_H_INCLUDED
#include <string.h>
#include "Patient.h"
#include "hotels.c"
#define Bool unsigned int
#define True 1
#define False 0

const char*etatQ[] = {"Positif", "Negatif"};

/***********************************************************************************/
Date dateSys(void);
int ajouter_listesC(HOTEL*, L_Contacts*);
void AjouterContactToHotel(HOTEL *,Personne p);
HOTEL* Ajouter_a_Hotel(L_Hotel* , Patient*);
HOTEL* choixDeHotel(L_Hotel* l, Patient* p);
Contact* rechercher_personne(L_Hotel *l,char*, char*);
/**********************************************************************************/
int MenuQ(void);
int MenuRecherche(void);
#endif // QUARANTAINE_H_INCLUDED
