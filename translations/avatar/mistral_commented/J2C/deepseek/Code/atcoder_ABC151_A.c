#include <stdio.h>
#include <stdlib.h>

long sum(long a, long b, long module) {
    return (a + b + module) % module;
}

long sub(long a, long b, long module) {
    return (a - b + module) % module;
}

long prod(long a, long b) {
    return (a * b) % module;
}

long div(long a, long b, long module) {
    long quotient = a * inv(b, module);
    return quotient % module;
}

long inv(long a, long module) {
    long b = module;
    long u = 1;
    long v = 0;

    while (b > 0) {
        long t = a / b;
        long z = a;
        a = b;
        b = z % module;
        long temp = u;
        u = v;
        v = temp - t * v;
    }

    if (u < 0) u += module;

    return u;
}

int main() {
    long a;
    scanf("%ld", &a);
    printf("%c", a + 1);
    return 0;
}

