#include <stdio.h>
#include <stdlib.h>
#include  <time.h>

#define ON '*'
#define OFF '.'
#define DUREE_TEMPO 400

typedef unsigned char interrupteurs_t ;
#define NB_AMPOULES (8*sizeof(interrupteurs_t))


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

int ValeurAmpoule(interrupteurs_t inter, int i) {

  interrupteurs_t mask = 1;         // 00000001
  mask = (mask) << ((sizeof(interrupteurs_t) * 8) - 1);  // ampoule la plus à gauche
  mask = (mask) >> (i);          // décalage bit à bit vers la droite
  interrupteurs_t result = inter & mask;  // résultat du masque, pour savoir quelle ampoule est allumée
  return result != 0;
}


interrupteurs_t Inversion(interrupteurs_t inter){
	inter = ~inter ;
	return inter;
}


interrupteurs_t Compteur(interrupteurs_t inter){

	return inter +1;
}

interrupteurs_t RotationGauche(interrupteurs_t inter){

if (ValeurAmpoule(inter,0)) {
	inter = inter << 1;            // si l'ampoule tout à gauche est allumée
	interrupteurs_t mask = 1;         // 00000001
	inter = inter | mask;    		// ou logique
} else{
	inter = inter << 1;
}

	return inter;
}

interrupteurs_t RotationDroite(interrupteurs_t inter){
	if (ValeurAmpoule(inter,sizeof(interrupteurs_t) * 8) - 1) {
		inter = inter >> 1;

		interrupteurs_t mask = (sizeof(interrupteurs_t) * 8) - 1 ;
		inter = inter | mask; 	// ou logique

	} else{
		inter = inter >> 1;
	}


		return inter;
}



int main(int argc, char const *argv[]) {

	interrupteurs_t inter; // les interrupteurs qui pilotent les ampoules
	unsigned char rampe[8*sizeof(interrupteurs_t)+1]={0}; // les ampoules que l'on affiche

	inter = 0x0E ;   // en notation hexa

  while (1) {

    for (int i = 0; i < NB_AMPOULES; i++) {
				if (ValeurAmpoule(inter,i) == 1) {
						rampe[i] = ON;
				} else {
							rampe[i] = OFF;
				}


    }
		printf("%s \r",rampe); fflush(stdout);
		Temporisation(DUREE_TEMPO);
		inter = RotationGauche(inter);

  }

  return EXIT_SUCCESS;
}
