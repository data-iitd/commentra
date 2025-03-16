#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <limits.h>

#define INF INT_MAX
#define MOD 1000000007

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

int main() {
    int q, h, s, d, n;
    scanf("%d %d %d %d", &q, &h, &s, &d);
    scanf("%d", &n);

    int best1L = fmin(q * 4, fmin(h * 2, s));
    int best2L = fmin(d, best1L * 2);

    if (n % 2 == 0) {
        printf("%d\n", best2L * (n / 2));
    } else {
        printf("%d\n", best2L * (n / 2) + best1L);
    }

    return 0;
}
