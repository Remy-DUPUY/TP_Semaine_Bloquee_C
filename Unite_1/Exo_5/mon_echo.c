#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
 *
 */


// argc = arguments count et argv = arguments values
int main(int argc, char** argv) {

 int i;

   for (i=1; i < argc; i++){

// strchr recherche la première occurrence du caractère passé en second paramètre (' ')
// dans la chaîne de caractères spécifiée via le premier paramètre (argv[i]).
   if(strchr(argv[i],' ')){
     printf(" %s  ",argv[i]);
   } else{
      printf("%s",argv[i]);
   }


  }
   printf("\n");

    return EXIT_SUCCESS;
}
