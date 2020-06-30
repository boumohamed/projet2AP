#include "Hopitals.h"
#include "Patient.h"
L_Hopitals* creer_LHopital()
{
    L_Hopitals* h = malloc(sizeof(L_Hopitals));
    if(h == NULL)
        exit(-1);
    h->Head = NULL;
    return h;
}
hopital creer_hopital()
{
    hopital l;
    int choix;

    gotoxy(positionH+20,positionV);Color(titles1_color,0); printf("veuillez saisir les information de l'Hopital");
    gotoxy(positionH,positionV+2);Color(printing_color,0);printf("Type Clinique(1)/Hopital(2)   : ");
    Color(writting_color,0);scanf("%d",&choix);
        if(choix == 1 || choix == 2)
            strcpy(l.type,typeHopital[choix-1]);
    fflush(stdin);
    gotoxy(positionH,positionV+3);Color(printing_color,0);printf("Nom                           : ");
    Color(writting_color,0);gets(l.nom);
    gotoxy(positionH,positionV+4);Color(printing_color,0);printf("Ville                         : ");
    Color(writting_color,0);gets(l.ville);
    gotoxy(positionH,positionV+5);Color(printing_color,0);printf("Adresse                       : ");
    Color(writting_color,0);gets(l.adresse);
    gotoxy(positionH,positionV+6);Color(printing_color,0);printf("Quartier                      : ");
    Color(writting_color,0);gets(l.qaurtier);
    gotoxy(positionH,positionV+7);Color(printing_color,0);printf("boulvard                      : ");
    Color(writting_color,0);gets(l.boulvard);
    gotoxy(positionH,positionV+8);Color(printing_color,0);printf("Code Postal                   : ");
    Color(writting_color,0);scanf("%d",&l.CodePostal);
    gotoxy(positionH,positionV+9);Color(printing_color,0);printf("nombre de lits                : ");
    Color(writting_color,0);scanf("%d",&l.nombreDeLits);
    gotoxy(positionH,positionV+10);Color(printing_color,0);printf("nombre De medcines            : ");
    Color(writting_color,0);scanf("%d",&l.nbreDeMedcins);
    gotoxy(positionH,positionV+11);Color(printing_color,0);printf("nombre De Paramedicaux        : ");
    Color(writting_color,0);scanf("%d",&l.nbreDeParamedicaux);
    gotoxy(positionH,positionV+12);Color(printing_color,0);printf("nombre de salle de dialyse    : ");
    Color(writting_color,0);scanf("%d",&l.nbreDeSalleDialyse);
    gotoxy(positionH,positionV+13);Color(printing_color,0);printf("nombre de lits de reanimation : ");
    Color(writting_color,0);scanf("%d",&l.nombreDeLitsRe);


    return l;

}
HOPITAL* creer_HOPITAL()
{
        HOPITAL* L = malloc(sizeof(HOPITAL));
        if(L == NULL)
            exit(-1);

        L->hopital_suivant = NULL;
        return L;

}
void Modification_Hopital(HOPITAL *L)
{
    char c;
    fflush(stdin);
    Color(writting_color,12);gotoxy(PositionMenuPrincipalH+10,PositionMenuPrincipalV-6);printf("%s %s",L->DATA.type,L->DATA.nom);
    gotoxy(positionH,positionV+2);Color(printing_color,0);printf("vouler vous modifier nombre de lits ? oui(O)/non(N) : ");
    Color(writting_color,0);scanf("%c",&c);
    if(c == 'o' || c == 'O')
    {
        gotoxy(positionH,positionV+3);Color(printing_color,0);printf("Nombre de Lits actuel : ");
        Color(writting_color,0);printf("%d",L->DATA.nombreDeLits);
        gotoxy(positionH,positionV+4);Color(printing_color,0);printf("Nouveau Nombre de Lits : ");
        Color(writting_color,0);scanf("%d",&L->DATA.nombreDeLits);
    }
    fflush(stdin);
    gotoxy(positionH,positionV+5);Color(printing_color,0); printf("vouler vous modifier nombre de lits de Reanimation ? oui(O)/non(N) : ");
    Color(writting_color,0);scanf("%c",&c);
    if(c == 'o' || c == 'O')
    {
        gotoxy(positionH,positionV+6);Color(printing_color,0);printf("Nombre de Lits de Reanimation actuel : ");
        Color(writting_color,0);printf("%d",L->DATA.nombreDeLitsRe);
        gotoxy(positionH,positionV+7);Color(printing_color,0);printf("Nouveau Nombre de Lits de Reanimation : ");
        Color(writting_color,0);scanf("%d",&L->DATA.nombreDeLitsRe);
    }
    fflush(stdin);
    gotoxy(positionH,positionV+8);Color(printing_color,0);printf("vouler vous modifier nombre de Medcins ? oui(O)/non(N) : ");
    Color(writting_color,0);scanf("%c",&c);
    if(c == 'o' || c == 'O')
    {
        gotoxy(positionH,positionV+9);Color(printing_color,0);printf("Nombre de Medcins actuel : ");
        Color(writting_color,0);printf("%d",L->DATA.nbreDeMedcins);
        gotoxy(positionH,positionV+10);Color(printing_color,0);printf("Nouveau Nombre de Medcins : ");
        Color(writting_color,0);scanf("%d",&L->DATA.nombreDeLits);
    }
    fflush(stdin);
    gotoxy(positionH,positionV+11);Color(printing_color,0);printf("vouler vous modifier nombre de Paramedicaux ? oui(O)/non(N) : ");
    Color(writting_color,0);scanf("%c",&c);
    if(c == 'o'|| c == 'O')
    {
       gotoxy(positionH,positionV+12);Color(printing_color,0);printf("Nombre  de Paramedicaux actuel : ");
       Color(writting_color,0);printf("%d",L->DATA.nbreDeParamedicaux);
       gotoxy(positionH,positionV+13);Color(printing_color,0);printf("Nouveau Nombre  de Paramedicaux : ");
       Color(writting_color,0);scanf("%d",&L->DATA.nbreDeParamedicaux);
    }
    fflush(stdin);
    gotoxy(positionH,positionV+14);Color(printing_color,0);printf("vouler vous modifier nombre de Salles de dialyse ? oui(O)/non(N) : ");
    Color(writting_color,0);scanf("%c",&c);
    if(c == 'o' || c == 'O')
    {
        gotoxy(positionH,positionV+15);Color(printing_color,0);printf("Nombre  de Salle actuel : ");
        Color(writting_color,0);printf("%d",L->DATA.nbreDeSalleDialyse);
        gotoxy(positionH,positionV+16);Color(printing_color,0);printf("Nouveau Nombre  de Salle : ");
        Color(writting_color,0);scanf("%d",&L->DATA.nbreDeSalleDialyse);
    }
}


