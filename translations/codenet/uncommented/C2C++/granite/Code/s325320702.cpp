

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<stdbool.h>
#include<assert.h>
#include<ctype.h>
typedef long long ll;
typedef long double ld;
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define repp(i,l,r,k)for(ll i=(l);i<(r);i+=(k))
#define rrep(i,l,r)for(ll i=(l);i>=(r);i--)
#define INF (1LL<<60)
#define MOD1 1000000007
#define MOD2 998244353
#define MAX_N (1 << 20)
#define YES printf("Yes\n")
#define NO printf("No\n")
#define PN printf("\n")
#define charsize 100005 //10^5+5
#define PI 3.141592653589793238

void swap(ll *a, ll *b){ll c;c=*b;*b=*a;*a= c;}
void cin(ll *n){ scanf("%lld",&(*n)); }
ll max2(ll a,ll b){return a>=b?a:b;}
ll min2(ll a,ll b){return a>=b?b:a;}
ll min3(ll a, ll b, ll c){return (a<=b && a<=c)? a : b<=c? b : c;}
ll max3(ll a, ll b, ll c){return (a>=b && a>=c)? a : b>=c? b : c;}
ll minn(ll n, ll a[]){ll b=INF;rep(i,0,n) b=min2(b,a[i]);return b;}
ll maxn(ll n, ll a[]){ll b=-INF;rep(i,0,n) b=max2(b,a[i]);return b;}
ll POW(ll a, ll b){ll c=1;rep(i,0,b) c*=a;return c;}
double POW_d(double a, double b){double c=1;rep(i,0,b) c*=a;return c;}
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
ll mod_MOD1(ll n){n+= n<0?((-n)/MOD1+1)*MOD1:0; return n%=MOD1;}
ll mod_p(ll n,ll p){n+= n<0?((-n)/p+1)*p:0; return n%=p;}
ll change_into_num(char s[], ll len, ll p){ return!p? 0 : POW(10,p-1)*(s[len-p]-'0') + change_into_num(s,len,p-1); }
ll digits(ll a, ll b){return a/b?1+digits(a/b,b):1;}
ll base(ll n, ll a, ll i){return i==1?n%a:base(n/a,a,i-1);}
ll is_inArr1(ll x, ll n){ return ( x<0 || x>=n )? 0 : 1 ; }
ll is_inArr2(ll y, ll x, ll h, ll w){ return ( y<0 || y>=h || x<0 || x>=w )? 0 : 1 ; }


void lr_lower( int *l, int *r, ll am, ll val, int type ){ (type<3)? ( am < val?  ( *l = (*l+*r)/2 ) : ( *r= (*l+*r)/2 ) ) : ( am <= val? ( *l = (*l+*r)/2 ) : ( *r= (*l+*r)/2 ) ); }
void lr_upper( int *l, int *r, ll am, ll val, int type ){ (type<3)? ( am <= val?  ( *l = (*l+*r)/2 ) : ( *r= (*l+*r)/2 ) ) : ( am < val? ( *l = (*l+*r)/2 ) : ( *r= (*l+*r)/2 ) ); }
int cmp_lower( ll a, ll b, int type ){ return (type==1)? ( a==b? 1 : 0 ) : (type==2)? ( a>=b? 1 : 0 ) : ( a>b? 1 : 0 ) ; }
int cmp_upper( ll a, ll b, int type ){ return (type==1)? ( a==b? 1 : 0 ) : (type==2)? ( a<=b? 1 : 0 ) : ( a<b? 1 : 0 ) ; }
// return smallest p  which meets  a[p]==val :1  >=:2   >:3
ll lower_bound( ll a[], int l, int r, ll val, int type ){  while(r-l>1) lr_lower(&l,&r,a[ (l+r)/2 ],val,type);  return cmp_lower(a[l],val,type)? l : cmp_lower(a[r],val,type)? r : -1;  }
// return biggest p  which meets   a[p]==val :1  <=:2   <:3
ll upper_bound( ll a[], int l, int r, ll val, int type ){  while(r-l>1) lr_upper(&l,&r,a[ (l+r)/2 ],val,type); return cmp_upper(a[r],val,type)? r : cmp_upper(a[l],val,type)? l : -1; }
// count i  which meets ai==x
ll count(ll a[], int l, int r, ll x){  int p = lower_bound(a,l,r,x,1);  return p==-1? 0 : upper_bound(a,p,r,x,1)-p+1; }

