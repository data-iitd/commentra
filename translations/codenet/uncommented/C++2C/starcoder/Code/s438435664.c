#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

// 最小公倍数
int gcd(int x, int y) {
  int tmp = 0;
  if (x < y){
    tmp=x;
    x=y;
    y=tmp;
  }
  while (y > 0) {
    int r = x % y;
    x = y;
    y = r;
  }
  return x;
}

// 最大公倍数
int lcm(int x,int y){
  return x/gcd(x,y)*y;
}

// 階乗
int kaijo(int k){
    int sum = 1;
    for (int i = 1; i <= k; ++i)
    {
        sum *= i;
    }
    return sum;
}

//for(int i = ; i < ; i++){}

int lmax(int s,int t){
  if(s>t){
    return s;
  }
  else{
    return t;
  }
}

int lmin(int s,int t){
  if(s<t){
    return s;
  }
  else{
    return t;
  }
}
// ここから開始

int main(){
  int n,k;
  scanf("%d%d",&n,&k);
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

