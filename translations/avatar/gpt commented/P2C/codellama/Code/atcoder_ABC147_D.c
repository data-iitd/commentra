
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_N 1000000
#define MAX_BITS 60

int main() {
    int N;
    scanf("%d", &N);

    int A[MAX_N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    int result = 0;
    for (int b = 0; b < MAX_BITS; b++) {
        int bs = 0;
        for (int i = 0; i < N; i++) {
            if (A[i] & (1 << b)) {
                bs++;
            }
        }
        result = (result + bs * (N - bs) * (1 << b)) % 1000000007;
    }

    printf("%d\n", result);

    return 0;
}

