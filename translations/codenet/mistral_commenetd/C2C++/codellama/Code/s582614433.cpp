#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
#define rep(i,l,r)for(ll i=(l);i<(r);i++) // for loop with initialization, condition, and increment
#define repp(i,l,r,k)for(ll i=(l);i<(r);i+=(k)) // for loop with initialization, limit, increment, and loop variable name
#define INF ((1LL<<62)-(1LL<<31)) // constant value for infinity
#define max(p,q)((p)>(q)?(p):(q)) // macro for finding maximum of two values
#define min(p,q)((p)<(q)?(p):(q)) // macro for finding minimum of two values
#define bit(n,m)(((n)>>(m))&1) // macro for checking the bit at position m in binary representation of n
#define upll(a,b)return *(ll*)a<*(ll*)b?-1:*(ll*)a>*(ll*)b?1:0; // comparison function for qsort() to sort in ascending order
#define downll(a,b)return *(ll*)a<*(ll*)b?1:*(ll*)a>*(ll*)b?-1:0; // comparison function for qsort() to sort in descending order
void sortup(ll*a,int n){ // function to sort an array in ascending order using qsort()
	qsort(a,n,sizeof(ll),upll);
}
void sortdown(ll*a,int n){ // function to sort an array in descending order using qsort()
	qsort(a,n,sizeof(ll),downll);
}
ll pom(ll a,ll n,int m){ // function to calculate (a^n) % m using modular exponentiation
	ll x=1;
	for(a%=m;n;n/=2)
		n&1?x=x*a%m:0,
		a=a*a%m;
	return x;
}
//#define MOD 998244353 // uncomment this line if you want to use a specific modulo value
#define MOD 1000000007 // constant value for the modulo
#define invp(a,p)pom(a,p-2,p) // macro for calculating the modular inverse of a number a with respect to modulo p
// Data structure for an edge with source string, destination vertex, and weight
struct edge{
	ll p,i; // p: destination vertex, i: index of the edge in the data array
	char s[20]; // source string
};
bool esort(edge a,edge b){ // comparison function for sorting edges based on their source strings and destination vertices
	if(strcmp(a.s,b.s))return strcmp(a.s,b.s)<0; // compare source strings first
	return a.p<b.p; // if source strings are equal, compare destination vertices
}
edge data[100]; // array to store edges
ll n; // number of vertices
int main(){ // main function
	scanf("%lld",&n); // read the number of vertices
	rep(i,0,n){ // for each vertex
		scanf(" %s%lld",data[i].s,&data[i].p); // read the source string and destination vertex
		data[i].i=i; // assign the index of the edge to the edge itself
	}
	sort(data,data+n,esort); // sort the edges based on their source strings and destination vertices
	rep(i,0,n)printf("%lld\n",data[i].i+1); // print the indices of the sorted edges
}
