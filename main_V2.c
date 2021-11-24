#include <stdio.h>
#include <stdlib.h>
#include <string.h>


    typedef struct compte {
           char nom [30];
           char CIN [12];
           float montant ;

    }compte;

    void introduire (compte tab_compte[] , int c);
    void tri (compte tab_compte[] , int n);
    void echange (compte tab_compte1[], compte tab_compte2[] , int n);
    int menu1();
    int menu2();
    int menu3();


int main()
{
    int choix_1, choix_11, choix_12;
    int re_menu ;
    int n_compte=0, i, indice1, indice2, c=0, com1, com2;
    compte liste_compte[100];
    compte tab_clone[100];
    char CIN_test[12], nom_test[30];
    float mont;
    int test;
    float seuil, val, pourcentage;

    menu1:
        system("cls");

    choix_1 = menu1();

    ///  menu N1
    switch(choix_1){

        ///  Introduire un compte bancaire
        case 1:{
            system("cls");

            introduire(liste_compte, n_compte);
            n_compte++;


            ///****************************************************  retour en arrière
            etq_1:
            printf("\n\t cliquer 9 pour retourner au menu principal \n");
            scanf("%d",&re_menu);
            if(re_menu==9){
                goto menu1;
            }
            else{
                goto etq_1;
            }
            break;
        }


        ///  Introduire plusieurs comptes bancaires
        case 2:{
            system("cls");

            do{
            introduire(liste_compte, n_compte);
            n_compte++;

            etq_2:
            printf("\n\t cliquer 1 pour pour introduire un autre compte \n");
            printf("\n\t cliquer 9 pour retourner au menu principal \n");
            scanf("%d",&re_menu);

            if (re_menu==1){
                continue;
            }
            else if(re_menu==9){
                goto menu1;
            }
            else{
                goto etq_2;
            }

            }while(1);

            break;
        }

        ///  Operations
        case 3:{
                system("cls");

                menu2:
                system("cls");

                choix_11 = menu2();


                ///  menu N2
                switch (choix_11){

                    ///  Retrait
                    case 1:{
                        if(n_compte==0){
                                printf("error; t'as pas encore cree un compte \n\n");
                        }
                        else{

                        erreur_du_saisi_1:
                        system("cls");

                        indice1=n_compte+1;
                        c=0;

                        printf("\n\t ************  retrait  ************\n \n");

                        printf("\n\t donner le Nom et Prenom du Client \n");
                        scanf("%s",&nom_test);
                        printf("\n\t donner CIN du Client \n");
                        scanf("%s",&CIN_test);

                        /// nom saisi exicte ?
                        for(i=0 ; i<n_compte ; i++){
                            test=strcmp(liste_compte[i].nom , nom_test);
                            if(test==0){
                            }
                        }

                        if(c==n_compte){
                            printf("\n\t Ce nom n'est pour aucun de nos clients \n \n");
                            goto etq_312;
                        }
                        else{
                            /// CIN saisi exicte ?
                            test=strcmp(liste_compte[indice1].CIN , CIN_test);
                            if(test==0){
                                printf("\n\t %s \t %s\n",liste_compte[indice1].nom, liste_compte[indice1].CIN);
                                printf("\n\t sold bancaire : %2.f\n \n",liste_compte[indice1].montant);
                                printf("\n\t Donnez le montant que vous souhaitez retirer \n");
                            }
                            else{
                                printf("\n\t vous avez un erreur soit dans le nom du client ou dans son CIN \n");

                                etq_311:
                                printf("\n\t cliquer 1 pour re saisir les information du client \n");
                                printf("\n\t cliquer 9 pour retourner au menu precedente \n");
                                printf("\n\t cliquer 99 pour retourner au menu principal \n");
                                scanf("%d",&re_menu);

                                if(re_menu==1){
                                goto erreur_du_saisi_1;
                                }
                                else if(re_menu==9){
                                goto menu2;
                                }
                                else if(re_menu==99){
                                goto menu1;
                                }
                                else{
                                goto etq_311;
                                }
                                }
                                }
                            /// ( - )
                            scanf("%f",&mont);
                            if( mont < liste_compte[indice1].montant ){
                                    liste_compte[indice1].montant = liste_compte[indice1].montant - mont ;
                                    printf("\n\t le nouveau sold bancaire : %2.f\n",liste_compte[indice1].montant);
                            }
                            else{

                                printf("\n\t tu peux pas faire cette operation; \n");
                            }
                        }

                        ///****************************************************  retour en arrière
                        etq_312:
                        printf("\n\t cliquer 9 pour retourner au menu precedente \n");
                        printf("\n\t cliquer 99 pour retourner au menu principal \n");
                        scanf("%d",&re_menu);
                        if(re_menu==9){
                        goto menu2;
                        }
                        else if(re_menu==99){
                        goto menu1;
                        }
                        else{
                        goto etq_312;
                        }
                        break;
                    }
                    ///  Depot
                    case 2:{

                        if(n_compte==0){
                            printf("\n\t error; t'as pas encore cree un compte \n\n");
                        }
                        else{
                            erreur_du_saisi_2:
                        system("cls");
                        indice1=n_compte+1;

                        printf("\n\t ************  depot  ************\n \n");

                        printf("\n\t donner le Nom et Prenom du Client \n");
                        scanf("%s",&nom_test);

                        printf("\n\t donner CIN du Client \n");
                        scanf("%s",&CIN_test);

                        /// nom saisi existe ?
                        for(i=0 ; i<n_compte ; i++){
                            test=strcmp(liste_compte[i].nom , nom_test);
                            if(test==0){
                                indice1 = i ;
                                break;
                            }
                            else{
                                c++;
                            }
                        }

                        if(c==n_compte){
                            printf("\n\t Ce nom n'est pour aucun de nos clients \n");
                        }
                        else{
                            /// CIN saisi existe
                            test=strcmp(liste_compte[indice1].CIN , CIN_test);
                            if(test==0){
                                printf("\n\t %s \t %s\n",liste_compte[indice1].nom, liste_compte[indice1].CIN);
                                printf("\n\t sold bancaire : %2.f\n \n",liste_compte[indice1].montant);
                                printf("\n\t Donnez le montant que vous souhaitez ajouter \n");
                            }
                            else{
                                printf("\n\t vous avez un erreur soit dans le nom du client ou dans son CIN \n");

                                etq_321:
                                printf("\n\t cliquer 1 pour re saisir les information du client \n");
                                printf("\n\t cliquer 9 pour retourner au menu precedente \n");
                                printf("\n\t cliquer 99 pour retourner au menu principal \n");
                                scanf("%d",&re_menu);

                                if(re_menu==1){
                                goto erreur_du_saisi_2;
                                }
                                else if(re_menu==9){
                                goto menu2;
                                }
                                else if(re_menu==99){
                                goto menu1;
                                }
                                else{
                                goto etq_321;
                                }
                                }
                                }
                            /// ( + )
                            scanf("%f",&mont);
                            liste_compte[indice1].montant = liste_compte[indice1].montant + mont ;
                            printf("\n\t le nouveau sold bancaire : %2.f\n",liste_compte[indice1].montant);

                        }



                        ///****************************************************  retour en arrière
                        etq_322:
                        printf("\n\t cliquer 9 pour retourner au menu precedente \n");
                        printf("\n\t cliquer 99 pour retourner au menu principal \n");
                        scanf("%d",&re_menu);
                        if(re_menu==9){
                        goto menu2;
                        }
                        else if(re_menu==99){
                        goto menu1;
                        }
                        else{
                        goto etq_322;
                        }
                        break;
                    }
                    default :{
		                break;
	                }

                }

            break;
        }

        ///  Affichage
        case 4:{
                system("cls");

                menu3:
                system("cls");

                choix_12 = menu3();

                ///  menu N3
                switch(choix_12){

                    ///  Affichage des comptes bancaire par Ordre Ascendant
                    case 1:{
                        system("cls");

                        if(n_compte<2){
                                printf("\n\t error; vous avez besoin au moins 2 compte pour faire cette operation \n\n");
                        }
                        else {

                        echange (liste_compte, tab_clone, n_compte);
                        tri (tab_clone, n_compte);

                        ///Affichage Ascendant
                        for(i=n_compte-1 ; i>=0 ; i--){
                            printf("\n\t %s \t %s \t %.2f \n\n",tab_clone[i].nom, tab_clone[i].CIN, tab_clone[i].montant);
                        }

                        }


                        ///****************************************************  retour en arrière
                        etq_41:
                        printf("\n\t cliquer 9 pour retourner au menu precedente \n");
                        printf("\n\t cliquer 99 pour retourner au menu principal \n");
                        scanf("%d",&re_menu);
                        if(re_menu==9){
                        goto menu3;
                        }
                        else if(re_menu==99){
                        goto menu1;
                        }
                        else{
                        goto etq_41;
                        }
                        break;
                    }
                    ///  Affichage des comptes bancaire par Ordre Descendant
                    case 2:{
                        system("cls");

                        if(n_compte<2){
                                printf("\n\t error; vous avez besoin au moins 2 compte pour faire cette operation \n\n");
                        }
                        else{

                        echange (liste_compte, tab_clone, n_compte);
                        tri (tab_clone, n_compte);

                        ///Affichage Descendant
                        for(i=0 ; i<n_compte ; i++){
                            printf("\n\t %s \t %s \t %.2f \n\n",tab_clone[i].nom, tab_clone[i].CIN, tab_clone[i].montant);
                        }

                        }


                        ///****************************************************  retour en arrière
                        etq_42:
                        printf("\n\t cliquer 9 pour retourner au menu precedente \n");
                        printf("\n\t cliquer 99 pour retourner au menu principal \n");
                        scanf("%d",&re_menu);
                        if(re_menu==9){
                        goto menu3;
                        }
                        else if(re_menu==99){
                        goto menu1;
                        }
                        else{
                        goto etq_42;
                        }
                        break;
                    }
                    ///  Affichage des comptes bancaire ayant un montant superieur a la seuil
                    case 3:{
                        system("cls");

                        if(n_compte<2){
                                printf("\n\t error; vous avez besoin au moins 2 compte pour faire cette operation \n\n");
                        }
                        else {

                        echange (liste_compte, tab_clone, n_compte);
                        tri (tab_clone, n_compte);
                        printf("\n\t donnez la seuil \n");
                        scanf("%f",&seuil);

                        ///Affichage Ascendant vol2
                        for(i=n_compte-1 ; i>=0 ; i--){
                            if(tab_clone[i].montant > seuil){
                                printf("\n\t %s \t %s \t %.2f \n\n",tab_clone[i].nom, tab_clone[i].CIN, tab_clone[i].montant);
                            }
                        }

                        }

                        ///****************************************************  retour en arrière
                        etq_43:
                        printf("\n\t cliquer 9 pour retourner au menu precedente \n");
                        printf("\n\t cliquer 99 pour retourner au menu principal \n");
                        scanf("%d",&re_menu);
                        if(re_menu==9){
                        goto menu3;
                        }
                        else if(re_menu==99){
                        goto menu1;
                        }
                        else{
                        goto etq_43;
                        }
                        break;
                    }
                    ///  Affichage des comptes bancaire ayant un montant superieur a la seuil
                    case 4:{
                        system("cls");

                        if(n_compte<2){
                                printf("\n\t error; vous avez besoin au moins 2 compte pour faire cette operation \n\n");
                        }
                        else {

                        echange (liste_compte, tab_clone, n_compte);
                        tri (tab_clone, n_compte);
                        printf("\n\t donnez la seuil\n");
                        scanf("%f",&seuil);

                        ///Affichage Descendant vol 2
                        for(i=0 ; i<n_compte ; i++){
                            if(tab_clone[i].montant > seuil){
                                    printf("\n\t %s \t %s \t %.2f \n\n",tab_clone[i].nom, tab_clone[i].CIN, tab_clone[i].montant);
                                }
                        }

                        }


                        ///****************************************************  retour en arrière
                        etq_44:
                        printf("\n\t cliquer 9 pour retourner au menu precedente \n");
                        printf("\n\t cliquer 99 pour retourner au menu principal \n");
                        scanf("%d",&re_menu);
                        if(re_menu==9){
                        goto menu3;
                        }
                        else if(re_menu==99){
                        goto menu1;
                        }
                        else{
                        goto etq_44;
                        }
                        break;
                    }
                    ///  Recherche par CIN
                    case 5:{
                        system("cls");

                        if(n_compte==0){
                                printf("\n\t error; t'as pas encore cree un compte \n\n");
                        }
                        else {

                        c=0;
                        printf("\n\t %d\n",c);

                        printf("\n\t donner CIN du Client \n");
                        scanf("%s",&CIN_test);

                        /// CIN saisi existe ?
                        for(i=0 ; i<n_compte ; i++){
                            test=strcmp(liste_compte[i].CIN , CIN_test);
                            if(test==0){
                                indice1 = i ;
                                break;
                            }
                            else{
                                c++;
                            }
                        }

                        if(c==n_compte){
                            printf("\n\t Ce CIN n'est pour aucun de nos clients \n\n");

                        }
                        else{
                                printf("\n\t %s \t %s\n",liste_compte[indice1].nom, liste_compte[indice1].CIN);
                                printf("\n\t sold bancaire : %2.f\n \n",liste_compte[indice1].montant);
                            }
                        }



                        ///****************************************************  retour en arrière
                        etq_45:
                        printf("\n\t cliquer 9 pour retourner au menu precedente \n");
                        printf("\n\t cliquer 99 pour retourner au menu principal \n");
                        scanf("%d",&re_menu);
                        if(re_menu==9){
                        goto menu3;
                        }
                        else if(re_menu==99){
                        goto menu1;
                        }
                        else{
                        goto etq_45;
                        }
                        break;
                    }
                    default :{
		                break;
	                }

                }
            break;
        }

        ///  Fidelisation
        case 5:{
            system("cls");

            if(n_compte<3){
                printf("\n\t error; vous avez besoin au moins 3 compte pour faire cette operation \n\n");
            }
            else {

            echange (liste_compte, tab_clone, n_compte);
            tri (tab_clone, n_compte);

            com1=0;
            com2=0;

            while (com2 < 3){

                            /// trouver lemblacement du 3 premier montant dans la liste principal
                            for(i=0 ; i<n_compte ; i++){
                            test=strcmp(liste_compte[i].CIN , tab_clone[com1].CIN);
                            if(test==0){
                                indice1 = i ;
                                break;
                            }
                            }

                            pourcentage=1.3/100 ;
                            val = liste_compte[indice1].montant;
                            liste_compte[indice1].montant = val + (val * pourcentage) ;
                            printf("\n\t %s \t %s \t %.2f \n\n",liste_compte[indice1].nom, liste_compte[indice1].CIN, liste_compte[indice1].montant);

                            if(tab_clone[com1].montant == tab_clone[com1+1].montant){
                                com1++;
                            }
                            else{
                                com1++;
                                com2++;
                            }
            }
            }



            ///****************************************************  retour en arrière
            etq5:
            printf("\n\t cliquer 9 pour retourner au menu principal \n");
            scanf("%d",&re_menu);
            if(re_menu==9){
                goto menu1;
            }
            else{
                goto etq5;
            }
            break;
        }

        case 6:{
            exit(-1);
            break;
        }
        default :{
		    break;
	    }
    }

    return 0;
}
int menu1 (){
    int r;
    printf("\n\t 1 : Introduire un compte bancaire \n");
    printf("\n\t 2 : Introduire plusieurs comptes bancaires \n");
    printf("\n\t 3 : Operations \n");
    printf("\n\t 4 : Affichage \n");
    printf("\n\t 5 : Fidelisation \n");
    printf("\n\t 6 : Quitter l application \n");
    scanf("%d",&r);

    return r;
}

