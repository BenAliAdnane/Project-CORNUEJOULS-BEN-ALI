#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#ifndef __POINT__
#define __POINT__

typedef struct point_s *Point;

typedef struct temps_s *Temps;

void pos_initiale();

float def_Pas();

void def_settings(int *sigma, int* rho, int* beta);

void point_suivant(float dt, float sigma, float rho, float beta);

void demande_dt();


#endif