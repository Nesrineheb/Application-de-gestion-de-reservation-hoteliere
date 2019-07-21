#include<windows.h>
#include <string.h>
#include<stdlib.h>
#include <stdio.h>
#include <conio.h>
#include"conio2.h"

/******maillon--------C  ( les chambre) **********************/
typedef struct maillonc
{
   int num;
   int typ;
   char statut[20];
   char date_debut[20];
   char date_fin[20];
   char nom[20];
   int prix;
    struct maillonc *Suivc;
}maillonc;
/****maillon-------------B       (les hôtels)    *************/

typedef struct maillonb
{
   char nomhotel[20];
    char ville[20];
    int capach;
    int nb_ch_libre;
    int nb_ch_occupe;
    struct maillonc *tetl;
    struct maillonc *teto;
    struct maillonb *Suivb;
}maillonb;
/******maillon--------A   ( les lettre de l'alphabet)**********************/
typedef struct maillona
{
  char alpha[25];
  struct maillonb *tete_hotel;
  struct maillona *Suiva;
}maillona;


///**********************************************************************///
///                          machine abstraite  de maillon _____C        ///
///**********************************************************************///
/*structure**********************/
struct maillonc *Allouer ();
void remp_LLC_a(maillona**tete,int n);
void liberer(maillonc *tete);
struct maillonc *Suivant(  struct maillonc *P);
void Aff_Adrc( struct maillonc *P,  struct maillonc *Q);
/*remplier******************/
void affnum(struct maillonc *P, int v);
void afftyp(struct maillonc *P, int v);
void affstatut(struct maillonc *P, char ch[20]);
void affdated(struct maillonc *p, char ch[20]);
void affdatef(struct maillonc *p, char ch[20]);
void affprix(struct maillonc *P, int v);
void affnom(struct maillonc *P,char ch[20]);
void taper(int n);
/*valeurs**************************/
int valnum( struct maillonc *P);
int valtyp( struct maillonc *P);
int valprix( struct maillonc *P);
int valnbchlibre( struct maillonb *p);
int valnboccupe( struct maillonb *p);
char* valstatut( struct maillonc *P);
char* valnom(struct maillonc *P);
/*remplir llc de maillion c ***********/
void remp_LLC_c(maillonc* *tete,int n);
/*AFFICHER  llc de maillion c ***********/
void affich_LLC_c(maillonc* tete);

///**********************************************************************///
///                          machine abstraite  de maillon _____B       ///
///**********************************************************************///
/*structure**********************/
struct maillonb *Allouerb();
void libererb(maillonb *tete);
/*remplier******************/
void affcap(struct maillonb *P, int v);
void affnbchlibre(struct maillonb *P, int v);
void affnboccupe(struct maillonb *P, int v);
void aff_ville(struct maillonb *P, char ch[20]);
void aff_nomh(struct maillonb *P, char ch[20]);
/*valeurs**************************/
int valcap( struct maillonb *P);
int valnbchlibre( struct maillonb *P);
int valnboccupe( struct maillonb *P);
char* val_ville( struct maillonb *P);
char* val_nomh( struct maillonb *P);
/**********   remplir LLC---b*/
void remp_LLC_b(maillonc **tete,int n);

///**********************************************************************///
///                          machine abstraite  de maillon _____A       ///
///**********************************************************************///
/*structure**********************/
struct maillona *Allouera ();
void liberera(maillona *tete);
struct maillona *Suivanta(  struct maillona *P);
void Aff_Adra( struct maillona *P,  struct maillona *Q);
/*remplier******************/
void affalpha(struct maillona *P, char ch[0]);
void affnbhotel(struct maillona *P, int v);
/*valeurs**************************/
char* valalpha( struct maillona *P);
int valnbhotel( struct maillona *P);
//////////////////////*                  REMPLIR MAILLION     A                         *////////////
int lengh_annu(maillona *tete);
int lengh_hotels(maillonb *tete);

/***************************     les fonctions de   TP        ****************************************************/

void charger_reservation(maillona **tete);                    //1-charger reservation
/***************************************************************************************************************/
void sauvgarder_reservation(maillona *tete);                  //2-sauvgarder
/***************************************************************************************************************/
void afficher_reservation(maillona *tete);                    //3-affichage du statut de reservation
/***************************************************************************************************************/
void inserer_reservation(maillona *tete);                     //4-insertion
/***************************************************************************************************************/
void modifi(maillona*tete);                                   //5-1-modification total
/***************************************************************************************************************/
void modifi_simple(maillona*tete);                            //5-2 modification dans la chambre actuelle
/***************************************************************************************************************/
void supprimer_reserv(maillona *tete);                        //6-supprimer un ereservation
/***************************************************************************************************************/
void rech_A1_ville(maillona *tete);                           //7-A1-1-rechercher une chamre A1 a partir d'un nom
/***************************************************************************************************************/
void rech_A2_ville(maillona *tete);                           //7-A2-1-rechercher une chambre A1 a partir d'un nom
/***************************************************************************************************************/
void rech_A1_hotel(maillona *tete);                           //7-A1-2-rechercher une reservation A1 a partir d'un nom hotel
/***************************************************************************************************************/
void rech_A2_hotel(maillona *tete) ;                          //7-A2-2-rechercher une chambre A2 a partir d'un nom hotel
/***************************************************************************************************************/
int  rechA1_prix(maillona *tete);                             //7-A1-1-recherch la chambre A1 ayant le plus petit prix
/***************************************************************************************************************/
int  rechA2_prix(maillona *tete);                             //7-A2-1-recherch la chambre A2 ayant le plus petit prix
/***************************************************************************************************************/
void rechercher_nom(maillona *tete);                          //8-rechercher une reservation a partir d'un nom
/***************************************************************************************************************/
void ajouter_hotel(maillona **tete) ;                         //9-ajouter un hotel
/***************************************************************************************************************/
void supprimer_hotel(maillona *tete);                         //10-supprimer un hotel
/***************************************************************************************************************/
void date_fin(maillona *tete);
/***************************************************************************************************************/
void tri_bille(maillona *tetea);






/**Fonction affichage**/
void Color(int couleurDuTexte,int couleurDeFond);
void debutTP();
void loading();
