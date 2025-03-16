#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>

using namespace std;

typedef long long ll;

void swap (int *x, int *y) {
  int temp;

  temp = *x;
  *x = *y;
  *y = temp;

  return;
}


ll gcd(ll a, ll b){
  ll c;

  while (b > 0){
    c = a % b;
    a = b;
    b = c;
  }

  return a;
}

int upll(const void*a, const void*b){
  return*(ll*)a<*(ll*)b?-1:*(ll*)a>*(ll*)b?1:0;
}

int downll(const void*a, const void*b){
  return*(ll*)a<*(ll*)b?1:*(ll*)a>*(ll*)b?-1:0;
}

void sortup(ll*a,int n){
  qsort(a,n,sizeof(ll),upll);
}

void sortdown(ll*a,int n){
  qsort(a,n,sizeof(ll),downll);
}

ll modpow(ll a,ll n,ll mod){
  ll ans=1;
  while(n>0){
    if(n & 1){
      ans=ans*a%mod;
    }
    a=a*a%mod;
    n/=2;
  }
  return ans;
}

ll modinv(ll a,ll mod){
  return modpow(a,mod-2,mod);
}

int max(int a,int b){
  if(a<b){
    return b;
  }
  else{
    return a;
  }
}

int min(int a,int b){
  if(a<b){
    return a;
  }
  else{
    return b;
  }
}

void chmax(int *a,int b){
  if(*a < b){
    *a = b;
  }

  return;
}

void chmin(int *a,int b){
  if(*a > b){
    *a =b;
  }

  return;
}


int main(void){
  int n;
  scanf("%d",&n);
  int sum=0;
  int m=n;
  for(int i=0;i<9;i++){
    sum+=n%10;
    n/=10;
  }
  if(m%sum==0){
    printf("Yes\n");
  }else{
    printf("No\n");
  }
  return 0;
}

