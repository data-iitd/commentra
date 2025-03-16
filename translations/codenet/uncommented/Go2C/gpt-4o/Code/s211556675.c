#include <stdio.h>

int max(int a, int b, int c) {
    if (a >= b && a >= c) return a;
    if (b >= a && b >= c) return b;
    return c;
}

int main() {
    int A, B, C, K;
    scanf("%d %d %d %d", &A, &B, &C, &K);
    
    int ma = max(A, B, C);
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

// <END-OF-CODE>
