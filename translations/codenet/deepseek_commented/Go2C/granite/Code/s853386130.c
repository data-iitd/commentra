
#include <stdio.h>
#include <stdlib.h>

// Constants for the modulo operation and infinity value
#define mod 1000000007
#define INF 1000000007

int min(int a, int b) {
    return a < b? a : b;
}

int** permutations(int* arr, int n) {
    int** res = (int**)malloc(sizeof(int*) * n);
    for (int i = 0; i < n; i++) {
        res[i] = (int*)malloc(sizeof(int) * n);
        for (int j = 0; j < n; j++) {
            res[i][j] = arr[j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j == 1) {
                int tmp = res[i][0];
                for (int k = 0; k < n-1; k++) {
                    res[i][k] = res[i][k+1];
                }
                res[i][n-1] = tmp;
            } else {
                int tmp = res[i][0];
                for (int k = 0; k < n-1; k++) {
                    res[i][k] = res[i][k+1];
                }
                res[i][n-1] = tmp;
            }
        }
    }

    return res;
}

int main() {
    // Create a new reader to read from standard input
    FILE *r = stdin;

    // Read the number of cities, roads, and restaurants
    int n, m, R;
    fscanf(r, "%d", &n);
    fscanf(r, "%d", &m);
    fscanf(r, "%d", &R);

    // Read the indices of the restaurants and decrement by 1 for 0-based indexing
    int* rs = (int*)malloc(sizeof(int) * R);
    for (int i = 0; i < R; i++) {
        fscanf(r, "%d", &rs[i]);
        rs[i]--;
    }

    // Initialize the cost matrix with INF and set diagonal to 0
    int** costs = (int**)malloc(sizeof(int*) * n);
    for (int i = 0; i < n; i++) {
        costs[i] = (int*)malloc(sizeof(int) * n);
        for (int j = 0; j < n; j++) {
            costs[i][j] = INF;
        }
        costs[i][i] = 0;
    }

    // Read the road connections and their costs, updating the cost matrix
    int a, b, c;
    for (int i = 0; i < m; i++) {
        fscanf(r, "%d", &a);
        fscanf(r, "%d", &b);
        fscanf(r, "%d", &c);
        a--;
        b--;
        costs[a][b] = c;
        costs[b][a] = c;
    }

    // Use the Floyd-Warshall algorithm to compute the shortest paths between all pairs of cities
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                costs[i][j] = min(costs[i][j], costs[i][k] + costs[k][j]);
            }
        }
    }

    // Generate all permutations of the restaurant indices and find the minimum cost tour
    int** perms = permutations(rs, R);
    int ans = INF;
    for (int i = 0; i < R; i++) {
        int tmp = 0;
        for (int j = 1; j < R; j++) {
            int from = perms[i][j-1];
            int to = perms[i][j];
            tmp += costs[from][to];
        }
        ans = min(ans, tmp);
    }
    printf("%d\n", ans);

    // Free memory
    for (int i = 0; i < n; i++) {
        free(costs[i]);
    }
    free(costs);
    free(rs);
    for (int i = 0; i < R; i++) {
        free(perms[i]);
    }
    free(perms);

    return 0;
}

