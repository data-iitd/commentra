
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <assert.h>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <complex>
#include <bitset>
#include <stack>
#include <iomanip>
#include <numeric>
#include <functional>
using namespace std;
#define MOD 100000007
#define REP(i,n) for(int i=0; i<(int)(n); i++)
typedef long long ll;
typedef pair<int,int> pint;
typedef pair<ll,ll> pll;
#define mp make_pair
#define pb push_back
#define all(s) (s).begin(),(s).end()
#define fi first
#define se second

int n,k;
vector<int> g[100005];
ll dfs(int v,int p,int f){
    ll ret=1;
    int c=k-1;
    if(f==k) c--;
    for(int u : g[v]){
        if(u==p) continue;
        if(c==0) return 0;
        ret=ret*dfs(u,v,c)%MOD;
        c--;
    }
    return ret;
}

int main(){
    cin>>n>>k;
    REP(i,n-1){
        int a,b;
        cin>>a>>b;
        a--;b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    cout<<dfs(0,-1,0)<<endl;
    return 0;
}

