
#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

#define MOD 1000000000 + 7

typedef struct {
    int x, y;
} P;

int N, M;
P edges[100000];
ll dp[100000][20];
ll ans[100000];

void dfs(int v, int p) {
    for (int i = 0; i < N - 1; i++) {
        if (edges[i].x == v) {
            if (edges[i].y!= p) {
                dfs(edges[i].y, v);
                for (int j = 0; j < 20; j++) {
                    dp[v][j] += dp[edges[i].y][j];
                    dp[v][j] %= M;
                }
            }
        } else if (edges[i].y == v) {
            if (edges[i].x!= p) {
                dfs(edges[i].x, v);
                for (int j = 0; j < 20; j++) {
                    dp[v][j] += dp[edges[i].x][j];
                    dp[v][j] %= M;
                }
            }
        }
    }
    dp[v][0]++;
    for (int i = 0; i < 20; i++) {
        ans[v] += dp[v][i];
        ans[v] %= M;
    }
}

int main() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N - 1; i++) {
        scanf("%d %d", &edges[i].x, &edges[i].y);
        edges[i].x--;
        edges[i].y--;
    }
    dfs(0, -1);
    for (int i = 0; i < N; i++) {
        printf("%lld\n", ans[i] - 1);
    }
    return 0;
}
