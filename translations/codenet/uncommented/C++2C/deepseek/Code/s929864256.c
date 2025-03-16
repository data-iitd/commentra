#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    long long a, b;
    scanf("%lld %lld", &a, &b);
    long long result = a + b;
    if (result < a - b) {
        result = a - b;
    }
    if (result < a * b) {
        result = a * b;
    }
    printf("%lld\n", result);
    return 0;
}
