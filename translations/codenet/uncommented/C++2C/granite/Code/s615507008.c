
#include <stdio.h>

void solve(int N, int T[], int M, int P[], int X[]){
    for (int i = 0; i < M; i++) {
        int ans = 0;
        for (int j = 0; j < N; j++) {
            if (j == P[i] - 1) ans += X[i];
            else ans += T[j];
        }
        printf("%d\n", ans);
    }
}

int main(){
    int N;
    scanf("%d", &N);
    int T[N];
    for (int i = 0; i < N; i++) scanf("%d", &T[i]);
    int M;
    scanf("%d", &M);
    int P[M], X[M];
    for (int i = 0; i < M; i++) scanf("%d %d", &P[i], &X[i]);
    solve(N, T, M, P, X);
    return 0;
}


Translate the above C code to Rust and end with comment "