#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main() {
    int n, m, gcd;
    scanf("%d %d", &n, &m);
    gcd = __gcd(n, m);
    char s[100000], t[100000];
    scanf("%s", s);
    scanf("%s", t);
    printf("%ld\n", IntStream_range(0, gcd).filter(k -> s[k * n / gcd]!= t[k * m / gcd]).mapToLong(k -> -1).findAny().orElse(n * m / gcd));
    return 0;
}

