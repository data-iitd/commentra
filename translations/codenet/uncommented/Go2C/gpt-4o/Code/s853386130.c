#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MOD 1000000007
#define INF 1000000007

int min(int x, int y) {
    return x < y ? x : y;
}

void floydWarshall(int n, int costs[n][n]) {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                costs[i][j] = min(costs[i][j], costs[i][k] + costs[k][j]);
            }
        }
    }
}

void permutations(int *arr, int start, int end, int n, int **result, int *count) {
    if (start == end) {
        for (int i = 0; i < n; i++) {
            result[*count][i] = arr[i];
        }
        (*count)++;
    } else {
        for (int i = start; i <= end; i++) {
            // Swap
            int temp = arr[start];
            arr[start] = arr[i];
            arr[i] = temp;

            permutations(arr, start + 1, end, n, result, count);

            // Swap back
            temp = arr[start];
            arr[start] = arr[i];
            arr[i] = temp;
        }
    }
}

int main() {
    int n, m, R;
    scanf("%d %d %d", &n, &m, &R);

    int *rs = (int *)malloc(R * sizeof(int));
    for (int i = 0; i < R; i++) {
        scanf("%d", &rs[i]);
        rs[i]--; // Convert to 0-based index
    }

    int costs[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            costs[i][j] = INF;
        }
        costs[i][i] = 0;
    }

    for (int i = 0; i < m; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        a--; // Convert to 0-based index
        b--; // Convert to 0-based index
        costs[a][b] = c;
        costs[b][a] = c;
    }

    // Calculate shortest paths using Floyd-Warshall
    floydWarshall(n, costs);

    // Generate all permutations of rs
    int permCount = 1;
    for (int i = 1; i <= R; i++) {
        permCount *= i;
    }
    int **perms = (int **)malloc(permCount * sizeof(int *));
    for (int i = 0; i < permCount; i++) {
        perms[i] = (int *)malloc(R * sizeof(int));
    }
    int count = 0;
    permutations(rs, 0, R - 1, R, perms, &count);

    int ans = INF;
    for (int i = 0; i < permCount; i++) {
        int tmp = 0;
        for (int j = 1; j < R; j++) {
            int from = perms[i][j - 1];
            int to = perms[i][j];
            tmp += costs[from][to];
        }
        ans = min(ans, tmp);
    }

    printf("%d\n", ans);

    // Free allocated memory
    free(rs);
    for (int i = 0; i < permCount; i++) {
        free(perms[i]);
    }
    free(perms);

    return 0;
}

// <END-OF-CODE>
