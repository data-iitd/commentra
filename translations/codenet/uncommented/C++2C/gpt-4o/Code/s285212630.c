#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define int long long
#define MAX_L 22
#define INF 1145141919
#define MOD 1000000007

typedef struct {
    int first;
    int second;
} P;

int N;
<<<<<<< HEAD
P G[100000][2]; // Adjusted to hold pairs for each node
=======
P G[100000][2]; // Adjusted to hold pairs of edges
>>>>>>> 98c87cb78a (data updated)
int U[MAX_L][100000], R[100000];
long long L[100000];

void dfs(int x, int p, int r, long long l) {
    U[0][x] = p;
    R[x] = r;
    L[x] = l;
    for (int i = 0; i < 2; i++) {
        int t = G[x][i].first;
<<<<<<< HEAD
        if (t == p || t == 0) continue; // Avoid visiting the parent
=======
        if (t == p) continue;
>>>>>>> 98c87cb78a (data updated)
        dfs(t, x, r + 1, l + G[x][i].second);
    }
}

int lca(int a, int b) {
    if (R[a] > R[b]) {
        int temp = a;
        a = b;
        b = temp;
    }
    for (int k = 0; k < MAX_L; k++) {
<<<<<<< HEAD
        if ((R[a] - R[b]) >> k & 1) b = U[k][b];
=======
        if ((R[a] - R[b]) >> k & 1) {
            b = U[k][b];
        }
>>>>>>> 98c87cb78a (data updated)
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

long long dist(int x, int y) {
    int g = lca(x, y);
    return L[x] + L[y] - 2LL * L[g];
}

int main() {
    scanf("%lld", &N);
    for (int i = 0; i < N - 1; i++) {
        int a, b, c;
        scanf("%lld %lld %lld", &a, &b, &c);
        a--, b--;
        G[a][0] = (P){b, c};
        G[b][0] = (P){a, c};
    }
    for (int i = 0; i < MAX_L; i++) {
        for (int j = 0; j < N; j++) {
            U[i][j] = -1;
        }
    }
    dfs(0, -1, 0, 0);
    for (int i = 0; i < MAX_L - 1; i++) {
        for (int v = 0; v < N; v++) {
            if (U[i][v] == -1) U[i + 1][v] = -1;
            else U[i + 1][v] = U[i][U[i][v]];
        }
    }
    int Q, K;
    scanf("%lld %lld", &Q, &K);
    K--;
    for (int i = 0; i < Q; i++) {
        int x, y;
        scanf("%lld %lld", &x, &y);
        x--, y--;
        printf("%lld\n", dist(x, K) + dist(K, y));
    }
    return 0;
}

// <END-OF-CODE>
