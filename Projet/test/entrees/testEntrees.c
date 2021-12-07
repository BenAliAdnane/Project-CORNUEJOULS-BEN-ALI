#include <stdio.h>
#include <stdlib.h>
#include "../../../Include/entrees.h" 


int main()
{
    FILE* fichier;
    fichier = fopen("test.txt","r+");

    fprintf(fichier ,"1 a 2");

    fclose(fichier);

    fichier = fopen("test.txt","w+");

    fprintf(fichier ,"123");

    fclose(fichier);

    printf("%d\n",lit_format("test.txt",4));

    return 0;
}