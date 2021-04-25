#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Image
{
  unsigned char* pixels ;
  unsigned int largeur ;
  unsigned int hauteur ;
} t_image ;

#define DEBUG 	0  // utilisé en interne dans le module entree_sortie.c
#define OK 	0  // les 2 codes retour possibles ...
#define ERREUR 	1  // ... de EcrireImagePGM



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

//----------------------------------------------------------------------
// LireImagePGM fait les allocations mémoires pour créer la structure
// et la zone pour stocker les pixels
// elle lit le fichier image et initialise la structure.
// ele renvoie un pointeur sur la structure créée
//----------------------------------------------------------------------
t_image* LireImagePGM(const char* nomFichier){

  FILE* fichier;
  t_image* image;
  fichier = fopen(nomFichier,"r");

if (!fichier) {
  printf("Problème de lecture !\n");
} else{

int hauteur;
int largeur;

fscanf(fichier,"P5\n%d %d\n255\n",&largeur,&hauteur);

image = CreerImage(largeur,hauteur);

fread(image->pixels,sizeof(unsigned char),image->largeur*image->hauteur,fichier);
}

fclose(fichier);

return image;

}

//----------------------------------------------------------------------
// EcrireImagePGM écrit l'image stockée dans im dans la structure dans
// un fichier au format PGM dont le nom est passé en paramètre.
// elle renvoie OK si l'écriture s'est bien déroulée, ERREUR sinon
//----------------------------------------------------------------------
int EcrireImagePGM(const char* nomFichier, const t_image image){

FILE* fichier;

fichier = fopen(nomFichier,"w");

if (!fichier) {
    printf("Problème au niveau de l'ouverture du fichier !\n");
} else{
  printf("Fichier ouvert ! \n");
}

fprintf(fichier,"%s\n%d %d\n%d\n", "P5", image.largeur,image.hauteur,255);

fwrite(image.pixels,sizeof(unsigned char),image.largeur*image.hauteur,fichier);

fclose(fichier);

return OK;

}

int main(int argc, char const *argv[]) {

t_image* image;

image = CreerImage(800,800);
ImageUnie(image,255);

EcrireImagePGM("nouvelle_image.pgm",*image);
LibererImage(image);

image = LireImagePGM("voiron.pgm");
EcrireImagePGM("Mon-voiron.pgm",*image);


  return EXIT_SUCCESS;
}
