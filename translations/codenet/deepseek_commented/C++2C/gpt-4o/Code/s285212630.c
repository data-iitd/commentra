// Include necessary headers for input/output, data manipulation, and other functionalities
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
<<<<<<< HEAD
#include <stdbool.h>
=======
>>>>>>> 98c87cb78a (data updated)

#define int long long
#define MAX_L 22
#define INF 1145141919
#define MOD 1000000007

typedef struct {
    int _1;
    int _2;
} P;

int N;
P G[100000][100000]; // Adjacency list representation
int U[MAX_L][100000], R[100000];
long long L[100000];
int G_size[100000]; // To keep track of the number of edges for each node

// Depth-First Search (DFS) function to traverse the graph and populate the ancestor matrix and rank array
void dfs(int x, int p, int r, long long l) {
    U[0][x] = p;
    R[x] = r;
    L[x] = l;
    for (int i = 0; i < G_size[x]; i++) {
        P pp = G[x][i];
        int t = pp._1;
        if (t == p) continue;
        dfs(t, x, r + 1, l + pp._2);
    }
}

// Lowest Common Ancestor (LCA) function to find the lowest common ancestor of two nodes
int lca(int a, int b) {
    if (R[a] > R[b]) {
        int temp = a;
        a = b;
        b = temp;
    }
    for (int k = 0; k < MAX_L; k++) {
        if ((R[a] - R[b]) >> k & 1) {
            b = U[k][b];
        }
    }
    if (a == b) return a;
    for (int k = MAX_L - 1; k >= 0; k--) {
        if (U[k][a] != U[k][b]) {
            a = U[k][a];
            b = U[k][b];
        }
    }
    return U[0][a];
}

// Distance calculation function to find the distance between two nodes
long long dist(int x, int y) {
    int g = lca(x, y);
    return L[x] + L[y] - 2LL * L[g];
}

// Main function to read input, initialize the graph, call dfs to populate the ancestor matrix, and process queries
int main() {
    scanf("%lld", &N);
    for (int i = 0; i < N - 1; i++) {
        int a, b, c;
        scanf("%lld %lld %lld", &a, &b, &c);
        a--, b--;
        G[a][G_size[a]]._1 = b;
        G[a][G_size[a]]._2 = c;
        G_size[a]++;
        G[b][G_size[b]]._1 = a;
        G[b][G_size[b]]._2 = c;
        G_size[b]++;
    }
<<<<<<< HEAD
    memset(U, -1, sizeof(U));
    dfs(0, -1, 0, 0);
=======
    
    memset(U, -1, sizeof(U));
    dfs(0, -1, 0, 0);
    
>>>>>>> 98c87cb78a (data updated)
    for (int i = 0; i < MAX_L - 1; i++) {
        for (int v = 0; v < N; v++) {
            if (U[i][v] == -1) U[i + 1][v] = -1;
            else U[i + 1][v] = U[i][U[i][v]];
        }
    }
<<<<<<< HEAD
    int Q, K;
    scanf("%lld %lld", &Q, &K);
    K--;
=======
    
    int Q, K;
    scanf("%lld %lld", &Q, &K);
    K--;
    
>>>>>>> 98c87cb78a (data updated)
    for (int i = 0; i < Q; i++) {
        int x, y;
        scanf("%lld %lld", &x, &y);
        x--, y--;
        printf("%lld\n", dist(x, K) + dist(K, y));
    }
<<<<<<< HEAD
    return 0;
}

=======
    
    return 0;
}
>>>>>>> 98c87cb78a (data updated)
// <END-OF-CODE>
