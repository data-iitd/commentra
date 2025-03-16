#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    long gcd, lcd = 1;
    for (int i = 0; i < n; i++) {
        gcd = getGCD(lcd, a[i]);
        lcd = lcd * a[i] / gcd;
        if (lcd > m) {
            printf("0\n");
            return 0;
        }
    }
    for (int i = 0; i < n; i++) {
        if ((lcd / a[i]) % 2 == 0) {
            printf("0\n");
            return 0;
        }
    }
    printf("%ld\n", (m / lcd + 1) / 2);
    return 0;
}

long getGCD(long a, long b) {
    if (b == 0) {
        return a;
    } else {
        return getGCD(b, a % b);
    }
}

