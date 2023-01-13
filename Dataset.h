#ifndef DATASET_H_INCLUDED
#define DATASET_H_INCLUDED
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
    struct produit p1; int j;FILE *fptr;
    fptr=fopen("Database.txt","a");
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
    fprintf(fptr,"%i\n",p1.serie);
    fprintf(fptr,"%s\n",p1.nom);
    fprintf(fptr,"%f\n",p1.prix);
    fprintf(fptr,"%i\n",p1.nb);
    fclose(fptr);
    return(j);
}

void affiche(struct produit p[50],int x){
    printf("Num de serie          Nom du produit          Prix du prduit          Nombre d'unites\n");
    for (int i=0;i<x;i++){
        printf("%i                %s                     %f                %i\n",p[i].serie,p[i].nom,p[i].prix,p[i].nb);
    }
}


int supp(struct produit p[50],int x){
    int key; struct produit prod;int j;FILE *fptr;
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
    fptr=fopen("Database.txt","w");
    for (int y=0;y<j-1;y++){
        fprintf(fptr,"%i\n",p[y].serie);
        fprintf(fptr,"%s\n",p[y].nom);
        fprintf(fptr,"%f\n",p[y].prix);
        fprintf(fptr,"%i\n",p[y].nb);
    }
    fclose(fptr);
    return(j-1);
}

void modif(struct produit p[50],int x){
    int k; struct produit p1;FILE *fptr;
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
    fptr=fopen("Database.txt","w");
    for (int y=0;y<j-1;y++){
        fprintf(fptr,"%i\n",p[y].serie);
        fprintf(fptr,"%s\n",p[y].nom);
        fprintf(fptr,"%f\n",p[y].prix);
        fprintf(fptr,"%i\n",p[y].nb);
    }
    fclose(fptr);
}


#endif // DATASET_H_INCLUDED
