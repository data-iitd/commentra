#include <stdio.h>
#include <stdlib.h>

long long max(long long a, long long b, long long c, long long d) {
    long long m = a > b ? a : b;
    m = m > c ? m : c;
    return m > d ? m : d;
}

int main() {
    long long a, b, c, d;
    scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
    printf("%lld\n", max(a * c, b * d, a * d, b * c));
    return 0;
}

// <END-OF-CODE>
