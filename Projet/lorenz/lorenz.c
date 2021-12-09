#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "../../Include/entrees.h"
#include "../../Include/lorenz.h"


void pos_initiale(){
    
    printf("Position initiale (x, y, z) :\n");
    
    FILE* fichier = NULL;
        do{
            fichier = fopen("positions.txt", "w+");
            float t = 0;
            fprintf(fichier, "%f ", t);
            float x, y, z;

            scanf("%f %f %f", &x, &y, &z);
            if (lit_format("positions.txt", 100) ==1){
                fprintf(fichier, "%f ", x);

                fprintf(fichier, "%f ", y);

                fprintf(fichier, "%f ", z);

            }else{
                fclose(fichier);
            }
        }while(lit_format("positions.txt", 100)!=1);


    fclose(fichier);
}

void point_suivant(float dt, float sigma, float rho, float beta){
    FILE* fichier;
    fichier = fopen("positions.txt", "r+");
    fseek(fichier, -1 , SEEK_END);
    
    float t0, x0, y0, z0;
    char current_char;

    for (int i = 0; i < 4; i++){
        do{
            fseek(fichier, -1, SEEK_END);
            fscanf(fichier, "%c", &current_char);
        }while(current_char!= " ");
    }
    fscanf(fichier, "%f", &t0);
    fscanf(fichier, "%f", &x0);
    fscanf(fichier, "%f", &y0);
    fscanf(fichier, "%f", &z0);


    float t1 = t0 + dt;
    float x1 = x0 + (sigma * (y0 - x0)) * dt;
    float y1 = y0 + (x0 * (rho - z0) - y0) * dt;
    float z1 = z0 + (x0 * y0 - beta * z0) * dt;
    fseek(fichier, 0, SEEK_END);
    fprintf(fichier, "%f ", t1);
    fprintf(fichier, "%f ", x1);
    fprintf(fichier, "%f ", y1);
    fprintf(fichier, "%f ", z1);

}


struct temps_s
{
    float dt;
    float Temps_max;
}Temps_s;



/*      Ancienne version, sans fichiers



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

    suivant ->t = +