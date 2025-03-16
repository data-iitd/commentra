#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

int main() {
    long long N, K;
    long long A[200100];
    long long B[200100];
    int now = 1;
    long long cnt = 0;
    scanf("%lld %lld", &N, &K);
    for (int i = 0; i < N; i++) {
        scanf("%lld", &A[i + 1]);
    }
    for (int i = 0; i < 200100; i++) {
        B[i] = -1;
    }
    B[1] = 0;
    for (long long j = 1; j <= K; j++) {
        now = A[now];
        if (B[now] == -1) {
            B[now] = j;
        } else {
            cnt = j;
            break;
        }
    }
    if (j < K) {
        long long tmp = (K - B[now]) % (cnt - B[now]);
        for (long long j = 0; j < tmp; j++) {
            now = A[now];
        }
    }
    printf("%d\n", now);
    return 0;
}
