#include <iostream> // Include iostream for input and output
#include <string>   // Include string for using string class

class RemRing { // Define a new class named RemRing
    long module; // Declare a long variable named module to store the ring modulus

public:
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
            b = z % b; // Update b with the remainder of z modulo the module
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
    std::string s; // Declare a string variable to store a line of input

    // Read a line of input and print the ASCII value of its first character incremented by 1
    std::getline(std::cin, s);
    std::cout << static_cast<char>(s[0] + 1); // Output the incremented character

    return 0; // Return 0 to indicate successful completion
}

// <END-OF-CODE>
