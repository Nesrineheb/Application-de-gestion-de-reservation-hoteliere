#include "Tp_LLC.h"
#include <string.h>
#include<windows.h>


///**********************************************************************///
///                          machine abstraite-----CHAMBRE                           ///
///**********************************************************************///
struct maillonc *Allouer ()
{
    return ((struct maillonc *) malloc( sizeof(struct maillonc )));
}
struct maillonc *Suivant(  struct maillonc *P)
{
    return( P->Suivc );
}
void liberer(maillonc *tete)
{
    maillonc *p,*q;
    p=tete;
    while(p!=NULL)
    {
        q=p->Suivc;
        free(p);
        p=q;
    }
}
void Aff_Adrc( struct maillonc *P,  struct maillonc *Q)
{
    P->Suivc = Q;
}
/*      remplir les champs du maillonc CHAMBRE    */
void affnum(struct maillonc *P, int v)                         /* 1- affecter LE NEMERO DE LA CHAMBRE    */
{
    P->num =v;
}
void affstatut(struct maillonc *P, char ch[20])                      /* 2- affecter  statut DE LA CHAMBRE    */
{
    strcpy(P->statut,ch);
}
void conversion(int j,char conv[0])
{

    switch (j)
    {
    case 0 :
    {
        conv[0]='0';
        break;
    };
    case 1 :
    {
        conv[0]='1';
        break;
    };
    case 2 :
    {
        conv[0]='2';
        break;
    };
    case 3 :
    {
        conv[0]='3';
        break;
    };
    case 4 :
    {
        conv[0]='4';
        break;
    };
    case 5 :
    {
        conv[0]='5';
        break;
    };
    case 6 :
    {
        conv[0]='6';
        break;
    };
    case 7 :
    {
        conv[0]='7';
        break;
    };
    case 8 :
    {
        conv[0]='8';
        break;
    };
    case 9 :
    {
        conv[0]='9';
        break;
    };
    }
}

void affdated(struct maillonc *p, char ch[20])     /*  3- affecter LA DATE DE DEBUT DE LA RESERVATION DE LA CHAMBRE      */
{

    strcpy(p->date_debut,ch);
}

void affdatef(struct maillonc *p, char ch[20])     /*  3- affecter LA DATE DE DEBUT DE LA RESERVATION DE LA CHAMBRE      */
{
    strcpy(p->date_fin,ch);
}
void affprix(struct maillonc *P, int v)                        /* 5- affecter le prix de la chambre   */
{
    P->prix =v;
}
void afftyp(struct maillonc *P, int v)                         /* 2- affecter  LE TYPE DE LA CHAMBRE      */
{
    P->typ =v;
}
void affnom(struct maillonc *p,char ch[20])
{
    sprintf(p->nom,ch);
}
void taper(int n)
{
    int i;
    for(i=0; i<n; i++)
    {
        printf("\n");
    }
}
void Color(int couleurDuTexte,int couleurDeFond)       /* 8-fonction d'affichage de couleurs */
{
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}
/********************************************************************************************************/
/** remplir la liste avec le tete @param :tete **/

//------- afficher les elements de la liste --------------------------------------------------**/
void affich_LLC_c(maillonc* tete)
{
    maillonc *p;
    p=tete;
    if(tete!=NULL)
    {
        while(p!=NULL)
        {
            Color(15,16);
            printf(" le nemero de votre chambre est : \t%d|",p->num);
            taper(1);
            printf(" le type de votre chambre est : \t%d|",p->typ);
            taper(1);
            printf(" le prix est : \t%d|",p->prix);
            taper(1);

            printf("void affich_LLC_c(maillonc* tete) LE STATUT DE VOTRE HAMBRE EST / \t%s|",p->statut);
            taper(1);

            printf("le nom de votre client est : \n\t");
            printf(" %s   |",valnom(p));

            printf("%d",valnum(p));
            taper(5);
            p=p->Suivc;
        }
        printf("°");
    }




    else
    {
        printf("le liste est vide mon ami ");
    }
}
/******                donner les valeurs des champs           ***************************/
int valnum( struct maillonc *P)
{
    return P->num ;
}
int valtyp( struct maillonc *P)
{
    return P->typ ;
}
int valprix( struct maillonc *P)
{
    return P->prix ;
}
char* valstatut( struct maillonc *P)
{
    return P->statut ;
}
char* valnom(struct maillonc *p)
{
    return p->nom;
}
char* val_dat_debut(struct maillonc *p)
{
    return p->date_debut;
}
char* val_dat_fin(struct maillonc *p)
{
    return p->date_fin;
}
/**********************      MAILLON-----HOTEL                     ******************************************/
/*                         structure  HOTEL                        **********************/
struct maillonb *Allouerb ()
{
    return ((struct maillonb *) malloc( sizeof(struct maillonb )));
}
struct maillonb *Suivantb(  struct maillonb *P)
{
    return( P->Suivb );
}
void libererb(maillonb *tete)
{
    maillonb *p;
    p=tete;

    liberer(p->tetl);
    liberer(p->teto);
    free(p);


}
void Aff_Adrcb( struct maillonb *P,  struct maillonb *Q)
{
    P->Suivb = Q;
}
/********    -----    REMPLIR MAILLON-HOTEL  ********************/
void affcap(struct maillonb *p,int h)
{
    p->capach=h;
}
void affnbchlibre(struct maillonb *p,int h)
{
    p->nb_ch_libre=h;
}
void affnboccupe(struct maillonb *p,int h)
{
    p->nb_ch_occupe=h;
}
void aff_nomh(struct maillonb *p,char ch[20])
{
    sprintf(p->nomhotel,ch); ;
}
void aff_ville(struct maillonb *p,char ch[20])
{
    sprintf(p->ville,ch); ;
}
/*----------------donner les valeurs des champs des valeurs de maillon -HOTEL -------****/
int valcap( struct maillonb *p)
{
    return p->capach;
}
int valnbchlibre( struct maillonb *p)
{
    return p->nb_ch_libre;
}
int valnboccupe( struct maillonb *p)
{
    return p->nb_ch_occupe;
}
char* val_ville( struct maillonb *p)
{
    return p->ville;
}
char* val_nomh(struct maillonb *p)
{
    return p->nomhotel;
}
/*remplir le maillon -------HOTEL */
void remp_LLC_b(maillonc **tete,int n)
{
    maillonc *p,*q;
    int i,typ,prix;


    i=1;
    *tete=NULL;
    for(i=1; i<=n; i++)
    {
        printf("\t entrer les donnes de %d chembre de votre hotel : \t  \n",i);
        p=Allouer();
        printf("la nouvelle chambre est allouer \n");
        affnum(p,i);
        printf("le nemero est : %d\n",valnum(p));
        affstatut(p,"libre");
        printf("le statut est %s ",valstatut(p));
        printf(" le type de la chambre A1 entrer 1 ou A2 entrer  2\n");
        scanf("%d",&typ);
        afftyp(p,typ);
        printf("le type que vous entrer est : %d \n",valtyp(p));
        printf(" entrer le prix de votre %d chambre\n",i);
        scanf("%d",&prix);
        affprix(p,prix);
        printf("le prix de %d est %d\n",i,valprix(p));
        affdated(p,"00/00/0000");
        affdatef(p,"00/00/0000");
        affnom(p,"vide");

        Aff_Adrc(p,NULL);
        if (*tete==NULL) *tete=p;
        else Aff_Adrc(q,p);
        q=p;
    }
}
///**********************************************************************///
///                          machine abstraite     DE MAILLON -------A                      ///
///**********************************************************************///
/*    les structures A  */
struct maillona *Allouera ()
{
    return ((struct maillona *) malloc( sizeof(struct maillona )));
}
struct maillona *Suivanta(  struct maillona *P)
{
    return( P->Suiva );
}
void liberera(maillona *tete)
{
    maillona *p,*q;
    p=tete;
    while(p!=NULL)
    {
        q=p->Suiva;
        free(p);
        p=q;
    }
}
void Aff_Adra( struct maillona*P,  struct maillona *Q)
{
    P->Suiva= Q;
}
/********      COMMENT REMPLIR MAILLON  A  ********************/
void affalpha(struct maillona *p,char ch[20])
{
    strcpy(p->alpha,ch);
}
/*---------donner les valeurs des champs des valeurs de maillon -B-------****/
char* valalpha( struct maillona *p)
{
    return p->alpha[0];
}
/*REMPLIR UN MAILLION A */

