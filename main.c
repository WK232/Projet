#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct produit {
    int serie;
    char nom[50];
    float prix;
    int nb;
};

int rech(struct produit p[50],int x, int y){
    int k1=0,k2=0;
    while ((k1<x)&&(k2==0)){
        if (p[k1].serie==y){
            k2=1;
        }
        k1++;
    }
    if (k2==1){
        return(k1);
    }
    else {
        return(-1);
    }
}

int ajout (struct produit p[50], int *x){
    struct produit p1; int j;
    printf("Veuiller donner le numero de serie du produit : ");
    scanf("%i",&p1.serie);
    printf("Veuiller donner le nom du produit :");
    fflush(stdin);
    gets(&p1.nom);
    printf("Veuiller donner le prix du produit en dinars :");
    scanf("%f",&p1.prix);
    printf ("Veuiller donner le nombre d'unites :");
    scanf("%i",&p1.nb);
    j=x;
    p[j]=p1;
    j++;
    return(j);
}

void affiche(struct produit p[50],int x){
    printf("Num de serie          Nom du produit          Prix du prduit          Nombre d'unites\n");
    for (int i=0;i<x;i++){
        printf("%i                %s                     %f                %i\n",p[i].serie,p[i].nom,p[i].prix,p[i].nb);
    }
}


int supp(struct produit p[50],int x){
    int key; struct produit prod;int j;
    printf("veuiller donner le num de serie du produit à supprimer :");
    scanf("%i",&key);
    if (rech(p,x,key)==-1){
        printf("Produit introuvable");
    }
    else {
        printf("%i",rech(p,x,key));
        for (int i=rech(p,x,key)-1;i<x-1;i++){
            prod=p[i];
            p[i]=p[i+1];
            p[i+1]=prod;
        }
    }
    j=x;
    return(j-1);
}

void modif(struct produit p[50],int x){
    int k; struct produit p1;
    printf("Veuiller donner le numero de serie du produit à modifier : ");
    scanf("%i",&k);
    if (rech(p,x,k)==-1){
        printf("Produit introuvable!!");
    }
    else {
        printf("Veuiller donner le numero de serie du produit : ");
        scanf("%i",&p1.serie);
        printf("Veuiller donner le nom du produit :");
        fflush(stdin);
        gets(&p1.nom);
        printf("Veuiller donner le prix du produit en dinars :");
        scanf("%f",&p1.prix);
        printf ("Veuiller donner le nombre d'unites :");
        scanf("%i",&p1.nb);
        p[rech(p,x,k)-1]=p1;
    }
}

int main()
{
    int j=0,g; struct produit p[50] ; char k;
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
