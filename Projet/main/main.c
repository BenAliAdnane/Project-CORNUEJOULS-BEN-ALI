#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include "../../Include/entrees.h"
#include "../../Include/lorenz.h"
#include "../../Include/parametre.h"


int main()
{
    printf("Debut du Programme...Lancement \n\n");

    Parametre parametre_enregistre = demande_parametre();

    printf("Choisissez les coordonnées initiale\n");

    pos_initiale();

    Temps temps_enregistre = demande_temps();

    lorenz(temps_enregistre, parametre_enregistre);

    // accrocher gnuplot ...
    return 0;
}