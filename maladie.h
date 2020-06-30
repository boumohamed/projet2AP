#ifndef MALADIE_H_INCLUDED
#define MALADIE_H_INCLUDED

typedef struct
{
   char Nom[20];
   struct Maladie *suivante;

}Maladie;

typedef struct
{
   Maladie *Head;
}L_Maladies;

L_Maladies* creer_liste_Maladies(void);
Maladie*  creer_Maladie(void);
void Ajouter_Maladie(L_Maladies*, char*);
void afficher_maladie(L_Maladies* );

#endif // MALADIE_H_INCLUDED
