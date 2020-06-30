#include "Patient.h"
#include "maladie.c"

Personne creer_Personne()
{
    Personne p;
    static int iD = 0;
    int choix,i;
    p.ID = ++iD;
    fflush(stdin);
    gotoxy(positionH+20,positionV);Color(titles1_color,0); printf("veuillez saisir les information du Patient");
    gotoxy(positionH,positionV+2);Color(printing_color,0);printf("Nom                            : ");
    Color(writting_color,0);gets(p.Nom);
    gotoxy(positionH,positionV+3);Color(printing_color,0);printf("Prenom                         : ");
    Color(writting_color,0);gets(p.Prenom);
    gotoxy(positionH,positionV+4);Color(printing_color,0);printf("Adresse                        : ");
    Color(writting_color,0);gets(p.adresse);
    gotoxy(positionH,positionV+5);Color(printing_color,0);printf("Boulvard                       : ");
    Color(writting_color,0);gets(p.boulvard);
    gotoxy(positionH,positionV+6);Color(printing_color,0);printf("Code Postal                    : ");
    Color(writting_color,0);scanf("%d",&p.CodePostal);
    gotoxy(positionH,positionV+7);Color(printing_color,0);printf("Genre Homme(1)/Femme(2)        : ");
    Color(writting_color,0);scanf("%d",&choix);
        if(choix == 1 || choix == 2)
            strcpy(p.genre,genre[choix-1]);
    gotoxy(positionH,positionV+8);Color(printing_color,0);printf("Age                            : ");
    Color(writting_color,0);scanf("%d",&p.Age);
    gotoxy(positionH,positionV+9);Color(printing_color,0);printf("etat Critique(1)/Normal(2)     : ");
    Color(writting_color,0);scanf("%d",&choix);
        if(choix == 1 || choix == 2)
            strcpy(p.etat,etat[choix-1]);
    gotoxy(positionH,positionV+10);Color(printing_color,0);printf("Contamination Vrai(1)/Faux(2)  : ");
    Color(writting_color,0);scanf("%d",&choix);
        if(choix == 1)
        {
            p.contamination_introduite = True;
            fflush(stdin);
            gotoxy(positionH,positionV+10);printf("                                   ");
            gotoxy(positionH,positionV+10);Color(printing_color,0);printf("Prevenance                     : ");
            Color(writting_color,0);gets(p.Prevenace);
        }
        else if(choix == 2)
            {
                p.contamination_introduite = False;
                strcpy(p.Prevenace, "Locale");
            }
        else
            strcpy(p.Prevenace, "N/A");
   gotoxy(positionH,positionV+11);Color(printing_color,0);printf("Nombre de Contacts             : ");
   Color(writting_color,0);scanf("%d",&p.NbreDeContacts);
   p.NbreDeMaladies = 0;
    return p;

}

Patient *creer_Patient()
{
    Patient *p = malloc(sizeof(Patient));
    int i,j=0;
    char c;
    p->DATA = creer_Personne();
    clrscr();

    p->Maladies = creer_liste_Maladies();
    for(i = 0; i<5; i++)
    {   clrscr();
        fflush(stdin);
        gotoxy(positionH,positionV);Color(titles2_color,0); printf("Ce patient a %s Oui(O)/Non(N)     : ",Maladies[i]);
        scanf("%c",&c);
        if(c == 'o' || c == 'O')
        {
            Ajouter_Maladie(p->Maladies, Maladies[i]);
            p->DATA.NbreDeMaladies++;
        }
    }

    clrscr();
    if(p->DATA.NbreDeContacts > 0)
            {
                gotoxy(positionH+20,positionV);Color(titles1_color,0); printf("veuillez saisir la liste des Contacts");
                p->Contacts = creer_liste_Contacts();
                for(i = 0; i < p->DATA.NbreDeContacts; i++)
                {
                    clrscr();
                    gotoxy(positionH+10,positionV);Color(titles2_color,0);printf("contacte %d",i+1);
                    Ajouter_Contacts(p->Contacts);

                }

            }
    p->patient_suivant = NULL;

    return p;
}


