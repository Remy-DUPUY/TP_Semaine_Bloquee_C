#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "entree_sortie.h"



void AfficherImage(char* nomFichier){
    char buffer[strlen(nomFichier)+4];
    sprintf(buffer," eog %s\n",nomFichier);
    system(buffer);
}


unsigned char* CreerImage(int largeur, int hauteur){

    return  malloc((largeur*hauteur)*sizeof(unsigned char));// largeur*hauteur*taille en octet des char
}


void ImageUnie(unsigned char* image, int largeur, int hauteur, unsigned char couleur){
  for (int i = 0; i < hauteur*largeur; i++) {
    image[i] = couleur;
  }
}


void Negatif(unsigned char* image, int largeur, int hauteur){

for (int i = 0; i < largeur*hauteur; i++) {
    image[i] = ~image[i];
}

}

void Seuillage(unsigned char* image, int largeur, int hauteur, unsigned char seuil){

  for (int i = 0; i < largeur*hauteur; i++) {
      if (image[i] > seuil) {
        image[i] = 255;
      } else{
        image[i] = 0;
      }
  }

}

/*
void Degrade(unsigned char* image, int largeur, int hauteur){
    for (int i = 0; i < largeur*hauteur; i++) {

    }
}
*/


int main(int argc, char const *argv[]) {

int largeur;
int hauteur;
// unsigned char* monImage;

 // revoie un pointeur vers le tableau de pixels

 // Creer un tableau binaire qui va acceuillir l'image :
unsigned char *vecteur = LireImagePGM("guadalest.pgm",&largeur,&hauteur);

// modification du tableau (effets) :

//Negatif(vecteur,largeur,hauteur);
Seuillage(vecteur,largeur,hauteur,125);



// on insère l'image dans notre vecteur puis on l'affiche :
EcrireImagePGM("guadalest_copie.pgm",vecteur,largeur,hauteur);
AfficherImage("guadalest_copie.pgm");

free(vecteur);


/* création de mon image grise :
monImage = CreerImage(200,200);
ImageUnie(monImage,200,200,155);

EcrireImagePGM("mon_image.pgm",monImage,200,200);


AfficherImage("mon_image.pgm");



free(monImage);
*/
  return EXIT_SUCCESS;
}
