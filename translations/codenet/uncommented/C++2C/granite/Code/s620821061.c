
#include <stdio.h>
#include <string.h>

typedef long long ll;

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

#define MAX_V 1040
int V;
int G[2*MAX_V][2*MAX_V];
int match[2*MAX_V];
bool used[2*MAX_V];

void init() {
    memset(G, 0, sizeof(G));
}

void add(int a, int b) {
    G[a][b+MAX_V] = G[b+MAX_V][a] = 1;
}

bool dfs(int v) {
    used[v] = true;
    for (int i = 0; i < V; i++) {
        int u = G[v][i], w = match[u];
        if (w < 0 || (!used[w] && dfs(w))) {
            match[v] = u;
            match[u] = v;
            return true;
        }
    }
    return false;
}

int exec() {
    int res = 0;
    memset(match, -1, sizeof(match));
    for (int v = 0; v < V; v++) {
        if (match[v] < 0) {
            memset(used, 0, sizeof(used));
            if (dfs(v)) {
                res++;
            }
        }
    }
    return res;
}

int main() {
    while (true) {
        int n, m;
        scanf("%d %d", &n, &m);
        if (!n) break;
        V = n + m;
        init();
        int a[n], b[m];
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        for (int i = 0; i < m; i++) {
            scanf("%d", &b[i]);
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (gcd(a[i], b[j])!= 1) {
                    add(i, j);
                }
            }
        }
        printf("%d\n", exec());
    }
    return 0;
}
