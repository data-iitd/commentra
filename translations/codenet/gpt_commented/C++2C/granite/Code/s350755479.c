
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#define MAXN 100010
#define inf 0x3f3f3f3f
#define eps 1e-8
#define mod 100000007
#define pi acos(-1.0)
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair <int,int> pii;
typedef pair <ll,ll> pll;

ll read()
{
    ll x=0,f=1;char ch=getchar();
    while ((ch<'0'||ch>'9')&&ch!='-') ch=getchar();
    if (ch=='-') f=-1,ch=getchar();
    while (ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}

struct node
{
    int x,y,id;
} a[MAXN];

struct edge
{
    int u,v,val;
    bool operator < (const edge &bb) const
    {
        return val<bb.val;
    }
} b[MAXN*2];

int n,cnt;
int f[MAXN];

bool cmp1(node a,node b)
{
    return a.x<b.x;
}

bool cmp2(node a,node b)
{
    return a.y<b.y;
}

int find(int x)
{
    if (f[x]==x) return x;
    return f[x]=find(f[x]);
}

int main()
{
    n=read();
    for (int i=1;i<=n;i++)
    {
        a[i].x=read();
        a[i].y=read();
        a[i].id=i;
    }
    sort(a+1,a+n+1,cmp1);
    for (int i=2;i<=n;i++)
    {
        b[cnt].u=a[i-1].id;
        b[cnt].v=a[i].id;
        b[cnt].val=a[i].x-a[i-1].x;
        cnt++;
    }
    sort(a+1,a+n+1,cmp2);
    for (int i=2;i<=n;i++)
    {
        b[cnt].u=a[i-1].id;
        b[cnt].v=a[i].id;
        b[cnt].val=a[i].y-a[i-1].y;
        cnt++;
    }
    sort(b,b+cnt);
    ll ans=0;
    for (int i=1;i<=n;i++) f[i]=i;
    for (int i=0;i<cnt;i++)
    {
        int u=find(b[i].u),v=find(b[i].v);
        if (u!=v)
        {
            f[u]=v;
            ans+=b[i].val;
        }
    }
    printf("%lld\n",ans);
    return 0;
}
