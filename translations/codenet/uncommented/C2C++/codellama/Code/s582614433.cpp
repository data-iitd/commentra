#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
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

struct edge{ll p,i;char s[20];};
bool esort(const edge&a,const edge&b){
	if(strcmp(a.s,b.s))return strcmp(a.s,b.s)<0;
	if(a.p<b.p)return true;
	return false;
}

ll n,m;
edge data[100];
int main(){
	cin>>n;
	rep(i,0,n){
		cin>>data[i].s>>data[i].p;
		data[i].i=i;
	}
	sort(data,data+n,esort);
	rep(i,0,n)cout<<data[i].i+1<<endl;
}