int lengh_annu(maillona *tete)
{
    maillona *p ;
    p=tete;
    int cpt=0;
    while(p!=NULL) cpt++;
    return cpt;
}
int lengh_hotels(maillonb *tete)
{
    maillonb *p ;
    p=tete;
    int cpt=0;
    while(p!=NULL) cpt++;
    return cpt;
}

void aff_jour(maillonc *p,char kiiiw[25])
{
    strcpy(p->date_debut,kiiiw);
}



/***************************     les fonctions de   TP        ****************************************************/
void charger_reservation(maillona **tete)            //1-charger les  reservations d'un fichier texte
{
    FILE *F;
    char nom[20],namep[20],vip[20];
    char vi[20];
    int  cap;
    char libre[5];
    strcpy(libre,"libre");
    char occupe[5];
    strcpy(occupe,"occupe");
    int  num;
    char sta[20];
    int typ;
    char nom_person[20];
    char dat_d[20];
    char dat_f[20];
    int prix;
    int nbl;
    int nbo;
    maillona *t,*u;
    maillonb *q;
    maillonc *r;
    F=fopen("a.txt","r");
    t=NULL;
    strcpy(namep,"impossible");
    strcpy(vip,"yasser");

    while(!feof(F))
    {
        fscanf(F,"%s ;%s ;%d ;%d ;%d ;%d ;%d ;%s ;%s ;%s ;%s ;%d  \n",nom,vi,&cap,&nbl,&nbo,&num,&typ,sta,nom_person,dat_d,dat_f,&prix);
        //printf("%s ;%s ;%d ;%d ;%d ;%d ;%d ;%s ;%s ;%s ;%s ;%d  \n",nom,vi,cap,nbl,nbo,num,typ,sta,nom_person,dat_d,dat_f,prix);


        r=Allouer();

        affnum(r,num);       //printf("le num est \t %d\n",valnum(r));
        affstatut(r,sta);    //printf("le statut de chambre est \t %d\n",valstatut(r));
        afftyp(r,typ);
        affnom(r,nom_person);
        affdated(r,dat_d);
        affdatef(r,dat_f) ;

        //printf("le typ de chambre est \t %d\n",valtyp(r));
        affprix(r,prix);     //printf("le prix de chambre est \t %d\n",valprix(r));
        if((strcmp(nom,namep)!=0) ||( strcmp(vi,vip)!=0) )
        {
            q=Allouerb();
            q->tetl=NULL;
            q->teto=NULL;
            aff_nomh(q,nom);  //printf("le nom delotel  est \t %s\n",val_nomh(q));
            aff_ville(q,vi); // printf("la ville  delotel  est \t %s\n",val_ville(q));
            affcap(q,cap);    //printf("le nb de capa     %d\n",valcap(q));
            affnbchlibre(q,nbl); //printf("hada houwa nb   %d \n\n\n",valnbchlibre(r));
            affnboccupe(q,nbo);  //printf("hada houwa nb   %d \n\n\n",valnboccupe(r));
            if(strcasecmp(sta,occupe)==0 )
            {
                q->teto=r;
            }
            else
            {
                q->tetl=r;
            }
            Aff_Adrc(r,NULL);
            if(t==NULL)
            {

                t=Allouera();
                affalpha(t,nom);   //printf("la lettre d annuire  est \t %c\n",valalpha(t));
                Aff_Adra(t,NULL);
                t->tete_hotel=q;
                Aff_Adrcb(q,NULL);
                *tete=t;
            }
            else
            {
                if(nom[0]==valalpha(t))
                {
                    Aff_Adrcb(q,t->tete_hotel);
                    t->tete_hotel=q;
                }
                else
                {
                    u=Allouera();
                    affalpha(u,nom);// printf("la lettre  est \t %c\n",valalpha(u));
                    Aff_Adra(t,u);
                    Aff_Adra(u,NULL);
                    u->tete_hotel=q;
                    Aff_Adrcb(q,NULL);
                    t=u;
                }

            }
        }

        else
        {
            if(strcasecmp(sta,occupe)==0)
            {
                if(q->teto==NULL)
                {
                    q->teto=r;
                    Aff_Adrc(r,NULL);
                }
                else
                {
                    Aff_Adrc(r,q->teto);
                    q->teto=r;
                }
            }
            else
            {

                if(q->tetl==NULL)
                {
                    q->tetl=r;
                    Aff_Adrc(r,NULL);
                }
                else
                {
                    Aff_Adrc(r,q->tetl);
                    q->tetl=r;
                }
            }

        }
        //printf("\n le nom prec est %s sgfdhgfdh  %s\n",namep,nom);
        strcpy(namep,nom);
        //printf("\n le nom suivant est %s\n",namep);
        strcpy(vip,vi);
        // printf("\n la ville suivante est %s\n",vip);

    }
    // printf("le while \t %d",cpt);

    fclose(F);
}
/***************************************************************************************************************/

