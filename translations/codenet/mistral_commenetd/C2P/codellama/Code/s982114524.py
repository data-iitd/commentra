
#include <stdio.h>
#include <stdlib.h>

#define N 10

int main(void){
  int i, x;
  x = 0;

  for(i=1; i<=N; i++){
    x += i;
  }

  printf("The sum of numbers from 1 to %d is: %d\n", N, x);

  return 0;
}

