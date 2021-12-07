#include <stdio.h>
#include <stdlib.h>
#include "../../../Include/entrees.h" 


int main()
{
    FILE* fichier;
    fichier = fopen("test.txt","r+");

    fprintf(fichier ,"1557");

    fclose(fichier);

    printf("%d\n",lit_format("test.txt",4));

    return 0;
}