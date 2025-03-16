#include <stdio.h>

long module;

long sum(long a, long b) {
    return (a + b + module) % module;
}

long sub(long a, long b) {
    return (a - b + module) % module;
}

long prod(long a, long b) {
    return (a * b) % module;
}

long inv(long a) {
    long b = module;
    long u = 1;
    long v = 0;
    while (b > 0) {
        long t = a / b;
        a -= t * b;
        u -= t * v;
        long z = a;
        a = b;
        b = z;
        z = u;
        u = v;
        v = z;
    }
    u %= module;
    if (u < 0) u += module;
    return u;
}

long div(long a, long b) {
    return (a * inv(b)) % module;
}

int main() {
    char s[100]; // Assuming a maximum length for the input string
    fgets(s, sizeof(s), stdin);
    printf("%c\n", s[0] + 1);
    return 0;
}

// Note: The RemRing class functionality is implemented through functions.
// The module variable should be set before using the arithmetic functions.

