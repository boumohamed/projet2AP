#include "Quarantaine.h"
#include "Hotels.h"


int MenuQ(void)
{
    int choix,j;
    char c;
    clrscr();
    Color(writting_color,4);gotoxy(PositionMenuPrincipalH+20,PositionMenuPrincipalV-6);printf("GPC-19");
    Color(writting_color,8);gotoxy(PositionMenuPrincipalH+15,PositionMenuPrincipalV-3);printf("Gestion De Quarantaine");
    Color(writting_color,3);gotoxy(1,1);printf("Mohamed Bouzri, EMSI 2020");
    /** _______  Haut **/
    for(j = 1 ; j<50; j++)
    {
        gotoxy(PositionMenuPrincipalH+j,PositionMenuPrincipalV);Color(FramColor,0);printf("%c",205);
    }
    /** extrimité haut à gouche  **/
    gotoxy(PositionMenuPrincipalH,PositionMenuPrincipalV);Color(FramColor,0);printf("%c",201);
    /** extrimité haut à droite  **/
    gotoxy(PositionMenuPrincipalH+50,PositionMenuPrincipalV);printf("%c",187);
    /** || à gouche **/
    for(j = 1 ; j<25; j++)
        {
           gotoxy(PositionMenuPrincipalH+50,PositionMenuPrincipalV+j);Color(FramColor,0);printf("%c",186);
        }
    /** exri  basse à droite **/
    gotoxy(PositionMenuPrincipalH+50, PositionMenuPrincipalV+25);printf("%c",188);
    /** || à gouche **/
    for(j = 1 ; j<25; j++)
        {
           gotoxy(PositionMenuPrincipalH,PositionMenuPrincipalV+j);Color(FramColor,0);printf("%c",186);
        }
    /** extrimité basse gouche **/
        gotoxy(PositionMenuPrincipalH, PositionMenuPrincipalV+25);printf("%c",200);

    /** __________ bas**/
        for(j = 1; j<50; j++)
        {
           gotoxy(PositionMenuPrincipalH+j, PositionMenuPrincipalV+25);Color(FramColor,0);printf("%c",205);
        }
    Color(writting_color,5);gotoxy(PositionMenuPrincipalH+10,PositionMenuPrincipalV+3);printf("(1) Ajouter Un Hotel");
    gotoxy(PositionMenuPrincipalH+10,PositionMenuPrincipalV+5);printf("(2) Afficher Les Hotel");
    gotoxy(PositionMenuPrincipalH+10,PositionMenuPrincipalV+7);printf("(3) les personnes Au Quarantaine");
    gotoxy(PositionMenuPrincipalH+10,PositionMenuPrincipalV+9);printf("(4) ajouter une personne");
    gotoxy(PositionMenuPrincipalH+10,PositionMenuPrincipalV+11);printf("(5) contacts d'un patient");
    gotoxy(PositionMenuPrincipalH+10,PositionMenuPrincipalV+13);printf("(6) supprimer une personne");
    gotoxy(PositionMenuPrincipalH+10,PositionMenuPrincipalV+15);printf("(7) modifier une personne");
    gotoxy(PositionMenuPrincipalH+10,PositionMenuPrincipalV+17);printf("(8) modifier un Hotel");
    gotoxy(PositionMenuPrincipalH+10,PositionMenuPrincipalV+19);Color(writting_color,4);printf("(0) Retour");
    Color(printing_color,0);gotoxy(PositionMenuPrincipalH+10,PositionMenuPrincipalV+21);printf("choix : ");
    Color(writting_color,0);
    do{
            gotoxy(PositionMenuPrincipalH+18,PositionMenuPrincipalV+21);printf("                          ");
            gotoxy(PositionMenuPrincipalH+19,PositionMenuPrincipalV+21);
    }while(((scanf("%d%c", &choix, &c)!=2 || c!='\n') && clean_stdin()) || choix < 0 || choix > 8 );
    return choix;
}


