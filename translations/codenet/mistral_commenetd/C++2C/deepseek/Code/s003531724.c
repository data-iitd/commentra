#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define rep(i,a,b) for(int i = a; i <= b; i++)
#define dep(i,a,b) for(int i = a; i >= b; i--) 
#define Rep(i,a) for(int i = 0; i < a; i++)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define x first
#define y second
#define ab(x) ((x) < 0 ? -(x) : (x))

typedef long long LL;

typedef struct { int to, pre, c; } edge;
typedef struct { int first, second; } pii;

#define N 100010

// Define a structure to represent an edge in the graph
edge e[N << 1]; int u[N], l = 0;
void ins(int a, int b, int c) { e[++l] = (edge){b, u[a], c}, u[a] = l; }
#define v e[i].to
#define ec e[i].c
#define reg(i,a) for(int i = u[a]; i; i = e[i].pre)

// Define some variables and arrays for storing information about the graph
int n, m;
bool vis[N], ok;
LL cnt[3]; int d[N];
int T;

// Define a function to perform a depth-first search of the graph
void dfs(int x, int l) {
    vis[x] = true; cnt[l]++; d[x] = l;
    reg(i,x) {
        T++;
        if (!vis[v]) dfs(v, (l + ec) % 3);
        else if ((l + ec) % 3 != d[v]) ok = false;
    }
}

// Define the main function to read the input and compute the answer
int main() {
    // Read the input n and m, where n is the number of nodes and m is the number of edges
    scanf("%d%d",&n,&m);
    // Initialize some variables and arrays
    LL ans = 0;
    rep(i,1,n) if (!vis[i]) {
        T = 0;
        rep(j,0,2) cnt[j] = 0; ok = true;
        // Perform a depth-first search for the current unvisited node
        dfs(i, 0); LL s = cnt[0] + cnt[1] + cnt[2];
        // Compute the answer based on the information obtained during the depth-first search
        if (!ok) ans += s * s;
        else {
            if (cnt[0] && cnt[1] && cnt[2]) 
                ans += cnt[0] * cnt[1] + cnt[1] * cnt[2] + cnt[2] * cnt[0];
            else 
                ans += T / 2;
        }
    }
    // Output the answer and terminate the program
    printf("%lld\n", ans);
}
