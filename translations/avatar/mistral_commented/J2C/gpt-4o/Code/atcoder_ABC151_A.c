#include <stdio.h> // Include standard input/output library
#include <stdlib.h> // Include standard library for memory allocation and other utilities

// Define a structure to represent the RemRing class
typedef struct {
    long module; // Declare a long variable to store the ring modulus
} RemRing;

// Function to create a new RemRing instance
RemRing* createRemRing(long module) {
    RemRing* ring = (RemRing*)malloc(sizeof(RemRing)); // Allocate memory for RemRing
    ring->module = module; // Initialize the module variable
    return ring; // Return the created RemRing instance
}

// Function to compute the sum of two numbers modulo the module
long sum(RemRing* ring, long a, long b) {
    return (a + b + ring->module) % ring->module;
}

// Function to compute the difference of two numbers modulo the module
long sub(RemRing* ring, long a, long b) {
    return (a - b + ring->module) % ring->module;
}

// Function to compute the product of two numbers modulo the module
long prod(RemRing* ring, long a, long b) {
    return (a * b) % ring->module;
}

// Function to compute the quotient of two numbers modulo the module
long div(RemRing* ring, long a, long b) {
    long quotient = a * inv(ring, b); // Compute the quotient by multiplying the dividend with the multiplicative inverse of the divisor
    return quotient % ring->module; // Return the quotient modulo the module
}

// Function to compute the multiplicative inverse of a number modulo the module
long inv(RemRing* ring, long a) {
    long b = ring->module; // Initialize b as the module
    long u = 1; // Initialize u as 1
    long v = 0; // Initialize v as 0

    // Perform extended Euclidean algorithm to find the multiplicative inverse of a modulo the module
    while (b > 0) {
        long t = a / b; // Compute the quotient of a divided by b
        long z = a; // Store a temporarily
        a = b; // Update a with the value of b
        b = z % ring->module; // Update b with the remainder of z modulo the module
        long temp = u; // Store u temporarily
        u = v; // Update u with the value of v
        v = temp - t * v; // Update v as (u - t * v) % module
    }

    // If the result is negative, add the module to make it positive
    if (u < 0) u += ring->module;

    return u; // Return the multiplicative inverse of a
}

int main() {
    char s[100]; // Declare a character array to store input
    // Read a line of input
    fgets(s, sizeof(s), stdin);
    // Print the ASCII value of the first character incremented by 1
    printf("%c", s[0] + 1);

    // Example usage of RemRing (optional, can be removed if not needed)
    RemRing* ring = createRemRing(100); // Create a RemRing with a modulus of 100
    printf("\nSum: %ld", sum(ring, 10, 20)); // Example sum
    printf("\nSub: %ld", sub(ring, 20, 10)); // Example subtraction
    printf("\nProd: %ld", prod(ring, 10, 20)); // Example product
    printf("\nDiv: %ld", div(ring, 20, 10)); // Example division
    free(ring); // Free the allocated memory for RemRing

    return 0; // Return 0 to indicate successful execution
}

// <END-OF-CODE>
