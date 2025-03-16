#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

int main() {
    long long a, b;
    scanf("%lld %lld", &a, &b);
    printf("%lld\n", (long long)fmax(a + b, fmax(a - b, a * b)));
    return 0;
}

