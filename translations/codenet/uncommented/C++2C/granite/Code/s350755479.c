
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;

#define MAX_N 100000
#define MOD 100000007
#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i=0;i<n;i++)
#define forn(i,n) for(int i=1;i<=n;i++)
#define N 100000007

int n,fa[MAX_N+5];
struct node{
    int x,y,id;
}a[MAX_N+5];
struct edge{
    int u,v,val;
    bool operator <(const edge &a)const{
        return val<a.val;
    }
}e[MAX_N*2+5];

bool cmp1(node a,node b){
    return a.x<b.x;
}
bool cmp2(node a,node b){
    return a.y<b.y;
}

int find(int x){
    if(fa[x]==x) return x;
    return fa[x]=find(fa[x]);
}

int main(){
    scanf("%d",&n);
    forn(i,n){
        scanf("%d%d",&a[i].x,&a[i].y);
        a[i].id=i;
    }
    sort(a+1,a+n+1,cmp1);
    int cnt=0;
    forn(i,n-1){
        e[cnt].u=a[i].id;
        e[cnt].v=a[i+1].id;
        e[cnt].val=a[i+1].x-a[i].x;
        cnt++;
    }
    sort(a+1,a+n+1,cmp2);
    forn(i,n-1){
        e[cnt].u=a[i].id;
        e[cnt].v=a[i+1].id;
        e[cnt].val=a[i+1].y-a[i].y;
        cnt++;
    }
    sort(e,e+cnt);
    ll ans=0;
    forn(i,n) fa[i]=i;
    forn(i,cnt){
        int u=e[i].u,v=e[i].v,val=e[i].val;
        if(find(u)==find(v)) continue;
        fa[find(u)]=find(v);
        ans+=val;
    }
    printf("%lld\n",ans);
    return 0;
}

