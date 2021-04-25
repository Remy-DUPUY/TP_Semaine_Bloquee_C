#include <stdio.h>
#include <stdlib.h>

void Bin2Dec(){

  int  nbBin, valeur_binaire, valeur_decimale = 0;

  int base = 1;

  int reste;

  printf("Donner un nombre en binaire : \n");

  scanf("%d", &nbBin);

  valeur_binaire = nbBin;

  while (nbBin > 0)

  {

      reste = nbBin % 10;

      valeur_decimale = valeur_decimale + reste * base;

      nbBin = nbBin / 10 ;

      base = base * 2;

  }

  printf("<%d>2 = <%d>10 \n",valeur_binaire,valeur_decimale);




}


int main() {

Bin2Dec();

return EXIT_SUCCESS;
}
