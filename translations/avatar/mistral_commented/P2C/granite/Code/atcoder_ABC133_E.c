
###
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <assert.h>
#include <limits.h>
#include <stdarg.h>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <sys/time.h>
#include <fstream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
using namespace std;
typedef long long int lint;
typedef unsigned long long int luint;

#define rep(i, n) for(lint i = 0; i < (lint)(n); i++)
#define all(a) (a).begin(), (a).end()
#define each(a, i) for(auto& i : (a))
#define pb push_back
#define mp make_pair
#define mt make_tuple

template<typename T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<typename T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<typename T1, typename T2> istream& operator>>(istream& is, pair<T1, T2>& p) { is >> p.first >> p.second; return is; }
template<typename T1, typename T2> ostream& operator<<(ostream& os, pair<T1, T2>& p) { os << p.first << " " << p.second; return os; }

lint mod = 100000007;
lint N, K;
vector<lint> G[100000];
lint dfs(lint fro, lint to, lint f) {
    lint caseNum = 1;
    lint colorNum = K - 1;
    if (f == K) {
        colorNum = K - 2;
    }
    for (lint u : G[fro]) {
        if (u == to) {
            continue;
        }
        lint pat = dfs(u, fro, colorNum);
        if (pat == 0) {
            caseNum = 0;
            break;
        }
        caseNum = caseNum * pat % mod;
        colorNum--;
    }
    return caseNum;
}

int main() {
    cin >> N >> K;
    rep(i, N - 1) {
        lint a, b;
        cin >> a >> b;
        a--; b--;
        G[a].pb(b);
        G[b].pb(a);
    }
    lint ans = dfs(0, -1, K);
    cout << ans << endl;
    return 0;
}
