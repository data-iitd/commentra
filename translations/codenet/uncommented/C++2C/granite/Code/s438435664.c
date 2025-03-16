
#include <stdio.h>

int main(){
  int n,k;
  scanf("%d %d",&n,&k);
  int sum = 0;
  for(int b = 1; b <= n; b++){
    int cnt = (n+1)/b;
    int md = (n+1)%b;
    sum+=cnt*max((b-k),0)+max((md-k),0);
    if(k==0) sum--;
  }
  printf("%d\n",sum);
  return 0;
}
