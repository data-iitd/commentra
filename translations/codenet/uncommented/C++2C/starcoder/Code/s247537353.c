#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

int main(){
  int A,B,C,K;
  scanf("%d%d%d%d",&A,&B,&C,&K);
  if(A+B>=K){
    printf("%d\n",min(A,K));
  }else{
    printf("%d\n",A-(K-(A+B)));
  }
}

