#include <stdio.h>
#include <stdlib.h>

#define REP(i, n) for (int i = 0; i < (n); i++)

// Function to solve the problem
void solve(long long N, // Number of elements in T
           long long *T, // Input array T
           long long M, // Number of queries
           long long *P, // Position of each query
           long long *X // Value of each query
         ) {
    // Initialize a variable to store the answer for each query
    long long ans = 0;

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
        printf("%lld\n", ans);
    }
}

// Main function
int main() {
    // Read the number of elements in T from the standard input
    long long N;
    scanf("%lld", &N);

    // Initialize an array T of size N
    long long *T = (long long *)malloc(N * sizeof(long long));

    // Read the elements of T from the standard input
    REP(i, N) scanf("%lld", &T[i]);

    // Read the number of queries from the standard input
    long long M;
    scanf("%lld", &M);

    // Initialize arrays P and X of size M
    long long *P = (long long *)malloc(M * sizeof(long long));
    long long *X = (long long *)malloc(M * sizeof(long long));

    // Read the positions and values of the queries from the standard input
    REP(i, M) scanf("%lld %lld", &P[i], &X[i]);

    // Call the solve function with the given arguments
    solve(N, T, M, P, X);

    // Free allocated memory
    free(T);
    free(P);
    free(X);

    // Return 0 to indicate successful execution
    return 0;
}

// <END-OF-CODE>