void afficher_Hopital(hopital l)
{
    Color(writting_color,1);
    printf("%s %s\t\t%s\t\t%d\t\t%d\t\t%d\t%d",l.type,l.nom,l.qaurtier,l.nbreDeMedcins,l.nombreDeLits,l.nombreDeLitsRe,l.nbreDeSalleDialyse);
}
void afficher_listeHopitaux(L_Hopitals *L)
{
    HOPITAL *par = L->Head;
    int i = 1;
    while(par != NULL)
    {
        gotoxy(2,2+i);
        afficher_Hopital(par->DATA);
        ++i;
        par = par->hopital_suivant;
    }
}

int MenuPrincipale(void)
{
    int choix,j;
    char c;
    clrscr();
    Color(writting_color,8);gotoxy(PositionMenuPrincipalH+8,PositionMenuPrincipalV-3);printf("Menu Principal");
    Color(writting_color,4);gotoxy(PositionMenuPrincipalH+12,PositionMenuPrincipalV-6);printf("GPC-19");
    /** _______  Haut **/
    for(j = 1 ; j<30; j++)
    {
        gotoxy(PositionMenuPrincipalH+j,PositionMenuPrincipalV);Color(FramColor,0);printf("%c",205);
    }
    /** extrimité haut à gouche  **/
    gotoxy(PositionMenuPrincipalH,PositionMenuPrincipalV);Color(FramColor,0);printf("%c",201);
    /** extrimité haut à droite  **/
    gotoxy(PositionMenuPrincipalH+30,PositionMenuPrincipalV);printf("%c",187);
    /** || à gouche **/
    for(j = 1 ; j<10; j++)
        {
           gotoxy(PositionMenuPrincipalH+30,PositionMenuPrincipalV+j);Color(FramColor,0);printf("%c",186);
        }
    /** exri  basse à droite **/
    gotoxy(PositionMenuPrincipalH+30, PositionMenuPrincipalV+10);printf("%c",188);
    /** || à gouche **/
    for(j = 1 ; j<10; j++)
        {
           gotoxy(PositionMenuPrincipalH,PositionMenuPrincipalV+j);Color(FramColor,0);printf("%c",186);
        }
    /** extrimité basse gouche **/
        gotoxy(PositionMenuPrincipalH, PositionMenuPrincipalV+10);printf("%c",200);

    /** __________ bas**/
        for(j = 1; j<30; j++)
        {
           gotoxy(PositionMenuPrincipalH+j, PositionMenuPrincipalV+10);Color(FramColor,0);printf("%c",205);
        }
    Color(writting_color,5);gotoxy(PositionMenuPrincipalH+3,PositionMenuPrincipalV+3);printf("(1) Gestion Des Patients");
    gotoxy(PositionMenuPrincipalH+3,PositionMenuPrincipalV+5);printf("(2) Gestion Des Hopitaux");
    gotoxy(PositionMenuPrincipalH+3,PositionMenuPrincipalV+7);printf("(3) Gestion De Quarantaine");
    Color(writting_color,0);gotoxy(PositionMenuPrincipalH+3,PositionMenuPrincipalV+9);printf("choix : ");
    Color(writting_color,0);
    do{
            gotoxy(PositionMenuPrincipalH+10,PositionMenuPrincipalV+9);printf("                    ");
            gotoxy(PositionMenuPrincipalH+11,PositionMenuPrincipalV+9);
    }while(((scanf("%d%c", &choix, &c)!=2 || c!='\n') && clean_stdin()) || choix < 1 || choix > 3);

    return choix;
}
int clean_stdin()
{
    while (getchar()!='\n');
    return 1;
}
int Menu2(void)
{
    int choix,j;
    char c;
    /** _______  Haut **/
    Color(writting_color,4);gotoxy(PositionMenuPrincipalH+20,PositionMenuPrincipalV-6);printf("GPC-19");
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
    Color(writting_color,5);gotoxy(PositionMenuPrincipalH+10,PositionMenuPrincipalV+3);printf("(1) Ajouter Un Patient");
    gotoxy(PositionMenuPrincipalH+10,PositionMenuPrincipalV+5);printf("(2) Afficher Les Patients");
    gotoxy(PositionMenuPrincipalH+10,PositionMenuPrincipalV+7);printf("(3) Cheracher Un Patient ");
    gotoxy(PositionMenuPrincipalH+10,PositionMenuPrincipalV+9);printf("(4) Modifier L'etat D'un Patient");
    gotoxy(PositionMenuPrincipalH+10,PositionMenuPrincipalV+11);printf("(5) Supprimer Un Patient");
    gotoxy(PositionMenuPrincipalH+10,PositionMenuPrincipalV+13);printf("(6) Afficher Les Patiens Selon...");
    Color(writting_color,4);gotoxy(PositionMenuPrincipalH+10,PositionMenuPrincipalV+15);printf("(0) Retour");
    Color(writting_color,0);gotoxy(PositionMenuPrincipalH+10,PositionMenuPrincipalV+17);printf("choix : ");

    do{
            gotoxy(PositionMenuPrincipalH+18,PositionMenuPrincipalV+17);printf("                          ");
            gotoxy(PositionMenuPrincipalH+19,PositionMenuPrincipalV+17);
    }while(((scanf("%d%c", &choix, &c)!=2 || c!='\n') && clean_stdin()) || choix < 0 || choix > 6 );
  return choix;

}
int Menu1(void)
{
    int choix,j;
    char c;
    clrscr();
    Color(writting_color,4);gotoxy(PositionMenuPrincipalH+20,PositionMenuPrincipalV-6);printf("GPC-19");
    Color(writting_color,8);gotoxy(PositionMenuPrincipalH+15,PositionMenuPrincipalV-3);printf("Gestion Des Hopitaux");
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
    Color(writting_color,5);
    gotoxy(PositionMenuPrincipalH+10,PositionMenuPrincipalV+3);printf("(1) Ajouter Un Hopital");
    gotoxy(PositionMenuPrincipalH+10,PositionMenuPrincipalV+5);printf("(2) Afficher Les Hopitaux");
    gotoxy(PositionMenuPrincipalH+10,PositionMenuPrincipalV+7);printf("(3) Acceder A Un Hopital");
    gotoxy(PositionMenuPrincipalH+10,PositionMenuPrincipalV+9);printf("(4) Modifier Un Hopital");
    gotoxy(PositionMenuPrincipalH+10,PositionMenuPrincipalV+11);Color(writting_color,4);printf("(0) Retour");
    Color(printing_color,0);gotoxy(PositionMenuPrincipalH+10,PositionMenuPrincipalV+13);printf("choix : ");
    Color(writting_color,0);
    do{
            gotoxy(PositionMenuPrincipalH+18,PositionMenuPrincipalV+13);printf("                          ");
            gotoxy(PositionMenuPrincipalH+19,PositionMenuPrincipalV+13);
    }while(((scanf("%d%c", &choix, &c)!=2 || c!='\n') && clean_stdin()) || choix < 0 || choix > 4 );
    return choix;

}




