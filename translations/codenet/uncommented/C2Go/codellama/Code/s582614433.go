#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define repp(i,l,r,k)for(ll i=(l);i<(r);i+=(k))
#define INF ((1LL<<62)-(1LL<<31))
#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))
#define bit(n,m)(((n)>>(m))&1)
int upll(const void*a, const void*b){return*(ll*)a<*(ll*)b?-1:*(ll*)a>*(ll*)b?1:0;}
int downll(const void*a, const void*b){return*(ll*)a<*(ll*)b?1:*(ll*)a>*(ll*)b?-1:0;}
void sortup(ll*a,int n){qsort(a,n,sizeof(ll),upll);}
void sortdown(ll*a,int n){qsort(a,n,sizeof(ll),downll);}
ll pom(ll a,ll n,int m){ll x=1;for(a%=m;n;n/=2)n&1?x=x*a%m:0,a=a*a%m;return x;}
//#define MOD 998244353
#define MOD 1000000007
#define invp(a,p)pom(a,p-2,p)
//辺の情報を個別に持つタイプ

type E struct{
	p,i ll
	s [20]byte
}
func esort(a,b unsafe.Pointer)int{
	p,q := (*E)(a),(*E)(b)
	if(strcmp((*p).s,(*q).s))return strcmp((*p).s,(*q).s)
	if((*p).p<(*q).p)return 1
	return -1
}

var data [100]E
var n,m ll
func main(){
	fmt.Scanf("%lld",&n)
	rep(i,0,n){
		fmt.Scanf(" %s%lld",data[i].s,&data[i].p)
		data[i].i=i
	}
	qsort(data,n,sizeof(E),esort)
	rep(i,0,n)fmt.Println(data[i].i+1)
}

