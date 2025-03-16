#include <stdio.h>

// Structure to perform operations in a modular arithmetic system
typedef struct {
    long module; // Variable to store the modulus value
} RemRing;

// Function to initialize the modulus
void initRemRing(RemRing *ring, long module) {
    ring->module = module;
}

// Function to perform modular addition
long sum(RemRing *ring, long a, long b) {
    return (a + b + ring->module) % ring->module;
}

// Function to perform modular subtraction
long sub(RemRing *ring, long a, long b) {
    return (a - b + ring->module) % ring->module;
}

// Function to perform modular multiplication
long prod(RemRing *ring, long a, long b) {
    return (a * b) % ring->module;
}

// Function to compute the modular inverse using the Extended Euclidean Algorithm
long inv(RemRing *ring, long a) {
    long b = ring->module;
    long u = 1;
    long v = 0;

    // Extended Euclidean Algorithm to find the inverse
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

    // Ensure the result is positive
    u %= ring->module;
    if (u < 0) u += ring->module;

    // Return the modular inverse
    return u;
}

// Function to perform modular division
long div(RemRing *ring, long a, long b) {
    return (a * inv(ring, b)) % ring->module;
}

int main() {
    // Declare a string to hold the input
    char s[2]; // Array to hold one character and the null terminator

    // Read a line of input from the user
    fgets(s, sizeof(s), stdin);

    // Output the next character in the ASCII sequence of the first character of the input
    printf("%c", s[0] + 1);

    return 0;
}

// <END-OF-CODE>