int MenuHotel(void)
{
    int choix,j;
    char c;
    clrscr();
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
    Color(writting_color,5);gotoxy(PositionMenuPrincipalH+10,PositionMenuPrincipalV+3);printf("(1) Ajouter Une Personne");
    gotoxy(PositionMenuPrincipalH+10,PositionMenuPrincipalV+5);printf("(2) Afficher Les Personnes");
    gotoxy(PositionMenuPrincipalH+10,PositionMenuPrincipalV+7);printf("(3) les Contactes D'un Patient");
    gotoxy(PositionMenuPrincipalH+10,PositionMenuPrincipalV+9);printf("(4) Supprimer Une personne");
    gotoxy(PositionMenuPrincipalH+10,PositionMenuPrincipalV+11);printf("(5) Modifier Une personne");
    gotoxy(PositionMenuPrincipalH+10,PositionMenuPrincipalV+13);Color(writting_color,4);printf("(0) Retour");
    Color(printing_color,0);gotoxy(PositionMenuPrincipalH+10,PositionMenuPrincipalV+15);printf("choix : ");
    Color(writting_color,0);
    do{
            gotoxy(PositionMenuPrincipalH+18,PositionMenuPrincipalV+15);printf("                          ");
            gotoxy(PositionMenuPrincipalH+19,PositionMenuPrincipalV+15);
    }while(((scanf("%d%c", &choix, &c)!=2 || c!='\n') && clean_stdin()) || choix < 0 || choix > 5 );
    return choix;
}





