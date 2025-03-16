#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main() {
    int n, m, gcd;
    char s[1000], t[1000];
    scanf("%d %d", &n, &m);
    gcd = (int)gcd(n, m);
    scanf("%s %s", s, t);
    int i, j;
    for (i = 0; i < gcd; i++) {
        if (s[i * n / gcd] != t[i * m / gcd]) {
            printf("%d", -1);
            return 0;
        }
    }
    printf("%ld", (long)n * m / gcd);
    return 0;
}

