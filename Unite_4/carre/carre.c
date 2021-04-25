#include <stdio.h>
#include <stdlib.h>



int carre1(int x){

  return x*x;
}

// pointeur
int carre2(int* adr_x){

*adr_x = (*adr_x) * (*adr_x);

return *adr_x ;
}

int main(int argc, char const *argv[]) {

int a = 3;

printf("Valeur de l'entier avant l'appel de la fonction : \n");
printf("%d\n",a);

printf("Valeur de l'entier après l'appel de la fonction : \n");
carre2(&a); // pointeur sur x

printf("%d\n",a);


  return EXIT_SUCCESS;
}
