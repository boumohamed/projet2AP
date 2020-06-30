#ifndef HOTELS_H_INCLUDED
#define HOTELS_H_INCLUDED

typedef struct
{
    char Nom[20],boulvard[20], Quartier[20];
    int capacite,CodePostal,Disponibilte;
}hotel;

hotel lesHotels[10]; /******** les Premiers Hotels  *******/

typedef struct
{
    hotel DATA;
    L_Contacts *Contacts;
    struct Hotel *Hotel_suivant;
}HOTEL;

typedef struct
{
    HOTEL* Head;
}L_Hotel;


int ajouter_Hotel(L_Hotel* , hotel );
hotel creer_hotel(void);
HOTEL* creer_HOTEL(void);
void inithotels();
void afficher_Hotel(hotel );
void initialiser_Hotels(L_Hotel* );
void afficher_listeHotels(L_Hotel* );
void Modification_Hotel(HOTEL *);
HOTEL* Recherche_ToAddHOTEL(L_Hotel* , int , char *);
HOTEL* Recherche_HotelByName(L_Hotel* , char *, int );
HOTEL* choixDeHotelpourUncontact(L_Hotel* );

#endif // HOTELS_H_INCLUDED
