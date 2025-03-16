
#include <iostream> // Include header file for input/output operations
#include <string> // Include header file for string operations

using namespace std; // Use the standard namespace

class RemRing { // Define a new class named RemRing
    long module; // Declare a long variable named module to store the ring modulus

    public: // Define a public section for the class
        RemRing(long module) { // Constructor to initialize the module variable
            this->module = module;
        }

        long sum(long a, long b) { // Method to compute the sum of two numbers modulo the module
            return (a + b + module) % module;
        }

        long sub(long a, long b) { // Method to compute the difference of two numbers modulo the module
            return (a - b + module) % module;
        }

        long prod(long a, long b) { // Method to compute the product of two numbers modulo the module
            return (a * b) % module;
        }

        long div(long a, long b) { // Method to compute the quotient and remainder of two numbers modulo the module
            long quotient = a * inv(b); // Compute the quotient by multiplying the dividend with the multiplicative inverse of the divisor
            return quotient % module; // Return the quotient modulo the module
        }

        long inv(long a) { // Method to compute the multiplicative inverse of a number modulo the module
            long b = module; // Initialize b as the module
            long u = 1; // Initialize u as 1
            long v = 0; // Initialize v as 0

            // Perform extended Euclidean algorithm to find the multiplicative inverse of a modulo the module
            while (b > 0) {
                long t = a / b; // Compute the quotient of a divided by b
                long z = a; // Store a temporarily
                a = b; // Update a with the value of b
                b = z % module; // Update b with the remainder of z modulo the module
                long temp = u; // Store u temporarily
                u = v; // Update u with the value of v
                v = temp - t * v; // Update v as (u - t * v) % module
            }

            // If the result is negative, add the module to make it positive
            if (u < 0) u += module;

            return u; // Return the multiplicative inverse of a
        }
};

int main() { // Main function to start the program
    long module; // Declare a long variable named module to store the ring modulus
    long a, b; // Declare two long variables named a and b to store the dividend and divisor

    // Read the ring modulus and the dividend and divisor from the standard input
    cin >> module >> a >> b;

    // Create a new RemRing object to perform operations modulo the ring modulus
    RemRing r(module);

    // Print the sum of a and b modulo the ring modulus
    cout << r.sum(a, b) << endl;

    // Print the difference of a and b modulo the ring modulus
    cout << r.sub(a, b) << endl;

    // Print the product of a and b modulo the ring modulus
    cout << r.prod(a, b) << endl;

    // Print the quotient and remainder of a and b modulo the ring modulus
    cout << r.div(a, b) << endl;

    // Print the multiplicative inverse of a modulo the ring modulus
    cout << r.inv(a) << endl;

    return 0; // Return 0 to indicate successful execution
}

