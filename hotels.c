#include "Hotels.h"

L_Hotel* creer_LHotel()
{
    L_Hotel* h = malloc(sizeof(L_Hotel));
    if(h == NULL)
        exit(-1);
    h->Head = NULL;
    return h;
}

hotel creer_hotel(void)
{
    hotel H;

    gotoxy(positionH,positionV+2);Color(printing_color,0);printf("Nom                        : ");
    Color(writting_color,0);gets(H.Nom);
    gotoxy(positionH,positionV+3);Color(printing_color,0);printf("Quartier                   : ");
    Color(writting_color,0);gets(H.Quartier);
    gotoxy(positionH,positionV+4); Color(printing_color,0);printf("boulvard                   : ");
    Color(writting_color,0);gets(H.boulvard);
    gotoxy(positionH,positionV+5); Color(printing_color,0);printf("code Postal                : ");
    Color(writting_color,0);scanf("%d",&H.CodePostal);
    gotoxy(positionH,positionV+6);Color(printing_color,0);printf("capacite                   : ");
    Color(writting_color,0);scanf("%d",&H.capacite);
    H.Disponibilte = H.capacite;

    return H;

}

HOTEL* creer_HOTEL(void)
{
    HOTEL* H = (HOTEL *) malloc(sizeof(HOTEL));
    if(H == NULL)
        exit(-1);
    H->Hotel_suivant = NULL;
    return H;
}

int ajouter_Hotel(L_Hotel* L, hotel H)
{
    int valider = 0;
    HOTEL *New = creer_HOTEL();
    New->DATA = H;
    New->Contacts = creer_liste_Contacts();
    if(L != NULL)
    {
        New->Hotel_suivant = L->Head;
        L->Head = New;
        valider = 1;
    }
    return valider;
}


HOTEL* Recherche_ToAddHOTEL(L_Hotel* H, int CP, char *boulvard)
{
    HOTEL *par = H->Head;
    HOTEL *Find = NULL;
    if(H != NULL)
    {
        while(par != NULL)
            {
                if(par->DATA.CodePostal == CP || !strcmp(par->DATA.boulvard,boulvard))
                {
                    Find = par;
                    return Find;
                }
                par = par->Hotel_suivant;
            }
    }
    return Find;
}

HOTEL* Recherche_HotelByName(L_Hotel* H, char *name, int CP)
{
    HOTEL *par = H->Head;
    HOTEL *Find = NULL;
    if(H != NULL)
    {
        while(par != NULL)
            {
                if( !strcmp(par->DATA.Nom,name) || par->DATA.CodePostal == CP)
                {
                    Find = par;
                    return Find;
                }
                par = par->Hotel_suivant;
            }
    }
    return Find;
}

