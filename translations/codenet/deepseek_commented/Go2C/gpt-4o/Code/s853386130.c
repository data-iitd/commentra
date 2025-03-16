#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MOD 1000000007
#define INF 1000000007

// Function to find the minimum of two integers
int min(int a, int b) {
    return a < b ? a : b;
}

// Function to generate all permutations of an array
void permute(int *arr, int l, int r, int **result, int *count) {
    if (l == r) {
        result[*count] = (int *)malloc(sizeof(int) * (r + 1));
        for (int i = 0; i <= r; i++) {
            result[*count][i] = arr[i];
        }
        (*count)++;
    } else {
        for (int i = l; i <= r; i++) {
            // Swap
            int temp = arr[l];
            arr[l] = arr[i];
            arr[i] = temp;

            // Recursion
            permute(arr, l + 1, r);

            // Backtrack
            temp = arr[l];
            arr[l] = arr[i];
            arr[i] = temp;
        }
    }
}

int main() {
    // Read the number of cities, roads, and restaurants
    int n, m, R;
    scanf("%d %d %d", &n, &m, &R);

    // Read the indices of the restaurants
    int *rs = (int *)malloc(sizeof(int) * R);
    for (int i = 0; i < R; i++) {
        scanf("%d", &rs[i]);
        rs[i]--; // Decrement for 0-based indexing
    }

    // Initialize the cost matrix with INF and set diagonal to 0
    int **costs = (int **)malloc(sizeof(int *) * n);
    for (int i = 0; i < n; i++) {
        costs[i] = (int *)malloc(sizeof(int) * n);
        for (int j = 0; j < n; j++) {
            costs[i][j] = INF;
        }
        costs[i][i] = 0;
    }

    // Read the road connections and their costs
    for (int i = 0; i < m; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        a--; b--; // Decrement for 0-based indexing
        costs[a][b] = c;
        costs[b][a] = c;
    }

    // Use the Floyd-Warshall algorithm to compute the shortest paths
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                costs[i][j] = min(costs[i][j], costs[i][k] + costs[k][j]);
            }
        }
    }

    // Generate all permutations of the restaurant indices
    int **perms = (int **)malloc(sizeof(int *) * 720); // 6! = 720 for R <= 6
    int count = 0;
    permute(rs, 0, R - 1, perms, &count);

    // Find the minimum cost tour
    int ans = INF;
    for (int i = 0; i < count; i++) {
        int tmp = 0;
        for (int j = 1; j < R; j++) {
            int from = perms[i][j - 1];
            int to = perms[i][j];
            tmp += costs[from][to];
        }
        ans = min(ans, tmp);
        free(perms[i]); // Free the allocated memory for each permutation
    }
<<<<<<< HEAD
    free(perms);

    // Print the result
    printf("%d\n", ans);

    // Free allocated memory
=======
    free(perms); // Free the permutations array

    printf("%d\n", ans);

    // Free the costs matrix
>>>>>>> 98c87cb78a (data updated)
    for (int i = 0; i < n; i++) {
        free(costs[i]);
    }
    free(costs);
<<<<<<< HEAD
    free(rs);
=======
    free(rs); // Free the restaurant indices array
>>>>>>> 98c87cb78a (data updated)

    return 0;
}

// <END-OF-CODE>
