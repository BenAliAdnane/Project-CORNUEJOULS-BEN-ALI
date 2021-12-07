#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#define TAILLE_MAX 1000

bool lit_format(char * s)
{
    bool valid;
    valid = false;
    fgets(s, TAILLE_MAX,stdin);

    int len = strlen(s);

    while( len>0 && isspace(s[len-1]))
    {
        len--;
        if(len>0)
        {
            valid = true;
            for (int i=0; i<len ; i++)
            {
                if(!isdigit(s[i]))
                {
                    valid = false;
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

void lire_entier(char * n)
{
    int lu;
    do
    {
        lu=scanf("%s", n);
        if(lu!=1 && lit_format(n)==false)
            printf("refais");
    }while(lu!=1 && lit_format(n)!=true);
    
}

void lire_decimal( char * n )
{
    int lu;
    do
    {
        lu=scanf("%s", n); // pas de & car on a deja float * n // //renvoie 0 si pas float, 1 sinon//
        if(lu!=1 && lit_format(n)==false)
            printf("refais");
    }while(lu!=1 && lit_format(n)!=true);
}
