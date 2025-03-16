
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
#include <string>
#include <bitset>
#define MOD 100000007
#define MAX_N 1000000
#define MAX_M 1000000
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> iP;
typedef pair<P,P> PP;
int n,m;
int a[MAX_N];
ll fact[MAX_M];
ll inv[MAX_N];
ll sum[MAX_N];
int main(){
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  fact[0]=1;
  for(int i=1;i<MAX_M;i++){
    fact[i]=fact[i-1]*i%MOD;
  }
  inv[1]=1;
  for(int i=2;i<MAX_N;i++){
    inv[i]=(MOD-MOD/i)*inv[MOD%i]%MOD;
  }
  sum[0]=inv[1];
  for(int i=1;i<MAX_N;i++){
    sum[i]=sum[i-1]+inv[i+1];
    sum[i]%=MOD;
  }
  ll ans=0;
  for(int i=0;i<n;i++){
    ans+=a[i]*(sum[i]+sum[n-1-i]-1)%MOD;
    ans%=MOD;
  }
  ans%=MOD;
  ans*=fact[n];
  ans%=MOD;
  printf("%lld\n",ans);
  return 0;
}
