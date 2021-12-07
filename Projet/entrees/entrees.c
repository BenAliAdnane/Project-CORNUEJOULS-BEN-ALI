#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#define TAILLE_MAX 100

int lit_format(FILE* fichier)
{
    int valid;
    char s[TAILLE_MAX]="";
    valid = 0;
    fgets(s, TAILLE_MAX,fichier);

    int len = strlen(s);

    while( len>0 )
    {
        while(isspace(s[len-1]))
        {
            len--;
        }
        
        if(len>0)
        {
            valid = 1;
            for (int i=0; i<len ; i++)
            {
                if(!isdigit(s[i]) && !isspace(s[i]))
                {
                    valid = 0;
                    break;
                }
            }
        }
    }
    return valid;
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

void lire_entier(FILE* fichier)
{
    do 
    {
        if(lit_format(fichier)==0)
            printf("refais");
    }while(lit_format(fichier)!=1);
}

void lire_decimal( FILE* fichier) // Au final ce sont les même, mais on aura besoin que de lire_entier
{
    do
    {
        if(lit_format(fichier)==0)
            printf("refais");
    }while(lit_format(fichier)!=1);
}
