
#include <stdio.h>
#include <stdlib.h>

// Define a new class named RemRing
typedef struct RemRing {
    long module; // Declare a long variable named module to store the ring modulus
} RemRing;

// Declare a new function named newRemRing to create a new RemRing object
RemRing *newRemRing(long module) {
    RemRing *r = (RemRing *) malloc(sizeof(RemRing)); // Allocate memory for a new RemRing object
    r->module = module; // Initialize the module variable
    return r; // Return the new RemRing object
}

// Declare a new function named sum to compute the sum of two numbers modulo the module
long sum(RemRing *r, long a, long b) {
    return (a + b + r->module) % r->module;
}

// Declare a new function named sub to compute the difference of two numbers modulo the module
long sub(RemRing *r, long a, long b) {
    return (a - b + r->module) % r->module;
}

// Declare a new function named prod to compute the product of two numbers modulo the module
long prod(RemRing *r, long a, long b) {
    return (a * b) % r->module;
}

// Declare a new function named div to compute the quotient and remainder of two numbers modulo the module
long div(RemRing *r, long a, long b) {
    long quotient = a * inv(r, b); // Compute the quotient by multiplying the dividend with the multiplicative inverse of the divisor
    return quotient % r->module; // Return the quotient modulo the module
}

// Declare a new function named inv to compute the multiplicative inverse of a number modulo the module
long inv(RemRing *r, long a) {
    long b = r->module; // Initialize b as the module
    long u = 1; // Initialize u as 1
    long v = 0; // Initialize v as 0

    // Perform extended Euclidean algorithm to find the multiplicative inverse of a modulo the module
    while (b > 0) {
        long t = a / b; // Compute the quotient of a divided by b
        long z = a; // Store a temporarily
        a = b; // Update a with the value of b
        b = z % r->module; // Update b with the remainder of z modulo the module
        long temp = u; // Store u temporarily
        u = v; // Update u with the value of v
        v = temp - t * v; // Update v as (u - t * v) % module
    }

    // If the result is negative, add the module to make it positive
    if (u < 0) u += r->module;

    return u; // Return the multiplicative inverse of a
}

int main() {
    RemRing *r = newRemRing(1000000007); // Create a new RemRing object with a module of 1000000007
    char s[1000000]; // Declare a char array variable to store a line of input
    scanf("%s", s); // Read a line of input
    printf("%c", s[0] + 1); // Print the ASCII value of its first character incremented by 1
    return 0;
}

