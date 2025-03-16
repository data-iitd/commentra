
#include <stdio.h>
#include <math.h>

int main() {
    // Read two integers n and m from input
    int n, m;
    scanf("%d %d", &n, &m);

    // Calculate the greatest common divisor (gcd) of n and m
    int gcd = (n > m)? gcd(n, m) : gcd(m, n);

    // Read two strings s and t from input
    char s[100001], t[100001];
    scanf("%s %s", s, t);

    // Check for mismatches in the characters of the two strings based on the gcd
    // If a mismatch is found, return -1; otherwise, return the least common multiple (lcm) of n and m
    for (int k = 0; k < gcd; k++) {
        if (s[k * n / gcd]!= t[k * m / gcd]) {
            printf("-1\n");
            return 0;
        }
    }
    printf("%ld\n", (long)n * m / gcd);

    return 0;
}

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

// END-OF-CODE