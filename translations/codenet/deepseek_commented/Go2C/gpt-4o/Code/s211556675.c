#include <stdio.h>

int max(int a, int b, int c) {
<<<<<<< HEAD
    int m = a;
    if (b > m) m = b;
    if (c > m) m = c;
    return m;
=======
    if (a >= b && a >= c) return a;
    if (b >= a && b >= c) return b;
    return c;
>>>>>>> 98c87cb78a (data updated)
}

int main() {
    int A, B, C, K;
    
    // Read input values
    scanf("%d %d %d %d", &A, &B, &C, &K);
    
    // Determine the maximum value among A, B, and C
    int ma = max(A, B, C);
    
    // Calculate the sum of the other two values
    int rest = 0;
    if (ma == A) {
        rest = B + C;
    } else if (ma == B) {
        rest = A + C;
    } else {
        rest = A + B;
    }
    
    // Double the maximum value K times
    for (int i = 0; i < K; i++) {
        ma *= 2;
    }
    
    // Print the final result
    printf("%d\n", ma + rest);
    
    return 0;
}

// <END-OF-CODE>
