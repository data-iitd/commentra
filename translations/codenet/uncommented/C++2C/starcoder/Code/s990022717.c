#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#define MAX 1000000000

int main(){
  int n,k,x,y;
  scanf("%d %d %d %d",&n,&k,&x,&y);
  int sum=0;
  for(int i=1;i<=n;i++){
    if(i>k)sum+=y;
    else sum+=x;
  }
  printf("%d\n",sum);

  return 0;
}

