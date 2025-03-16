// Importing necessary libraries
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Global variables initialization
#define MOD 1000000007
#define INF 1000000007

// Function to find the minimum of two integers
int min(int a, int b) {
    return a < b ? a : b;
}

// Function to generate all permutations of given array
void permutations(int *arr, int n, int **result, int *count) {
    if (n == 1) {
        result[*count] = (int *)malloc(sizeof(int) * (*count + 1));
        for (int i = 0; i < *count; i++) {
            result[*count][i] = arr[i];
        }
        (*count)++;
        return;
    }

    for (int i = 0; i < n; i++) {
        permutations(arr, n - 1, result, count);
        if (n % 2 == 1) {
            int temp = arr[i];
            arr[i] = arr[n - 1];
            arr[n - 1] = temp;
        } else {
            int temp = arr[0];
            arr[0] = arr[n - 1];
            arr[n - 1] = temp;
        }
    }
}

int main() {
    // Reading input
    int n, m, R;
    scanf("%d %d %d", &n, &m, &R);

    // Initializing rs array with starting points
    int *rs = (int *)malloc(sizeof(int) * R);
    for (int i = 0; i < R; i++) {
        scanf("%d", &rs[i]);
        rs[i]--; // Decreasing starting point index for matrix indexing
    }

    // Initializing costs matrix with infinite values
    int **costs = (int **)malloc(sizeof(int *) * n);
    for (int i = 0; i < n; i++) {
        costs[i] = (int *)malloc(sizeof(int) * n);
        for (int j = 0; j < n; j++) {
            costs[i][j] = INF; // Initializing costs[i][j] with infinite value
            if (i == j) costs[i][j] = 0; // Initializing costs[i][i] with zero value
        }
    }

    // Reading roads and filling costs matrix with their costs
    for (int i = 0; i < m; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        a--; // Decreasing starting point index for matrix indexing
        b--; // Decreasing ending point index for matrix indexing
        costs[a][b] = c; // Filling costs[a][b] with cost c
        costs[b][a] = c; // Filling costs[b][a] with cost c
    }

    // Applying Warshall-Floyd algorithm to find shortest paths between all pairs of cities
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                costs[i][j] = min(costs[i][j], costs[i][k] + costs[k][j]); // Updating costs[i][j]
            }
        }
    }

    // Calculating minimum cost of visiting all cities in a single tour
    int **permResults = (int **)malloc(sizeof(int *) * 1000); // Assuming a maximum of 1000 permutations
    int count = 0;
    permutations(rs, R, permResults, &count); // Generating all permutations of starting points
    int ans = INF; // Initializing answer with infinite value

    for (int i = 0; i < count; i++) { // Iterating through all permutations
        int tmp = 0; // Initializing temporary variable tmp with zero value
        for (int j = 1; j < R; j++) { // Iterating through all pairs of consecutive starting points
            int from = permResults[i][j - 1]; // Getting previous starting point
            int to = permResults[i][j]; // Getting current starting point
            tmp += costs[from][to]; // Adding cost of road from from to to tmp
        }
        ans = min(ans, tmp); // Updating answer with minimum of current answer and tmp
    }

    printf("%d\n", ans); // Printing answer

    // Freeing allocated memory
    free(rs);
    for (int i = 0; i < n; i++) {
        free(costs[i]);
    }
    free(costs);
    for (int i = 0; i < count; i++) {
        free(permResults[i]);
    }
    free(permResults);

    return 0;
}

// <END-OF-CODE>
