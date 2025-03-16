#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <ctype.h>
#include <limits.h>
#include <float.h>
#include <time.h>
#include <assert.h>

int main(int argc, char **argv) {
    int n, m, gcd;
    scanf("%d %d", &n, &m);
    char s[n], t[m];
    scanf("%s", s);
    scanf("%s", t);
    gcd = __gcd(n, m);
    printf("%ld\n", n * m / gcd);
    return 0;
}

