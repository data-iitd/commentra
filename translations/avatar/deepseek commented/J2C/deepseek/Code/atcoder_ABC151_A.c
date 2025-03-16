#include <stdio.h>
#include <stdlib.h>

long sum(long a, long b, long module) {
    return (a + b + module) % module;
}

long sub(long a, long b, long module) {
    return (a - b + module) % module;
}

long prod(long a, long b, long module) {
    return (a * b) % module;
}

long div(long a, long b, long module) {
    return (a * inv(b, module)) % module;
}

long inv(long a, long module) {
    long b = module;
    long u = 1;
    long v = 0;

    // Extended Euclidean Algorithm to find the modular inverse
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

int main() {
    // Read a single line of input from the user
    char s[100];
    scanf("%s", s);

    // Increment the first character of the input by 1 and print it
    printf("%c\n", s[0] + 1);

    return 0;
}