Personne creer_PersonneC(void)
{
    static int iD = 0;
    Personne p;
    int choix;
    p.ID = ++iD;
    fflush(stdin);
    gotoxy(positionH,positionV+2);Color(printing_color,0);printf("Nom                           : ");
    Color(writting_color,0);gets(p.Nom);
    gotoxy(positionH,positionV+3);Color(printing_color,0);printf("Prenom                        : ");
    Color(writting_color,0);gets(p.Prenom);
    gotoxy(positionH,positionV+4);Color(printing_color,0);printf("Adresse                       : ");
    Color(writting_color,0);gets(p.adresse);
    gotoxy(positionH,positionV+5);Color(printing_color,0);printf("Boulvard                      : ");
    Color(writting_color,0);gets(p.boulvard);
    gotoxy(positionH,positionV+6);Color(printing_color,0);printf("Code Postal                   : ");
    Color(writting_color,0);scanf("%d",&p.CodePostal);
    gotoxy(positionH,positionV+7);Color(printing_color,0);printf("Genre Homme(1)/Femme(2)       : ");
    Color(writting_color,0);scanf("%d",&choix);
        if(choix == 1 || choix == 2)
            strcpy(p.genre,genre[choix-1]);
    gotoxy(positionH,positionV+8);Color(printing_color,0);printf("Age                           : ");
    Color(writting_color,0);scanf("%d",&p.Age);

    gotoxy(positionH,positionV+9);Color(printing_color,0);printf("etat Positive(1)/Negative(2)  : ");
    Color(writting_color,0);scanf("%d",&choix);
    strcpy(p.etatV,etatV[choix-1]);
    p.NbreDeContacts = 0;
    p.NbreDeMaladies = 0;
    p.DateDebut = dateSys();
    p.DateFin = dateFin0(p.DateDebut);

    return p;
}
L_Patient* creer_liste_Patients(void)
{
    L_Patient *l = malloc(sizeof(L_Patient));
    if(l == NULL)
        exit(-1);
    l->Head = NULL;
    return l;
}
L_Contacts* creer_liste_Contacts(void)
{
    L_Contacts* l = malloc(sizeof(L_Contacts));
    if(l == NULL)
        exit(-1);
    l->Head = NULL;
    return l;
}
Contact*  creer_Contact(void)
{
    Contact *c = malloc(sizeof(Contact));
    if(c == NULL)
        exit(-1);
    c->DATA = creer_PersonneC();
    c->suivant = NULL;

    return c;
}



void Ajouter_Contacts(L_Contacts *l)
{
    Contact *c = creer_Contact();
    if(l == NULL)
        exit(-1);
    if(l->Head == NULL)
        l->Head = c;
    else
    {
        c->suivant = l->Head;
        l->Head    = c;
    }
}




Patient* Recherche_PatientN(L_Patient* l, char* Nom, char* Prenom)
{
    Patient *par = l->Head;
    Patient *Find = NULL;

    while(par != NULL)
    {
        if(!strcmp(par->DATA.Nom,Nom) && !strcmp(par->DATA.Prenom,Prenom))
        {
            Find =  par;
            break;
        }
            par = par->patient_suivant;
    }
    return Find;
}
void Recherche_PatientAG(L_Patient* l, int age, char* Genre)
{
    Patient *par = l->Head;
    int i = 1;
    gotoxy(2,4);Color(writting_color,4);printf("Nom\t\tPrenom\t\tGenre\t etat\t\tAge\tContacts\tMaladies");
    while(par != NULL)
    {
        if(par->DATA.Age >= age && !strcmp(par->DATA.genre,Genre))
        {
            gotoxy(2,4+i);
            afficher_TPatients(par->DATA);
            ++i;
        }
            par = par->patient_suivant;
    }
}

void Recherche_PatientEG(L_Patient* l, char* Etat, char* Genre)
{
    Patient *par = l->Head;
    int i = 1;
    gotoxy(2,4);Color(writting_color,4);printf("Nom\t\tPrenom\t\tGenre\t etat\t\tAge\tContacts\tMaladies");
    while(par != NULL)
    {
        if(!strcmp(par->DATA.etat,Etat) && !strcmp(par->DATA.genre,Genre))
        {
            gotoxy(2,4+i);
            afficher_TPatients(par->DATA);
            ++i;
        }
            par = par->patient_suivant;
    }
}

void supprimer_Patient(L_Patient* l, Patient *p)
{
    Patient *par = l->Head;
    Patient *supprimer = NULL;
    Contact *parC;
    Contact *supC;
    Maladie *parM;
    Maladie *supM;
    if(par == p)
    {
        supprimer = l->Head;
        l->Head = supprimer->patient_suivant;
    }
    else
        while(par != NULL)
                {
                    if(par->patient_suivant == p)
                    {
                        supprimer = par->patient_suivant;
                        par->patient_suivant = supprimer->patient_suivant;
                        break;
                    }
                    par = par->patient_suivant;
                }

    free(&supprimer->DATA);
    parC = supprimer->Contacts->Head;
    while(parC != NULL)
    {
        supC = parC;
        parC = parC->suivant;
        free(&supC->DATA);
        free(supC);
    }
    parM = supprimer->Maladies->Head;
    while(parM != NULL)
    {
        supM = parM;
        parM = parM->suivante;
        free(&supM->Nom);
        free(supM);
    }

    free(supprimer);

}
void Color(int couleurDuTexte,int couleurDeFond)
{
        HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}
