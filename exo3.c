#include <stdlib.h>
#include <stdio.h>
int main() {
 const int DIM = 1000;
 int i,j,k;
 double **a, **b, **cresu, **ctest;
 a= (double**) malloc(DIM*sizeof(double*));
 b= (double**) malloc(DIM*sizeof(double*));
 cresu= (double**) malloc(DIM*sizeof(double*));
 ctest= (double**) malloc(DIM*sizeof(double*));
 
 /* Initialisation */
 for (i=0; i<DIM; i++) {
 a[i]=(double*) malloc(DIM*sizeof(double));
 b[i]=(double*) malloc(DIM*sizeof(double));
 cresu[i]=(double*) malloc(DIM*sizeof(double));
 ctest[i]=(double*) malloc(DIM*sizeof(double));

 #pragma omp parallel 
 for (j = 0; j < DIM; j++) {
 a[i][j] = (double)(i-j);
 b[i][j] = (double)(i+j);
 cresu[i][j] = 0.0; ctest[i][j] = 0.0;
 }
 }
 
 /* Multiplication séquentielle */
 for (i = 0; i < DIM; i++)
 for (j = 0; j < DIM; j++)
 for (k = 0; k < DIM; k++)
 ctest[i][j] += a[i][k] * b[k][j];
 return 0;
}
