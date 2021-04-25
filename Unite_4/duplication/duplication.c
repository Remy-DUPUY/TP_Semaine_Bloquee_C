#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char* StringDup(char* s){

char* chaine = malloc(strlen(s)*sizeof(char)+1); // on réserve l'espace mémoire nécessaire +
                                                 // calcul de la taille de la chaine destination s
strcpy(chaine,s);    // on copie le contenu de la chaine vers la chaine s

return chaine;


}

int main(int argc, char const *argv[]) {

char chaine[] = "exemple de chaine à copier" ;
char* copie ;	// copie à allouer dynamiquement

copie = StringDup(chaine);

printf("Chaine de base : %s \n Copie : %s \n",chaine,copie);

free(copie);

  return EXIT_SUCCESS;
}