HOPITAL* choixDeHopital(L_Hopitals* l, Patient* p)
{
    HOPITAL* par = l->Head;
    HOPITAL* Find = NULL;
    char c;
    while(par != NULL)
    {
        if(!strcmp(p->DATA.etat,etat[0]) && par->DATA.nombreDeLitsRe > 0 || !strcmp(p->DATA.etat,etat[1]) && par->DATA.nombreDeLits > 0)/** etre sur que les lits de Reanimation ont dispo */
        {
            fflush(stdin);
            Color(printing_color,0);printf("vouler vous Ajouter ce patient  a %s %s ? oui(O)/non(N) : ", par->DATA.type, par->DATA.nom);
            Color(writting_color,0);scanf("%c",&c);
            if(c == 'o' || c == 'O')
            {
                Find = par;
                clrscr();
                return Find;
            }
        }
        par = par->hopital_suivant;
    }
    return Find;

}



void init()
{
    /** Hopital 1 **/
strcpy(Premiers_Hopitaux[0].nom,"Ben M'sik");
Premiers_Hopitaux[0].nbreDeMedcins      = 12;
Premiers_Hopitaux[0].nbreDeParamedicaux = 22;
Premiers_Hopitaux[0].nbreDeSalleDialyse = 4;
Premiers_Hopitaux[0].nombreDeLits       = 70;
Premiers_Hopitaux[0].nombreDeLitsRe     = 20;
Premiers_Hopitaux[0].CodePostal         = 20000;
strcpy(Premiers_Hopitaux[0].boulvard,"ben m'sik" );
strcpy(Premiers_Hopitaux[0].ville, "Casablanca");
strcpy(Premiers_Hopitaux[0].qaurtier,"ben m'sik" );
strcpy(Premiers_Hopitaux[0].type, typeHopital[1]);

/** Hopital 2 **/
strcpy(Premiers_Hopitaux[1].nom,"Zenith  ");
Premiers_Hopitaux[1].nbreDeMedcins      = 12;
Premiers_Hopitaux[1].nbreDeParamedicaux = 22;
Premiers_Hopitaux[1].nbreDeSalleDialyse = 4;
Premiers_Hopitaux[1].nombreDeLits       = 70;
Premiers_Hopitaux[1].nombreDeLitsRe     = 20;
Premiers_Hopitaux[1].CodePostal         = 20100;
strcpy(Premiers_Hopitaux[1].boulvard,"El Qods" );
strcpy(Premiers_Hopitaux[1].ville, "Casablanca");
strcpy(Premiers_Hopitaux[1].qaurtier,"Sidi maarouf" );
strcpy(Premiers_Hopitaux[1].type, typeHopital[1]);
/** Hopital 3 **/
strcpy(Premiers_Hopitaux[2].nom,"Sidi Bernoussi");
Premiers_Hopitaux[2].nbreDeMedcins      = 9;
Premiers_Hopitaux[2].nbreDeParamedicaux = 18 ;
Premiers_Hopitaux[2].nbreDeSalleDialyse = 3;
Premiers_Hopitaux[2].nombreDeLits       = 60;
Premiers_Hopitaux[2].nombreDeLitsRe     = 10;
Premiers_Hopitaux[2].CodePostal         = 20200;
strcpy(Premiers_Hopitaux[2].boulvard,"Sidi Bernoussi" );
strcpy(Premiers_Hopitaux[2].ville, "Casablanca");
strcpy(Premiers_Hopitaux[2].qaurtier, "Sidi Bernoussi") ;
strcpy(Premiers_Hopitaux[2].type, typeHopital[1]);

/** Hopital 4 **/
strcpy(Premiers_Hopitaux[3].nom,"Moulay Youssef");
Premiers_Hopitaux[3].nbreDeMedcins      = 15;
Premiers_Hopitaux[3].nbreDeParamedicaux = 30;
Premiers_Hopitaux[3].nbreDeSalleDialyse = 5;
Premiers_Hopitaux[3].nombreDeLits       = 100;
Premiers_Hopitaux[3].nombreDeLitsRe     = 15;
Premiers_Hopitaux[3].CodePostal         = 20300;
strcpy(Premiers_Hopitaux[3].boulvard,"Moulay Youssef" );
strcpy(Premiers_Hopitaux[3].ville, "Casablanca");
strcpy(Premiers_Hopitaux[3].qaurtier, "bourgone");
strcpy(Premiers_Hopitaux[3].type, typeHopital[1]);

/** Hopital 5 **/
strcpy(Premiers_Hopitaux[4].nom,"Mohammed V");
Premiers_Hopitaux[4].nbreDeMedcins      = 20;
Premiers_Hopitaux[4].nbreDeParamedicaux = 40;
Premiers_Hopitaux[4].nbreDeSalleDialyse = 10;
Premiers_Hopitaux[4].nombreDeLits       = 120;
Premiers_Hopitaux[4].nombreDeLitsRe     = 10;
Premiers_Hopitaux[4].CodePostal         = 20400;
strcpy(Premiers_Hopitaux[4].boulvard,"Abdelkader Torres" );
strcpy(Premiers_Hopitaux[4].ville, "Casablanca");
strcpy(Premiers_Hopitaux[4].qaurtier, "Hay Mohammadi");
strcpy(Premiers_Hopitaux[4].type, typeHopital[1]);

/** Hopital 6 **/
strcpy(Premiers_Hopitaux[5].nom,"de Marbre");
Premiers_Hopitaux[5].nbreDeMedcins      = 5;
Premiers_Hopitaux[5].nbreDeParamedicaux = 10;
Premiers_Hopitaux[5].nbreDeSalleDialyse = 1;
Premiers_Hopitaux[5].nombreDeLits       = 20 ;
Premiers_Hopitaux[5].nombreDeLitsRe     = 4;
Premiers_Hopitaux[5].CodePostal         = 20500;
strcpy(Premiers_Hopitaux[5].boulvard,"National 1" );
strcpy(Premiers_Hopitaux[5].ville, "Casablanca");
strcpy(Premiers_Hopitaux[5].qaurtier, "Lissasfa");
strcpy(Premiers_Hopitaux[5].type, typeHopital[0]);

/** Hopital 7 **/
strcpy(Premiers_Hopitaux[6].nom,"des Princes");
Premiers_Hopitaux[6].nbreDeMedcins      = 10;
Premiers_Hopitaux[6].nbreDeParamedicaux = 15;
Premiers_Hopitaux[6].nbreDeSalleDialyse = 1;
Premiers_Hopitaux[6].nombreDeLits       = 20;
Premiers_Hopitaux[6].nombreDeLitsRe     = 5;
Premiers_Hopitaux[6].CodePostal         = 20600;
strcpy(Premiers_Hopitaux[6].boulvard,"Allal Elfassi" );
strcpy(Premiers_Hopitaux[6].ville, "Casablanca");
strcpy(Premiers_Hopitaux[6].qaurtier, "Centre Ville");
strcpy(Premiers_Hopitaux[6].type, typeHopital[0]);

/** Hopital 8 **/
strcpy(Premiers_Hopitaux[7].nom,"Solomed");
Premiers_Hopitaux[7].nbreDeMedcins       = 8;
Premiers_Hopitaux[7].nbreDeParamedicaux  = 18;
Premiers_Hopitaux[7].nbreDeSalleDialyse  = 5;
Premiers_Hopitaux[7].nombreDeLits        = 40;
Premiers_Hopitaux[7].nombreDeLitsRe      = 15;
Premiers_Hopitaux[7].CodePostal         = 20700;
strcpy(Premiers_Hopitaux[7].boulvard,"Tariq Ibnou Ziad" );
strcpy(Premiers_Hopitaux[7].ville, "Casablanca");
strcpy(Premiers_Hopitaux[7].qaurtier, "les Hopitaux");
strcpy(Premiers_Hopitaux[7].type, typeHopital[0]);
/** Hopital 9 **/
strcpy(Premiers_Hopitaux[8].nom,"du Maroc");
Premiers_Hopitaux[8].nbreDeMedcins       = 5;
Premiers_Hopitaux[8].nbreDeParamedicaux  = 12;
Premiers_Hopitaux[8].nbreDeSalleDialyse  = 0;
Premiers_Hopitaux[8].nombreDeLits        = 15;
Premiers_Hopitaux[8].nombreDeLitsRe      = 2;
Premiers_Hopitaux[8].CodePostal         = 20800;
strcpy(Premiers_Hopitaux[8].boulvard,"El Qods" );
strcpy(Premiers_Hopitaux[8].ville, "Casablanca");
strcpy(Premiers_Hopitaux[8].qaurtier, "Sidi Maarouf") ;
strcpy(Premiers_Hopitaux[8].type, typeHopital[0]);

/** Hopital 10 **/
strcpy(Premiers_Hopitaux[9].nom,"El Madina");
Premiers_Hopitaux[9].nbreDeMedcins      = 10;
Premiers_Hopitaux[9].nbreDeParamedicaux = 20 ;
Premiers_Hopitaux[9].nbreDeSalleDialyse = 4 ;
Premiers_Hopitaux[9].nombreDeLits       = 30 ;
Premiers_Hopitaux[9].nombreDeLitsRe     = 4 ;
Premiers_Hopitaux[9].CodePostal         = 20900;
strcpy(Premiers_Hopitaux[9].boulvard,"Palmiers" );
strcpy(Premiers_Hopitaux[9].ville, "Casablanca");
strcpy(Premiers_Hopitaux[9].qaurtier, "Palmiers");
strcpy(Premiers_Hopitaux[9].type, typeHopital[0]);
}

