#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include "../../../Include/lorenz.h"
#include "../../../Include/entrees.h"


int main(){
    pos_initiale();
    
    Temps T = demande_temps();
    
    int sigma;
    int rho;
    int beta;
    
    sigma = 1;
    rho = 2;
    beta = 3;
    float dt =0.1;

    return 0;
}




/* ancien main, avec struct Point
int main(){
    Point pos0;
    pos0 = malloc(sizeof(Point));

    pos_initiale(pos0);

    printf("x = %f, y = %f, z = %f", pos0->x, pos0->y, pos0->z);

    printf("\n");

    float dt;
    dt = def_Pas();
    printf("dt = %f\n", dt);

    int sigma[1];
    int rho[1];
    int beta[1];

    def_settings(sigma, rho, beta);
    printf("sigma = %d,rho = %d, beta = %d \n", *sigma, *rho, *beta);

    return 0;
}
*/