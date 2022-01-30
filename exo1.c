/* OpenMP exo 1*/


/* Question 01*/

#include <stdio.h>
#include <omp.h>
#define SIZE 100
int main() {
 long a[SIZE], b[SIZE], c[SIZE], d[SIZE];
 for (size_t i = 0; i < SIZE; i++)
 a[i] = b[i] = i;
 #pragma omp parallel
 {
 #pragma omp for schedule(static) no wait 
 // #pragma omp for schedule (static)
 for (size_t i = 0; i < SIZE; i++)
 c[i] = a[i] + b[i];
 
 #pragma omp for schedule(static)
 for (size_t i = 0; i < SIZE; i++)
 d[i] = a[i] + c[i];
 }
 
 
 for (size_t i = 0; i < SIZE; i++)
 printf("%ld \n", d[i]);
 return 0;
}

//Le nowait dans la ligne 15 empeche d'avoir le résultat correct car le calcul de C doit se finir entièrement 
// avant de passer à la prochaine boucle, meme si le nombre d'itérations alloué à un thread est le meme mais 
// on est pas sur que c'est exactement le meme bloc d'itérations
// Solution 1 : enlever le nowait 

/*Question 02*/ 
//Une meilleure solution pour optimiser le temps d'attente des autres threads est 

#include <stdio.h>
#include <omp.h>
#define SIZE 100
int main() {
 long a[SIZE], b[SIZE], c[SIZE], d[SIZE];
 for (size_t i = 0; i < SIZE; i++)
 a[i] = b[i] = i;
 #pragma omp parallel
 {
 #pragma omp for collapse(2)
 {
 // #pragma omp for schedule (static)
 for (size_t i = 0; i < SIZE; i++)
 c[i] = a[i] + b[i];
 
 for (size_t i = 0; i < SIZE; i++)
 d[i] = a[i] + c[i];
 }
 }
 
 for (size_t i = 0; i < SIZE; i++)
 printf("%ld \n", d[i]);
 return 0;
}
