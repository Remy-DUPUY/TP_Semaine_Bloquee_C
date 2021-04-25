#include <stdio.h>
#include <stdlib.h>


/*
 *
 */

// table de multiplication :

int main() {

    int entier = 0;
    int resultat = 0;

    printf("Vous voulez la table de combien ? ");
    scanf("%d", &entier);

    for (int i = 0; i < 11; i++) {
        resultat = (i * entier);

        printf("%d x %d = %d\n", i, entier, resultat);


    }



    return EXIT_SUCCESS;

}