int ajouter_Hopital(L_Hopitals* L, hopital H)
{
    int valider = 0;
    HOPITAL *New = creer_HOPITAL();
    New->DATA = H;
    New->listPaient =  creer_liste_Patients();
    if(L != NULL)
    {
        New->hopital_suivant = L->Head;
        L->Head = New;
        valider = 1;
    }
    return valider;
}
int nombre_deLisdisp(L_Patient *P, char* etatp)
{
    int cpt = 0;
    Patient * par = P->Head;
    if(strcmp(etatp,etat[0]) == 0)
        while(par != NULL)
        {
            cpt++;
            par = par->patient_suivant;
        }
    else if(strcmp(etatp,etat[1]) == 0)
        while(par != NULL)
        {
            cpt++;
            par = par->patient_suivant;
        }
    else
        cpt = 0;
    return cpt;
}
void initialiser_Hopitaux(L_Hopitals* L)
{
    int i;
    for(i = 0 ; i<10; i++)
        ajouter_Hopital(L,Premiers_Hopitaux[i]);
}



int Ajouter_Patient(HOPITAL* H,Patient *P)
{

    int valider = 0;
    L_Patient *l = H->listPaient;
    if(l != NULL)
    {
        if((!strcmp(P->DATA.etat,etat[0]) && H->DATA.nombreDeLitsRe > 0))
        {
            P->patient_suivant = l->Head;
            l->Head = P;
            H->DATA.nombreDeLitsRe--;
            valider = 1;
        }
        else if((!strcmp(P->DATA.etat,etat[1]) && H->DATA.nombreDeLits > 0))
        {
            P->patient_suivant = l->Head;
            l->Head = P;
            H->DATA.nombreDeLits--;
            valider = 1;
        }
    }
    return valider;
}

