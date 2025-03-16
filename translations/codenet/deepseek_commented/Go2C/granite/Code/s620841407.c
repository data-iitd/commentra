
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef long long ll;

// Define the operations for the ReRootingSolver
ll f(ll x, ll y) { return x * y % m; }
ll g(ll v, ll p) { return v + 1; }

// Initialize and use the ReRootingSolver to compute the results
int main() {
    // Read the number of nodes and edges
    int n, m;
    scanf("%d %d", &n, &m);

    // Construct the graph from the edges
    int x, y;
    int edges[n-1][2];
    for (int i = 0; i < n-1; i++) {
        scanf("%d %d", &x, &y);
        x--;
        y--;
        edges[i][0] = x;
        edges[i][1] = y;
    }

    // Define the ReRootingSolver struct for solving the re-rooting problem
    typedef struct {
        int NodeCount;
        int Adjacents[n][n];
        int IndexForAdjacents[n][n];
        ll Res[n];
        ll DP[n][n];
        ll Identity;
        ll (*Operate)(ll, ll);
        ll (*OperateNode)(ll, ll);
    } ReRootingSolver;

    ReRootingSolver *s = (ReRootingSolver *)malloc(sizeof(ReRootingSolver));

    s->NodeCount = n;
    s->Identity = 0;
    s->Operate = f;
    s->OperateNode = g;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            s->DP[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        s->Res[i] = 0;
    }

    if (s->NodeCount > 1) {
        s->Initialize(s);
    } else {
        s->Res[0] = s->OperateNode(s->Identity, 0);
    }

    // Query and print the results
    for (int i = 0; i < n; i++) {
        printf("%lld\n", s->Res[i]);
    }

    // Free the memory allocated for the ReRootingSolver
    free(s);

    return 0;
}
