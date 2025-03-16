#include <stdio.h>

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    int k, a, b, c;
    long long ans = 0; // Use long long to avoid overflow for large values
    scanf("%d", &k);
    for (a = 1; a <= k; a++) {
        for (b = 1; b <= k; b++) {
            for (c = 1; c <= k; c++) {
                ans += gcd(a, gcd(b, c));
            }
        }
    }
    printf("%lld\n", ans); // Use %lld for long long
    return 0;
}

// <END-OF-CODE>
