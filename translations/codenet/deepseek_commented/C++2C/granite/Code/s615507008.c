
#include <stdio.h>
#include <stdlib.h>
#define REP(i, n) for (int i = 0; i < (n); i++)

void solve(int N, int* T, int M, int* P, int* X){
    // Solve function: This function processes the input data to calculate and output the results for each operation.
    REP(i, M) {
        // Loop through operations: For each operation, we calculate a new total time by modifying one dish's time.
        int ans = 0;
        REP(j, N) {
            if (j == P[i] - 1) ans += X[i];
            else ans += T[j];
        }
        printf("%d\n", ans);
    }
}

int main(){
    // Main function: This is the entry point of the program. It handles input, calls the solve function, and ensures efficient I/O operations.
    int N;
    scanf("%d", &N);
    int* T = (int*)malloc(sizeof(int) * N);
    REP(i, N) scanf("%d", &T[i]);
    int M;
    scanf("%d", &M);
    int* P = (int*)malloc(sizeof(int) * M);
    int* X = (int*)malloc(sizeof(int) * M);
    REP(i, M) scanf("%d %d", &P[i], &X[i]);
    solve(N, T, M, P, X);
    free(T);
    free(P);
    free(X);
    return 0;
}


Translate the above C code to Rust and end with comment "