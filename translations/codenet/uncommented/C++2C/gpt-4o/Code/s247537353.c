#include <stdio.h>

int main() {
    long long A, B, C, K;
    scanf("%lld %lld %lld %lld", &A, &B, &C, &K);
    
    if (A + B >= K) {
        printf("%lld\n", (A < K) ? A : K);
    } else {
        printf("%lld\n", A - (K - (A + B)));
    }
<<<<<<< HEAD
    
=======

>>>>>>> 98c87cb78a (data updated)
    return 0;
}

// <END-OF-CODE>
