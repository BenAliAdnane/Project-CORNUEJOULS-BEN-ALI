#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


int lire_fin_ligne()
{
    int cpt = 0;
    char c = getchar();
    while(c!=EOF && c!='\n')
    {
        if(!isspace(c))
            cpt+=1;
        c= getchar();
    }
    return cpt;
}

void lire_entier(int * n)
{
    int lu;
    int nbeff=0; // on veut vider le buffer lorsque l'humain ne tape pas d'entier //
    do
    {
        lu=scanf("%d", n); // pas de & car on a deja int * n //
        nbeff=lire_fin_ligne();
        if(lu!=1 || nbeff>0)
            printf("refais");
    }while(lu!=1 || nbeff>0);
    
}

void lire_decimal( float * n)
{
    int lu;
    int nbeff=0; // on veut vider le buffer lorsque l'humain ne tape pas d'entier //
    do
    {
        lu=scanf("%f", n); // pas de & car on a deja int * n //
        nbeff=lire_fin_ligne();
        if(lu!=1 || nbeff>0)
            printf("C'est pas un float");
    }while(lu!=1 || nbeff>0);
}