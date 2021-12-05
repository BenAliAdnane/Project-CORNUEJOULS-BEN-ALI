#include <stdio.h>
#include <stdlib.h>


int main()
{
    FILE* fichier = NULL;
    int age = 0;
    fichier = fopen("test.txt","r+");

    if (fichier!=NULL) // Verification fichier bien ouvert 
    {
        // ajout des points dans le fichier 
        printf("Quel age as-tu?\n");
        scanf("%d", &age);

        fprintf(fichier,"Le monsieur qui utilise le programme, il a %d ans", age);

        fputc('A', fichier);//Le 'A' est a remplacer par la position du point que l'on trouve grâce a lorenz
        fclose(fichier);// fermeture du fichier pour la mémoire 
    }

    else
        printf("Impossible d'ouvrir le fichier voulu");

    return 0;

}