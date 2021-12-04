#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include "../lorenz/lorenz.c"
#include "../../Include/lorenz.h"
#include "../../Include/entrees.h"


int main(){
    float pos0[3];
    pos_initiale(pos0);

    for (int i =0; i < 3; i++){
        printf("%f ",pos0[i]);
    }

    printf("\n");

    float dt[1];
    def_Pas(dt);
    printf("dt = %f\n", *dt);

    int sigma[1];
    int rho[1];
    int beta[1];

    def_settings(sigma, rho, beta);
    printf("sigma = %d,rho = %d, beta = %d \n", *sigma, *rho, *beta);

    return 0;
}
