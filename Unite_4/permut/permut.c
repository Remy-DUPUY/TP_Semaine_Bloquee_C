#include <stdio.h>
#include <stdlib.h>

// avec les pointeurs :
void Permut(int* adr_a, int* adr_b) {
  int temp = 0;
  temp = *adr_a;  // temp = la valeur à l'adresse de a
  *adr_a = *adr_b;
  *adr_b = temp;
}


int main(int argc, char const *argv[]) {

int a,b;

a = 2;
b = 5;


printf("Avant la permutation, a = %d et b = %d\n",a , b);

Permut(&a,&b);

printf("Apres la permutation, a = %d et b = %d\n", a, b);


  return EXIT_SUCCESS;
}
