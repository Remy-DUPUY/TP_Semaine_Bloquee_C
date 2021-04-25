#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {

int entier1 = atoi(argv[1]); // premier entier

char operateur = argv[2][0]; // opérateur

int entier2 = atoi(argv[3]); // deuxième entier


// conditions principales

if(operateur == '+'){
    printf("%i %c  %i = %i\n",entier1,operateur,entier2,entier1+entier2);
}

else if (operateur == '-'){
    printf("%i %c  %i = %i\n",entier1,operateur,entier2,entier1-entier2);
}

else if (operateur == 'x'){
    printf("%i %c  %i = %i\n",entier1,operateur,entier2,entier1*entier2);
}

else if (operateur == '/'){
    if(entier1 == 0 || entier2 == 0){
      printf("Il est impossible de diviser par 0 ! \n");
    } else{
      printf("%i %c  %i = %i\n",entier1,operateur,entier2,entier1/entier2);
    }
}

else{
  printf("Entrée incorrecte, opérateur faux \n");
}


  return EXIT_SUCCESS;
}