HOPITAL* Recherche_ToAdd(L_Hopitals* H, int CP, char *boulvard)
{
    HOPITAL *par = H->Head;
    HOPITAL *Find = NULL;
    clrscr();

    if(H != NULL)
    {
        while(par != NULL)
            {

                if(par->DATA.CodePostal == CP && !strcmp(par->DATA.boulvard,boulvard))
                {
                    Find = par;
                }
                par = par->hopital_suivant;
            }
    }
    return Find;
}

HOPITAL* rechercher_Hopital(L_Hopitals* L)
{
    HOPITAL * par = L->Head;
    HOPITAL * find = NULL;
    char Boulvard[20], NOM[20];
    int CP;
    fflush(stdin);
    clrscr();
    gotoxy(positionH+20,positionV);Color(titles1_color,0); printf("veuillez saisir les information de l'Hopital");
    gotoxy(positionH,positionV+2);Color(printing_color,0);printf("Nom         : ");
    Color(writting_color,0);gets(NOM);
    gotoxy(positionH,positionV+3);Color(printing_color,0);printf("Boulevard   : ");
    Color(writting_color,0);gets(Boulvard);
    gotoxy(positionH,positionV+4);Color(printing_color,0);printf("Code Postal : ");
    Color(writting_color,0);scanf("%d",&CP);
    while(par != NULL)
    {
        if(!strcmp(par->DATA.nom,NOM) || !strcmp(par->DATA.boulvard,Boulvard) || par->DATA.CodePostal ==  CP)
            {
                find = par;
                break;
            }
        par = par->hopital_suivant;
    }
    return find;

}
int modification_etat(HOPITAL* H, Patient * p)
{
    int valider = 0,choix;
    char etat0[10];
        strcpy(etat0,p->DATA.etat);
        gotoxy(positionH,positionV);Color(printing_color,0);printf("etat De Patient Est : %s ",p->DATA.etat);
        gotoxy(positionH,positionV+1); printf("%s(1) %s(2) %s(3) : ",etat[0], etat[1], etat[2]);
        Color(writting_color,0);scanf("%d",&choix);
        if(choix == 1 || choix == 2 || choix == 3)
        {
            strcpy(p->DATA.etat,etat[choix-1]);
            if(!strcmp(etat0,etat[0]) && !strcmp(p->DATA.etat,etat[1]))
            {
                H->DATA.nombreDeLitsRe--;
                H->DATA.nombreDeLits++;
            }
            else if(!strcmp(etat0,etat[1]) && !strcmp(p->DATA.etat,etat[0]))
            {
                H->DATA.nombreDeLitsRe++;
                H->DATA.nombreDeLits--;
            }
            else if(!strcmp(etat0,etat[0]) && !strcmp(p->DATA.etat,etat[2]))
            {
                H->DATA.nombreDeLitsRe++;
            }

            else if(!strcmp(etat0,etat[2]) && !strcmp(p->DATA.etat,etat[2]))
            {
               H->DATA.nombreDeLits++;
            }
            if(!strcmp(p->DATA.etat,etat[2]))
                valider = 1;
        }
    return valider;
}
Patient* Global_Recherch(L_Hopitals* l, char *nom, char *prenom)
{
    HOPITAL* par = l->Head;
    Patient *Find = NULL;
    while(par != NULL)
    {
        Find = Recherche_PatientN(par->listPaient, nom, prenom);
        if(Find != NULL)
            break;
        par = par->hopital_suivant;
    }
    return Find;
}

