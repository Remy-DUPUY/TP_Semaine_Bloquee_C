#include <stdio.h>
#include <stdlib.h>


void AfficheCar(int n, char c){

  int i;

  for(i = 0 ; i < n ; i++)
  {
      printf("%c", c);
  }

}

// pyramide saisie en ligne de commande :

int main(int argc, char const *argv[]) {

int nbLignes = atoi(argv[1]);  // Nombre de lignes d'étoile à afficher = hauteur

int centreLigne;
int i;

char ligne[64];	// Ligne d'étoiles


// Initialisation à vide de chaque ligne
for(i=0; i<64; i++) {
  ligne[i] = ' ';
}

ligne[64 - 1] = '\0';

  centreLigne = nbLignes -1;


  for (i=0; i < nbLignes; i++) {
    ligne[centreLigne - i] = argv[2][0];
    ligne[centreLigne + i] = argv[2][0];

    // Affichage de la ligne
    printf("%s\n", ligne);

  }

  return EXIT_SUCCESS;
}


/* pyramide saisie en mode scanf() :

  int main(int argc, char const *argv[]) {
    // Déclaration des variables
     int nbLignes;	// Nombre de lignes d'étoile à afficher = hauteur
     int centreLigne;
     int i;
    char ligne[64];	// Ligne d'étoiles

    printf("hauteur ? : ");
    scanf("%d", &nbLignes);

    // Initialisation à vide de chaque ligne
    for(i=0; i<64; i++) {
      ligne[i] = ' ';
    }


    ligne[64 - 1] = '\0';

    centreLigne = nbLignes -1;

    for (i=0; i < nbLignes; i++) {
      ligne[centreLigne - i] = '*';
      ligne[centreLigne + i] = '*';     argv[2][0]

      // Affichage de la ligne
      printf("%s\n", ligne);

    }

  return EXIT_SUCCESS;
  }
*/
