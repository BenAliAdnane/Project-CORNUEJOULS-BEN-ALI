#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#define TAILLE_MAX 10

struct chaine
{
    char * t;
};

struct chaine * nouvelle_chaine(int nb_valeur , char * filename)
{
    struct chaine * res;
    FILE* file = fopen(filename,"w+");
    char caractere_actuel = fgetc(file);
    res = (struct chaine *)malloc(sizeof(struct chaine));
    res->t = (char *)malloc(nb_valeur*(sizeof(char)));
    for (int i=0 ; caractere_actuel!=EOF; i++)
    {
        if(!isspace(caractere_actuel))
            res->t[i]=caractere_actuel;
        caractere_actuel=fgetc(file);
    }
    return res;
}

int lit_format(char * filename, int nb_valeur)  // renvoie 1 si que des entiers ou décimaux, 0 sinon
{
    struct chaine * echange;
    echange = nouvelle_chaine(nb_valeur, filename);

    int a = strlen(echange->t);

    for(int i=0; i<a; i++)
    {
        if(!isdigit(echange->t[i]))
            return 0;
    }
    return 1;
} 

int lire_fin_ligne() // indique le nombre de caractère qu'il reste dans une ligne //
{
    int cpt = 0;
    char c = getchar(); // renvoie directement ce qu'il y'a dans le buffer char par char ou EOF si fin ligne//
    while(c!=EOF && c!='\n')
    {
        if(!isspace(c))
            cpt+=1;
        c= getchar();
    }
    return cpt;
}

void lire_entier(char * filename,int nb_valeur)
{
    do 
    {
        if(lit_format(filename,nb_valeur)==0)
            printf("refais");
    }while(lit_format(filename, nb_valeur)!=1);
}

void lire_decimal( char * filename , int nb_valeur) // Au final ce sont les même, mais on aura besoin que de lire_entier
{
    if(lit_format(filename, nb_valeur)==0)
        printf("refais");
}

void demande_dt()
{
    
    //tu crées en avance un fichier dt //
    FILE* file;
    float a;
    printf("hey");
    do
    {
        file = fopen("demande_dt.txt","w+");
        printf("%d",lit_format("demande_dt.txt",10));
        scanf("%f",&a);
        if ( lit_format("demande_dt.txt",10)==1)
            fputc(a,file);
        else
            fclose(file);
    } while(lit_format("demande_dt.txt",10)!=1);
}

