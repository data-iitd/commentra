#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main() {
    int N;
    scanf("%d", &N);
    int64_t A[N];
    for (int i = 0; i < N; i++) {
        scanf("%ld", &A[i]);
    }
    int64_t result = 0;
    for (int b = 0; b < 60; b++) {
        int64_t bs = 0;
        for (int i = 0; i < N; i++) {
            bs += (A[i] >> b) & 1;
        }
        result = (result + bs * (N - bs) * (1LL << b)) % 1000000007;
    }
    printf("%ld\n", result);
    return 0;
}
