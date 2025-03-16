
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <limits.h>
#include <stdbool.h>

int main() {
    int N;
    scanf("%d", &N);
    int A[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }
    long long result = 0;
    for (int b = 0; b < 60; b++) {
        int bs = 0;
        for (int i = 0; i < N; i++) {
            bs += ((A[i] >> b) & 1);
        }
        result = (result + bs * (N - bs) * (1LL << b)) % 1000000007;
    }
    printf("%lld\n", result);
    return 0;
}
// END-OF-CODE