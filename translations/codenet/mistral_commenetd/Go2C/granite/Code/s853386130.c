
#include <stdio.h>
#include <stdlib.h>

// Global variables initialization
#define mod 1000000007
#define INF 1000000007

int main() {
    // Reading input from standard input
    FILE *r = stdin;
    // Variables initialization
    int n, m, R;
    fscanf(r, "%d", &n); // Reading number of cities n
    fscanf(r, "%d", &m); // Reading number of roads m
    fscanf(r, "%d", &R); // Reading number of starting points R

    // Initializing rs slice with starting points
    int *rs = (int *)malloc(R * sizeof(int));
    for (int i = 0; i < R; i++) {
        fscanf(r, "%d", &rs[i]); // Reading starting point i
        rs[i]--; // Decreasing starting point index for matrix indexing
    }

    // Initializing costs matrix with infinite values
    int **costs = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        costs[i] = (int *)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            costs[i][j] = INF; // Initializing costs[i][j] with infinite value
            costs[i][i] = 0;   // Initializing costs[i][i] with zero value
        }
    }

    // Reading roads and filling costs matrix with their costs
    for (int i = 0; i < m; i++) {
        int a, b, c;
        fscanf(r, "%d", &a); // Reading road starting point a
        fscanf(r, "%d", &b); // Reading road ending point b
        fscanf(r, "%d", &c); // Reading road cost c
        a--;                 // Decreasing starting point index for matrix indexing
        b--;                 // Decreasing ending point index for matrix indexing
        costs[a][b] = c;     // Filling costs[a][b] with cost c
        costs[b][a] = c;     // Filling costs[b][a] with cost c
    }

    // Applying Warshall-Floyd algorithm to find shortest paths between all pairs of cities
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                costs[i][j] = costs[i][j] < costs[i][k] + costs[k][j]? costs[i][j] : costs[i][k] + costs[k][j]; // Updating costs[i][j] with minimum of current value and costs[i][k] + costs[k][j]
            }
        }
    }

    // Calculating minimum cost of visiting all cities in a single tour
    int **perms = (int **)malloc(R * sizeof(int *));
    for (int i = 0; i < R; i++) {
        perms[i] = (int *)malloc(R * sizeof(int));
        for (int j = 0; j < R; j++) {
            perms[i][j] = rs[j]; // Copying rs to perms
        }
    }
    int ans = INF; // Initializing answer with infinite value
    for (int i = 0; i < R; i++) { // Iterating through all permutations
        int tmp = 0; // Initializing temporary variable tmp with zero value
        for (int j = 1; j < R; j++) { // Iterating through all pairs of consecutive starting points
            int from = perms[i][j - 1]; // Getting previous starting point
            int to = perms[i][j];     // Getting current starting point
            tmp += costs[from][to]; // Adding cost of road from from to to tmp
        }
        ans = ans < tmp? ans : tmp; // Updating answer with minimum of current answer and tmp
    }
    printf("%d\n", ans); // Printing answer

    // Freeing dynamically allocated memory
    for (int i = 0; i < R; i++) {
        free(perms[i]);
    }
    free(perms);
    for (int i = 0; i < n; i++) {
        free(costs[i]);
    }
    free(costs);
    free(rs);

    return 0;
}
