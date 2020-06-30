#include "maladie.h"

L_Maladies* creer_liste_Maladies(void)
{
    L_Maladies* l = malloc(sizeof(L_Maladies));
    if(l == NULL)
        exit(-1);
    l->Head = NULL;
    return l;
}
Maladie*  creer_Maladie(void)
{
    Maladie *m = malloc(sizeof(Maladie));
    if(m == NULL)
        exit(-1);
    m->suivante = NULL;

    return m;
}
void Ajouter_Maladie(L_Maladies* l, char *Nom)
{
    Maladie *m = creer_Maladie();
    strcpy(m->Nom,Nom);
    if(l == NULL)
        exit(-1);
    if(l->Head == NULL)
        l->Head = m;
    else
    {
        m->suivante = l->Head;
        l->Head    = m;
    }
}

void afficher_maladie(L_Maladies* L)
{
    int i = 1;
    Maladie * par = L->Head;
    if(par != NULL)
        {gotoxy(positionH+50,positionV-2);Color(titles1_color,0);printf("Maladies");}
    while(par != NULL)
    {
        gotoxy(positionH+45,positionV+i);Color(printing_color,0);printf("%s",par->Nom);
        i+=2;
        par = par->suivante;
    }
}