int MenuPatients(void)
{
    int choix,j;
    char c;
    clrscr();
    Color(writting_color,4);gotoxy(PositionMenuPrincipalH+20,PositionMenuPrincipalV-6);printf("GPC-19");
    Color(writting_color,8);gotoxy(PositionMenuPrincipalH+15,PositionMenuPrincipalV-3);printf("Gestion Des Patients");
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
    Color(writting_color,5);gotoxy(PositionMenuPrincipalH+10,PositionMenuPrincipalV+3);printf("(1) Ajouter Patient");
    gotoxy(PositionMenuPrincipalH+10,PositionMenuPrincipalV+5);printf("(2) Afficher Tout Les Patient");
    gotoxy(PositionMenuPrincipalH+10,PositionMenuPrincipalV+7);printf("(3) Chercher Des Patients Selon...");
    gotoxy(PositionMenuPrincipalH+10,PositionMenuPrincipalV+9);printf("(4) Rechercher Un Patien");
    gotoxy(PositionMenuPrincipalH+10,PositionMenuPrincipalV+11);printf("(5) Modification etat D'un Patient");
    gotoxy(PositionMenuPrincipalH+10,PositionMenuPrincipalV+13);printf("(6) suppression D'un Patient");
    gotoxy(PositionMenuPrincipalH+10,PositionMenuPrincipalV+15);Color(writting_color,4);printf("(0) Retour");
    Color(printing_color,0);gotoxy(PositionMenuPrincipalH+10,PositionMenuPrincipalV+17);printf("choix : ");
    Color(writting_color,0);
    do{
            gotoxy(PositionMenuPrincipalH+18,PositionMenuPrincipalV+17);printf("                          ");
            gotoxy(PositionMenuPrincipalH+19,PositionMenuPrincipalV+17);
    }while(((scanf("%d%c", &choix, &c)!=2 || c!='\n') && clean_stdin()) || choix < 0 || choix > 6 );
    return choix;
}

