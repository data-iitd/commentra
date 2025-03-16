#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define intmax INT_MAX
#define lmax LONG_MAX
#define uintmax UINT_MAX
#define ulmax ULONG_MAX
#define llmax LLONG_MAX
#define ll long long
#define rep(i,a,N) for(i=a;i<N;i++)
#define rrp(i,N,a) for(i=N-1;i>=a;i--)
#define llfor ll i,j
#define sc(a) scanf("%lld", &a)
#define pr(a) printf("%lld\n", a)
#define pY puts("YES")
#define pN puts("NO")
#define py puts("Yes")
#define pn puts("No")
#define pnn printf("\n")
#define all(a) a.begin(),a.end()
#define push(a,b) (a).push_back(b)
#define llvec vector<vector<ll>>
#define charvec vector<vector<char>>
#define size(a,b) (a,vector<ll>(b))
#define llpvec vector<pair<ll,ll>>
#define pi acos(-1)
#define cei(x,y) ((x)/y + ((x)%y ? 1 : 0))
#define gcd(x,y) (y ? gcd(y,x%y) : x)
#define lcm(x,y) ((x)/gcd(x,y)*y)
#define llpow(x,n) (i,ans=1;for(i=0;i<n;i++)ans*=x;ans)
#define fact(x) (i,ans=1;for(i=0;i<x;i++)ans*=(x-i);ans)
#define ncr(n,r) (fact(n)/fact(r)/fact(n-r))
#define npr(n,r) (fact(n)/fact(n-r))
#define prime(a) (a<=1 ? 0 : i,for(i=2;i*i<=a;i++)if(a%i==0)return 0;1)
#define fib(x) (i,fibo[x+10]={1,1,1},for(i=3;i<=x;i++)fibo[i]=fibo[i-1]+fibo[i-2];fibo[x])
#define dig(n) (d=0,i=0,while(n/10>0)i++,d++)

int main(){
 ll h,w;
 scanf("%lld %lld", &h, &w);
 char t[10], s[10]="snuke";
 for(i=0;i<h;i++){
  for(j=0;j<w;j++){
   sc(t);
   if(!strcmp(s,t)){
    char c='A'+j;
    printf("%c%lld\n", c, i+1);
    return 0;
   }
  }
 }

return 0;
}
