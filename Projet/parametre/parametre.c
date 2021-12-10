#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include "../../Include/entrees.h"
#include "../../Include/parametre.h"
#include "../../Include/lorenz.h"

struct parametre_s
{
    float sigma;
    float rho;
    float beta;
}Parametre_s;

Parametre demande_parametre()
{
    float Rho;
    float Sigma;
    float Beta;
    Parametre parametre_enregistre;
    parametre_enregistre=(Parametre)malloc(sizeof(struct parametre_s));

    printf("Veuillez choisir les parametres sigma,rho,beta \n\n");

    printf("sigma :");

    lire_decimal(&Sigma);

    printf("\n");

    parametre_enregistre->sigma = Sigma;
    
    printf("rho :");

    lire_decimal(&Rho);

    printf("\n");

    parametre_enregistre->rho = Rho;

    printf("beta :");

    lire_decimal(&Beta);

    printf("\n");

    parametre_enregistre->beta = Beta;

    return parametre_enregistre;
}