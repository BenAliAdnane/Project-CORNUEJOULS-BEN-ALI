#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include "../../Include/entrees.h"
#define TAILLE_MAX 10

int lire_fin_ligne()
{
    int compteur = 0;
    char caractere = getchar();
    while(caractere!=EOF && caractere!='\n')
    {
        if(!isspace(caractere))
            compteur+=1;
        caractere= getchar();
    }
    return compteur;
}

void lire_entier(int * n)
{
    lit_format("%d", n);
}

void lire_decimal(float * n)
{
    lit_format("%f", n);
}

void lit_format(char * format, void * n)
{
    int lu = 0;
    int nombre;
    do
    {
        lu = scanf(format, n);
        nombre = lire_fin_ligne();
    }while((lu!=1) || (nombre > 0));
}

