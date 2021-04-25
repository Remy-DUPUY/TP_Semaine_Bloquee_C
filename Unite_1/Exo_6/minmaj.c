#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10
#define OK 0
#define FIN 1

//----------------------------------------------------
int LireUneLigne(char*buf, int size, FILE* f)
// Pascal Bertolino 2005
// lit une ligne du fichier f
// met dans buf les size-1 premiers caracteres maxi
// jette les suivants s'ils existent
// enleve le '\n' de la fin s'il y est
// marche aussi avec les chaines vides
// retourne FIN si rien à lire, OK sinon
//----------------------------------------------------
{
	char trash[64] ;  // chaine poubelle
	char* res ;       // retour de la fonction fgets

	res = fgets(buf, size, f) ; // recupere le debut dans buf
	if (!res)
		return FIN ;

	if (strchr(buf, '\n') == NULL)
	{      // on n'a pas lu le RC donc on n'a pas tout lu
		do // on jette la suite
		{
			res = fgets(trash, 64, f) ;
			if (res == NULL)
				return FIN ;
			//printf("*jette:%s*\n", trash) ;
		}
		while (strchr(trash, '\n') == NULL) ;
	}
	else
	{
		*strchr(buf, '\n') = '\0' ; // remplace '\n' par '\0'
	}

	return OK ;
}



int main(){
  char chaine[64];
  int nbMaj = 0 ;
  int nbMin = 0 ;
  int autre = 0 ;

  printf("Entrez une chaîne quelconque : ");
  LireUneLigne(chaine, 64, stdin);            // stdin est le clavier. La fonction remplit la chaine, 64 est le nb de charactères

// boucle principale qui parcourt toute la chaine
  for (int i = 0; i < strlen(chaine); i++) {  // strlen  = la taille de la chaine
      if (chaine[i] >= 'A' && chaine[i] <= 'Z') {
        nbMaj++;
      }
      else if (chaine[i] >= 'a' && chaine[i] <= 'z') {
        nbMin++;
      }

			else {
        autre++;
      }

  }

printf("%d majuscule(s)\n %d minuscule(s)\n %d autre\n", nbMaj,nbMin,autre );


  return EXIT_SUCCESS;
}
