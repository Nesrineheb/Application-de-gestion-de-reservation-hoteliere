#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <conio.h>
#include"conio2.h"
#include"Tp_LLC.h"
#include <time.h>


int main()
{
     // Faire un cadre avec des caractéres spéciaux
    int j,k,a,h,xx;
    gotoxy(10,1);
    wprintf(L"%1c",120);
    for (j=0;j<60;j++)
    {
        wprintf(L"%1c",120);
    }
    h=wherex();
    wprintf(L"%1c",120);
    printf("\n");
    for (j=0;j<10;j++)
    {
        gotoxy(10,j+2);
        wprintf(L"%1c",120);
    }
    a=wherey();
    for (j=0;j<10;j++)
    {
        gotoxy(h,2+j);
        wprintf(L"%1c",120);
    }
    gotoxy(h,j+2);
    wprintf(L"%1c",120);
    gotoxy(11,j+2);
    for (j=0;j<60;j++)
    {
        wprintf(L"%1c",120);
    }
    gotoxy(10,12);
    wprintf(L"%1c",120);

    // Ecrire le titre cilgnotant dans le cadre

    j=0;
    do
    {
        textbackground(WHITE);
        textcolor(j);
        delay(100);
        gotoxy(12,5);
        wprintf(L" Bienvenu dans notre application d'agence de voyage \n",130,130);
        gotoxy(28,7);
        printf("<< ESI agency ''gestion hoteleri''>>");
        if (j!=14) j++;
        else j=0;
    }
    while(!kbhit());

    // Cesser de clignoter en appuyant sur une touche qlq
    // Ecrire les infos liés au tp

    system("color f0");
    gotoxy(25,5);
    wprintf(L"TP-1-:  Liste lineaire chainee\n",130,130);
    gotoxy(28,7);
    printf("<< agence de voyage>>");
    gotoxy(19,15);
    delay(500);
    wprintf(L"Realis%lc par:  Hebbadj Nesrine &  Chouadera Yasser",130);
    gotoxy(30,17);
    delay(500);
    wprintf(L"Encadr%lc par: Mme KACET",130);
    gotoxy(17,20);
    delay(300);

    // Barre de chargement

    printf("Chargement: ");
    for (k=0;k<10;k++)
    {
        delay(100);
        printf("\333\333\333");
        xx=wherex();
        gotoxy(61,20);
        printf("%d %%",(k+1)*10);
        gotoxy(xx,20);
    }
    maillona *tetea ;
int choix,test,sortir,typ;
    system("color FC");
    charger_reservation(&tetea);
menu:
    system("mode  350, 200");
    debutTP();
    Color(15,0);
    scanf("%d",&choix);
    Color(15,7);
    switch (choix)
    {
    case 1 :
    {
        system("cls") ;
        printf("\t\t\t\t");
        Color(15,12);
        printf("\n");
         printf("                ====================================================\n");
         printf("                         Vous avez fait le choix numero 1 \n");
         printf("                ====================================================\n");

        printf(" *********************** Charger les reservations depuis un fichier Texte ******************\n\n\n");
        printf("Voulez-vous charger les reservations?\n\n");
        textcolor(4);
        printf("\t\t\t\t");
         Color(15,12);
        printf("OUI : 1");
        Color(15,12);
        printf("\t\t\t\t\t");
         Color(15,12);
        printf("NON : 0");
        Color(15,12);
        printf("\n\n\t\t\t\t\t\t\t");
        Color(15,12);
        scanf("%d",&test);
        if (test==1)
        {
            charger_reservation(&tetea);
           textcolor(4);
            printf("\n\n");
            printf("\t\t\t\t\t\t");
            textcolor(4);
            printf("Chargement avec succes!");
        }
        else printf(" ");
         Color(15,12);
        printf("\n\n\n\t\t");
         Color(15,12);
        printf("MENU");
         Color(15,12);
        printf(" : 1\t\t\t\t\t\t");
        Color(15,12);
        printf("SORTIR DU PROGRAMME");
        Color(15,12);
        printf(" : 0 \n\t\t\t\t\t\t\t");
         Color(15,12);
        scanf("%d",&sortir);
        if (sortir==1) goto menu ;
        else
        {
            system("cls");
            system("pause");
        }
        break;
    }
    case 2 :
    {
        system("cls") ;
        printf("\t\t\t\t");
         Color(15,12);

         printf("\n");
         printf("                ====================================================\n");
         printf("                         Vous avez fait le choix numero  02 \n");
         printf("                ====================================================\n");

        printf("*********************** Sauvegarder les réservations dans un fichier texte******************** \n\n\n");
        printf("Voulez-vous sauvegarder les reservations?\n\n");
         Color(15,12);
        printf("\t\t\t\t");
        Color(15,12);
        printf("OUI : 1");
        Color(15,12);
        printf("\t\t\t\t\t");
        Color(15,12);
        printf("NON : 0");
         Color(15,12);
        printf("\n\n\t\t\t\t\t\t\t");
        Color(15,12);
        scanf("%d",&test);
        if (test==1)
        {
            sauvgarder_reservation(tetea);
             Color(15,12);
            printf("\n\n");
            printf("\t\t\t\t\t\t");
             Color(15,12);
            printf(" la Sauvegardation  a ete effectue avec succes!");
        }
        else printf(" ");
         Color(15,12);
        printf("\n\n\n\t\t");
        Color(15,12);
        printf("MENU");
         Color(15,12);
        printf(" : 1\t\t\t\t\t\t");
        Color(15,12);
        printf("SORTIR DU PROGRAMME");
        Color(15,12);
        printf(" : 0 \n\t\t\t\t\t\t\t");
         Color(15,12);
        scanf("%d",&sortir);
        if (sortir==1) goto menu ;
        else
        {
            system("cls");
            system("pause");
        }
        break;
    }
    case 3:
    {
        system("cls") ;
        system("mode 120, 9001");
        printf("\t\t\t\t");
        Color(15,12);
         printf("\n");
         printf("                ====================================================\n");
         printf("                         Vous avez fait le choix numero  03 \n");
         printf("                ====================================================\n");

        printf(" ***************************************Affichage du statut des reservations **********************************\n\n");
         Color(15,12);
        printf("\t\tVoulez-vous afficher les statut des reservations?\n\n");
        printf("\t\t\t\t");
         Color(15,12);
        printf("OUI : 1");
         Color(15,12);
        printf("\t\t\t\t\t");
         Color(15,12);
        printf("NON : 0\n");
        scanf("%d",&test);
        if (test==1)
        {
            afficher_reservation(tetea);
        }
        else printf(" ");
       Color(15,12);
        printf("\n\n\n\t\t");
        Color(15,12);
        printf("MENU");
        textcolor(0);
        printf(" : 1\t\t\t\t\t\t");
        Color(15,12);
        printf("SORTIR DU PROGRAMME");
        textcolor(0);
        printf(" : 0 \n\t\t\t\t\t\t\t");
        Color(15,12);
        scanf("%d",&sortir);
        if (sortir==1) goto menu ;
        else
        {
            system("cls");
            system("pause");
        }
        break;
    }
    case 4:
    {
        system("cls") ;
        system("mode 120, 9001");
        printf("\t\t\t\t");
        Color(15,12);
        printf("\n");
         printf("                ====================================================\n");
         printf("                         Vous avez fait le choix numero  04 \n");
         printf("                ====================================================\n");

        printf(" ********************* Inserer une nouvelle reservation**************************\n\n");
        printf("Voulez-vous inserer une reservations ?\n\n");
        textcolor(15);
        printf("\t\t\t\t");
        Color(15,12);
        printf("OUI : 1");
        Color(15,12);
        printf("\t\t\t\t\t");
        Color(15,12);
        printf("NON : 0");
       Color(15,12);
        printf("\n\n\t\t\t\t\t\t\t");
       Color(15,12);
        scanf("%d",&test);
        if (test==1)
        {
            inserer_reservation(tetea);
            Color(15,12);
            printf("\n\n");
            printf("\t\t\t\t\t\t");
            Color(15,12);
            printf(" Votre reservation  a ete effectuee avec succes!");
        }
        else printf(" ");
        Color(15,12);
        printf("\n\n\n\t\t");
        Color(15,12);
        printf("MENU");
        textcolor(0);
        printf(" : 1\t\t\t\t\t\t");
        Color(15,12);
        printf("SORTIR DU PROGRAMME");
        textcolor(0);
        printf(" : 0 \n\t\t\t\t\t\t\t");
       Color(15,12);
        scanf("%d",&sortir);
        if (sortir==1) goto menu ;
        else
        {
            system("cls");
            system("pause");
        }
        break;
    }
    case 5 :
    {
        system("cls") ;
        Color(15,9);
        printf("\t\t\t\t");
        Color(15,12);
         printf("\n");
         printf("                ====================================================\n");
         printf("                         Vous avez fait le choix numero  05 \n");
         printf("                ====================================================\n");

        printf(" ******************************* Modifier une Reservation*******************************\n");
        printf("Voulez vous changer une reservation completement ou juste la modifier?\n\n");
        printf("1-Changer la reservation: (entree 1)\t\t\t\t");
        printf("2-Modifier la reservation: (entre 0)\n\t\t\t\t");
        scanf("%d",&choix);
        if (choix==1)
        {
            modifi(tetea);
        }
        else
        {
            modifi_simple(tetea);
        }
        Color(15,12);
        printf("\t\t\t\t");
       Color(15,12);
        printf("  Votre modification  a ete terminee!\n");
        Color(15,12);
        printf("\n\n\n\t\t");
        Color(15,12);
        printf("MENU");
        textcolor(0);
        printf(" : 1\t\t\t\t\t\t");
        Color(15,12);
        printf("SORTIR DU PROGRAMME");
        textcolor(0);
        printf(" : 0 \n\t\t\t\t\t\t\t");
        Color(15,12);
        scanf("%d",&sortir);
        if (sortir==1) goto menu ;
        else
        {
            system("cls");
            system("pause");
        }
        break;
    }

    case 6 :
    {
        system("cls") ;
       Color(15,12);
        printf("\t\t\t\t");
        Color(15,12);
        printf("\n");
         printf("                ====================================================\n");
         printf("                         Vous avez fait le choix numero  06 \n");
         printf("                ====================================================\n");

        printf(" ****************************** Supprimer une Reservation****************************\n");
         Color(15,12);
        printf("\t\t\t\t\t");
        Color(15,12);
        printf(" La Reservation a ete supprimee!");
        printf("Bonne jourenee!!*_*");
        Color(15,12);
        printf("\n\n\n\t\t");
        Color(15,12);
        printf("MENU");
        textcolor(0);
        printf(" : 1\t\t\t\t\t\t");
        Color(15,12);
        printf("SORTIR DU PROGRAMME");
        textcolor(0);
        printf(" : 0 \n\t\t\t\t\t\t\t");
       Color(15,12);
        scanf("%d",&sortir);
        if (sortir==1) goto menu ;
        else
        {
            system("cls");
            system("pause");
        }
        break;
    }

    case 7 :
    {
        system("cls") ;
        Color(15,12);
        printf("\t\t\t\t");
        Color(15,12);
        printf("\n");
         printf("                ====================================================\n");
         printf("                         Vous avez fait le choix numero  7 \n");
         printf("                ====================================================\n");

        printf(" ********************************** Rechercher une chambre libre selon son type********************** \n\n");
        int n;
        printf("1- rechercher une chambre libre par ville\n ");
        printf("2-rechercher une chambre  libre dans un hotel  precis \n ");
        printf("3-Rechercher une chambre libre  ayant le plus petit prix\n\n");
        printf("veuillez saisir votre choix svp\n");
        scanf("%d",&n);
        switch (n)
        {
        case 1 :
        {
            printf("Donner le type de la chambre ou souhaiter vous effectuez votre reservation   \n");
            printf("1-chambre individuelle (choisit )1\n");
            printf("2-chambre a deux (choisit 2)\n");
erreur1:
            scanf("%d",&typ);
            switch (typ)
            {
            case 1 :
            {
                rech_A1_ville(tetea);
                break;
            }
            case 2 :
            {
                rech_A2_ville(tetea);
                break;
            }
            default :
            {
                printf("Re-donner le type de la chambre   \n");
                goto erreur1;
            }
            }break;
        }
        case 2 :
        {
           printf("Donner le type de la chambre  \n");
            printf("1-chambre individuelle (choisit 1)\n");
            printf("2-chambre a deux (choisit 2)\n");
erreur2:
            scanf("%d",&typ);
            switch (typ)
            {
            case 1 :
            {
                rech_A1_hotel(tetea);
                break;
            }
            case 2 :
            {
                rech_A2_hotel(tetea);
                break;
            }
            default :
            {
                printf("Re-donner le type de la chambre (Chambre a un : 1 \t\t\t Chambre a deux : 2) \n");
                goto erreur2;
            }
            }
        }break;
        case 3 :
        {
            printf("Donner le type de la chambre  \n");
            printf("1-chambre individuelle (choisit 1)\n");
            printf("2-chambre a deux (choisit 2)\n");
erreur3:
            scanf("%d",&typ);
            switch (typ)
            {
            case 1 :
            {
                rechA1_prix(tetea);
                break;
            }
            case 2 :
            {
                rechA2_prix(tetea);
                break;
            }
            default :
            {
                printf("Re-donner le type de la chambre (Chambre a un : 1 \t\t\t( Chambre a deux : 2) \n");
                goto erreur3;
            }
            }
        }break;
        }
         Color(15,9);
        printf("\n\n\n\t\t");
        Color(15,12);
        printf("MENU");
        textcolor(0);
        printf(" : 1\t\t\t\t\t\t");
         Color(15,9);
        printf("SORTIR DU PROGRAMME");
        textcolor(0);
        printf(" : 0 \n\t\t\t\t\t\t\t");
          Color(15,9);
        scanf("%d",&sortir);
        if (sortir==1) goto menu ;
        else
        {
            system("cls");
            system("pause");
        }
        break;

    }


    case 8 :
    {
        system("cls") ;
         Color(15,9);
        printf("\t\t\t\t");
        Color(15,12);
        printf("\n");
         printf("                ====================================================\n");
         printf("                         Vous avez fait le choix numero 08 \n");
         printf("                ====================================================\n");

        printf(" ****************************** Rechercher la Reservation effectuee par une personne « Nom » ***************************\n\n");
        rechercher_nom(tetea);
           Color(15,9);
        printf("\n\n\n\t\t");
        Color(15,12);
        printf("MENU");
        textcolor(0);
        printf(" : 1\t\t\t\t\t\t");
          Color(15,9);
        printf("SORTIR DU PROGRAMME");
        textcolor(0);
        printf(" : 0 \n\t\t\t\t\t\t\t");
          Color(15,9);
        scanf("%d",&sortir);
        if (sortir==1) goto menu ;
        else
        {
            system("cls");
            system("pause");
        }
        break;
    }

    case 9:
    {
        system("cls") ;
          Color(15,9);
        printf("\t\t\t\t");
        Color(15,12);
        printf("\n");
         printf("                ====================================================\n");
         printf("                         Vous avez fait le choix numero 9 \n");
         printf("                ====================================================\n");

        printf(" ********************************* Rajouter un hotel******************* \n\n");
        ajouter_hotel(&tetea);
          Color(15,9);
        printf("\n\n\t\t\t\t\  Votre nouvelle hotel a ete ajouter .A bien tot*_*!");
        Color(15,12);
        printf("\n\n\n\t\t");
        Color(15,12);
        printf("MENU");
        textcolor(0);
        printf(" : 1\t\t\t\t\t\t");
        Color(15,12);
        printf("SORTIR DU PROGRAMME");
        textcolor(0);
        printf(" : 0 \n\t\t\t\t\t\t\t");
        Color(15,12);
        scanf("%d",&sortir);
        if (sortir==1) goto menu ;
        else
        {
            system("cls");
            system("pause");
        }
        break;
    }

    case 10:
    {
        system("cls") ;
        Color(15,12);
        printf("\t\t\t\t");
        Color(15,12);
        printf("\n");
         printf("                ====================================================\n");
         printf("                         Vous avez fait le choix numero 10 \n");
         printf("                ====================================================\n");

        printf("10- Supprimer un hotel  \n\n");
        supprimer_hotel(tetea);
        Color(15,12);
        printf("\n\n\t\t\t\t\tSupprime avec succes!");
       Color(15,12);
        printf("\n\n\n\t\t");
        Color(15,12);
        printf("MENU");
        textcolor(0);
        printf(" : 1\t\t\t\t\t\t");
        Color(15,12);
        printf("SORTIR DU PROGRAMME");
        textcolor(0);
        printf(" : 0 \n\t\t\t\t\t\t\t");
        Color(15,12);
        scanf("%d",&sortir);
        if (sortir==1) goto menu ;
        else
        {
            system("cls");
            system("pause");
        }
        break;
    }
    case 11 :
    {
        system("cls") ;
        Color(15,12);
         printf("\n");
         printf("                ====================================================\n");
         printf("                         Vous avez fait le choix numero 11 \n");
         printf("                ====================================================\n");

        date_fin(tetea);
        Color(15,9);
        printf("\n\n\n\t\t");
        printf("MENU");
        textcolor(0);
        printf(" : 1\t\t\t\t\t\t");
         Color(15,12);
        printf("SORTIR DU PROGRAMME");
        textcolor(0);
        printf(" : 0 \n\t\t\t\t\t\t\t");
         Color(15,12);
        scanf("%d",&sortir);
        if (sortir==1) goto menu ;
        else
        {
            system("cls");
            system("pause");
        }
        break;
    }
    case 12:
    {
        system("cls") ;
        Color(15,12);
        printf("\t\t\t\t");
        Color(15,12);
         printf("\n");
         printf("                ====================================================\n");
         printf("                         Vous avez fait le choix numero 12 \n");
         printf("                ====================================================\n");

        printf("********************************  Votre liste sera trier  par ordre alphabetique en quelque instant ************************* \n\n");
        printf("mercie de vous patientez...");
        tri_bille(tetea);
        Color(15,12);
        delay(100);
        printf("\t\t\t\t\t");
        loading();
        printf("\n\n\t\t\t\t\t Le trie des liste a ete effectue avec succes!\n\n\n\t\t\t");
        Color(15,12);
        printf("MENU");
        textcolor(0);
        printf(" : 1\t\t\t\t\t\t");
        Color(15,12);
        printf("SORTIR DU PROGRAMME");
        textcolor(0);
        printf(" : 0 \n\t\t\t\t\t\t\t");
        Color(15,12);
        scanf("%d",&sortir);
        if (sortir==1) goto menu ;
        else
        {
            system("cls");
            system("pause") ;
        }
        break;
    }

    }
    return 0;
}