void sauvgarder_reservation(maillona *tete)           //2-sauvgarder les reservations
{
    FILE *f2;
    f2=fopen("a.txt","w");
    maillona *t;
    maillonc *r,*y;
    maillonb *q;
    t=tete;
    while(t!=NULL)
    {

        q=t->tete_hotel;

        //printf(" lettre  :   %c\n",valalpha(t));
        while(q!=NULL)
        {
            r=q->tetl;
            y=q->teto;

            // printf("le nomhotel    %s |||  la ville  %s ||||   la capacite %d  |||| nb chambre libre : %d ||| nb chambre occupe %d ||| \n",val_nomh(q),val_ville(q),valcap(q),valnbchlibre(q),valnboccupe(q) );
            while(r!=NULL)
            {
                //printf(" nemero \%d  sta %s  typ %d la person %s date debut : %s date fin :%s prix %d\n",valnum(r),valstatut(r),valtyp(r),valnom(r),val_dat_debut(r),val_dat_fin(r),valprix(r));
                fprintf(f2,"%s ;%s ;%d ;%d ;%d ;%d ;%d ;%s ;%s ;%s ;%s ;%d  \n",val_nomh(q),val_ville(q),valcap(q),valnbchlibre(q),valnboccupe(q),valnum(r),valtyp(r),valstatut(r),valnom(r),val_dat_debut(r),val_dat_fin(r),valprix(r));
                r=Suivant(r);
            }
            while(y!=NULL)
            {
                //printf("nemero \%d  statut %s  typ %d la person %s date debut : %s date fin :%s prix %d\n",valnum(y),valstatut(y),valtyp(y),valnom(y),val_dat_debut(y),val_dat_fin(y),valprix(y));
                fprintf(f2,"%s ;%s ;%d ;%d ;%d ;%d ;%d ;%s ;%s ;%s ;%s ;%d  \n",val_nomh(q),val_ville(q),valcap(q),valnbchlibre(q),valnboccupe(q),valnum(y),valtyp(y),valstatut(y),valnom(y),val_dat_debut(y),val_dat_fin(y),valprix(y));
                y=Suivant(y);
            }
            q=Suivantb(q);
        }
        t=Suivanta(t);
    }
    fclose(f2);
}
/***************************************************************************************************************/
void afficher_reservation(maillona *tete)             //3-affichage du statut de reservation
{
    maillona *t;
    maillonb *q;
    maillonc *r,*y;
    t=tete;
    Color(0,9);
    while(t!=NULL)
    {
        q=t->tete_hotel;
        Color(4,9);
        printf("************************************************************************************************************************\n");
        Color(15,0);
        printf("la lettre est \%c",valalpha(t));
        while(q!=NULL)
        {
            Color(10,9);
            printf("\n====================================================================\n");
            r=q->tetl;
            y=q->teto;
            Color(0,15);
            printf(" le nom d'hotel: %s | la ville : %s | la capacite: %d | nb chambre libre: %d | nb chambre occupe: %d |\n",val_nomh(q),val_ville(q),valcap(q),valnbchlibre(q),valnboccupe(q) );
            Color(15,12);
            printf("Les reservations sont :\n");
            Color(0,9);
            while(y!=NULL)
            {

                printf("\nle numero: \%d | statut: %s | type:  %d | nom du client: %s | date debut : %s| date fin :%s| prix %d \n",valnum(y),valstatut(y),valtyp(y),valnom(y),val_dat_debut(y),val_dat_fin(y),valprix(y));
                y=Suivant(y);
            }
            q=Suivantb(q);
        }
        t=Suivanta(t);
    }

}
/***************************************************************************************************************/
void inserer_reservation(maillona *tete)            //4-insertion
{
    maillona *u;
    maillonb *p,*q;
    maillonc *prec,*r,*y;
    u=tete;
    prec=NULL;
    char nomh_inser[20];
    char nomv_inser[20];
    char nomper_inser[20];
    int num=1;
    char dd_insert[20];
    char df_insert[20];
    printf("  entrer le nom de l'hotel: ");
    scanf("%s",nomh_inser);
    printf("  entrer la ville  de l'hotel: ");
    scanf("%s",nomv_inser);
    printf("  entrer le numero de chambre: ");
    scanf("%d",&num);
    printf("  entrer le nom de person: ");
    scanf("%s",nomper_inser);
    printf("  entrer la date de debut: ");
    scanf("%s",dd_insert);
    printf("  entrer la date de fin: ");
    scanf("%s",df_insert);

    int trouve=0;
    int trouve1=0;

    while(u!=NULL )
    {
        if(valalpha(u) == nomh_inser[0])
        {
            trouve1=1;
            p=u->tete_hotel;
            while(p!=NULL)
            {

                if(strcmp(val_nomh(p),nomh_inser)==0 && strcmp(val_ville(p),nomv_inser)==0 )
                {

                    r=p->tetl;
                    y=p->teto;
                    while(r!=NULL  && trouve==0 )
                    {
                        if(num == valnum(r))
                        {
                            affstatut(r,"occupe");
                            affnom(r,nomper_inser);
                            affdated(r,dd_insert);
                            affdatef(r,df_insert);
                            affnbchlibre(p,valnbchlibre(p)-1);
                            affnboccupe(p,valnboccupe(p)+1);
                            if(prec==NULL)
                            {
                                trouve=1;
                                p->tetl=Suivant(r);
                                Aff_Adrc(r,y);
                                p->teto=r;
                            }
                            else
                            {
                                trouve=1;
                                Aff_Adrc(prec,Suivant(r));
                                Aff_Adrc(r,y);
                                p->teto=r;
                            }


                        }
                        prec=r;
                        r=Suivant(r);

                    }
                    if(trouve==0)
                    {
                        printf("la chambre deja occupee \n\n\n");
                    }

                }
                p=Suivantb(p);
            }
        }
        u=Suivanta(u);

    }
    if(trouve1==0) printf("il faut que votre hotel commence par une lettre \t ou \t un hotel qui existe ");
}
/***************************************************************************************************************/
void modifi(maillona*tete)                         //5-1-modification total
{
    maillona *u,*k;
    u=tete;
    k=tete;
    maillonb *p,*q;
    maillonc *r,*y,*prec;
    prec=NULL;

    char nomh_inser[20];
    char nomv_inser[20];
    char nomper_inser[20];
    int num=1;
    char dd_insert[20];
    char df_insert[20];
    char no[20];


    printf(" ******************************** modification d'une reservation ********************\n");
    printf("  entrer le nom de l'hotel de modification  : \t ");
    scanf("%s",nomh_inser);
    taper(2);
    printf("  entrer la ville  de l'hotel de modification  : \t ");
    scanf("%s",nomv_inser);
    taper(2);
    printf("  entrer le nom de person de modification: \t ");
    scanf("%s",nomper_inser);
    taper(2);
    printf("  entrer le numero de chambre de modification : \t ");
    scanf("%d",&num);
    taper(2);


    int trouve=0;
    int supp=0;

    while(u!=NULL )
    {
        p=u->tete_hotel;
        while(p!=NULL)
        {

            if(strcmp(val_nomh(p),nomh_inser)==0 && strcmp(val_ville(p),nomv_inser)==0 )
            {

                r=p->tetl;
                y=p->teto;
                while(y!=NULL  && trouve==0 )
                {
                    if(num == valnum(y)||strcasecmp(nomper_inser,valnom(y))==0)
                    {
                        supp=1;
                        affstatut(y,"libre");
                        affnom(y,"vide");
                        affdated(y,"00/00/0000");
                        affdatef(y,"00/00/0000");
                        if(prec==NULL)
                        {
                            trouve=1;
                            p->teto=Suivant(y);
                            Aff_Adrc(y,r);
                            p->tetl=y;
                        }
                        else
                        {
                            trouve=1;
                            Aff_Adrc(prec,Suivant(y));
                            Aff_Adrc(y,r);
                            p->tetl=y;
                        }
                    }
                    prec=y;
                    y=Suivant(y);

                }


            }
            p=Suivantb(p);
        }

        u=Suivanta(u);

    }
    if(trouve==0) printf("il faut que votre hotel commence par une lettre \t ou \t un hotel qui existe ");
    if(supp==1)
    {
        inserer_reservation(k);
    }



}
/***************************************************************************************************************/
void modifi_simple(maillona*tete)                  //5-2 modification dans la chambre actuelle
{
    maillona *u,*k;
    u=tete;
    k=tete;
    maillonb *p,*q;
    maillonc *r,*y,*prec;
    prec=NULL;

    char nomh_inser[20];
    char nomv_inser[20];
    char nomper_inser[20];
    char ch[20];
    int num=1;
    int num2=1;
    char dd_insert[20];
    char df_insert[20];
    char no[20];


    printf(" ******************************** modification    simple  d'une reservation ********************\n");
    printf("  entrer le nom de l'hotel de modification  : \t ");
    scanf("%s",nomh_inser);
    taper(2);
    printf("  entrer la ville  de l'hotel de modification  : \t ");
    scanf("%s",nomv_inser);
    taper(2);
    printf("  entrer le nom de person : \t ");
    scanf("%s",nomper_inser);
    taper(2);

    printf("  entrer le numero de chambre de modification : \t ");
    scanf("%d",&num);
    taper(2);
    int trouve=0;
    while(u!=NULL )
    {
        p=u->tete_hotel;
        while(p!=NULL)
        {
            if(strcmp(val_nomh(p),nomh_inser)==0 && strcmp(val_ville(p),nomv_inser)==0 )
            {
                r=p->tetl;
                y=p->teto;
                while(y!=NULL  && trouve==0 )
                {
                    if(num == valnum(y)||strcasecmp(nomper_inser,valnom(y))==0)
                    {

                        printf("la nouvelle person est : \t ");
                        scanf("%s",ch);
                        printf("entrer la nouvelle date de debut :\t  ");
                        scanf("%s",dd_insert);
                        printf("entrer la nouvelle date de fin :\t  ");
                        scanf("%s",df_insert);
                        affnom(y,ch);
                        affdated(y,dd_insert);
                        affdatef(y,df_insert);
                        affstatut(r,1);
                    }
                    y=Suivant(y);

                }
            }
            p=Suivantb(p);

        }
        u=Suivanta(u);
    }
    if(trouve==0) printf("il faut que votre hotel commence par une lettre \t ou \t un hotel qui existe ");
}
/***************************************************************************************************************/
void supprimer_reserv(maillona *tete)            //6-supprimer une reservation
{

    maillona *u,*k;
    u=tete;
    k=tete;
    maillonb *p,*q;
    maillonc *r,*y,*prec;
    prec=NULL;

    char nomh_inser[20];
    char nomv_inser[20];
    char nomper_inser[20];
    int num=1;
    char dd_insert[20];
    char df_insert[20];
    char no[20];


    printf(" ******************************** supprimer une reservation ********************\n");
    printf("  entrer le nom de l'hotel   : \t ");
    scanf("%s",nomh_inser);
    taper(2);
    printf("  entrer la ville  de l'hotel   : \t ");
    scanf("%s",nomv_inser);
    taper(2);
    printf("  entrer le nom de person de : \t ");
    scanf("%s",nomper_inser);
    taper(2);
    // printf("  entrer le numero de chambre de  : \t ");
    //  scanf("%d",&num);     taper(2);
    int trouve=0;
    while(u!=NULL )
    {
        p=u->tete_hotel;
        while(p!=NULL)
        {

            if(strcmp(val_nomh(p),nomh_inser)==0 && strcmp(val_ville(p),nomv_inser)==0 )
            {

                r=p->tetl;
                y=p->teto;
                while(y!=NULL  && trouve==0 )
                {
                    if(strcasecmp(nomper_inser,valnom(y))==0)
                    {
                        affstatut(y,"libre");
                        affnom(y,"...");
                        affdated(y,"00/00/0000");
                        affdatef(y,"00/00/0000");
                        affnbchlibre(p,valnbchlibre(p)+1);
                        affnboccupe(p,valnboccupe(p)-1);
                        if(prec==NULL)
                        {
                            trouve=1;
                            p->teto=Suivant(y);
                            Aff_Adrc(y,r);
                            p->tetl=y;
                        }
                        else
                        {
                            trouve=1;
                            Aff_Adrc(prec,Suivant(y));
                            Aff_Adrc(y,r);
                            p->tetl=y;
                        }

                    }
                    prec=y;
                    y=Suivant(y);

                }

            }
            p=Suivantb(p);
        }

        u=Suivanta(u);

    }
    if(trouve==0) printf("Il faut que votre hotel commence par une lettre \t ou \t un hotel qui existe ");



}
/***************************************************************************************************************/
/***** *******************  -les fonctions de recherche d'une chambre libre:::: ***** *********************************/
void rech_A1_ville(maillona *tete)                     //7-A1-1-rechercher une reservation a partir d'une ville
{

    char ville[20];
    int trouve=0;
    maillona *u;
    maillonb *p,*q;
    maillonc *r,*y;
    u=tete;
    printf(" ******************************** Rechercher une chambre libre A1 ********************\n");
    printf("  entrer la ville  : \t ");
    scanf("%s",ville);

    while(u!=NULL )
    {
        p=u->tete_hotel;
        while(p!=NULL)
        {
            if(strcasecmp(val_ville(p),ville)==0 && trouve==0 )
            {

                r=p->tetl;
                while(r!=NULL )
                {
                    if( valtyp(r)==1 && trouve==0)
                    {
                        trouve=1;
                        printf("------- La premiere chambre libre A1 dans la ville %s  ---------\n",val_ville(p));
                        printf(" \t L'hotel est :\t %s \n",val_nomh(p) );
                        printf(" \t La ville est :\t %s \n",val_ville(p) );
                        printf(" \t Le nemero de chambre  est :\t %d \n",valnum(r) );
                        printf(" \t Le prix  est :\t %d \n",valprix(r) );
                        taper(3);

                    }
                    r=Suivant(r);
                }
            }
            p=Suivantb(p);
        }
        u=Suivanta(u);
    }
    if(trouve==0) printf("Il n'est pas une chambre A1 dans LA VILLE  %s  ",ville);



}
/***************************************************************************************************************/
void rech_A2_ville(maillona *tete)                     //7-A2-1rechercher une reservation a partir d'une ville
{

    char ville[20];
    int trouve=0;
    maillona *u;
    maillonb *p,*q;
    maillonc *r,*y;
    u=tete;
    printf(" ******************************** Rechercher une chambre libre A2 ********************\n");
    printf("  entrer la ville  : \t ");
    scanf("%s",ville);

    while(u!=NULL )
    {
        p=u->tete_hotel;
        while(p!=NULL)
        {
            if(strcasecmp(val_ville(p),ville)==0 && trouve==0 )
            {

                r=p->tetl;
                while(r!=NULL )
                {
                    if( valtyp(r)==2 && trouve==0)
                    {
                        trouve=1;
                        printf("------- La premiere chambre libre A2 dans la ville %s  ---------\n",val_ville(p));
                        printf(" \t L'hotel est :\t %s \n",val_nomh(p) );
                        printf(" \t La ville est :\t %s \n",val_ville(p) );
                        printf(" \t Le nemero de chambre  est :\t %d \n",valnum(r) );
                        printf(" \t Le prix  est :\t %d \n",valprix(r) );
                        taper(3);

                    }
                    r=Suivant(r);
                }
            }
            p=Suivantb(p);
        }
        u=Suivanta(u);
    }
    if(trouve==0) printf("Il n'est pas une chambre A2 dans LA VILLE  %s  ",ville);



}
/***************************************************************************************************************/
void rech_A1_hotel(maillona *tete)                     //7-A1-2-rechercher une reservation a partir d'un nom hotel
{

    char hotel[20];
    int trouve=0;
    maillona *u;
    maillonb *p,*q;
    maillonc *r,*y;
    u=tete;
    printf(" ******************************** Rechercher une chambre libre A1 ********************\n");
    printf("  Entrer l'hotel  : \t ");
    scanf("%s",hotel);

    while(u!=NULL )
    {
        p=u->tete_hotel;
        while(p!=NULL)
        {
            if(strcasecmp(val_nomh(p),hotel)==0 && trouve==0 )
            {

                r=p->tetl;
                while(r!=NULL )
                {
                    if( valtyp(r)==1 && trouve ==0)
                    {
                        trouve=1;
                        printf("------- La premiere chambre libre A1 dans l'hotel %s  ---------\n",val_nomh(p));
                        printf(" \t La ville est :\t %s \n",val_ville(p) );
                        printf(" \t Le nemero de chambre  est :\t %d \n",valnum(r) );
                        printf(" \t Le prix  est :\t %d \n",valprix(r) );
                        printf("-----------------------------------------------------------------------------");
                        taper(3);

                    }
                    r=Suivant(r);
                }
            }
            p=Suivantb(p);
        }
        u=Suivanta(u);
    }
    if(trouve==0) printf("Il n'est pas une chambre A1 dans l'hotel  %s  ",hotel);



}
/***************************************************************************************************************/
void rech_A2_hotel(maillona *tete)                     //7-A2-2-rechercher une reservation a partir d'un nom hotel
{

    char hotel[20];
    int trouve=0;
    maillona *u;
    maillonb *p,*q;
    maillonc *r,*y;
    u=tete;
    printf(" ******************************** Rechercher une chambre libre A2 ********************\n");
    printf("  Entrer l'hotel  : \t ");
    scanf("%s",hotel);

    while(u!=NULL )
    {
        p=u->tete_hotel;
        while(p!=NULL)
        {
            if(strcasecmp(val_nomh(p),hotel)==0 && trouve==0 )
            {

                r=p->tetl;
                while(r!=NULL )
                {
                    if( valtyp(r)==2 && trouve ==0)
                    {
                        trouve=1;
                        printf("------- La premiere chambre libre A2 dans l'hotel %s  ---------\n",val_nomh(p));
                        printf(" \t La ville est :\t %s \n",val_ville(p) );
                        printf(" \t Le nemero de chambre  est :\t %d \n",valnum(r) );
                        printf(" \t Le prix  est :\t %d \n",valprix(r) );
                        printf("----------------------------------------------------------------------------");
                        taper(3);

                    }
                    r=Suivant(r);
                }
            }
            p=Suivantb(p);
        }
        u=Suivanta(u);
    }
    if(trouve==0) printf("Il n'est pas une chambre A2 dans l'hotel  %s  ",hotel);



}
/***************************************************************************************************************/
int  rechA1_prix(maillona *tete)                       //7-A1-3-recherch la chambre ayant le plus petit prix
{
    int prix_p=999999;
    char hotel[20];
    int trouve=0;
    maillona *u;
    maillonb *p,*q;
    maillonc *r,*y,*s;
    u=tete;
    int prix;
    int som;
    printf(" ******************************** Rechercher une chambre libre A1 ********************\n");
    while(u!=NULL )
    {
        p=u->tete_hotel;
        while(p!=NULL)
        {
            r=p->tetl;
            while(r!=NULL )
            {
                if( valtyp(r)==1 && valprix(r)<prix_p)
                {
                    trouve=1;
                    prix=valprix(r);
                    q=p;
                    s=r;

                }
                prix_p=valprix(r);
                r=Suivant(r);
            }
            p=Suivantb(p);
        }
        u=Suivanta(u);
    }
    if(trouve==1)
    {
        printf("------- la premiere chambre libre A1 ayant le plus petit prix est   ---------\n");
        printf("\t l'hotel est :\t %s\n",val_nomh(q));
        printf(" \t la ville est :\t %s \n",val_ville(q) );
        printf(" \t le nemero de chambre  est :\t %d \n",valnum(s) );
        printf(" \t le plus petit prix  est :\t %d \n",valprix(s) );
        taper(3);
    }
    if(trouve==0) printf("Il n'est pas une chambre A1 ayant le plus petit prix  %s  ");

    return prix;


}
/***************************************************************************************************************/
int  rechA2_prix(maillona *tete)                       //7-A2-3-recherch la chambre ayant le plus petit prix
{
    int prix_p=999999;
    char hotel[20];
    int trouve=0;
    maillona *u;
    maillonb *p,*q;
    maillonc *r,*y,*s;
    u=tete;
    int prix;
    int som;
    printf(" ******************************** Rechercher une chambre libre A2 ********************\n");
    while(u!=NULL )
    {
        p=u->tete_hotel;
        while(p!=NULL)
        {
            r=p->tetl;
            while(r!=NULL )
            {
                if( valtyp(r)==2 && valprix(r)<prix_p)
                {
                    trouve=1;
                    prix=valprix(r);
                    q=p;
                    s=r;

                }
                prix_p=valprix(r);
                r=Suivant(r);
            }
            p=Suivantb(p);
        }
        u=Suivanta(u);
    }
    if(trouve==1)
    {
        printf("------- La premiere chambre libre A2 ayant le plus petit prix est   ---------\n");
        printf("\t L'hotel est :\t %s\n",val_nomh(q));
        printf(" \t La ville est :\t %s \n",val_ville(q) );
        printf(" \t Le nemero de chambre  est :\t %d \n",valnum(s) );
        printf(" \t Le plus petit prix  est :\t %d \n",valprix(s) );
        printf("---------------------------------------------------------------------------------");
        taper(3);
    }
    if(trouve==0) printf("Il n'est pas une chambre A1 ayant le plus petit prix  %s  ");

    return prix;


}
/***************************************************************************************************************/
void rechercher_nom(maillona *tete)                     //8-rechercher une reservation a partir d'un nom
{

    char nomper_inser[20];
    int trouve=0;
    maillona *u;
    maillonb *p,*q;
    maillonc *r,*y;

    u=tete;
    printf(" ******************************** Rechercher une reservation ********************\n");
    printf("  Entrer le nom de person de : \t ");
    scanf("%s",nomper_inser);
    taper(2);

    while(u!=NULL )
    {
        p=u->tete_hotel;
        while(p!=NULL)
        {
            r=p->tetl;
            y=p->teto;
            while(y!=NULL  && trouve==0 )
            {
                if(strcasecmp(nomper_inser,valnom(y))==0)
                {
                    trouve=1;
                    printf("------- LA RESERVATION DE ms(***  %s  ***)  ---------\n",valnom(y));
                    printf(" \t L'hotel est :\t %s \n",val_nomh(p) );
                    printf(" \t La ville est :\t %s \n",val_ville(p) );
                    printf(" \t Le nemero de chambre  est :\t %d \n",valnum(y) );
                    printf(" \t Le type de la chambre reservee est :\t A%d \n",valtyp(y) );
                    printf(" \t La date de debut  est :\t %s \n",val_dat_debut(y) );
                    printf(" \t La date de fin  est :\t %s \n",val_dat_fin(y) );
                    printf(" \t Le prix  est :\t %d \n",valprix(y) );

                }
                y=Suivant(y);
            }
            p=Suivantb(p);
        }
        u=Suivanta(u);
    }
    if(trouve==0) printf("Il n'est pas de reservation dans notre liste d'hotel  ");



}
/***************************************************************************************************************/
void ajouter_hotel(maillona **tete)                     //9-ajouter un hotel
{



    char nom_h[20];
    printf("Entrer le nom d'hotel ajoute\n");
    scanf("%s",nom_h);
    char ville[20];
    printf("Entrer la ville d'hotel ajoute\n");
    scanf("%s",ville);
    int  cap;
    printf("Entrer la capacite h'hotel ajoute\n");
    scanf("%d",&cap);

    int  num;
    char sta[20];
    int typ;
    char nom_person[20];
    char dat_d[20];
    char dat_f[20];
    int prix,i;
    int trouve=0;


    maillona *t,*u,*j;
    maillonb *f,*p,*q,*prec;
    prec=NULL;
    maillonc *r,*y;
    t=*tete;
    j=*tete;
    p=Allouerb();
    aff_nomh(p,nom_h);
    aff_ville(p,ville);
    affcap(p,cap);
    p->teto=NULL;
    remp_LLC_b(&p->tetl,cap);

    while (t!=NULL && trouve==0)
    {
        q=t->tete_hotel;
        if(valalpha(t)==nom_h[0])
        {
            trouve=1;
            Aff_Adrcb(p,t->tete_hotel);
            t->tete_hotel=p;

        }
        t=Suivanta(t);
    }
    if(t==NULL && trouve==0)
    {

        trouve=1;

        u=Allouera();
        affalpha(u,nom_h);
        printf("La valeur du neveau annuaire est %c \n",valalpha(u));
        Aff_Adra(u,j);
        *tete=u;
        u->tete_hotel=p;


    }
    if(trouve==0) printf("Le nom d'hotel doit commencer par une lettre de (a..z)\n");



}
/***************************************************************************************************************/
void supprimer_hotel(maillona *tete)                    //10-supprimer un hotel
{
    maillona *u,*k,*prece;
    u=tete;
    k=tete;
    maillonb *p,*q,*prec;
    maillonc *b,*n;
    prec=NULL;
    p=NULL;
    char nomh_inser[20];
    char nomv_inser[20];
    int i=0;
    printf(" ********************************************************************** supprimer une reservation ****************************************************\n");
    printf("  Entrer le nom de l'hotel que vous voulez suprimer   : \t ");
    scanf("%s",nomh_inser);
    taper(2);
    printf("  Entrer la ville  de l'hotel  que vous voulez suprimer  : \t ");
    scanf("%s",nomv_inser);
    taper(2);
    int trouve=0;
    while(u!=NULL )
    {
        p=u->tete_hotel;
        while(p!=NULL && trouve==0)
        {
            if(strcmp(val_nomh(p),nomh_inser)==0 && strcmp(val_ville(p),nomv_inser)==0 )
            {

                trouve=1;
                b=p->tetl=NULL;
                n=p->teto=NULL;
                // while(b!=NULL)  {   free(b);    b=Suivant(b);  }
                //while(n!=NULL) {    free(n);    b=Suivant(n);   }
                if( prec==NULL)
                {
                    u->tete_hotel=Suivantb(p);
                    free(p);                                        ///

                }
                else
                {
                    Aff_Adrcb(prec,Suivantb(p));
                    p=NULL;
                }


            }
            else
            {
                prec=p;
                p=Suivantb(p);
            }
        }
        prece=u;
        u=Suivanta(u);
    }
    if(trouve==0)
    {
        printf("Il faut que votre hotel commence par une lettre \t ou \t un hotel qui existe     \n \t\t reessey ........\n\n ");
        supprimer_hotel(tete);
    }
}


