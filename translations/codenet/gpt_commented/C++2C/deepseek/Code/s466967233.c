#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    long long N, K;
    long long A[200100];
    long long B[200100];
    int now = 1;
    long long cnt = 0;

    scanf("%lld %lld", &N, &K);

    for (int i = 1; i <= N; i++) {
        scanf("%lld", &A[i]);
    }

    memset(B, -1, sizeof(B));

    B[1] = 0;

    int j;
    for (j = 1; j <= K; j++) {
        now = A[now];

        if (B[now] == -1) {
            B[now] = j;
        } else {
            cnt = j;
            break;
        }
    }

    if (j < K) {
        long long tmp;
        tmp = (K - B[now]) % (cnt - B[now]);

        for (long long j = 0; j < tmp; j++) {
            now = A[now];
        }
    }

    printf("%d\n", now);
    return 0;
}
