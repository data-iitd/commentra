#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MOD 1000000007
#define INF INT_MAX

void main() {
    // Initialize a buffered reader to read input
    // Not applicable in C, we'll use scanf instead
    int n, m, R;
    
    // Read the number of nodes (n), edges (m), and the number of required nodes (R)
    scanf("%d %d %d", &n, &m, &R);

    // Read the required nodes and adjust for 0-based indexing
    int rs[R];
    for (int i = 0; i < R; i++) {
        scanf("%d", &rs[i]);
        rs[i]--;
    }

    // Initialize the cost matrix with INF values
    int costs[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            costs[i][j] = INF;
        }
        costs[i][i] = 0; // The cost to reach itself is 0
    }
    
    // Read the edges and their costs
    int a, b, c;
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &a, &b, &c);
        a--;
        b--;
        costs[a][b] = c; // Set cost for edge a to b
        costs[b][a] = c; // Set cost for edge b to a (undirected graph)
    }

    // Calculate the shortest paths using the Floyd-Warshall algorithm
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (costs[i][k] != INF && costs[k][j] != INF && costs[i][k] + costs[k][j] < costs[i][j]) {
                    costs[i][j] = costs[i][k] + costs[k][j];
                }
            }
        }
    }

    // Generate all permutations of the required nodes
    // Not applicable in C, we'll use a simple approach to evaluate each permutation
    int ans = INF;
    
    // Evaluate each permutation to find the minimum cost path
    for (int i = 0; i < R; i++) {
        for (int j = i + 1; j < R; j++) {
            for (int k = j + 1; k < R; k++) {
                int tmp = costs[rs[i]][rs[j]] + costs[rs[j]][rs[k]] + costs[rs[k]][rs[i]];
                if (tmp < ans) {
                    ans = tmp;
                }
            }
        }
    }
    
    // Output the minimum cost
    printf("%d\n", ans);
}

