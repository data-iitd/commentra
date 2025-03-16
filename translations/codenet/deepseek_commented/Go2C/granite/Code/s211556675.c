
#include <stdio.h>

int max(int a, int b, int c) {
    int m = a;
    if (m < b) {
        m = b;
    }
    if (m < c) {
        m = c;
    }
    return m;
}

int main() {
    int A, B, C, K;
    scanf("%d %d %d %d", &A, &B, &C, &K);
    
    int ma = max(A, B, C);
    int rest = A + B + C - ma;
    
    for (int i = 1; i <= K; i++) {
        ma *= 2;
    }
    
    printf("%d\n", ma + rest);
    
    return 0;
}