/***************************************************************************************************************/
void tri_bille(maillona *tetea)
{
    int triee=0;
    maillona *temp;
    maillonb *p,*q,*s,*tete;
    p=NULL;
    s=NULL;
    q=NULL;
    temp=tetea;
    while (temp!=NULL)
    {
        tete=temp->tete_hotel;
        if(tete!=NULL)
        {
            triee=0;
            while(triee==0)
            {
                triee=1;
                p=tete ;
                q=Suivantb(p);
                while (q!=NULL)
                {
                    if (strcasecmp(val_nomh(p),val_nomh(q))>0)
                    {
                        s=Allouerb();
                        aff_nomh(s,val_nomh(p));
                        aff_ville(s,val_ville(p));
                        affcap(s,valcap(p));
                        affnbchlibre(s,valnbchlibre(p));
                        affnboccupe(s,valnboccupe(p));
                        s->tetl=p->tetl;
                        s->teto=p->teto;
                        affprix(s,valprix(p));

                        aff_nomh(p,val_nomh(q));
                        aff_ville(p,val_ville(q));
                        affcap(p,valcap(q));
                        affnbchlibre(p,valnbchlibre(q));
                        affnboccupe(p,valnboccupe(q));
                        p->tetl=q->tetl;
                        p->teto=q->teto;
                        affprix(p,valprix(q));

                        aff_nomh(q,val_nomh(s));
                        aff_ville(q,val_ville(s));
                        affcap(q,valcap(s));
                        affnbchlibre(q,valnbchlibre(s));
                        affnboccupe(q,valnboccupe(s));
                        q->tetl=s->tetl;
                        q->teto=s->teto;
                        affprix(q,valprix(s));
                        triee=0;
                    }
                    p=Suivantb(p);
                    q=Suivantb(q);
                }
            }

        }
        temp=Suivanta(temp);
    }
}

