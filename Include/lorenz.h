#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

void pos_initiale(float *t);

void def_Pas(float *t);

void def_settings(int *sigma, int* rho, int* beta);

int * point_suivant(int *t, int sigma, int rho, int beta);