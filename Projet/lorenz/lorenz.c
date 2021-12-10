#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "../../Include/entrees.h"
#include "../../Include/lorenz.h"
#include "../../Include/parametre.h"
//#include "../parametre/parametre.c"

struct parametre_s     // On met la structure conservant les parametres dans le .c et non .h 
{
    float sigma;
    float rho;
    float beta;
}Parametre_s;


void pos_initiale(){   // Demande à l'utilisateur les coordonnées de la poitions initial
    

    
    FILE* fichier = NULL;

    fichier = fopen("positions.txt", "w+");
    float t = 0;
    fprintf(fichier, "\n%f ", t);

    printf("Abscisse initiale (x) :\n");
    float x, y, z;

    lire_decimal(&x);
    printf("Ordonnee initiale (y) :\n");
    lire_decimal(&y);
    printf("Cote initiale (z) :\n");
    lire_decimal(&z);
    fprintf(fichier, "%f %f %f\n", x, y, z);
    fclose(fichier);

}


void point_suivant(float dt, float sigma, float rho, float beta){    // Prend les derniers points dans le fichier position 
    FILE* fichier;                                                      //et calcule et ajoute les suivants
    fichier = fopen("positions.txt", "r+");
    fseek(fichier, -1 , SEEK_END);              //On va a la fin du programme pour récupérer la derniere ligne de point
    
    float t0, x0, y0, z0;
    char current_char;

    for (int i = 0; i < 4; i++){                    // Ici on sait que l'on a 3 coordonnée et le temps donc i<4
        do{                                         // cette boucle nous permet de s'arreter dès qu'il y'a un espace (celui entre
            fseek(fichier, -2, SEEK_CUR);           // les coordonnées),
            fscanf(fichier, "%c", &current_char);   //permet de revenir au début de la dernière ligne
        }while(!isspace(current_char));             
    }
    fscanf(fichier, "%f %f %f %f", &t0, &x0, &y0, &z0); // A partir de là, on récupère les t,x,y,z de la derniere ligne


    float t1 = t0 + dt;                                  //On fait les calculs pour trouver les points suivant
    float x1 = x0 + (sigma * (y0 - x0)) * dt;            // Le calcul de la vitesse est directement fait dans ces calculs
    float y1 = y0 + (x0 * (rho - z0) - y0) * dt;         // Pas d'intermédiaire 
    float z1 = z0 + (x0 * y0 - beta * z0) * dt;
    fseek(fichier, 0, SEEK_END);                         //on reviens à la fin du fichier, et au moment du fprint on revient à la ligne
    fprintf(fichier, "%f %f %f %f\n", t1, x1, y1, z1);
    fclose(fichier);
}


struct temps_s
{
    float dt;
    int Temps_max;
}Temps_s;

Temps demande_temps()       //demande à l'utilisateur le temps max et l'intervalle de temps dt 
{                           //les rentres dans la structure associe au temps Puis retourne cette structure 
    float temps_max;
    float dt;
    Temps temps_enregistre;
    temps_enregistre=(Temps)malloc(sizeof(struct temps_s));

    printf("Veuillez choisir le temps maximum :");

    lire_decimal(&temps_max);

    temps_enregistre->Temps_max = temps_max;

    printf("Veuillez choisir le temps d'intervalle dt :");

    lire_decimal(&dt);

    temps_enregistre->dt = dt ;

    return temps_enregistre;
}

void lorenz(Temps temps_choisi, Parametre parametre_choisi)   // lorenz nous permet d'utiliser point_suivant Tmax/dt fois ce qui nous
{                                                               //permet d'avoir le fichier position avec justement, toutes les positions
    for(float i = 0; i < temps_choisi->Temps_max ; i+=(temps_choisi->dt))
    {
        point_suivant(temps_choisi->dt,parametre_choisi->sigma,parametre_choisi->rho,parametre_choisi->beta);
    }
}