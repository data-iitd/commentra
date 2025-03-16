#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#define INF 1000000000
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
