//Question 01 : Le nombre de threads et le type d'ordonnancement des itérations, ne sont pas spécifiés
/*
- Le nombre de threads n'est pas spécifié, l'ordonnancement des itérations est statique et 
la taille du bloc d'itérations assigné aux threads (chunk), n'est pas précisée.
- Le nombre de threads n'est pas spécifié, l'ordonnancement des itérations est statique et 
la taille du bloc d'itérations assigné aux threads (chunk), égale à 50.
- Le nombre de threads n'est pas spécifié, l'ordonnancement des itérations est
dynamique et la taille du bloc d'itérations assigné aux threads (chunk), n'est pas 
précisée.
- Le nombre de threads n'est pas spécifié, l'ordonnancement des itérations est 
dynamique et la taille du bloc d'itérations assigné aux threads (chunk), égale à 50.
*/
#include<stdio.h>
#include <omp.h>
int main (){ 
 static long nb_steps = 100000;
 double steps;
 int i; 
 double x, pi, sum = 0.0;
 
 steps = 1.0/(double) nb_steps;
 
 double start = omp_get_wtime();
 
 #pragma omp parallel
 {
 #pragma omp for
 //#pragma omp for schedul(static, 50)
  //#pragma omp for schedul(static)
    //#pragma omp for schedul(dynamic, 50)
     //#pragma omp for schedul(dynamic)


 for (i=1; i<= nb_steps; i++){
 x = (i-0.5)*steps;
 sum = sum + 4.0/(1.0+x*x);
 }
}
 double finish = omp_get_wtime();
 pi = steps * sum;
 
 printf("PI=%f\n Execution time = %f\n", pi, finish-start);
 return 0;
}
