#ifndef HOPITALS_H_INCLUDED
#define HOPITALS_H_INCLUDED

const char *typeRecherche[] = {"Nom", "Ville"};
const char *typeHopital[] = {"Clinique", "Hopital"};
const int PositionMenuPrincipalH = 50;
const int PositionMenuPrincipalV = 10;


typedef struct
{
    char nom[20], ville[20], adresse[20],qaurtier[20],type[10], boulvard[20];
    int CodePostal, nombreDeLits, nombreDeLitsRe, nbreDeSalleDialyse, nbreDeMedcins, nbreDeParamedicaux;

}hopital;

hopital Premiers_Hopitaux[10];
typedef struct
{
    hopital DATA;
    L_Patient *listPaient;
    struct HOPITAL * hopital_suivant;
}HOPITAL;
typedef struct
{
    HOPITAL * Head;

}L_Hopitals;
/************************************************************************************/
L_Hopitals* creer_LHopital(void);
hopital creer_hopital(void);
HOPITAL* creer_HOPITAL(void);

/************************************************************************************/
int Ajouter_Patient(HOPITAL* H,Patient *P);
HOPITAL* Recherche_ToAdd(L_Hopitals* H, int,  char*);
void Affectation_Patient(L_Hopitals* );
int modification_etat(HOPITAL*, Patient *);
void afficher_Hopital(hopital );
void afficher_listeHopitaux(L_Hopitals *L);
ajouter_Hopital(L_Hopitals* , hopital);
HOPITAL* rechercher_Hopital(L_Hopitals* L);
void Modification_Hopital(HOPITAL *);
HOPITAL* rechercher_Hopital(L_Hopitals* );
HOPITAL* Globale_Recherche_Patient(L_Hopitals* , char*, char*);
void GlobalRByGenreAge(L_Hopitals* l, int, char*);
void GlobalRByGenreEtat(L_Hopitals* l, char* , char* );
int MenuPrincipale(void);

/***********************************************************************************/

int Menu1(void);
int Menu2(void);
int MenuPatients(void);
/************************** initialisation des HOPITAUX  ***************************/
void init(void);




#endif // HOPITALS_H_INCLUDED
