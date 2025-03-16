#include <stdio.h>
#include <stdlib.h>

<<<<<<< HEAD
void solve(long long N, long long *T, long long M, long long *P, long long *X) {
    // Solve function: This function processes the input data to calculate and output the results for each operation.
    for (long long i = 0; i < M; i++) {
        // Loop through operations: For each operation, we calculate a new total time by modifying one dish's time.
        long long ans = 0;
        for (long long j = 0; j < N; j++) {
=======
#define REP(i, n) for (int i = 0; i < (n); i++)

// Function to solve the problem
void solve(long long N, long long* T, long long M, long long* P, long long* X) {
    // Loop through operations
    for (int i = 0; i < M; i++) {
        long long ans = 0;
        for (int j = 0; j < N; j++) {
>>>>>>> 98c87cb78a (data updated)
            if (j == P[i] - 1) ans += X[i];
            else ans += T[j];
        }
        printf("%lld\n", ans);
    }
}

int main() {
<<<<<<< HEAD
    // Main function: This is the entry point of the program. It handles input, calls the solve function, and ensures efficient I/O operations.
    long long N;
    scanf("%lld", &N);
    long long *T = (long long *)malloc(N * sizeof(long long));
    for (long long i = 0; i < N; i++) {
        scanf("%lld", &T[i]);
    }
    long long M;
    scanf("%lld", &M);
    long long *P = (long long *)malloc(M * sizeof(long long));
    long long *X = (long long *)malloc(M * sizeof(long long));
    for (long long i = 0; i < M; i++) {
        scanf("%lld %lld", &P[i], &X[i]);
    }
=======
    // Main function
    long long N;
    scanf("%lld", &N);
    long long* T = (long long*)malloc(N * sizeof(long long));
    REP(i, N) scanf("%lld", &T[i]);
    
    long long M;
    scanf("%lld", &M);
    long long* P = (long long*)malloc(M * sizeof(long long));
    long long* X = (long long*)malloc(M * sizeof(long long));
    REP(i, M) scanf("%lld %lld", &P[i], &X[i]);
    
>>>>>>> 98c87cb78a (data updated)
    solve(N, T, M, P, X);
    
    // Free allocated memory
    free(T);
    free(P);
    free(X);
    
    return 0;
}

// <END-OF-CODE>
