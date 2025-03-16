
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <climits>
#include <cctype>
#include <ctime>
#include <queue>
#include <stack>
#include <set>
#include <bitset>
#include <iomanip>
#include <sstream>
#include <list>
#include <numeric>

using namespace std;

typedef long long ll;
typedef unsigned long long u64;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;

#define rep(i,n) for(int i = 0; i < (n); i++)
#define REP(i,n) for(int i = 1; i <= (n); i++)
#define mp(a,b) make_pair((a),(b))
#define pb(a) push_back((a))
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end())
#define lower_bound(v,x) lower_bound((v).begin(),(v).end(),(x))
#define upper_bound(v,x) upper_bound((v).begin(),(v).end(),(x))
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define MEM(a,b) memset((a),(b),sizeof(a))
#define fr first
#define sc second
#define foreach(it,x) for(__typeof((x).begin()) it=(x).begin();it!=(x).end();it++)

template<class T> inline void _checkmax(T &a, T b){ if(b > a) a = b; }
template<class T> inline void _checkmin(T &a, T b){ if(b < a) a = b; }

const int N = 100000 + 10;
const int MOD = 1000000007;

int n,m;
int a[N];
int dp[N];

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int T = 1;
    //cin >> T;
    for(int cas = 1; cas <= T; cas++){
        scanf("%d%d",&n,&m);
        MEM(a,0);
        MEM(dp,0);
        REP(i,m){
            scanf("%d",&a[i]);
        }
        dp[0] = 1;
        REP(i,n){
            if(a[i] == 0){
                dp[i] = (dp[i-1] + dp[i-2]) % MOD;
            }
        }
        printf("Case %d: %d\n",cas,dp[n]);
    }
    return 0;
}

