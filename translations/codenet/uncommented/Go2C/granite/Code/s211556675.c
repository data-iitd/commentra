
#include <stdio.h>

int main() {
    int A, B, C, K;
    scanf("%d %d %d %d", &A, &B, &C, &K);
    int ma = A;
    if (ma < B) ma = B;
    if (ma < C) ma = C;
    int rest = 0;
    if (ma == A) {
        rest += B + C;
    } else if (ma == B) {
        rest += A + C;
    } else {
        rest += A + B;
    }
    for (int i = 1; i <= K; i++) {
        ma *= 2;
    }
    printf("%d\n", ma + rest);
    return 0;
}
