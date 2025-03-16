#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define ll long long

#define swap(x,y) {int temp; temp=x; x=y; y=temp;}
#define gcd(a,b) while(b>0){int c=a%b; a=b; b=c;} return a;
#define upll(a,b) return(a<b)?-1:(a>b)?1:0;
#define downll(a,b) return(a<b)?1:(a>b)?-1:0;
#define sortup(a,n) qsort(a,n,sizeof(ll),upll);
#define sortdown(a,n) qsort(a,n,sizeof(ll),downll);
#define modpow(a,n,mod) ans=1; while(n>0){if(n & 1) ans=ans*a%mod; a=a*a%mod; n/=2;} return ans;
#define modinv(a,mod) return modpow(a,mod-2,mod);
#define max(a,b) (a<b)?b:a
#define min(a,b) (a<b)?a:b
#define chmax(a,b) if(a<b) a=b
#define chmin(a,b) if(a>b) a=b

int main(void){
  int n;
  scanf("%d",&n);
  int sum=0;
  int m=n;
  for(int i=0;i<9;i++){
    sum+=n%10;
    n/=10;
  }
  if(m%sum==0) printf("Yes\n");
  else printf("No\n");
  return 0;
}

