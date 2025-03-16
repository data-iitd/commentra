
#include <stdio.h>
#include <stdlib.h>
#define REP(i, n) for (int i = 0; i < (n); i++)

// Function to solve the problem
void solve(int N, // Number of elements in T
            int *T, // Input array T
            int M, // Number of queries
            int *P, // Position of each query
            int *X // Value of each query
          ) {
    // Initialize a variable to store the answer for each query
    int ans = 0;

    // Iterate through each query
    REP(i, M) {
        // Initialize the answer variable to zero
        ans = 0;

        // Iterate through each element in T up to the position of the current query
        REP(j, N) {
            // If the current index j is equal to the position of the current query - 1
            if (j == P[i] - 1) {
                // Add the value of X[i] to the answer variable
                ans += X[i];
            }
            // Otherwise, add the value of the current element in T to the answer variable
            else {
                ans += T[j];
            }
        }

        // Print the answer for the current query
        printf("%d\n", ans);
    }
}

// Main function
int main() {
    // Initialize iostream objects
    setbuf(stdout, NULL);

    // Read the number of elements in T from the standard input
    int N;
    scanf("%d", &N);

    // Initialize an array T of size N
    int *T = (int *)malloc(sizeof(int) * N);

    // Read the elements of T from the standard input
    REP(i, N) scanf("%d", &T[i]);

    // Read the number of queries from the standard input
    int M;
    scanf("%d", &M);

    // Initialize arrays P and X of size M
    int *P = (int *)malloc(sizeof(int) * M);
    int *X = (int *)malloc(sizeof(int) * M);

    // Read the positions and values of the queries from the standard input
    REP(i, M) scanf("%d %d", &P[i], &X[i]);

    // Call the solve function with the given arguments
    solve(N, T, M, P, X);

    // Free the allocated memory
    free(T);
    free(P);
    free(X);

    // Return 0 to indicate successful execution
    return 0;
}

