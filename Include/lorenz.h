#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#ifndef __POINT__
#define __POINT__

typedef struct point_s *Point;

void pos_initiale(Point p);

float def_Pas();

void def_settings(int *sigma, int* rho, int* beta);

void point_suivant(Point p, Point suivant, float dt, int sigma, int rho, int beta);


#endif