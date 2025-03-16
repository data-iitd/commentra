#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MOD 1000000007
#define INF 1000000007

<<<<<<< HEAD
// Function prototypes
int min(int x, int y);
void permutations(int *arr, int n, int **result, int *returnSize);
void floydWarshall(int n, int **costs);
void swap(int *a, int *b);
=======
// Function to find the minimum of two integers
int min(int x, int y) {
    return (x < y) ? x : y;
}

// Function to calculate the modular exponentiation
int modpow(int a, int n, int mod) {
    int res = 1;
    while (n > 0) {
        if (n % 2 != 0) {
            res = (res * a) % mod;
        }
        a = (a * a) % mod;
        n /= 2;
    }
    return res;
}

// Function to calculate the modular inverse
int modinv(int n, int mod) {
    return modpow(n, mod - 2, mod);
}

// Function to calculate n choose k (nCk) % mod
int modcomb(int n, int k, int mod) {
    int x = 1, y = 1;
    for (int i = 0; i < k; i++) {
        x = (x * (n - i)) % mod;
        y = (y * (i + 1)) % mod;
    }
    return (x * modinv(y, mod)) % mod;
}

// Function to read all permutations of an array
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

            permute(arr, l + 1, r);

            // Backtrack
            temp = arr[l];
            arr[l] = arr[i];
            arr[i] = temp;
        }
    }
}
>>>>>>> 98c87cb78a (data updated)

int main() {
    int n, m, R;
    scanf("%d %d %d", &n, &m, &R);

<<<<<<< HEAD
    int *rs = (int *)malloc(R * sizeof(int));
=======
    int *rs = (int *)malloc(sizeof(int) * R);
>>>>>>> 98c87cb78a (data updated)
    for (int i = 0; i < R; i++) {
        scanf("%d", &rs[i]);
        rs[i]--; // Adjust for 0-based indexing
    }

    // Initialize the cost matrix with INF values
<<<<<<< HEAD
    int **costs = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        costs[i] = (int *)malloc(n * sizeof(int));
=======
    int **costs = (int **)malloc(sizeof(int *) * n);
    for (int i = 0; i < n; i++) {
        costs[i] = (int *)malloc(sizeof(int) * n);
>>>>>>> 98c87cb78a (data updated)
        for (int j = 0; j < n; j++) {
            costs[i][j] = INF;
        }
        costs[i][i] = 0; // The cost to reach itself is 0
    }

    // Read the edges and their costs
    for (int i = 0; i < m; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        a--; b--; // Adjust for 0-based indexing
        costs[a][b] = c; // Set cost for edge a to b
        costs[b][a] = c; // Set cost for edge b to a (undirected graph)
    }

    // Calculate the shortest paths using the Floyd-Warshall algorithm
<<<<<<< HEAD
    floydWarshall(n, costs);

    // Generate all permutations of the required nodes
    int **perms = NULL;
    int returnSize = 0;
    permutations(rs, R, &perms, &returnSize);
    int ans = INF;

    // Evaluate each permutation to find the minimum cost path
    for (int i = 0; i < returnSize; i++) {
        int tmp = 0;
        for (int j = 1; j < R; j++) {
            int from = perms[i][j - 1];
            int to = perms[i][j];
            tmp += costs[from][to]; // Accumulate the cost of the current permutation
        }
        ans = min(ans, tmp); // Update the answer with the minimum cost found
    }

    // Output the minimum cost
    printf("%d\n", ans);

    // Free allocated memory
    for (int i = 0; i < n; i++) {
        free(costs[i]);
    }
    free(costs);
    free(rs);
    for (int i = 0; i < returnSize; i++) {
        free(perms[i]);
    }
    free(perms);

    return 0;
}

// Function to find the minimum of two integers
int min(int x, int y) {
    return (x < y) ? x : y;
}

// Function to generate all permutations of an array
void permutations(int *arr, int n, int ***result, int *returnSize) {
    int *temp = (int *)malloc(n * sizeof(int));
    int **res = (int **)malloc(10000 * sizeof(int *)); // Arbitrary size for permutations
    *returnSize = 0;

    void helper(int *arr, int n, int *temp, int *resSize) {
        if (n == 1) {
            res[*resSize] = (int *)malloc(sizeof(int) * (sizeof(arr) / sizeof(arr[0])));
            for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
                res[*resSize][i] = arr[i];
            }
            (*resSize)++;
        } else {
            for (int i = 0; i < n; i++) {
                helper(arr, n - 1, temp, resSize);
                if (n % 2 == 1) {
                    swap(&arr[i], &arr[n - 1]);
                } else {
                    swap(&arr[0], &arr[n - 1]);
                }
            }
        }
    }

    helper(arr, n, temp, returnSize);
    *result = res;
}

// Function to swap two integers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Floyd-Warshall algorithm to find shortest paths
void floydWarshall(int n, int **costs) {
=======
>>>>>>> 98c87cb78a (data updated)
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                costs[i][j] = min(costs[i][j], costs[i][k] + costs[k][j]);
            }
        }
    }
<<<<<<< HEAD
}
=======

    // Generate all permutations of the required nodes
    int **perms = (int **)malloc(sizeof(int *) * 720); // 6! = 720
    int count = 0;
    permute(rs, 0, R - 1, perms, &count);
    int ans = INF;

    // Evaluate each permutation to find the minimum cost path
    for (int i = 0; i < count; i++) {
        int tmp = 0;
        for (int j = 1; j < R; j++) {
            int from = perms[i][j - 1];
            int to = perms[i][j];
            tmp += costs[from][to]; // Accumulate the cost of the current permutation
        }
        ans = min(ans, tmp); // Update the answer with the minimum cost found
        free(perms[i]); // Free the allocated memory for the permutation
    }

    // Free the allocated memory for permutations
    free(perms);
    // Free the allocated memory for costs
    for (int i = 0; i < n; i++) {
        free(costs[i]);
    }
    free(costs);
    free(rs);

    // Output the minimum cost
    printf("%d\n", ans);
    return 0;
}

// <END-OF-CODE>
>>>>>>> 98c87cb78a (data updated)
