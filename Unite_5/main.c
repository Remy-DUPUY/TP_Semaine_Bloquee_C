#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "entree_sortie.h"



void AfficherImage(char* nomFichier){
    char buffer[strlen(nomFichier)+4];
    sprintf(buffer," eog %s\n",nomFichier);
    system(buffer);
}


t_image* CreerImage(int largeur, int hauteur){

t_image* image;

// allocation dynamique pour la structure en elle même
image = malloc(sizeof(t_image));

  image->largeur = largeur;
  image->hauteur = hauteur;
  image->pixels = malloc((largeur*hauteur)*sizeof(unsigned char)); // allocation dynamique pixels
return image;

}


void ImageUnie(t_image* image, unsigned char color){
  for (int i = 0; i < image->hauteur*image->largeur; i++) {
    image->pixels[i] = color;
  }
}


void LibererImage(t_image* image){
  free(image->pixels);
  free(image);
}


void Negatif(t_image* image){

for (int i = 0; i < image->hauteur*image->largeur; i++) {
    image->pixels[i] = ~image->pixels[i];
}

}

void Seuillage(t_image* image, unsigned char seuil){
  for (int i = 0; i < image->hauteur*image->largeur; i++) {
      if (image->pixels[i] > seuil) {
        image->pixels[i] = 255;
      } else{
        image->pixels[i] = 0;
      }
  }

}


int main(int argc, char const *argv[]) {

// t_image* monImage;

t_image* image;

 // Creer un tableau binaire qui va acceuillir l'image :
image = LireImagePGM("guadalest.pgm");

// modification du tableau (effets) :

//Negatif(image);
Seuillage(image,125);



// on insère l'image dans notre vecteur puis on l'affiche :
EcrireImagePGM("guadalest_copie.pgm",*image);
AfficherImage("guadalest_copie.pgm");

LibererImage(image);


/*
// création de mon image grise :
monImage = CreerImage(800,800);
ImageUnie(monImage,155);

EcrireImagePGM("nouvelle_image.pgm",*monImage);

AfficherImage("nouvelle_image.pgm");


LibererImage(monImage);
*/
  return EXIT_SUCCESS;
}