HOPITAL* Globale_Recherche_Patient(L_Hopitals* l, char* Nom, char* Prenom)
{
    HOPITAL* par = l->Head;
    HOPITAL* Find = NULL;
    while(par != NULL)
    {
        if(Recherche_PatientN(par->listPaient,Nom,Prenom) != NULL)
            Find = par;
        par = par->hopital_suivant;
    }
    return Find;
}
void GlobalRByAge(L_Hopitals* l, int age)
{
    HOPITAL* par = l->Head;
    while(par != NULL)
    {
         gotoxy(positionH+30,positionV-2);Color(writting_color,12);printf("%s %s",par->DATA.type,par->DATA.nom);
         Recherche_PatientA(par->listPaient,age);
         getch();
         clrscr();
         par = par->hopital_suivant;
    }
}
 void GlobalRByPrenom(L_Hopitals* l, char* Prenom)
 {
    HOPITAL* par = l->Head;
    while(par != NULL)
    {
         gotoxy(positionH+30,positionV-2);Color(writting_color,12);printf("%s %s",par->DATA.type,par->DATA.nom);
         Recherche_PatientP(par->listPaient,Prenom);
         getch();
         clrscr();
         par = par->hopital_suivant;
    }
 }
void GlobalRByEtat(L_Hopitals* l, char* Etat)
 {
    HOPITAL* par = l->Head;
    while(par != NULL)
    {
         gotoxy(positionH+30,positionV-2);Color(writting_color,12);printf("%s %s",par->DATA.type,par->DATA.nom);
         Recherche_PatientE(par->listPaient,Etat);
         getch();
         clrscr();
         par = par->hopital_suivant;
    }
 }

 void GlobalRByGenre(L_Hopitals* l, char* Genre)
 {
    HOPITAL* par = l->Head;
    while(par != NULL)
    {
         gotoxy(positionH+30,positionV-2);Color(writting_color,12);printf("%s %s",par->DATA.type,par->DATA.nom);
         Recherche_PatientG(par->listPaient,Genre);
         getch();
         clrscr();
         par = par->hopital_suivant;
    }
 }
void GlobalRByGenreAge(L_Hopitals* l,  int age, char* Genre)
 {
    HOPITAL* par = l->Head;
    while(par != NULL)
    {
         gotoxy(positionH+30,positionV-2);Color(writting_color,12);printf("%s %s",par->DATA.type,par->DATA.nom);
         Recherche_PatientAG(par->listPaient,age,Genre);
         getch();
         clrscr();
         par = par->hopital_suivant;
    }
 }
void GlobalRByGenreEtat(L_Hopitals* l, char* Etat, char* Genre)
{
    HOPITAL* par = l->Head;
    while(par != NULL)
    {
         gotoxy(positionH+30,positionV-2);Color(writting_color,12);printf("%s %s",par->DATA.type,par->DATA.nom);
         Recherche_PatientEG(par->listPaient,Etat,Genre);
         getch();
         clrscr();
         par = par->hopital_suivant;
    }
}
