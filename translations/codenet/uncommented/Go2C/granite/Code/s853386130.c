
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m, R;
    scanf("%d %d %d", &n, &m, &R);

    int rs[R];
    for (int i = 0; i < R; i++) {
        scanf("%d", &rs[i]);
        rs[i]--;
    }

    int costs[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            costs[i][j] = 1000000007;
        }
        costs[i][i] = 0;
    }
    for (int i = 0; i < m; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        a--;
        b--;
        costs[a][b] = c;
        costs[b][a] = c;
    }

    // Floyd-Warshall algorithm
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                costs[i][j] = costs[i][j] < costs[i][k] + costs[k][j]? costs[i][j] : costs[i][k] + costs[k][j];
            }
        }
    }

    // Permutations of the given R cities
    int perms[R][R];
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < R; j++) {
            perms[i][j] = rs[j];
        }
    }
    int min_cost = 1000000007;
    for (int i = 0; i < R; i++) {
        int cost = 0;
        for (int j = 1; j < R; j++) {
            int from = perms[i][j-1];
            int to = perms[i][j];
            cost += costs[from][to];
        }
        min_cost = cost < min_cost? cost : min_cost;
    }

    printf("%d\n", min_cost);

    return 0;
}
