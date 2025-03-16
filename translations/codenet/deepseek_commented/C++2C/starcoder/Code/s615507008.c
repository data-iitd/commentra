#include <stdio.h>
#include <stdlib.h>
#define REP(i, n) for (int i = 0; i < (n); i++)

void solve(long long N, long long T[], long long M, long long P[], long long X[]){
    REP(i, M) {
        long long ans = 0;
        REP(j, N) {
            if (j == P[i] - 1) ans += X[i];
            else ans += T[j];
        }
        printf("%lld\n", ans);
    }
}

int main(){
    long long N;
    scanf("%lld", &N);
    long long T[N];
    REP(i, N) scanf("%lld", &T[i]);
    long long M;
    scanf("%lld", &M);
    long long P[M];
    long long X[M];
    REP(i, M) scanf("%lld %lld", &P[i], &X[i]);
    solve(N, T, M, P, X);
    return 0;
}