int MenuRecherche()
{
    int choix,j;
    char c;
    clrscr();
    Color(writting_color,4);gotoxy(PositionMenuPrincipalH+20,PositionMenuPrincipalV-6);printf("GPC-19");
    /** _______  Haut **/
    for(j = 1 ; j<50; j++)
    {
        gotoxy(PositionMenuPrincipalH+j,PositionMenuPrincipalV);Color(FramColor,0);printf("%c",205);
    }
    /** extrimité haut à gouche  **/
    gotoxy(PositionMenuPrincipalH,PositionMenuPrincipalV);Color(FramColor,0);printf("%c",201);
    /** extrimité haut à droite  **/
    gotoxy(PositionMenuPrincipalH+50,PositionMenuPrincipalV);printf("%c",187);
    /** || à gouche **/
    for(j = 1 ; j<20; j++)
        {
           gotoxy(PositionMenuPrincipalH+50,PositionMenuPrincipalV+j);Color(FramColor,0);printf("%c",186);
        }
    /** exri  basse à droite **/
    gotoxy(PositionMenuPrincipalH+50, PositionMenuPrincipalV+20);printf("%c",188);
    /** || à gouche **/
    for(j = 1 ; j<20; j++)
        {
           gotoxy(PositionMenuPrincipalH,PositionMenuPrincipalV+j);Color(FramColor,0);printf("%c",186);
        }
    /** extrimité basse gouche **/
        gotoxy(PositionMenuPrincipalH, PositionMenuPrincipalV+20);printf("%c",200);

    /** __________ bas**/
        for(j = 1; j<50; j++)
        {
           gotoxy(PositionMenuPrincipalH+j, PositionMenuPrincipalV+20);Color(FramColor,0);printf("%c",205);
        }
    Color(writting_color,5);gotoxy(PositionMenuPrincipalH+10,PositionMenuPrincipalV+3);printf("(1) Age");
    gotoxy(PositionMenuPrincipalH+10,PositionMenuPrincipalV+5);printf("(2) Prenom");
    gotoxy(PositionMenuPrincipalH+10,PositionMenuPrincipalV+7);printf("(3) etat");
    gotoxy(PositionMenuPrincipalH+10,PositionMenuPrincipalV+9);printf("(4) genre");
    gotoxy(PositionMenuPrincipalH+10,PositionMenuPrincipalV+11);printf("(5) age & genre");
    gotoxy(PositionMenuPrincipalH+10,PositionMenuPrincipalV+13);printf("(6) etat & genre");
    gotoxy(PositionMenuPrincipalH+10,PositionMenuPrincipalV+15);Color(writting_color,4);printf("(0) Retour");
    Color(printing_color,0);gotoxy(PositionMenuPrincipalH+10,PositionMenuPrincipalV+17);printf("choix : ");
    Color(writting_color,0);
    do{
            gotoxy(PositionMenuPrincipalH+18,PositionMenuPrincipalV+17);printf("                          ");
            gotoxy(PositionMenuPrincipalH+19,PositionMenuPrincipalV+17);
    }while(((scanf("%d%c", &choix, &c)!=2 || c!='\n') && clean_stdin()) || choix < 0 || choix > 6 );
    return choix;
}
HOTEL* Ajouter_a_Hotel(L_Hotel* l, Patient* P)
{
   HOTEL *par = l->Head;
   HOTEL *Find = NULL;

   while(par != NULL)
   {
       if((par->DATA.CodePostal == P->DATA.CodePostal) &&  !strcmp(par->DATA.boulvard,P->DATA.boulvard))
          {
              Find = par;
              break;
          }
          par = par->Hotel_suivant;
   }
   return Find;
}

int ajouter_listesC(HOTEL *H, L_Contacts* l)
{
    Contact *par = l->Head;
    if(H != NULL && l != NULL)
    while(par != NULL)
    {
        AjouterContactToHotel(H,par->DATA);
        par = par->suivant;
    }
}



HOTEL* choixDeHotel(L_Hotel* l, Patient* p)
{
    HOTEL* par = l->Head;
    HOTEL* Find = NULL;
    char c;
    while(par != NULL)
    {
        if(par->DATA.capacite >= p->DATA.NbreDeContacts && par->DATA.Disponibilte > 0)
        {
            fflush(stdin);
            Color(printing_color,0);printf("vouler vous Ajouter les Personnes en contacts a l'Hotel %s ? oui(O)/non(N) : ", par->DATA.Nom);
            Color(writting_color,0);scanf("%c",&c);
            if(c == 'o' || c == 'O')
            {
                Find = par;
                return Find;
            }
        }
        par = par->Hotel_suivant;
    }
    return Find;

}




void affecterLesContacts(L_Hotel* l, Patient* p)
{
    HOTEL* par = l->Head;
    HOTEL* Find;
    Contact* parC = p->Contacts->Head;
    while(parC != NULL)
    {
        Find = NULL;
        while(par != NULL)
        {
            Find = Recherche_ToAddHOTEL(l, parC->DATA.CodePostal, parC->DATA.boulvard);
            if(Find != NULL && Find->DATA.Disponibilte > 0) /*** Bien trouver L'hotel du region Du contact ****/
            {
                AjouterContactToHotel(Find, parC->DATA);
                Color(0,11);printf("\n%s %s ===> Hotel %s",parC->DATA.Nom,parC->DATA.Prenom,Find->DATA.Nom);
                break;
            }
            else /*** N'a pas touve Hotel & donne choix a l'utilisateur ****/
            {
                Color(titles1_color,0);printf("\n%s %s N'a pas trouver Un Hotel ou Hotel De Son Region Est Plein\n",parC->DATA.Nom,parC->DATA.Prenom);
                Find = choixDeHotel(l, p);
                if(Find != NULL)
                {
                    AjouterContactToHotel(Find, parC->DATA);
                    Color(0,11);printf("\n%s %s ===> Hotel %s",parC->DATA.Nom,parC->DATA.Prenom,Find->DATA.Nom);
                    break;
                }

            }
            par = par->Hotel_suivant;
        }
        parC = parC->suivant;
    }
}








