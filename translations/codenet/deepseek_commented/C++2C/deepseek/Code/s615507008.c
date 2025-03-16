#include <stdio.h>
#include <stdlib.h>

// Include necessary headers: These headers are essential for input/output operations, using maps, sets, and vectors respectively.

// Define a macro for loop: This simplifies the for loop syntax, making the code more readable.

// Namespace usage: The code uses the std namespace to avoid prefixing standard library components with 'std::'.

void solve(long long N, long long *T, long long M, long long *P, long long *X){
    // Solve function: This function processes the input data to calculate and output the results for each operation.
    for (int i = 0; i < M; i++) {
        // Loop through operations: For each operation, we calculate a new total time by modifying one dish's time.
        long long ans = 0;
        for (int j = 0; j < N; j++) {
            if (j == P[i] - 1) ans += X[i];
            else ans += T[j];
        }
        printf("%lld\n", ans);
    }
}

int main(){
    // Main function: This is the entry point of the program. It handles input, calls the solve function, and ensures efficient I/O operations.
    long long N;
    scanf("%lld", &N);
    long long *T = (long long *)malloc(N * sizeof(long long));
    for (int i = 0; i < N; i++) scanf("%lld", &T[i]);
    long long M;
    scanf("%lld", &M);
    long long *P = (long long *)malloc(M * sizeof(long long));
    long long *X = (long long *)malloc(M * sizeof(long long));
    for (int i = 0; i < M; i++) scanf("%lld %lld", &P[i], &X[i]);
    solve(N, T, M, P, X);
    free(T);
    free(P);
    free(X);
    return 0;
}
