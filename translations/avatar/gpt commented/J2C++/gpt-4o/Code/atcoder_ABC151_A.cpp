#include <iostream>
#include <string>

class RemRing {
    long module; // Variable to store the modulus value

public:
    // Constructor to initialize the modulus
    RemRing(long module) : module(module) {}

    // Method to perform modular addition
    long sum(long a, long b) {
        return (a + b + module) % module;
    }

    // Method to perform modular subtraction
    long sub(long a, long b) {
        return (a - b + module) % module;
    }

    // Method to perform modular multiplication
    long prod(long a, long b) {
        return (a * b) % module;
    }

    // Method to perform modular division
    long div(long a, long b) {
        return (a * inv(b)) % module;
    }

    // Method to compute the modular inverse using the Extended Euclidean Algorithm
    long inv(long a) {
        long b = this->module;
        long u = 1;
        long v = 0;

        // Extended Euclidean Algorithm to find the inverse
        while (b > 0) {
            long t = a / b;
            a -= t * b;
            u -= t * v;
            std::swap(a, b);
            std::swap(u, v);
        }

        // Ensure the result is positive
        u %= this->module;
        if (u < 0) u += this->module;

        // Return the modular inverse
        return u;
    }
};

int main() {
    // Declare a string to hold the input
    std::string s;

    // Read a line of input from the user
    std::getline(std::cin, s);

    // Output the next character in the ASCII sequence of the first character of the input
    std::cout << static_cast<char>(s[0] + 1);

    return 0;
}

// <END-OF-CODE>
