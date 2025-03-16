#include <stdio.h>

typedef struct {
    long module;
} RemRing;

// Function to initialize the RemRing structure
RemRing createRemRing(long module) {
    RemRing ring;
    ring.module = module;
    return ring;
}

// Function to calculate the sum modulo module
long sum(RemRing *ring, long a, long b) {
    return (a + b + ring->module) % ring->module;
}

// Function to calculate the difference modulo module
long sub(RemRing *ring, long a, long b) {
    return (a - b + ring->module) % ring->module;
}

// Function to calculate the product modulo module
long prod(RemRing *ring, long a, long b) {
    return (a * b) % ring->module;
}

// Function to calculate the division modulo module
long div(RemRing *ring, long a, long b) {
    return (a * inv(ring, b)) % ring->module;
}

// Function to calculate the modular inverse
long inv(RemRing *ring, long a) {
    long b = ring->module;
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

    u %= ring->module;
    if (u < 0) u += ring->module;
    return u;
}

int main() {
    // Read a single line of input from the user
    char s[100];
    fgets(s, sizeof(s), stdin);

    // Increment the first character of the input by 1 and print it
    printf("%c\n", s[0] + 1);

    return 0;
}

// <END-OF-CODE>
