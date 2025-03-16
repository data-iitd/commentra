#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <limits.h>
#include <ctype.h>
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sqr(x) ((x)*(x))
#define INF 1000000000
#define MOD 1000000007
#define EPS 1e-9
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<vpii> vvpii;
typedef set<int> si;
typedef set<ll> sll;
typedef set<pii> spii;
typedef set<vi> svi;
typedef set<vll> svll;
typedef set<vpii> svpii;
typedef multiset<int> msi;
typedef multiset<ll> msll;
typedef multiset<pii> mspii;
typedef multiset<vi> msvi;
typedef multiset<vll> msvll;
typedef multiset<vpii> msvpii;
typedef map<int,int> mii;
typedef map<ll,ll> mll;
typedef map<pii,pii> mpii;
typedef map<vi,vi> mvi;
typedef map<vll,vll> mvll;
typedef map<vpii,vpii> mvpii;
int n,ta,ao;
vi g[100005];
int ta_dist[100005],ao_dist[100005];
void ta_dfs(int node){
    for(int v:g[node]){
        if(ta_dist[v]!=NULL) continue;
        ta_dist[v]=ta_dist[node]+1;
        ta_dfs(v);
    }
}
void ao_dfs(int node){
    for(int v:g[node]){
        if(ao_dist[v]!=NULL) continue;
        ao_dist[v]=ao_dist[node]+1;
        ao_dfs(v);
    }
}
int main(){
    scanf("%d%d%d",&n,&ta,&ao);
    ta--;ao--;
    for(int i=0;i<n-1;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        g[a].pb(b);
        g[b].pb(a);
    }
    ta_dfs(ta);
    ao_dfs(ao);
    int res=0;
    for(int i=0;i<n;i++){
        if(ta_dist[i]>ao_dist[i]) continue;
        res=max(res,ao_dist[i]);
    }
    printf("%d\n",res-1);
    return 0;
}