int menu2 (){
    int r;
    printf("\n\t 1 : Retrait \n");
    printf("\n\t 2 : Depot \n");
    scanf ("%d",&r);

    return r;
}

int menu3 (){
     int r;
    printf("\n\t 1 : Affichage des comptes bancaire par Ordre Ascendant \n");
    printf("\n\t 2 : Affichage des comptes bancaire par Ordre Descendant \n");
    printf("\n\t 3 : Affichage des comptes bancaire ayant un montant superieur a la seuil \n");
    printf("\n\t 4 : Affichage des comptes bancaire ayant un montant inferieur a la seuil \n");
    printf("\n\t 5 : Recherche par CIN \n");
    scanf("%d",&r);

    return r;
}

void introduire (compte tab_compte[] , int c){

            printf("\n\t le Nom et Prenom du Client : \n");
            scanf("%s",&tab_compte[c].nom);
            printf("\n\t CIN  :  \n");
            scanf("%s",&tab_compte[c].CIN);
            printf("\n\t le  Montant :\n");
            scanf("%f",&tab_compte[c].montant);
}


void tri (compte tab_compte[] , int n){
    int i,j;
    compte change;
    for(i=0 ; i<n ; i++){
        for(j=0 ; j<n ; j++){
            if(tab_compte[i].montant > tab_compte[j].montant){
                change = tab_compte[i] ;
                tab_compte[i] = tab_compte[j] ;
                tab_compte[j] = change ;
            }
        }
    }
}
void echange (compte tab_compte1[], compte tab_compte2[] , int n){
    int i;
    for(i=0 ; i<n ; i++){
        tab_compte2[i] = tab_compte1[i];
    }
}
