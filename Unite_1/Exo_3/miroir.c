#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// fonction principale d'inversion de chaine de caractères

int main() {

    char ch1[64] = "bonjour";
    char ch2[64] = "xxxxx";

    int t, i, j;

    j = 0;
    t = strlen(ch1);

    for (i = t - 1; i >= 0; i--) {
        ch2[j++] = ch1[i];
    }

    ch2[i] = '\0';

    printf(" Chaîne de caractère après inversion = %s \n", ch2);

    return EXIT_SUCCESS;








}
