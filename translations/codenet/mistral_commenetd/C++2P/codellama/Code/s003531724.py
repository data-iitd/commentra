#include <iostream>
#include <cstdio>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#define rep(i,a,b) for(int i = a; i <= b; i++)
#define dep(i,a,b) for(int i = a; i >= b; i--) 
#define Rep(i,a) for(int i = 0; i < a; i++)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define x first
#define y second
#define ab(x) ((x) < 0 ? -(x) : (x))
using namespace std;
typedef long long LL;
typedef map<int, int>::iterator mit;
typedef set<int>::iterator sit;
typedef pair<int, int> pii;
const int N = 1e5 + 10;

#define v e[i].to
#define ec e[i].c
#define reg(i,a) for(int i = u[a]; i; i = e[i].pre)

def dfs(x, l):
    vis[x] = True; cnt[l] += 1; d[x] = l
    for i in range(u[x], 0, -1):
        if not vis[v]: dfs(v, (l + ec) % 3)
        else:
            if (l + ec) % 3 != d[v]: ok = False

def main():
    # Read the input n and m, where n is the number of nodes and m is the number of edges
    n, m = map(int, input().split())
    # Initialize some variables and arrays
    ans = 0
    rep(i,1,n) if not vis[i]:
        T = 0
        rep(j,0,2) cnt[j] = 0
        ok = True
        # Perform a depth-first search for the current unvisited node
        dfs(i, 0)
        s = cnt[0] + cnt[1] + cnt[2]
        # Compute the answer based on the information obtained during the depth-first search
        if not ok: ans += s * s
        else:
            if cnt[0] and cnt[1] and cnt[2]: 
                ans += cnt[0] * cnt[1] + cnt[1] * cnt[2] + cnt[2] * cnt[0]
            else: 
                ans += T / 2
    # Output the answer and terminate the program
    print(ans)

