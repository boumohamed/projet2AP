#ifndef PATIENT_H_INCLUDED
#define PATIENT_H_INCLUDED
#include <conio.h>
#include <windows.h>
#include <string.h>
#include <time.h>
#include "maladie.h"
#define Bool unsigned int
#define True 1
#define False 0

const int frame_color = 3;
const int positionV = 4;
const int positionH = 3;
const int position0 = 4;
const int printing_color = 3;
const int writting_color = 11;
const int titles1_color = 10;
const int titles2_color = 7;
const int FramColor = 14;
const char *etat[] = {"Critique", "Normale","gueri(e)"};
const char *etatV[] = {"Positive", "Negative"};
const char *genre[] = {"Homme", "Femme"};
const char *Maladies[] = {"diabete", "hypothyroidie", "hypertension" , "canser", "Obesite"};
const char * NomJourSemaine[] = {"Dimanche", "Lundi", "Mardi", "Mercredi", "Jeudi", "Vendredi", "Samedi"};
const char * NomMois[] = {"janvier", "fevrier", "mars", "avril", "mai", "juin", "juillet", "aout", "septembre", "octobre", "novembre", "decembre"};

typedef struct
{
    int jj, mm, aa;

}Date;

typedef struct
{
   char Nom[20],Prenom[20],adresse[20],genre[10],etat[20], Prevenace[20],etatV[20], boulvard[20],contaminateurN[20],contaminateurP[20];
   int ID, Age, NbreDeContacts, NbreDeMaladies,CodePostal;
   Date DateDebut, DateFin;
   Bool contamination_introduite;
}Personne;




typedef struct
{
    Personne DATA;
    struct Contact *suivant;

}Contact;

typedef struct
{
    Contact *Head;
}L_Contacts;

typedef struct
{
    Personne DATA;
    L_Maladies* Maladies;
    L_Contacts* Contacts;
    struct Patient *patient_suivant;

}Patient;

typedef struct
{
    Patient * Head;
}L_Patient;


/**********************************************************************/
Personne creer_Personne(void);
Personne creer_PersonneC(void);
Patient* creer_Patient(void);
Contact*  creer_Contact(void);

L_Patient* creer_liste_Patients(void);
L_Contacts* creer_liste_Contacts(void);


/**********************************************************************/
void afficher_patient(Personne );
void afficher_ToutPatients(L_Patient *l);
void afficher_TPatients(Personne );
void afficher_ToutContact(L_Contacts *l);
void Ajouter_Contacts(L_Contacts* );
Patient* Recherche_PatientN(L_Patient*, char*, char*);
void Recherche_PatientEG(L_Patient*, char*, char* );
void Recherche_PatientAG(L_Patient*, int, char* );
void Recherche_PatientA(L_Patient*, int);
void Recherche_PatientG(L_Patient*, char *);
void Recherche_PatientP(L_Patient*, char *);
void Recherche_PatientE(L_Patient*, char *);
void supprimer_Patient(L_Patient*, Patient *);
void afficher_personneContact(Contact *par, int i);
Date dateSys();
Date dateFin0(Date );
/***********************************************************************/
void Color(int, int);                      // https://www.vulgarisation-informatique.com/forum-7-2190-1--Couleurs-en-C.php

#endif // PATIENT_H_INCLUDED
