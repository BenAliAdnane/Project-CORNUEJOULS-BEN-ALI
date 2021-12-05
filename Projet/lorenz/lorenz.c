#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "../../Include/entrees.h"
#include "../entrees/entrees.c"


void pos_initiale(float *t){
    printf("Position initiale (x, y, z) :\n");
    for (int i = 0; i < 3; i++){
        lire_decimal(&t[i]);
    }
}

void def_Pas(float *t){
    printf("Pas de temps (dt) :\n");
    lire_decimal(t);
}

void def_settings(int *sigma, int* rho, int* beta){
    printf("Parametres des equations (sigma, rho et beta) :\n");
    lire_entier(sigma);
    lire_entier(rho);
    lire_entier(beta);

}

int * point_suivant(int *t, int sigma, int rho, int beta){
    int res[3];
    res[0] = t[0] + sigma * (t[1] - t[0]);    //diviser par dt !!!//
    res[1] = t[1] + t[0] * (rho - t[2]) - t[1];
    res[2] = t[2] + t[0] * t[1] - beta*t[2];
    return res;
}