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

    Parametre parametre_enregistre = demande_parametre();     // on demande les parametres à l'utilisateur

    printf("Choisissez les coordonnees initiale\n");

    pos_initiale();                                            //on demande la position initial qui rentre directement dans fichier position

    Temps temps_enregistre = demande_temps();                   // On demande Tmax et dt 

    lorenz(temps_enregistre, parametre_enregistre);             //ON met les Tmax/dt point dans le fichier position 

    // accrocher gnuplot ...
    system("start gnuplot -persist -e \"splot 'positions.txt' u 2:3:4\"");          // affichage de la fonction avec gnuplot, splot pour 3d 
    
    return 0;
}