void AjouterContactToHotel(HOTEL *H,Personne p)
{
    L_Contacts *par = H->Contacts;
    Contact *c = malloc(sizeof(Contact));
    if(c == NULL)
        exit(-1);
    c->DATA = p;
    if(par->Head == NULL)
    {
        par->Head = c;
        c->suivant = NULL;
    }
    else
    {
        c->suivant = par->Head;
        par->Head = c;
    }
    H->DATA.Disponibilte--;
}







void afficher_TContact(Personne p)
{
    Color(writting_color,1);
    printf("%10s\t%10s\t\t%5s\t%8s\t%d\t\t%s %s",p.Nom,p.Prenom,p.genre,p.etatV,p.Age,p.contaminateurN,p.contaminateurP);
}


void afficher_ToutPesonne(L_Contacts *l)
{
    Contact *par = l->Head;
    int i = 1;
    Color(writting_color,4);gotoxy(2,4);
    printf("    Nom\t  Prenom\t\tGenre\t   etat\t\tAge\t\tcontaminateur");
    while(par != NULL)
    {
        gotoxy(2,4+i);
        afficher_TContact(par->DATA);
        i++;
        par = par->suivant;
    }
}











Contact* rechercher_personne(L_Hotel *l, char *Nom, char *Prenom)
{
    HOTEL *par = l->Head;
    Contact *parC;
    Contact *Find = NULL;

    while(par != NULL)
    {
        parC = par->Contacts->Head;
        while(parC != NULL)
        {
            if(!strcmp(parC->DATA.Nom,Nom) && !strcmp(parC->DATA.Prenom,Prenom))
                {
                    Find = parC;
                    break;
                }
                parC = parC->suivant;
        }
        par = par->Hotel_suivant;
    }
    return Find;
}

HOTEL* rechercher_Hotel(L_Hotel *l, char *Nom, char *Prenom)
{
    HOTEL *par = l->Head;
    Contact *parC;
    HOTEL *Find = NULL;

    while(par != NULL)
    {
        parC = par->Contacts->Head;
        while(parC != NULL)
        {
            if(!strcmp(parC->DATA.Nom,Nom) && !strcmp(parC->DATA.Prenom,Prenom))
                {
                    Find = par;
                    break;
                }
                parC = parC->suivant;
        }
        par = par->Hotel_suivant;
    }
    return Find;
}
void modification_etatv(HOTEL *h, Contact *c)
{
    int choix;
        gotoxy(positionH,positionV);Color(printing_color,0);printf("etat De Patient Est : %s ",c->DATA.etatV);
        gotoxy(positionH,positionV+1); printf("%s(1) %s(2) : ",etatV[0], etatV[1]);
        Color(writting_color,0);scanf("%d",&choix);
        if(choix == 1 || choix == 2)
        {
            strcpy(c->DATA.etatV,etatV[choix-1]);
            Color(titles1_color,0);printf("\tModification avec succer !");
        }
}


void contactsUnPatient(L_Hotel *l, char *nom, char *prenom)
{
    HOTEL *par = l->Head;
    Contact *parC;
    int i = 1;
    Color(writting_color,4);gotoxy(2,4);
    printf("    Nom\t  Prenom\t\tGenre\t   etat\t\tAge\t\tcontaminateur");
    while(par != NULL)
    {
        parC = par->Contacts->Head;
        while(parC != NULL)
        {
            if(!strcmp(parC->DATA.contaminateurN,nom) && !strcmp(parC->DATA.contaminateurP,prenom))
            {
                gotoxy(2,4+i);
                afficher_TContact(parC->DATA);
                i++;
            }
            parC = parC->suivant;
        }
        par = par->Hotel_suivant;
    }
}
int supprimer_Personne(HOTEL *h, Contact *c)
{
    Contact *par = h->Contacts->Head;
    Contact *supprimer;
    int valider = 0;
    Date d = dateSys();
    while(par != NULL)
    {
        if(par->suivant == c)
        {
            if(c->DATA.DateFin.jj == d.jj && !strcmp(c->DATA.etatV,etatV[1]))
                {
                    supprimer = par->suivant;
                    par->suivant = supprimer->suivant;
                    h->DATA.Disponibilte++;
                    valider = 1;
                    break;
                }
        }
        par = par->suivant;
    }
    free(&supprimer->DATA);
    free(supprimer);
    return valider;
}
