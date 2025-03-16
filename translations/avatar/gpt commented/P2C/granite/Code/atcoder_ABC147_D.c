
#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    scanf("%d", &N);

    long long A[N];
    for (int i = 0; i < N; i++) {
        scanf("%lld", &A[i]);
    }

    long long result = 0;
    for (int b = 0; b < 60; b++) {
        long long bs = 0;
        for (int i = 0; i < N; i++) {
            if (A[i] & (1LL << b)) {
                bs++;
            }
        }
        result = (result + bs * (N - bs) * (1LL << b)) % 1000000007;
    }

    printf("%lld\n", result);

    return 0;
}
