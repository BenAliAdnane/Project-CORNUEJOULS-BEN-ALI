#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "../../Include/entrees.h"
#include "../../Include/lorenz.h"



void pos_initiale(){
    
    printf("Position initiale (x, y, z) :\n");
    
    FILE* fichier = NULL;

        fichier = fopen("positions.txt", "w+");
        float t = 0;
        fprintf(fichier, "%f ", t);
        float x, y, z;

        lit_decimal(&x);
        lit_decimal(&y);
        lit_decimal(&z);
        fprintf(fichier, "%f %f %f\n", x, y, z);
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
        }while(!isspace(current_char));
    }
    fscanf(fichier, "%f %f %f %f", &t0, &x0, &y0, &z0);


    float t1 = t0 + dt;
    float x1 = x0 + (sigma * (y0 - x0)) * dt;
    float y1 = y0 + (x0 * (rho - z0) - y0) * dt;
    float z1 = z0 + (x0 * y0 - beta * z0) * dt;
    fseek(fichier, 0, SEEK_END);
    fprintf(fichier, "%f %f %f %f\n", t1, x1, y1, z1);
}


struct temps_s
{
    float dt;
    int Temps_max;
}Temps_s;

Temps demande_temps()
{
    int temps_max;
    float dt;
    Temps temps_enregistre;
    temps_enregistre=(Temps)malloc(sizeof(struct temps_s));

    printf("Veuillez choisir le temps maximum (entier) :");

    lire_entier(&temps_max);

    temps_enregistre->Temps_max = temps_max;

    printf("Veuillez choisir le temps d'intervalle dt (float) :");

    lire_decimal(&dt);

    temps_enregistre->dt = dt ;

    return temps_enregistre;
}

void lorenz(Temps temps_choisi, float sigma, float rho, float beta)
{
    for(int i = 0; i < temps_choisi->Temps_max ; i+=(temps_choisi->dt))
    {
        point_suivant(temps_choisi->dt,sigma,rho,beta);
    }
}