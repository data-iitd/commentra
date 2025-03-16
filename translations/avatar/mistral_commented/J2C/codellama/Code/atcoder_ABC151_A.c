
#include <stdio.h> // Include standard input/output library
#include <stdlib.h> // Include standard library for common functions
#include <string.h> // Include string library for string functions

struct RemRing { // Define a new structure named RemRing
    long module; // Declare a long variable named module to store the ring modulus
};

struct RemRing *createRemRing(long module) { // Function to create a new RemRing object
    struct RemRing *obj = (struct RemRing *)malloc(sizeof(struct RemRing)); // Allocate memory for the object
    obj->module = module; // Initialize the module variable
    return obj; // Return the object
}

long sum(struct RemRing *obj, long a, long b) { // Function to compute the sum of two numbers modulo the module
    return (a + b + obj->module) % obj->module; // Return the sum modulo the module
}

long sub(struct RemRing *obj, long a, long b) { // Function to compute the difference of two numbers modulo the module
    return (a - b + obj->module) % obj->module; // Return the difference modulo the module
}

long prod(struct RemRing *obj, long a, long b) { // Function to compute the product of two numbers modulo the module
    return (a * b) % obj->module; // Return the product modulo the module
}

long div(struct RemRing *obj, long a, long b) { // Function to compute the quotient and remainder of two numbers modulo the module
    long quotient = a * inv(obj, b); // Compute the quotient by multiplying the dividend with the multiplicative inverse of the divisor
    return quotient % obj->module; // Return the quotient modulo the module
}

long inv(struct RemRing *obj, long a) { // Function to compute the multiplicative inverse of a number modulo the module
    long b = obj->module; // Initialize b as the module
    long u = 1; // Initialize u as 1
    long v = 0; // Initialize v as 0

    // Perform extended Euclidean algorithm to find the multiplicative inverse of a modulo the module
    while (b > 0) {
        long t = a / b; // Compute the quotient of a divided by b
        long z = a; // Store a temporarily
        a = b; // Update a with the value of b
        b = z % obj->module; // Update b with the remainder of z modulo the module
        long temp = u; // Store u temporarily
        u = v; // Update u with the value of v
        v = temp - t * v; // Update v as (u - t * v) % module
    }

    // If the result is negative, add the module to make it positive
    if (u < 0) u += obj->module;

    return u; // Return the multiplicative inverse of a
}

int main() { // Main function to start the program
    struct RemRing *obj = createRemRing(1000000007); // Create a new RemRing object
    char s[1000000]; // Declare a character array to store a line of input
    char *sl[1000000]; // Declare a character array to store each word in a line of input
    int i; // Declare an integer variable to store the index of each word in a line of input

    // Read a line of input and print the ASCII value of its first character incremented by 1
    fgets(s, 1000000, stdin);
    for (i = 0; i < 1000000; i++) {
        if (s[i] == '\0') break;
        sl[i] = &s[i];
    }
    printf("%c", (sl[0][0] + 1) % 1000000007);

    return 0; // Return 0 to indicate successful execution
}

