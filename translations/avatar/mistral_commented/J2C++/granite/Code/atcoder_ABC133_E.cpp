

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cctype>
#include <cstring>
#include <utility>
#include <numeric>
#include <cassert>
#include <iomanip>
#include <bitset>
#include <list>
#include <random>
#include <functional>

using namespace std;

typedef long long ll;
typedef pair<int,int> P;

#define REP(i,n) for(int i=0; i<(n); i++)
#define FOR(i,a,b) for(int i=(a); i<(b); i++)
#define RREP(i,n) for(int i=(n)-1; i>=0; i--)
#define RFOR(i,a,b) for(int i=(a)-1; i>=(b); i--)
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()
#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define CHMIN(a,b) a=min((a),(b))
#define CHMAX(a,b) a=max((a),(b))

const ll MOD = 1000000007;
const ll INF = 1e18;
const double PI = acos(-1);

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int main(){
    int N, K;
    cin >> N >> K;
    vector<vector<int>> G(N);
    REP(i,N-1){
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    vector<ll> dp(N, 0);
    function<void(int,int)> dfs = [&](int v, int p){
        dp[v] = K - G[v].size();
        for(int u : G[v]){
            if(u == p) continue;
            dfs(u, v);
            dp[v] = dp[v] * dp[u] % MOD;
        }
    };
    dfs(0, -1);
    ll ans = 1;
    REP(i,N) ans = ans * dp[i] % MOD;
    cout << ans << endl;
    return 0;
}

