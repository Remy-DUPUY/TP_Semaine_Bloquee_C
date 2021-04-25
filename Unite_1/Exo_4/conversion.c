#include <stdio.h>
#include <stdlib.h>

// fonction qui convertit des Fahrenheit en celsius et affiche la valeur en celsius
// correspondante

float fahrToCelsius(float fahr) {

    float c = (fahr - 32)*(5.0 / 9.0);

    printf("%.1f \n", c);

    return c;


}

// fonction principale qui affiche le tableau de conversion Fahrenheit - Celsius


int main() {

    printf("Tableau de conversion Fahrenheit - Celsius : \n  ");
    printf("----------------------\n");
    printf("Fahrenheit    Celsius\n");
    printf("----------------------\n");

    // boucle d'affichage des valeurs en Fahrenheit (valeur de i)
    // affichage des valeur en celsius correspondante grâce à la fonction fahrToCelsius()

    for (float i = 0; i < 201; i = i + 20) {

        printf("%.0f \t", i);

        fahrToCelsius(i);



    }

    return EXIT_SUCCESS;




}
