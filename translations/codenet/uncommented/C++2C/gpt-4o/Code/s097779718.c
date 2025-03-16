#include <stdio.h>

long long Euclid(long long x, long long y) {
    long long tmp;

    if (x < y) {
        tmp = x;
        x = y;
        y = tmp;
    }

    if (!(x % y)) return y;
    return Euclid(y, x % y);
}

int main() {
    long long A, B; 
    scanf("%lld %lld", &A, &B);

    printf("%lld\n", (A * B) / Euclid(A, B));
    return 0;
}

// <END-OF-CODE>
