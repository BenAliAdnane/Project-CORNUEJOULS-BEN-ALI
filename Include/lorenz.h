#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "entrees.h"
#include "parametre.h"



typedef struct temps_s *Temps;

void pos_initiale();

void point_suivant(float dt, float sigma, float rho, float beta);

Temps demande_temps();

void lorenz(Temps temps_choisi, Parametre parametre_choisi);