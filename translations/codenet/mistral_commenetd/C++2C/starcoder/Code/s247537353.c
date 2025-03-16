#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

int main(){
  // Read input values from the standard input
  int A,B,C,K;
  scanf("%d%d%d%d",&A,&B,&C,&K);

  // Check if the sum of A and B is greater than or equal to K
  if(A+B>=K){
    // If true, print the minimum value between A and K
    printf("%d\n",min(A,K));
  }else{
    // If false, calculate the difference between K and the sum of A and B,
    // and subtract it from A to get the required value
    printf("%d\n",A-(K-(A+B)));
  }
}

