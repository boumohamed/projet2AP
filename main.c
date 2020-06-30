#include <stdio.h>
#include <stdlib.h>
#include "patient.c"
#include "hopitals.c"
#include "quarantaine.c"

int main()
{

    int choix,choix0, choix1,age;
    char Nom[20],Prenom[20];
    Patient *p;
    L_Patient *LPP;
    Contact *pc;
    hopital Hajouter;
    HOPITAL *Find;
    HOPITAL *par;
    L_Hotel* HOTELS = creer_LHotel();
    HOTEL* FindHotel;
    HOTEL* parC;
    hotel HOTajout;
    L_Hopitals *HOPITAUX = creer_LHopital();
    init();
    initialiser_Hopitaux(HOPITAUX);
    inithotels();
    initialiser_Hotels(HOTELS);
    while(1)
    {
        choix =  MenuPrincipale();
        switch(choix) {
/************************************************************************ PATIENTS ********************************************************************/
        case 1 :
                clrscr();
                do{
                    choix = MenuPatients();
                    switch(choix){

                        case 1 : /********** ajouter Patient *********/
                                clrscr();
                                p = creer_Patient();
                                clrscr();
                                Find = Recherche_ToAdd(HOPITAUX,p->DATA.CodePostal,p->DATA.boulvard);
                                if(Find != NULL)
                                {
                                    Ajouter_Patient(Find,p);
                                    Color(titles1_color,0);printf("Ajoute Avec Succer ! A ");
                                    Color(writting_color,12);printf("%s %s ",Find->DATA.type,Find->DATA.nom);
                                }
                                else
                                {
                                    Color(titles1_color,0);printf("  L'Hopital de La Region du Patient N'existe  Pas Ou Plien Cherchez un autre ! \n");
                                    Find = choixDeHopital(HOPITAUX, p);
                                    if(Find != NULL)
                                        Ajouter_Patient(Find,p);
                                    Color(titles1_color,0);printf("Ajoute Avec Succer ! A ");
                                    Color(writting_color,12);printf("%s %s ",Find->DATA.type,Find->DATA.nom);


                                }
                                if(p->DATA.NbreDeContacts > 0)
                                {
                                    affecterContaminateur(p->Contacts,p->DATA.Nom,p->DATA.Prenom);
                                    affecterLesContacts(HOTELS, p);
                                }
                                getch();
                                break;
                         case 2 : /************ tout Les Patients ******************/
                                 clrscr();
                                 par = HOPITAUX->Head;
                                 while(par != NULL)
                                 {
                                    gotoxy(positionH+30,positionV-2);Color(writting_color,12);printf("%s %s",par->DATA.type,par->DATA.nom);
                                    afficher_ToutPatients(par->listPaient);
                                    printf("\n\n tapez entrer pour continuer ");
                                    getch();
                                    clrscr();
                                    par = par->hopital_suivant;

                                 }
                                 getch();
                                 break;
                        case 3 : /*********** rechercher Des Patients Selon **************/
                                clrscr();
                                do{
                                    choix0 = MenuRecherche();
                                    switch(choix0)
                                    {
                                    case 1 : /***** selon age ******/
                                            clrscr();
                                            Color(printing_color,0);printf("Age : ");
                                            Color(writting_color,0);scanf("%d",&age);
                                            clrscr();
                                            GlobalRByAge(HOPITAUX, age);
                                            getch();
                                            break;
                                    case 2 : /***** selon Prenom ******/
                                            clrscr();
                                            Color(printing_color,0);printf("Prenom : ");
                                            fflush(stdin);
                                            Color(writting_color,0);gets(Prenom);
                                            clrscr();
                                            GlobalRByPrenom(HOPITAUX, Prenom);
                                            getch();
                                            break;
                                    case 3 : /***** selon etat ******/
                                            clrscr();
                                            Color(printing_color,0);printf("Critique(1) Normale(2) : ");Color(writting_color,0);scanf("%d",&choix);
                                            if(choix == 1 || choix == 2)
                                            {
                                                clrscr();
                                                GlobalRByEtat(HOPITAUX, etat[choix-1]);
                                                getch();
                                            }
                                            else
                                            {
                                                clrscr();
                                                Color(titles1_color,0);printf("Ressayer !");
                                                getch();
                                            }
                                            break;
                                    case 4 : /***** selon genre ******/
                                            clrscr();
                                            Color(printing_color,0); printf("Homme(1) Femme(2) : ");Color(writting_color,0);scanf("%d",&choix);
                                            if(choix == 1 || choix == 2)
                                            {
                                                clrscr();
                                                GlobalRByGenre(HOPITAUX, genre[choix-1]);
                                                getch();
                                            }
                                            else
                                            {
                                                clrscr();
                                                Color(titles1_color,0);printf("Ressayer !");
                                                getch();
                                            }
                                            break;
                                    case 5 : /***** genre & age ******/
                                            clrscr();
                                            Color(printing_color,0); printf("Homme(1) Femme(2) : ");Color(writting_color,0);scanf("%d",&choix);
                                            Color(printing_color,0);printf("Age : ");
                                            Color(writting_color,0);scanf("%d",&age);
                                            if(choix == 1 || choix == 2)
                                            {
                                                clrscr();
                                                GlobalRByGenreAge(HOPITAUX, age,genre[choix-1]);
                                                getch();
                                            }
                                            else
                                            {
                                                clrscr();
                                                Color(titles1_color,0);printf("Ressayer !");
                                                getch();
                                            }
                                            break;
                                    case 6 : /***** genre & etat ******/
                                            clrscr();
                                            Color(printing_color,0);printf("Critique(1) Normale(2) : ");Color(writting_color,0);scanf("%d",&choix0);
                                            Color(printing_color,0);printf("Homme(1) Femme(2)      : ");Color(writting_color,0);scanf("%d",&choix);
                                            if(choix == 1 || choix == 2 && choix0 == 1 || choix0 == 2)
                                            {
                                                clrscr();
                                                GlobalRByGenreEtat(HOPITAUX, etat[choix0-1],genre[choix-1]);
                                                getch();
                                            }
                                            else
                                            {
                                                clrscr();
                                                Color(titles1_color,0);printf("Ressayer !");
                                                getch();
                                            }
                                    }

                                }while(choix0 != 0);
                                break;
                        case 4 :
                                /******** recherche d'un Patient *******/
                                clrscr();
                                Color(printing_color,0);printf("Nom    : ");
                                fflush(stdin);
                                Color(writting_color,0);gets(Nom);
                                Color(printing_color,0);printf("Prenom : ");
                                Color(writting_color,0);gets(Prenom);
                                Find = Globale_Recherche_Patient(HOPITAUX, Nom, Prenom);
                                if(Find != NULL)
                                {
                                    p = Recherche_PatientN(Find->listPaient,Nom,Prenom);
                                    if(p != NULL)
                                    {
                                        clrscr();
                                        gotoxy(positionH+5,positionV-2);Color(titles1_color,0);printf("Informations De Patient ");
                                        afficher_patient(p->DATA);
                                        gotoxy(positionH,positionV+15);Color(writting_color,12);printf("%s %s",Find->DATA.type,Find->DATA.nom);
                                        if(p->Maladies != NULL)
                                            afficher_maladie(p->Maladies);
                                        if(p->Contacts != NULL)
                                            afficher_ToutContact(p->Contacts);
                                    }
                                    else
                                        {Color(titles1_color,0);printf("Patient Introuvable !");}
                                }
                                else
                                    {Color(titles1_color,0);printf("Patient Introuvable !");}
                                getch();
                                break;
                        case 5 :
                                /******** modification de l'etat  d'un Patient *******/
                                clrscr();
                                Color(printing_color,0);printf("Nom    : ");
                                fflush(stdin);
                                Color(writting_color,0);gets(Nom);
                                Color(printing_color,0);printf("Prenom : ");
                                Color(writting_color,0);gets(Prenom);
                                Find = Globale_Recherche_Patient(HOPITAUX, Nom, Prenom);
                                if(Find != NULL)
                                {
                                    p = Recherche_PatientN(Find->listPaient,Nom,Prenom);
                                    if(p != NULL)
                                    {
                                        if(modification_etat(Find, p))
                                            {
                                                Color(titles1_color,0);printf("Ce Patient Est %s (1)Supprimer ! ",p->DATA.etat);
                                                scanf("%d",&choix1);
                                                if(choix1 == 1)
                                                {
                                                    supprimer_Patient(Find->listPaient, p);
                                                    Color(titles1_color,0);printf("Supprission Avec Succer ! ");
                                                    getch();
                                                }
                                            }
                                     }
                                    else
                                        {Color(titles1_color,0);printf("Patient Introuvable !");getch();}
                                    }
                                  else
                                        {Color(titles1_color,0);printf("Patient Introuvable !");getch();}
                                break;
                         case 6 : /*********** SUPPRISSION  D'UN PATIENT ************/
                                 clrscr();
                                 fflush(stdin);
                                 Color(printing_color,0);printf("Nom    : ");
                                 fflush(stdin);
                                 Color(writting_color,0);gets(Nom);
                                 Color(printing_color,0);printf("Prenom : ");
                                 Color(writting_color,0);gets(Prenom);
                                 Find = Globale_Recherche_Patient(HOPITAUX, Nom, Prenom);
                                 if(Find != NULL)
                                 {
                                     p = Recherche_PatientN(Find->listPaient,Nom,Prenom);
                                     if(p != NULL)
                                     {
                                        afficher_patient(p->DATA);
                                        if(strcmp(p->DATA.etat,etat[2]))
                                            {gotoxy(positionH,positionV+14);Color(4,0);printf("Ce Patient N'est pas encore guere(e) !");}
                                        else
                                            {supprimer_Patient(Find->listPaient, p);gotoxy(positionH,positionV+11);Color(titles1_color,0);printf("Patient a ete Bien Supprime(e) !");}
                                     }
                                      else
                                        {Color(titles1_color,0);printf("Patient Introuvable !");}
                                  }
                                  else
                                     {Color(titles1_color,0);printf("Patient Introuvable !");}
                                getch();
                                break;
                    }
                    }while(choix != 0);
                    break;
/************************************************************************ HOPITAUX ********************************************************************/
        case 2 :
                    clrscr();
                    do{
                    choix1 = Menu1();
                    switch(choix1){
                        case 1 : /*********** AJOUTER UN HOPITAL ************/
                                clrscr();
                                Hajouter = creer_hopital();
                                if(ajouter_Hopital(HOPITAUX, Hajouter))
                                {
                                    Color(titles1_color,0);printf("\tAjoute Avec Succer !");
                                }
                                getch();
                                break;

                        case 2 : /*********** AFFICHER TOUT LES  HOPITAUX ************/
                                clrscr();
                                Color(writting_color,4);
                                gotoxy(2,2);
                                printf("Nom \t\t\t\tAdresse\t\t\tMedcines\tLits\tReanimation\tDialyse");
                                afficher_listeHopitaux(HOPITAUX);
                                getch();
                                break;


                        case 3 : /*********** ACCERDER A UN HOPITAL ************/

                                do {
                                    Find = rechercher_Hopital(HOPITAUX);
                                        if(Find == NULL)
                                        {
                                            clrscr();
                                            gotoxy(positionH+20,positionV);Color(titles1_color,0); printf("Cet Hopital N'existe Pas ! Ressayer ");
                                            getch();

                                        }
                                    }while(Find == NULL);
                                    do {
                                    clrscr();
                                    Color(writting_color,12);gotoxy(PositionMenuPrincipalH+15,PositionMenuPrincipalV-3);printf("%s %s",Find->DATA.type,Find->DATA.nom);
                                    choix0 = Menu2();
                                        switch(choix0){
                                            case 1 : /*********** AJOUTER  UN PATIENT ************/
                                                    clrscr();
                                                    p = creer_Patient();
                                                    if(Ajouter_Patient(Find,p))
                                                         {
                                                             Color(titles1_color,0);printf("Ajoute(e) Avec Succer !");getch();
                                                         }
                                                    else
                                                         {
                                                            Color(titles1_color,0);printf("  L'Hopital de La Region du Patient Est Plien Selecionnez Un Autre ! \n");
                                                            Find = choixDeHopital(HOPITAUX, p);
                                                            Ajouter_Patient(Find,p);
                                                            Color(titles1_color,0);printf("Ajoute Avec Succer ! A ");
                                                            Color(writting_color,12);printf("%s %s ",Find->DATA.type,Find->DATA.nom);
                                                            getch();
                                                        }
                                                    if(p->DATA.NbreDeContacts > 0)
                                                    {
                                                        affecterContaminateur(p->Contacts,p->DATA.Nom,p->DATA.Prenom);
                                                        affecterLesContacts(HOTELS, p);
                                                        getch();
                                                    }
                                                    break;
                                            case 2 : /*** afficher tout les patients de cet Hopital ****/
                                                    clrscr();
                                                    afficher_ToutPatients(Find->listPaient);
                                                    getch();
                                                    break;

                                            case 3 : /*********** RECHERCHE  D'UN PATIENT ************/
                                                    clrscr();
                                                    fflush(stdin);
                                                    Color(printing_color,0);printf("Nom    : ");
                                                    Color(writting_color,0);gets(Nom);
                                                    Color(printing_color,0);printf("Prenom : ");
                                                    Color(writting_color,0);gets(Prenom);
                                                    p = Recherche_PatientN(Find->listPaient,Nom,Prenom);
                                                    if(p != NULL)
                                                    {
                                                        clrscr();
                                                        gotoxy(positionH+5,positionV-2);Color(titles1_color,0);printf("Informations De Patient ");
                                                        afficher_patient(p->DATA);
                                                        if(p->Maladies != NULL)
                                                            afficher_maladie(p->Maladies);
                                                        if(p->Contacts != NULL)
                                                            afficher_ToutContact(p->Contacts);

                                                    }

                                                    else
                                                        {Color(titles1_color,0);printf("Patient Introuvable !");}
                                                    getch();
                                                    break;

                                            case 4 : /*********** MODIFICATION  D'UN PATIENT ************/
                                                     clrscr();
                                                     Color(printing_color,0);printf("Nom    : ");
                                                     fflush(stdin);
                                                     Color(writting_color,0);gets(Nom);
                                                     Color(printing_color,0);printf("Prenom : ");
                                                     Color(writting_color,0);gets(Prenom);
                                                     p = Recherche_PatientN(Find->listPaient, Nom, Prenom);
                                                     if(p != NULL)
                                                     {
                                                        if(modification_etat(Find, p))
                                                            {
                                                                Color(titles1_color,0);printf("Ce Patient Est %s (1)Supprimer ! ",p->DATA.etat);
                                                                scanf("%d",&choix);
                                                                if(choix == 1)
                                                                    supprimer_Patient(Find->listPaient, p);
                                                            }
                                                     }

                                                    else
                                                        {Color(titles1_color,0);printf("Patient Introuvable !");getch();}
                                                    break;
                                            case 5 : /*********** SUPPRISSION  D'UN PATIENT ************/
                                                     clrscr();
                                                     fflush(stdin);
                                                     Color(printing_color,0);printf("Nom       : ");
                                                     Color(writting_color,0);gets(Nom);
                                                     Color(printing_color,0);printf("prenom    : ");
                                                     Color(writting_color,0);gets(Prenom);
                                                     p = Recherche_PatientN(Find->listPaient, Nom, Prenom);
                                                     if(p != NULL)
                                                     {
                                                        afficher_patient(p->DATA);
                                                        if(strcmp(p->DATA.etat,etat[2]))
                                                            {gotoxy(positionH,positionV+13);Color(4,0);printf("Ce Patient N'est pas encore guere(e) !");}
                                                        else
                                                            {supprimer_Patient(Find->listPaient, p);gotoxy(positionH,positionV+11);Color(titles1_color,0);printf("Patient a ete Bien Supprime(e) !");}
                                                     }
                                                      else
                                                        {Color(titles1_color,0);printf("Patient Introuvable !");}
                                                    getch();
                                                    break;
                                            case 6 :  /*********** RECHERCHE AVEC CRITERES  ************/
                                                    clrscr();
                                                    do{
                                                        choix = MenuRecherche();
                                                        switch(choix)
                                                            {
                                                            case 1 : /**** SELON AGE ****/
                                                                    clrscr();
                                                                    Color(printing_color,0);printf("Age : ");
                                                                    Color(writting_color,0);scanf("%d",&age);
                                                                    clrscr();
                                                                    Recherche_PatientA(Find->listPaient,age);
                                                                    getch();
                                                                    break;
                                                            case 2 : /**** SELON PRENOM ****/
                                                                    clrscr();
                                                                    Color(printing_color,0);printf("Prenom : ");
                                                                    fflush(stdin);
                                                                    Color(writting_color,0);gets(Prenom);
                                                                    clrscr();
                                                                    Recherche_PatientP(Find->listPaient,Prenom);
                                                                    getch();
                                                                    break;
                                                            case 3 : /**** SELON etat ****/
                                                                    clrscr();
                                                                    Color(printing_color,0);printf("Critique(1) Normale(2) : ");Color(writting_color,0);scanf("%d",&choix);
                                                                    if(choix == 1 || choix == 2)
                                                                    {
                                                                        clrscr();
                                                                        Recherche_PatientE(Find->listPaient,etat[choix-1]);
                                                                        getch();
                                                                    }
                                                                    break;
                                                            case 4 :  /**** SELON GENRE ****/
                                                                    clrscr();
                                                                    Color(printing_color,0); printf("Homme(1) Femme(2) : ");Color(writting_color,0);scanf("%d",&choix);
                                                                    if(choix == 1 || choix == 2)
                                                                    {
                                                                        clrscr();
                                                                        Recherche_PatientG(Find->listPaient,genre[choix-1]);
                                                                        getch();
                                                                    }
                                                                    else
                                                                    {
                                                                        clrscr();
                                                                        Color(titles1_color,0);printf("Ressayer !");
                                                                        getch();
                                                                    }
                                                                    break;
                                                            case 5 :  /**** SELON AGE & GENRE****/
                                                                    clrscr();
                                                                    Color(printing_color,0);printf("Age : ");
                                                                    Color(writting_color,0);scanf("%d",&age);
                                                                    Color(printing_color,0); printf("Homme(1) Femme(2) : ");Color(writting_color,0);scanf("%d",&choix);
                                                                    if(choix == 1 || choix == 2)
                                                                    {
                                                                        clrscr();
                                                                        Recherche_PatientAG(Find->listPaient,age, genre[choix-1]);
                                                                    }

                                                                    else
                                                                    {
                                                                        clrscr();
                                                                        Color(titles1_color,0);printf("Ressayer !");
                                                                        getch();
                                                                    }
                                                                    getch();
                                                                    break;
                                                            case 6 :  /**** SELON etat 1 GENRE ****/
                                                                    clrscr();
                                                                    Color(printing_color,0);printf("Critique(1) Normale(2) : ");Color(writting_color,0);scanf("%d",&choix0);
                                                                    Color(printing_color,0); printf("Homme(1) Femme(2) : ");Color(writting_color,0);scanf("%d",&choix);
                                                                    if(choix == 1 || choix == 2 && choix0 == 1 || choix0 == 2)
                                                                    {
                                                                        clrscr();
                                                                        LPP = Find->listPaient;
                                                                        Recherche_PatientEG(LPP,etat[choix0-1], genre[choix-1]);
                                                                    }
                                                                    getch();
                                                                    break;
                                                            }

                                                        }while(choix != 0);
                                }
                                }while(choix0 != 0);
                               break;
                        case 4 : /*********** MODIFICATION  D'UN HOPITAL ************/
                                clrscr();
                                 do {
                                    Find = rechercher_Hopital(HOPITAUX);
                                        if(Find == NULL)
                                        {
                                            clrscr();
                                            gotoxy(positionH+20,positionV);Color(titles1_color,0); printf("Cet Hopital N'existe Pas ! Ressayer ");
                                            getch();

                                        }
                                    }while(Find == NULL);
                                    clrscr();
                                    Modification_Hopital(Find);
                                    Color(titles1_color,0);printf("\tModification Avec Succer !");
                                    getch();
                                    break;
                    }
                    }while(choix1 != 0);
                    break;
/************************************************************************ HOTELS & QUARANTAINE ********************************************************************/
        case 3 :
                do{
                    clrscr();
                    choix = MenuQ();
                    switch(choix){
                    case 1 : /*********** AJOUTER UN HOTEL ************/
                            clrscr();
                            HOTajout = creer_hotel();
                            if(ajouter_Hotel(HOTELS, HOTajout))
                            {
                                Color(titles1_color,0);printf("\tAjoute Avec Succer !");
                            }
                            getch();
                            break;

                    case 2 :/************* afficher tout les Hotels ********/
                            clrscr();
                            clrscr();
                            Color(writting_color,4);
                            gotoxy(2,2);
                            printf("Hotel\t\t\t\tQuartier\t\tcapacite\t\tdisponibles");
                            afficher_listeHotels(HOTELS);
                            getch();
                            break;
                    case 3 : /************ afficher les presonne en Q *****/
                            clrscr();
                            parC = HOTELS->Head;
                            while(parC != NULL)
                            {
                                gotoxy(positionH+30,positionV-2);Color(writting_color,12);printf("Hotel %s",parC->DATA.Nom);
                                afficher_ToutPesonne(parC->Contacts);
                                printf("\n\ntapez entrer pour continuer ");
                                getch();
                                clrscr();
                                parC = parC->Hotel_suivant;
                             }
                             getch();
                             break;

                    case 4 :  /*********** ajouter un personne a la quarantaine ************/
                            clrscr();
                            pc = creer_Contact();
                            gotoxy(positionH,positionV+10);Color(printing_color,0);printf("Nom Du Contaminateur          : ");
                            fflush(stdin);
                            Color(writting_color,0);gets(pc->DATA.contaminateurN);
                            gotoxy(positionH,positionV+11);Color(printing_color,0);printf("Prenom Du Contaminateur       : ");
                            Color(writting_color,0);gets(pc->DATA.contaminateurP);
                            FindHotel = Recherche_ToAddHOTEL(HOTELS, pc->DATA.CodePostal, pc->DATA.boulvard);


                            if(FindHotel != NULL && FindHotel->DATA.Disponibilte > 0)
                            {
                                AjouterContactToHotel(FindHotel, pc->DATA);
                                Color(0,11);printf("\n%s %s ===> Hotel %s",pc->DATA.Nom,pc->DATA.Prenom,FindHotel->DATA.Nom);
                            }
                            else
                            {
                                FindHotel = choixDeHotelpourUncontact(HOTELS);
                                if(FindHotel != NULL)
                                {AjouterContactToHotel(FindHotel, pc->DATA);
                                Color(0,11);printf("\n%s %s ===> Hotel %s",pc->DATA.Nom,pc->DATA.Prenom,FindHotel->DATA.Nom);}

                            }
                            getch();
                            break;
                    case 5 :/*********** chercher les contacts d'un patient *******/
                            clrscr();
                            Color(printing_color,0);printf("Nom    : ");
                            fflush(stdin);
                            Color(writting_color,0);gets(Nom);
                            Color(printing_color,0);printf("Prenom : ");
                            Color(writting_color,0);gets(Prenom);
                            contactsUnPatient(HOTELS,Nom,Prenom);
                            getch();
                            break;
                    case 6 : /*********** Suppression d'une personne *******/
                            clrscr();
                            Color(printing_color,0);printf("Nom    : ");
                            fflush(stdin);
                            Color(writting_color,0);gets(Nom);
                            Color(printing_color,0);printf("Prenom : ");
                            Color(writting_color,0);gets(Prenom);
                            pc = rechercher_personne(HOTELS,Nom,Prenom);
                            FindHotel = rechercher_Hotel(HOTELS,Nom,Prenom);
                            if(FindHotel != NULL)
                            {
                              if(pc != NULL)
                            {
                                clrscr();
                                Color(writting_color,12);gotoxy(PositionMenuPrincipalH+10,PositionMenuPrincipalV-8);printf("Hotel %s",FindHotel->DATA.Nom);
                                afficher_personneContact(pc, 2);
                                if(supprimer_Personne(FindHotel, pc))
                                    {Color(titles1_color,0);printf("\n\tsuppression Avec Succer !");}
                                else
                                    {gotoxy(positionH,positionV+5);Color(4,0);printf("Cette personne encore de traitement  !");}
                            }
                            else
                                {Color(titles1_color,0);printf("Patient Introuvable !");}
                            }
                            else
                                {Color(titles1_color,0);printf("Patient Introuvable !");}
                            getch();
                            break;
                    case 7 : /*********** Modification de l'etat d'une personne *******/
                            clrscr();
                            Color(printing_color,0);printf("Nom    : ");
                            fflush(stdin);
                            Color(writting_color,0);gets(Nom);
                            Color(printing_color,0);printf("Prenom : ");
                            Color(writting_color,0);gets(Prenom);
                            pc = rechercher_personne(HOTELS,Nom,Prenom);
                            FindHotel = rechercher_Hotel(HOTELS,Nom,Prenom);
                            if(FindHotel != NULL)
                            {
                                if(pc != NULL)
                                modification_etatv(FindHotel, pc);
                                else
                                {Color(titles1_color,0);printf("Patient Introuvable !");}
                            }
                            else
                                {Color(titles1_color,0);printf("Patient Introuvable !");}
                            getch();
                            break;
                    case 8 : /******** modifier Un Hotel ***********/
                            clrscr();
                            Color(printing_color,0);printf("Nom         : ");
                            fflush(stdin);
                            Color(writting_color,0);gets(Nom);
                            Color(printing_color,0);printf("Code Postal : ");
                            Color(writting_color,0);scanf("%d",&age);        /** variable age comme CP **/
                            FindHotel = Recherche_HotelByName(HOTELS,Nom,age);
                            if(FindHotel != NULL)
                            {
                                clrscr();
                                Color(writting_color,12);gotoxy(PositionMenuPrincipalH+10,PositionMenuPrincipalV-8);printf("Hotel %s",FindHotel->DATA.Nom);
                                Modification_Hotel(FindHotel);
                                Color(titles1_color,0);printf("\tModification Avec Succer !");
                                getch();
                            }
                            else
                            {
                                gotoxy(positionH+20,positionV);Color(titles1_color,0); printf("Cet Hotel N'existe Pas ! Ressayer ");
                                getch();
                            }
                            break;
                    }
                }while(choix != 0);
            }

    }

    return 0;
}

