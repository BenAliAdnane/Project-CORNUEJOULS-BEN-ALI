#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>


typedef struct temps_s *Temps;

void pos_initiale();

void point_suivant(float dt, float sigma, float rho, float beta);

Temps demande_temps();

void lorenz(Temps temps_choisi, float sigma, float rho, float beta);