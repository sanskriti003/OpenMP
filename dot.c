//c program to find dot product of vectors using openmp
#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
int main(int argc,char *argv[]){
double sum, a[256],b[256];
int i,n=256;
for(i=0;i<n;i++){
    a[i]=i*0.5;
    b[i]=i*2.0;
}
sum=0;
for(i=0;i<n;i++)
    sum+=a[i]*b[i];
printf("a*b=%f\n",sum);
}
