#include <stdlib.h>   
#include <stdio.h>   
#include <omp.h>      //OpenMP header
#define ARRAY_SIZE 8  //Size of arrays whose elements will be added
int main (int argc, char *argv[])
{
// elements of arrays a and b will be added
// and stored in array c
int * a;
int * b;
int * c;
int n = ARRAY_SIZE;                 // number of array elements
int n_per_thread;                   // elements per thread
int total_threads = omp_get_num_threads();    // number of threads to use
int i;       // loop index
// allocating space for the arrays
a = (int *) malloc(sizeof(int)*n);
b = (int *) malloc(sizeof(int)*n);
c = (int *) malloc(sizeof(int)*n);
// initializing array a and b with consecutive integer values
for(i=0; i<n; i++) {
a[i] = i;
}
for(i=0; i<n; i++) {
b[i] = i;
}
omp_set_num_threads(total_threads);
// determining how many elements each process will work on
n_per_thread = n/total_threads;
#pragma omp parallel for shared(a, b, c) private(i) schedule(static, n_per_thread)
for(i=0; i<n; i++) {
c[i] = a[i]+b[i];
printf("Thread %d works on element%d\n", omp_get_thread_num(), i);
}
printf("i\ta[i]\t+\tb[i]\t=\tc[i]\n");
for(i=0; i<n; i++) {
printf("%d\t%d\t\t%d\t\t%d\n", i, a[i], b[i], c[i]);
}
// cleaning up memory
free(a);  free(b); free(c);
return 0;
}