/***************************************************************************************************************/
void date_fin(maillona *tete)
{
    maillona *p=tete;
    maillonb *q=NULL;
    maillonc *r=NULL,*prec=NULL,*occ=NULL,*lib=NULL;
    maillonc *inter=NULL;
    int jour;
    int mois,annee;
    int trouve=0;
    SYSTEMTIME lyom;
    GetSystemTime(&lyom);
    while (p!=NULL)
    {
        q=p->tete_hotel;
        while (q!=NULL)
        {
            occ=q->tetl;
            lib=q->teto;
            r=lib;
            while (r!=NULL && trouve==0)
            {
                sscanf(val_dat_fin(r),"%d/%d/%d",&jour,&mois,&annee);
                if ((lyom.wYear==annee) && (lyom.wMonth==mois) && (lyom.wDay==jour))
                {
                    affstatut(r,"libre");
                    affnom(r,"...");
                    affdated(r,"00/00/0000");
                    affdatef(r,"00/00/0000");
                    affnbchlibre(q,valnbchlibre(q)+1);
                    affnboccupe(q,valnboccupe(q)-1);
                    trouve=1;
                    if (prec==NULL)
                    {
                        q->teto=Suivant(r);
                        Aff_Adrc(r,lib);
                        q->tetl=r;
                    }
                    else
                    {
                        Aff_Adrc(prec,Suivant(r));
                        Aff_Adrc(r,lib);
                        q->tetl=r;
                    }

                }
                prec=r;
                r=Suivant(r);
            }
            q=Suivantb(q);
        }
        p=Suivanta(p);
    }
}
/***************************************************************************************************************/
/***************************    MODULES AFFICHAGE    ***********************************************************/