ll *factors[2], fac_cnt=0, is_factor_prepared=0;
ll factor_pre(){  rep(i,0,1){ if(is_factor_prepared++) return 0; }  ll tmp=(1e6)/2+1, fac_tmp[tmp];  rep(i,0,tmp){fac_tmp[i]=i?2*i+1:2;}  rep(i,1,tmp){if(fac_tmp[i]==i?0:1){  rep(i,1,tmp){fac_tmp[i]=i?0:1;}  rep(i,1,tmp){if(fac_tmp[i]==i?0:1){  rep(i,1,tmp){if(fac_tmp[i]==i?0:1){  rep(i,1,tmp){if(fac_tmp[i]==i?0:1){  rep(i,1,tmp){if(fac_tmp[i]==i?0:1){  rep(i,1,tmp){if(fac_tmp[i]==i?0:1){  rep(i,1,tmp){if(fac_tmp[i]==i?0:1){  rep(i,1,tmp){if(fac_tmp[i]==i?0:1){  rep(i,1,tmp){if(fac_tmp[i]==i?0:1){  rep(i,1,tmp){if(fac_tmp[i]==i?0:1){  rep(i,1,tmp){if(fac_tmp[i]==i?0:1){  rep(i,1,tmp){if(fac_tmp[i]==i?0:1){  rep(i,1,tmp){if(fac_tmp[i]==i?0:1){  rep(i,1,tmp){if(fac_tmp[i]==i?0:1){  rep(i,1,tmp){if(fac_tmp[i]==i?0:1){  rep(i,1,tmp){if(fac_tmp[i]==i?0:1){  rep(i,1,tmp){if(fac_tmp[i]==i?0:1){  rep(i,1,tmp){if(fac_tmp[i]==i?0:1){  rep(i,1,tmp){if(fac_tmp[i]==i?0:1){  rep(i,1,tmp){if(fac_tmp[i]==i?0:1){  rep(i,1,tmp){if(fac_tmp[i]==i?0:1){  rep(i,1,tmp){if(fac_tmp[i]==i?0:1){  rep(i,1,tmp){if(fac_tmp[i]==i?0:1){  rep(i,1,tmp){if(fac_tmp[i]==i?0:1){  rep(i,1,tmp){if(fac_tmp[i)==i?0:1){  rep(i,1,tmp){if(fac_tmp[i)==i?0:1){  rep(i,1,tmp){if(fac_tmp[i)==i?0:1){  rep(i,1,tmp){if(fac_tmp[i)==i?0:1){  rep(i,1,tmp){if(fac_tmp[i)==i?0:1){  rep(i,1,tmp){if(fac_tmp[i)==i?0:1){  rep(i,1,tmp){if(fac_tmp[i)==i?0:1){  rep(i,1,tmp){if(fac_tmp[i)==i?0:1){  rep(i,1,tmp){if(fac_tmp[i)==i?0:1){  rep(i,1,tmp){if(fac_tmp[i)==i?0:1){  rep(i,1,tmp){if(fac_tmp[i)==i?0:1){  rep(i,1,tmp){if(fac_tmp[i)==i?0:1){  rep(i,1,tmp){if(fac_tmp[i)==i?0:1){  rep(i,1,tmp){if(fac_tmp[i)==i?0:1){  rep(i,1,tmp){if(fac_tmp[i)==i?0:1){  rep(i,1,tmp){if(fac_tmp[i)==i?0:1){  rep(i,1,tmp){if(fac_tmp[i)==i?0:1){  rep(i,1,tmp){if(fac_tmp[i)==i?0:1){  rep(i,1,tmp){if(fac_tmp[i)==i?0:1){  rep(i,1,tmp){if(fac_tmp[i)==i?0:1){  rep(i,1,tmp){if(fac_tmp[i)==i?0:1){if(fac_tmp[i)==i?0:1){  rep(i,1,tmp){if(fac_tmp[i)==i?0:1){

ll P(ll a,ll b){return (a/b);
ll P(ll a,ll b){return (a%b);
ll P(ll a,ll b){return (a/b);
ll P(ll a,ll b){return (a%b);
ll P(ll a,ll b){return (a/b);
ll P(ll a,ll b){return (a%b);
ll P(ll a,ll b){return (a/b);
ll P(ll a,ll b){return (a*b);
ll P(ll a,ll b){return (a%b);
ll P(ll a,ll b){return (a/b);
ll P(ll a,ll b){return (a*b);
ll P(ll a,ll b){return (a%b);
ll P(ll a,ll b){return (a/b);
ll P(ll a,ll b){return (a<b);
ll P(ll a,ll b){return (a/b);
ll P(ll a,ll b){return (a%b);
ll P(ll a,ll b){return (a<b);
ll P(ll a,ll b){return (a/b);
ll P(ll a,ll b){return (a%b);
ll P(ll a,ll b){return (a<b);
ll P(ll a,ll b){return (a/b);
ll P(ll a,ll b){return (a%b);
ll P(ll a,ll b){return (a<b);
ll P(ll a,ll b){return (a/b);
ll P(ll a,ll b){return (a%b);
ll P(ll a,ll b){return (a/b);
ll P(ll a,ll b){return (a<b);
ll P(ll a,ll b){return (a/b);
ll P(ll a,ll b){return (a%b);
ll P(ll a,ll b){return (a<b);
ll P(ll a,ll b){return (a/b);
ll P(ll a,ll b){return (a%b);
ll P(ll a,ll b){return (a<b);
ll P(ll a,ll b){return (a/b);
ll P(ll a,ll b){return (a%b);
ll P(ll a,ll b){return (a<b);
ll P(ll a,ll b){return (a/b);
ll P(ll a,ll b){return (a%b);
ll P(ll a,ll b){return (a<b);
ll P(ll a,ll b){return (a/b);
ll P(ll a,ll b){return (a%b);
ll P(ll a,ll b){return (a<b);
ll P(ll a,ll b){return (a/b);
ll P(ll a,ll b){return (a<b);
ll P(ll a,ll b){return (a/b);
ll P(ll a,ll b){return (a%b);
ll P(ll a,ll b){return (a<b);
ll P(ll a,ll b){return (a/b);
ll P(ll a,ll b){return (a%b);
ll P(ll a,ll b){return (a<b);
ll P(ll a,ll b){return (a/b);
ll P(ll a,ll b){return (a<b);
ll P(ll a,ll b){return (a/b);
ll P(ll a,ll b){return (a%b);
ll P(ll a,ll b){return (a/b);
ll P(ll a,ll b){return (a<b);
ll P(ll a,ll b){return (a/b);
ll P(ll a,ll b){return (a<b);
ll P(ll a,ll b){return (a/b);
ll P(ll a,ll b){return (a%b);
ll P(ll a,ll b){return (a<b);
ll P(ll a,ll b){return (a/b);
ll P(ll a,ll b){return (a%b);
ll P(ll a,ll b){return (a/b);
ll P(ll a,ll b){return (a<b);
ll P(ll a,ll b){return (a/b);
ll P(ll a,ll b){return (a%b);
ll P(ll a,ll b){return (a/b);
ll P(ll a,ll b){return (a<b);
ll P(ll a,ll b){return (a/b);
ll P(ll a,ll b){return (a<b);
ll P(ll a,ll b){return (a/b);
ll P(ll a,ll b){return (a%b);
ll P(ll a,ll b){return (a/b);
ll P(ll a,ll b){return (a<b);
ll P(ll a,ll b){return (a/b);
ll P(ll a,ll b){return (a<b);
ll P(ll a,ll b){return (a/b);
ll P(ll a,ll b){return (a<b);
ll P(ll a,ll b){return (a/b);
ll P(ll a,ll b){return (a%b);
ll P(ll a,ll b){return (a/b);
ll P(ll a,ll b){return (a<b);
ll P(ll a,ll b){return (a/b);
ll P(ll a,ll b){return (a%b);
ll P(ll a,ll b){return (a/b);
ll P(ll a,ll b){return (a<b);
ll P(ll a,ll b){return (a/b);
ll P(ll a,ll b){return (a%b);
ll P(ll a,ll b){return (a/b);
ll P(ll a,ll b){return (a<b);
ll P(ll a,ll b){return (a/b);
ll P(ll a,ll b){return (a%b);
ll P(ll a,ll b){return (a/b);
ll P(ll a,ll b){return (a<b);
ll P(ll a,ll b){return (a/b);
ll P(ll a,ll b){return (a%b);
ll P(ll a,ll b){return (a/b);
ll P(ll a,ll b){return (a<b);
ll P(ll a,ll b){return (a/b);
ll P(ll a,ll b){
ll P(ll a==i?0:1){return (a/b);
ll P(ll a,ll b){return (a<b);
ll P(ll a,ll b){return (a/b);
ll P(ll a,ll b){
ll P(ll a==i?0:1);
ll P(ll a,ll b){return (a/b);
ll P(ll a,ll b){return (a<b);
ll P(ll a,ll b){return (a/b);
ll P(ll a,ll b){return (a<b);
ll P(ll a,ll b){return (a/b);
ll P(ll a,ll b){return (a<b);
ll P(ll a,ll b){return (a/b);
ll P(ll a,ll b){return (a<b);
ll P(ll a,ll b){return (a/b);
ll P(ll a,ll b){return (a<b);
ll P(ll a,ll b){return (a/b);
ll P(ll a,ll b){return (a<b);
ll P(ll a,ll b){return (a/b);
ll P(ll a,ll b){return (a<b);
ll P(ll a,ll b);
ll P(ll a,ll b){return (a/b);
ll P(ll a,ll b);
ll P(ll a,ll b){return (a/b);
ll a,ll b){return (a<b);
ll P(ll a,ll b){return (a/b);
ll P(ll a,ll b){return (a+b);
ll P(ll a,ll b){return (a/b);
ll P(ll a,ll b){return (a<b);
ll P(ll a,ll b){return (a/b);
ll P(ll a,ll b){return (a+b);
ll P(ll a,ll b){return (a/b);
ll P(ll a,ll b){return (a