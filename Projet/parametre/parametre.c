#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include "../../Include/entrees.h" 



void demande_dt()
{
    
    //tu crée en avance un fichier dt //
    FILE* file;
    float a;
    do
    {
        file = fopen("demande_dt.txt","w+");
        scanf("%f",&a);
        if ( lit_format("demande_dt.txt",10)==1)
            fputc(a,file);
        else
            fclose(file);
    } while(lit_format("demande_dt.txt",10)!=1);
}