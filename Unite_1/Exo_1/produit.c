#include <stdio.h>
#include <stdlib.h>


/*
 *
 */

// multiplication de 2 entiers :

int main() {

    // déclaration des variables
    int nombre1 = 0;
    int nombre2 = 0;
    int resulat = 0;

    // printf = afficher à l'écran
    printf("Produit de 2 entiers : \n");

    printf("Saisir un premier nombre : \n");
    scanf("%d", &nombre1); // scanf = récupérer la saisie de l'utilisateur (Scanner en Java)



    printf("Saisir un deuxième nombre : \n");
    scanf("%d", &nombre2);

    resulat = (nombre1 * nombre2);

    printf("%d x %d = %d \n ", nombre1, nombre2, resulat);

    return EXIT_SUCCESS;
}
