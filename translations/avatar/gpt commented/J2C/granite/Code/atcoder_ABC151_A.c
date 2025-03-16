
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Create a BufferedReader to read input from the console
    char input[100];
    fgets(input, 100, stdin);

    // Declare a string to hold the input
    char* s = input;

    // Output the next character in the ASCII sequence of the first character of the input
    printf("%c", s[0] + 1);

    return 0;
}

// Class to perform operations in a modular arithmetic system
typedef struct {
    long module; // Variable to store the modulus value
} RemRing;

// Constructor to initialize the modulus
RemRing* remRing_new(long module) {
    RemRing* ring = (RemRing*)malloc(sizeof(RemRing));
    ring->module = module;
    return ring;
}

// Method to perform modular addition
long remRing_sum(RemRing* ring, long a, long b) {
    return (a + b + ring->module) % ring->module;
}

// Method to perform modular subtraction
long remRing_sub(RemRing* ring, long a, long b) {
    return (a - b + ring->module) % ring->module;
}

// Method to perform modular multiplication
long remRing_prod(RemRing* ring, long a, long b) {
    return (a * b) % ring->module;
}

// Method to perform modular division
long remRing_div(RemRing* ring, long a, long b) {
    return (a * remRing_inv(ring, b)) % ring->module;
}

// Method to compute the modular inverse using the Extended Euclidean Algorithm
long remRing_inv(RemRing* ring, long a) {
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

// End of code