HOTEL* choixDeHotelpourUncontact(L_Hotel* l)
{
    HOTEL* par = l->Head;
    HOTEL* Find = NULL;
    char c;
    printf("\n");
    while(par != NULL)
    {
        if(par->DATA.Disponibilte > 0)
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

void initialiser_Hotels(L_Hotel* L)
{
    int i;
    for(i = 0 ; i<10; i++)
         ajouter_Hotel(L, lesHotels[i]);
}

void afficher_Hotel(hotel l)
{
    Color(writting_color,1);
    printf(" %s\t\t%20s\t\t   %d\t\t\t    %d",l.Nom,l.boulvard,l.capacite,l.Disponibilte);
}
void afficher_listeHotels(L_Hotel* l)
{
    HOTEL *par = l->Head;
    int i = 1;
    while(par != NULL)
    {
        gotoxy(2,2+i);
        afficher_Hotel(par->DATA);
        ++i;
        par = par->Hotel_suivant;
    }
}


void Modification_Hotel(HOTEL *L)
{
    char c;
    int capacite;
    fflush(stdin);
    Color(writting_color,12);gotoxy(PositionMenuPrincipalH+10,PositionMenuPrincipalV-8);printf("Hotel %s",L->DATA.Nom);
    gotoxy(positionH,positionV);Color(printing_color,0);printf("Nom Actuel : "); Color(writting_color,0);printf("%s",L->DATA.Nom);
    gotoxy(positionH,positionV+1);Color(printing_color,0);printf("vouler vous modifier le Nom? oui(O)/non(N) : ");
    Color(writting_color,0);scanf("%c",&c);
    if(c == 'o' || c == 'O')
    {
        fflush(stdin);
        gotoxy(positionH,positionV+2);Color(printing_color,0);printf("Nouveau Nom : ");
        Color(writting_color,0);gets(L->DATA.Nom);
    }

    clrscr();
    fflush(stdin);
    Color(writting_color,12);gotoxy(PositionMenuPrincipalH+10,PositionMenuPrincipalV-8);printf("Hotel %s",L->DATA.Nom);
    gotoxy(positionH,positionV);Color(printing_color,0);printf("capacite Actuelle : "); Color(writting_color,0);printf("%d",L->DATA.capacite);
    gotoxy(positionH,positionV+1);Color(printing_color,0); printf("vouler vous modifier la Capacite ? oui(O)/non(N) : ");
    Color(writting_color,0);scanf("%c",&c);
    if(c == 'o' || c == 'O')
    {
        capacite = L->DATA.capacite;
        gotoxy(positionH,positionV+2);Color(printing_color,0);printf("Nouvelle Capacite : ");
        Color(writting_color,0);scanf("%d",&L->DATA.capacite);
        capacite = L->DATA.capacite - capacite;
        L->DATA.Disponibilte = L->DATA.Disponibilte + capacite;
    }

    clrscr();
    fflush(stdin);
    Color(writting_color,12);gotoxy(PositionMenuPrincipalH+10,PositionMenuPrincipalV-8);printf("Hotel %s",L->DATA.Nom);
    gotoxy(positionH,positionV);Color(printing_color,0);printf("Quartier Actuel : "); Color(writting_color,0);printf("%s",L->DATA.Quartier);
    gotoxy(positionH,positionV+1);Color(printing_color,0);printf("vouler vous modifier Le Quartier ? oui(O)/non(N) : ");
    Color(writting_color,0);scanf("%c",&c);
    if(c == 'o' || c == 'O')
    {
        gotoxy(positionH,positionV+2);Color(printing_color,0);printf("Nouveau Quartier : ");
        Color(writting_color,0);gets(L->DATA.Quartier);
    }
    clrscr();
    fflush(stdin);
    Color(writting_color,12);gotoxy(PositionMenuPrincipalH+10,PositionMenuPrincipalV-8);printf("Hotel %s",L->DATA.Nom);
    gotoxy(positionH,positionV);Color(printing_color,0);printf("Code Postal Actuel : "); Color(writting_color,0);printf("%d",L->DATA.CodePostal);
    gotoxy(positionH,positionV+1);Color(printing_color,0);printf("vouler vous modifier le Code Postal ? oui(O)/non(N) : ");
    Color(writting_color,0);scanf("%c",&c);
    if(c == 'o'|| c == 'O')
    {
        gotoxy(positionH,positionV+2);Color(printing_color,0);printf("Nouveau Code Postal : ");
        Color(writting_color,0);scanf("%d",&L->DATA.CodePostal);
    }

    clrscr();
    fflush(stdin);
    Color(writting_color,12);gotoxy(PositionMenuPrincipalH+10,PositionMenuPrincipalV-8);printf("Hotel %s",L->DATA.Nom);
    gotoxy(positionH,positionV);Color(printing_color,0);printf("Boulvard Actuel : "); Color(writting_color,0);printf("%s",L->DATA.boulvard);
    gotoxy(positionH,positionV+1);Color(printing_color,0);printf("vouler vous modifier Le Boulvard ? oui(O)/non(N) : ");
    Color(writting_color,0);scanf("%c",&c);
    if(c == 'o' || c == 'O')
    {
        gotoxy(positionH,positionV+2);Color(printing_color,0);printf("Nouveau Boulvard : ");
        Color(writting_color,0);gets(L->DATA.boulvard);
    }
}

void inithotels()
{
    /****** Hotel 1 ************/
    strcpy(lesHotels[0].boulvard,"ben m'sik");
    lesHotels[0].capacite   = 100;
    lesHotels[0].Disponibilte   = 100;
    lesHotels[0].CodePostal = 20000;
    strcpy(lesHotels[0].Nom,"Nejma  ");
    strcpy(lesHotels[0].Quartier,"ben m'sik");

    /****** Hotel 2 ************/
    strcpy(lesHotels[1].boulvard,"El Qods");
    lesHotels[1].capacite   = 10;
    lesHotels[1].Disponibilte = 10;
    lesHotels[1].CodePostal = 20800;
    strcpy(lesHotels[1].Nom,"Prince  ");
    strcpy(lesHotels[1].Quartier,"Sidi maarouf");

    /****** Hotel 3 ************/
    strcpy(lesHotels[2].boulvard,"Sidi Bernoussi");
    lesHotels[2].capacite   = 20;
    lesHotels[2].Disponibilte = 20;
    lesHotels[2].CodePostal = 20200;
    strcpy(lesHotels[2].Nom,"Stars  ");
    strcpy(lesHotels[2].Quartier,"Sidi Bernoussi");

    /****** Hotel 4 ************/
    strcpy(lesHotels[3].boulvard,"Moulay Youssef");
    lesHotels[3].capacite   = 15;
    lesHotels[3].Disponibilte = 15;
    lesHotels[3].CodePostal = 20300;
    strcpy(lesHotels[3].Nom,"Califonia");
    strcpy(lesHotels[3].Quartier,"bourgone");

    /****** Hotel 5 ************/
    strcpy(lesHotels[4].boulvard,"Abdelkader Torres");
    lesHotels[4].capacite   = 35;
    lesHotels[4].Disponibilte = 35;
    lesHotels[4].CodePostal = 20400;
    strcpy(lesHotels[4].Nom,"Diamond");
    strcpy(lesHotels[4].Quartier,"Hay Mohammadi");

    /****** Hotel 6 ************/
    strcpy(lesHotels[5].boulvard,"National 1");
    lesHotels[5].capacite   = 60;
    lesHotels[5].Disponibilte = 60;
    lesHotels[5].CodePostal = 20500;
    strcpy(lesHotels[5].Nom,"Odeyssee");
    strcpy(lesHotels[5].Quartier,"Lissasfa");


    /****** Hotel 7 ************/
    strcpy(lesHotels[6].boulvard,"Allal Elfassi");
    lesHotels[6].capacite   = 120;
    lesHotels[6].Disponibilte = 120;
    lesHotels[6].CodePostal = 20600;
    strcpy(lesHotels[6].Nom,"Mogador");
    strcpy(lesHotels[6].Quartier,"Centre Ville");


    /****** Hotel 8 ************/
    strcpy(lesHotels[7].boulvard,"Ibno sina");
    lesHotels[7].capacite   = 200;
    lesHotels[7].Disponibilte = 200;
    lesHotels[7].CodePostal = 20700;
    strcpy(lesHotels[7].Nom,"verdano");
    strcpy(lesHotels[7].Quartier,"les Hopitaux");

    /****** Hotel 9 ************/
    strcpy(lesHotels[8].boulvard,"El Qods");
    lesHotels[8].capacite   = 10;
    lesHotels[8].Disponibilte = 10;
    lesHotels[8].CodePostal = 20800;
    strcpy(lesHotels[8].Nom,"El NOUR");
    strcpy(lesHotels[8].Quartier,"Sidi Maarouf");

    /****** Hotel 10 ************/
    strcpy(lesHotels[9].boulvard,"Palmiers");
    lesHotels[9].capacite   = 80;
    lesHotels[9].Disponibilte = 80;
    lesHotels[9].CodePostal = 20900;
    strcpy(lesHotels[9].Nom,"Palmier");
    strcpy(lesHotels[9].Quartier,"Palmiers");

}
