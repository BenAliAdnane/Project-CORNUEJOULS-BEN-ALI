#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "../../include/entrees.h"
#include "../entrees/entrees.c"

void pos_initiale(float *t){
    printf("Position initiale (x, y, z :\n");
    for (int i = 0; i < 3; i++){
        lire_decimal(&t[i]);
    }
}

int main(){
    float pos0[3];
    pos_initiale(pos0);

    return 0;
}