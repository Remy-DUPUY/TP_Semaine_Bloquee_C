#include <stdio.h>
#include <stdlib.h>
#include  <time.h>

void Temporisation(int n)
//------------------------------------------------------------------------------
// Fonction qui met n milli-secondes a s'executer
// C'est donc une temporisation de n ms
// necessite <stdio.h>
{
	clock_t start, stop ;

	n = n*CLOCKS_PER_SEC/1000 ; // clock() ne fonctionne pas forcement en milli-secondes
	start = clock() ;           // Top depart. start = l'heure de depart
	stop = start + n ;          // stop = l'heure de fin

	while(clock() < stop)       // On scrute l'heure tant qu'on n'a pas atteint la fin
	{
	}
}

//
 int main(int argc, char const *argv[]) {

// définition des variables (valeurs) :

char allume = argv[2][0];

char eteinte = argv[4][0];

int nb_ampoules = atoi(argv[6]);

int duree_tempo = atoi(argv[8]);

// définition des variables (orthographe) :
char parametre_ON = argv[1][1]; // a

char parametre_OFF = argv[3][1]; // e

char parametre_nbAmpoule = argv[5][1]; // n

char parametre_Tempo =  argv[7][1];   // t

// programme principal :

 char RAMPE[nb_ampoules];

// vérification de l'orthographe

if(parametre_ON == 'a' && parametre_OFF == 'e' && parametre_nbAmpoule == 'n' && parametre_Tempo == 't') {

	// programme avec les valeurs de l'utilisateur

	while (1) {
	    for (int i = 0; i < nb_ampoules; i++) {

	      for (int j = 0; j < nb_ampoules; j++) {
	        RAMPE[j] = eteinte;
	      }
	        RAMPE[i] = allume;
	        printf("%s \r",RAMPE); fflush(stdout);
	        Temporisation(duree_tempo);
	    }

		return EXIT_SUCCESS;
}

} else {
	printf("Erreur de syntaxe \n");
	printf("Usage : chenillard_v2 [-a <car_ampoule_allumee>] [-e <car_ampoule_eteinte>] \n [-t <temporisation>] [-n <nombre_d_ampoules>] \n");



	return EXIT_FAILURE;
}

}
