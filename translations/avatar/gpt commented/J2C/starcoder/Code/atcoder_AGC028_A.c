#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int gcd = __gcd(n, m);
    char s[100000], t[100000];
    scanf("%s", s);
    scanf("%s", t);
    for (int k = 0; k < gcd; k++) {
        if (s[k * n / gcd]!= t[k * m / gcd]) {
            printf("-1\n");
            return 0;
        }
    }
    printf("%ld\n", (long)n * m / gcd);
    return 0;
}

