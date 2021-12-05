#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "../../Include/entrees.h"
#include "../../Include/lorenz.h"


struct point_s{       //x, y, z sont les coordonnées et t le temps
    float x;
    float y;
    float z;
    float t;
} Point_s;



void pos_initiale(Point p){
    printf("Position initiale (x, y, z) :\n");
    lire_decimal(&(p->x));
    lire_decimal(&(p->y));
    lire_decimal(&(p->z));
    p->t = 0;
}

float def_Pas(){
    float res;
    printf("Pas de temps (dt) :\n");
    lire_decimal(&res);
    return res;
}

void def_settings(int *sigma, int* rho, int* beta){
    printf("Parametres des equations (sigma, rho et beta) :\n");
    lire_entier(sigma);
    lire_entier(rho);
    lire_entier(beta);

}

void point_suivant(Point p,Point suivant, float dt, int sigma, int rho, int beta){

    suivant->x = p->x + ( sigma * (p->y - p->x) )/dt;    //diviser par dt !!!//
    
    suivant->y = p->y + ( p->x * (rho - p->z) - p->y )/dt;
    
    suivant->z = p->z + ( p->x * p->y - beta*p->z )/dt;

    suivant ->t = p->t +1;
}