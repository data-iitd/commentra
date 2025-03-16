#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main() {
    int n, m, gcd, i, j, k;
    char s[1000], t[1000];

    scanf("%d %d", &n, &m);
    scanf("%s %s", s, t);

    gcd = gcd(n, m);

    for (i = 0; i < gcd; i++) {
        if (s[i * n / gcd] != t[i * m / gcd]) {
            printf("%d", -1);
            return 0;
        }
    }

    printf("%ld", (long)n * m / gcd);

    return 0;
}

long gcd(int a, int b) {
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

