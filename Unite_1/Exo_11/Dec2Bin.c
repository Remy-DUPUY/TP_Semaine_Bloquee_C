#include <stdio.h>
#include <stdlib.h>


void Dec2Bin(){

  int tab[10], nbDecimal, i;

    printf("Donner un nombre en décimal: \n");
    scanf("%d",&nbDecimal);

printf("<%d>10 = ",nbDecimal);

    for(i = 0; nbDecimal > 0; i++)
    {
      tab[i] = nbDecimal%2; // reste
      nbDecimal = nbDecimal/2;
    }

printf("<");

    for(i = i-1; i >= 0; i--)
    {

      printf("%d",tab[i]);
    }

printf(">2\n");

printf("\n");

}


int main(int argc, char const *argv[]) {
  Dec2Bin();

  return 0;
}
