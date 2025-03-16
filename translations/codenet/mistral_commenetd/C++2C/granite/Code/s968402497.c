
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#define mod 1000000007
#define mod9 998244353
#define ld long double
#define ull unsigned long long
#define db double
#define ll long long
const db eps=1e-7;
const db pi=acos(-1);
const int INF = 0x3f3f3f3f;
const ll inf=0x3f3f3f3f3f3f3f3f;
#define rep(i,be,en) for (int i=be;i<=en;i++)
#define per(i,be,en) for (int i=en;i>=be;i--)
using namespace std;
const int N=1e5+7;

int tc, n, m, fl=0;

int main(){
    scanf("%d%d%d",&tc,&n,&m);
    if(n>m) swap(n,m);
    for(int i=1;i<=m;i++){
        if(i*tc>=n&&i*tc<=m){
            printf("OK\n");
            fl=1;
            break;
        }
    }
    if(fl==0) puts("NG");
    return 0;
}
