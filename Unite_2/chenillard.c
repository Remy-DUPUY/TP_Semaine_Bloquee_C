#include <stdio.h>
#include <stdlib.h>
#include  <time.h>

#define ON '*'
#define OFF '.'
#define NB_AMPOULES 20
#define DUREE_TEMPO 100


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

char RAMPE[NB_AMPOULES];


int main(int argc, char const *argv[]) {

while (1) {
    for (int i = 0; i < NB_AMPOULES; i++) {

      for (int j = 0; j < NB_AMPOULES; j++) {
        RAMPE[j] = OFF;
      }
        RAMPE[i] = ON;
        printf("%s \r",RAMPE); fflush(stdout);
        Temporisation(DUREE_TEMPO);
    }
}

  return EXIT_SUCCESS;
}
