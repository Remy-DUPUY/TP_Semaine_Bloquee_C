#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <ctype.h>


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

  //initialisation du tableau:

  int compteur[26]; //26 cases: la première case correspond à la première lettre, 1 case = 1 lettre de l'alphabet
  char c;


  printf("Entrez une chaine quelconque\n");


  for (int i = 0; i < 26; i++)
  {
       compteur[i] = 0; //au départ, le compteur de chaque lettre est à zéro.
  }

  int codelettre;


  while (c != '\n')
  {
 		c = getchar(); //on récupères les caractères entrés au clavier, (le dernier caractère, c.a.d un retour à la ligne)

       codelettre = c -'a'; // avec cette ligne on converti le code de la touche en un numero 0 <= codelettre < 26 uniquement si c'est une lettre entre 'a' et 'z'
       if (codelettre >= 0 && codelettre < 26) //si c'est bien une lettre, '\n' n'est pas une lettre par exemple mais peut être entré par l'utilisateur
       {
           compteur[codelettre] += 1;
       }
  }

  // Affichage du résultat:
  for (int i = 0; i<26; i++)
  {
		c='a'+i; // mise à jour de mon caractère c, affiche les 26 lettre des a à z

		printf("%c : apparait %d fois\n",c,compteur[i]);

  }


  return EXIT_SUCCESS;
}
