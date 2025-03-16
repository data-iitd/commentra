#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <limits.h>
#include <float.h>
#include <assert.h>

#define INF (1LL << 61) - 1
#define MOD 1000000007
#define ALL(a) (a).begin(),(a).end()
#define rALL(a) (a).rbegin(),(a).rend()
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)

int main(){
  int A,B,C,K;
  scanf("%d %d %d %d",&A,&B,&C,&K);
  if(A+B>=K){
    printf("%d\n",min(A,K));
  }else{
    printf("%d\n",A-(K-(A+B)));
  }
}