void debutTP()                                      /// Affiche le menu du programme
{

    system("color FC");
    int i;
    textbackground(0);
    textcolor(BLACK);
    gotoxy(3,3);
    delay(78);
    printf("%c%c%c%c%c",219,219,219,219,219);
    gotoxy(3,4);
    delay(78);
    printf("%c%c",219,219);
    gotoxy(3,5);
    delay(78);
    printf("%c%c%c%c%c",219,219,219,219,219);
    gotoxy(3,6);
    delay(78);
    printf("%c%c",219,219);
    gotoxy(3,7);
    delay(78);
    printf("%c%c%c%c%c",219,219,219,219,219);
    gotoxy(9,3);
    delay(78);
    printf("%c%c%c%c%c\n\n\n\n",219,219,219,219,219);
    gotoxy(9,4);
    delay(78);
    printf("%c%c\n\n\n\n",219,219);
    gotoxy(9,5);
    delay(78);
    printf("%c%c%c%c%c\n\n\n\n",219,219,219,219,219);
    gotoxy(12,6);
    delay(78);
    printf("%c%c\n\n\n\n",219,219);
    gotoxy(9,7);
    delay(78);
    printf("%c%c%c%c%c\n\n\n\n",219,219,219,219,219);
    gotoxy(15,3);
    textcolor(WHITE);
    delay(78);
    printf("%c%c\n\n\n",219,254);
    textcolor(BLACK);
    gotoxy(15,3);
    delay(78);
    printf("%c%c\n\n\n\n",219,219);
    gotoxy(15,5);
    delay(78);
    printf("%c%c\n\n\n\n",219,219);
    gotoxy(15,6);
    delay(78);
    printf("%c%c\n\n\n\n",219,219);
    gotoxy(15,7);
    delay(78);
    printf("%c%c\n\n\n\n",219,219);
    gotoxy(18,3);
    Color(15,0);
    printf("E");
    delay(40);
    printf("c");
    delay(40);
    printf("o");
    delay(40);
    printf("l");
    delay(40);
    printf("e");
    delay(40);
    printf(" ");
    delay(40);
    printf("N");
    delay(40);
    printf("a");
    delay(40);
    printf("t");
    delay(40);
    printf("i");
    delay(40);
    printf("o");
    delay(40);
    printf("n");
    delay(40);
    printf("a");
    delay(40);
    printf("l");
    delay(40);
    printf("e");
    gotoxy(18,5);
    printf("S");
    delay(50);
    printf("u");
    delay(50);
    printf("p");
    delay(50);
    printf("e");
    delay(50);
    printf("r");
    delay(50);
    printf("i");
    delay(50);
    printf("e");
    delay(50);
    printf("u");
    delay(50);
    printf("r");
    delay(50);
    printf("e");
    gotoxy(18,7);
    printf("d");
    delay(50);
    printf("'");
    delay(50);
    printf("I");
    delay(50);
    printf("n");
    delay(50);
    printf("f");
    delay(50);
    printf("o");
    delay(50);
    printf("r");
    delay(50);
    printf("m");
    delay(50);
    printf("a");
    delay(50);
    printf("t");
    delay(50);
    printf("i");
    delay(50);
    printf("q");
    delay(50);
    printf("u");
    delay(50);
    printf("e");
    delay(50);
    gotoxy(35,7);
    textbackground(5);
    printf("=======================================MENU=======================================");
    gotoxy(30,14);
    textbackground(WHITE);
    textcolor(5);
    printf("1. Charger les reservations depuis un fichier Texte");
    gotoxy(30,16);
    delay(100);
    textbackground(WHITE);
    textcolor(5);
    printf("2. Sauvegarder les reservations dans un fichier texte.");
    gotoxy(30,18);
    delay(200);
    textbackground(WHITE);
    textcolor(5);
    printf("3. Affichage du statut des reservations.");
    gotoxy(30,20);
    delay(300);
    textbackground(WHITE);
    textcolor(5);
    printf("4. Inserer une nouvelle reservation ");
    gotoxy(30,22);
    delay(400);
    textbackground(WHITE);
    textcolor(5);
    printf("5. Modifier une reservation ");
    gotoxy(30,24);
    delay(500);
    textbackground(WHITE);
    textcolor(5);
    printf("6. Supprimer une reservation ");
    gotoxy(30,26);
    delay(600);
    textbackground(WHITE);
    textcolor(5);
    printf("7. Rechercher une chambre libre selon son type");
    gotoxy(30,28);
    delay(700);
    textbackground(WHITE);
    textcolor(5);
    printf("8. Rechercher une reservation deja effectuee");
    gotoxy(30,30);
    delay(800);
    textbackground(WHITE);
    textcolor(5);
    printf("9. Rajouter un hotel ");
    gotoxy(30,32);
    delay(900);
    textbackground(WHITE);
    textcolor(5);
    printf("10. Supprimer un hotel ");
    gotoxy(30,34);
    delay(1000);
    textbackground(WHITE);
    textcolor(5);
    printf("11. Liberer toutes les chambres occupees ");
    gotoxy(30,36);
    delay(1100);
    textbackground(WHITE);
    textcolor(5);
    printf("12. Trier les listes des hotels par ordre alphabetique ");
    gotoxy(30,38);
    delay(1200);
    textbackground(WHITE);
    textcolor(5);
    printf("13. Sortir du programme");
    gotoxy(30,40);
    delay(1300);
    textcolor(5);
    textbackground(WHITE);
    textcolor(5);
    printf("Veuillez inserez votre choix svp *_* ?");
    textcolor(5);
    gotoxy(  30,42.5);

}
//*********************************************************************************//
void loading()
        {
            int l;
            Color(15,12);
            printf("LOADING ");
            for(l=0;l<5;l++)
            {Color(0,12);delay(50);printf("%c ",254);}
            Color(15,12);
            printf("100 %c",37);
            textcolor(15);
        }
//**********************************************************************************//


































