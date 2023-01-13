#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Dataset.h"


int main()
{
    int j=0,g; struct produit p[50] ; char k;FILE *fptr;
    printf("Veuiller donner une operation a realiser : \n 1-Ajouter un produit \n 2-Afficher la description du produit \n 3-Supprimer un produit \n 4-Modifier un produit \n 5-Rechercher un produit dans le stock \n");
    scanf("%c",&k);
    while ((k!='q')&&(k!='Q')){
        if (k=='1'){
            system("cls");
            j=ajout(p,j);
            }
        else if (k=='2'){
            system("cls");
            affiche(p,j);
        }
        else if (k=='3'){
            system("cls");
            j=supp(p,j);
        }
        else if (k=='4'){
            system("cls");
            modif(p,j);
        }
        else if (k=='5'){
            system("cls");
            printf("veuiller donner le numero de serie du produit en question : ");
            scanf("%i",&g);
            if (rech(p,j,g)!=-1){
                printf("Le produit existe dans votre liste  \n");
                printf("%i     %s     %f     %i\n",p[rech(p,j,g)-1].serie,p[rech(p,j,g)-1].nom,p[rech(p,j,g)-1].prix,p[rech(p,j,g)-1].nb);
            }
            else {
                printf("Le produit n'existe pas!!!");
            }
        }
        scanf("%c",&k);
        printf("Veuiller donner une operation a realiser : \n 1-Ajouter un produit \n 2-Afficher la description du produit \n 3-Supprimer un produit \n 4-Modifier un produit \n 5-Rechercher un produit dans le stock \n Pour quitter appuyer sur q \n");
    }
    system("cls");
    return 0;
}
