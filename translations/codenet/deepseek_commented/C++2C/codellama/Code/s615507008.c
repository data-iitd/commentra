#include <stdio.h>
#include <stdlib.h>
#define REP(i, n) for (int i = 0; i < (n); i++)

void solve(long long N, long long *T, long long M, long long *P, long long *X){
    // Solve function: This function processes the input data to calculate and output the results for each operation.
    REP(i, M) {
        // Loop through operations: For each operation, we calculate a new total time by modifying one dish's time.
        long long ans = 0;
        REP(j, N) {
            if (j == P[i] - 1) ans += X[i];
            else ans += T[j];
        }
        printf("%lld\n", ans);
    }
}

int main(){
    // Main function: This is the entry point of the program. It handles input, calls the solve function, and ensures efficient I/O operations.
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    long long N;
    scanf("%lld", &N);
    long long *T = (long long *)malloc(N * sizeof(long long));
    REP(i, N) scanf("%lld", &T[i]);
    long long M;
    scanf("%lld", &M);
    long long *P = (long long *)malloc(M * sizeof(long long));
    long long *X = (long long *)malloc(M * sizeof(long long));
    REP(i, M) scanf("%lld %lld", &P[i], &X[i]);
    solve(N, T, M, P, X);
    return 0;
}