void afficher_patient(Personne p)
{
    gotoxy(positionH,positionV+1);Color(printing_color,0);printf("Matricule                  : ");
    Color(writting_color,0);printf("%05d",p.ID);
    gotoxy(positionH,positionV+2);Color(printing_color,0);printf("Nom                        : ");
    Color(writting_color,0);printf("%s",p.Nom);
    gotoxy(positionH,positionV+3);Color(printing_color,0);printf("Prenom                     : ");
    Color(writting_color,0);printf("%s",p.Prenom);
    gotoxy(positionH,positionV+4);Color(printing_color,0);printf("Adresse                    : ");
    Color(writting_color,0);printf("%s",p.adresse);
    gotoxy(positionH,positionV+5);Color(printing_color,0);printf("Boulvard                   : ");
    Color(writting_color,0);printf("%s",p.boulvard);
    gotoxy(positionH,positionV+6);Color(printing_color,0);printf("Code Postal                : ");
    Color(writting_color,0);printf("%d",p.CodePostal);
    gotoxy(positionH,positionV+7);Color(printing_color,0);printf("Genre                      : ");
    Color(writting_color,0);printf("%s",p.genre);
    gotoxy(positionH,positionV+8);Color(printing_color,0);printf("age                        : ");
    Color(writting_color,0);printf("%d",p.Age);
    gotoxy(positionH,positionV+9);Color(printing_color,0);printf("etat                       : ");
    Color(writting_color,0);printf("%s",p.etat);
    gotoxy(positionH,positionV+10);Color(printing_color,0);printf("Nombre de Maladies         : ");
    Color(writting_color,0);printf("%d",p.NbreDeMaladies);
    gotoxy(positionH,positionV+11);Color(printing_color,0);printf("Nombre de Contacts         : ");
    Color(writting_color,0);printf("%d",p.NbreDeContacts);
    gotoxy(positionH,positionV+12);Color(printing_color,0);printf("Contamination              : ");
    Color(writting_color,0);printf("%s",p.Prevenace);
}
void afficher_ToutPatients(L_Patient *l)
{
    Patient *par = l->Head;
    int i = 1;
    Color(writting_color,4);gotoxy(2,4);
    printf("Nom\t\tPrenom\t\tGenre\t etat\t\tAge\tContacts\tMaladies");
    while(par != NULL)
    {
        gotoxy(2,4+i);
        afficher_TPatients(par->DATA);
        i++;
        par = par->patient_suivant;
    }
}
void afficher_TPatients(Personne p)
{
    Color(writting_color,1);
    printf("%s   \t%s\t\t%s\t %s\t%d\t %d\t\t  %d",p.Nom,p.Prenom,p.genre,p.etat,p.Age,p.NbreDeContacts,p.NbreDeMaladies);
}

void afficher_ToutContact(L_Contacts *l)
{
    Contact *par = l->Head;
    int i = 1,j ;
    if(par != NULL)
            {gotoxy(positionH+75,positionV-2);Color(titles1_color,0);printf("Contacts");}
    while(par != NULL)
        {
            afficher_personneContact(par,i);

            for(j = 0 ; j<40; j++)
            {
                gotoxy(positionH+70+j,positionV+i+7);Color(titles1_color,0);printf("%c",205);
            }
            i+=8;
            par = par->suivant;
        }
}


void afficher_personneContact(Contact *par, int i)
{
    gotoxy(positionH+70,positionV+i);Color(printing_color,0);printf("Nom              : ");
    Color(writting_color,0);printf("%s",par->DATA.Nom);
    gotoxy(positionH+70,positionV+i+1);Color(printing_color,0);printf("Prenom           : ");
    Color(writting_color,0);printf("%s",par->DATA.Prenom);
    gotoxy(positionH+70,positionV+i+2);Color(printing_color,0);printf("Genre            : ");
    Color(writting_color,0);printf("%s",par->DATA.genre);
    gotoxy(positionH+70,positionV+i+3);Color(printing_color,0);printf("age              : ");
    Color(writting_color,0);printf("%d",par->DATA.Age);
    gotoxy(positionH+70,positionV+i+4);Color(printing_color,0);printf("etat             : ");
    Color(writting_color,0);printf("%s",par->DATA.etatV);
    gotoxy(positionH+70,positionV+i+5);Color(printing_color,0);printf("date Debut       : ");
    Color(writting_color,0);printf("%02d/%02d/%d",par->DATA.DateDebut.jj,par->DATA.DateDebut.mm,par->DATA.DateDebut.aa);
    gotoxy(positionH+70,positionV+i+6);Color(printing_color,0);printf("date Fin         : ");
    Color(writting_color,0);printf("%02d/%02d/%d",par->DATA.DateFin.jj,par->DATA.DateFin.mm,par->DATA.DateFin.aa);
}

