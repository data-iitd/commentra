
#include<stdio.h>
#include<stdlib.h>
 
int main(){ 
  int N; scanf("%d",&N);
  int *X = (int *)malloc(sizeof(int)*N);
  int *Y = (int *)malloc(sizeof(int)*N);
  for(int i = 0; i < N; i++){ scanf("%d",&X[i]); Y[i] = X[i]; }
  
  qsort(Y,N,sizeof(int));
  
  int y = Y[N/2];
  for(int i = 0; i < N; i++){
    if( X[i] < Y[N/2]){printf("%d\n",Y[N/2]);}
    else{printf("%d\n",Y[N/2 - 1]);}
  }
  free(X);free(Y);return 0;}