void Recherche_PatientA(L_Patient* l, int age)
{
    Patient *par = l->Head;
    int i = 1;
    gotoxy(2,4);Color(writting_color,4);printf("Nom\t\tPrenom\t\tGenre\t etat\t\tAge\tContacts\tMaladies");
    while(par != NULL)
    {
        if(par->DATA.Age >= age)
        {
            gotoxy(2,4+i);
            afficher_TPatients(par->DATA);
            ++i;
        }
        par = par->patient_suivant;
    }
}
void Recherche_PatientG(L_Patient* l, char* genre)
{
    Patient *par = l->Head;
    int i = 1;
    gotoxy(2,4);Color(writting_color,4);printf("Nom\t\tPrenom\t\tGenre\t etat\t\tAge\tContacts\tMaladies");
    while(par != NULL)
    {
        if(!strcmp(par->DATA.genre,genre))
        {
            gotoxy(2,4+i);
            afficher_TPatients(par->DATA);
            ++i;
        }
        par = par->patient_suivant;
    }
}
void Recherche_PatientE(L_Patient* l, char * E)
{
    Patient *par = l->Head;
    int i = 1;
    gotoxy(2,4);Color(writting_color,4);printf("Nom\t\tPrenom\t\tGenre\t etat\t\tAge\tContacts\tMaladies");
    while(par != NULL)
    {
        if(!strcmp(par->DATA.etat,E))
        {
            gotoxy(2,4+i);
            afficher_TPatients(par->DATA);
            ++i;
        }
        par = par->patient_suivant;
    }
}
void Recherche_PatientP(L_Patient* l, char *Prenom)
{
    Patient *par = l->Head;
    int i = 1;
    gotoxy(2,4);Color(writting_color,4);printf("Nom\t\tPrenom\t\tGenre\t etat\t\tAge\tContacts\tMaladies");
    while(par != NULL)
    {
        if(!strcmp(par->DATA.Prenom,Prenom))
        {
            gotoxy(2,4+i);
            afficher_TPatients(par->DATA);
            ++i;
        }
        par = par->patient_suivant;
    }
}
void affecterContaminateur(L_Contacts *l, char *nom, char *prenom)
{
    Contact* par = l->Head;
    while(par != NULL)
    {
        strcpy(par->DATA.contaminateurN,nom);
        strcpy(par->DATA.contaminateurP,prenom);
        par = par->suivant;
    }
}

Date dateSys()
{
    Date D;
    time_t t = time(NULL);
    struct tm temps = *localtime(&t);

    D.aa = temps.tm_year + 1900;
    D.mm = temps.tm_mon + 1;
    D.jj = temps.tm_mday;
    return D;
}


Date dateFin0(Date D)
{
    Date F;
    int rest;
    if(D.mm == 1 || D.mm == 3 || D.mm == 5 || D.mm == 7 || D.mm == 8 || D.mm == 10)
    {
        if(D.jj + 21 > 31)
        {
            F.jj = D.jj + 21;
            rest = F.jj - 31;
            F.jj = rest;
            F.mm = D.mm + 1;
            F.aa = D.aa;
        }
        else
            F.jj = D.jj+21;
    }

    else if(D.mm == 4 || D.mm == 6 || D.mm == 9 || D.mm == 11 )
    {
        if(D.jj + 21 > 30)
        {
            F.jj = D.jj + 21;
            rest = F.jj - 30;
            F.jj = rest;
            F.mm = D.mm + 1;
            F.aa = D.aa;
        }
        else
            F.jj = D.jj+21;
    }
    else if(D.mm == 12 )
    {
        if(D.jj + 21 > 31)
        {
            F.jj = D.jj + 21;
            rest = F.jj - 31;
            F.jj = rest;
            F.mm = 1;
            F.aa = D.aa + 1;
        }
        else
            F.jj = D.jj+21;
    }
     else if(D.mm == 2 )
    {
        if(D.jj + 21 > 28)
        {
            F.jj = D.jj + 21;
            rest = F.jj - 28;
            F.jj = rest;
            F.mm = D.mm + 1;
            F.aa = D.aa;
        }
        else
            F.jj = D.jj+21;
    }

    return F;
}
