#include <iostream>
#include <string>

class RemRing {
public:
    long long module;

    // Constructor to initialize the module value
    RemRing(long long module) {
        this->module = module;
    }

    // Method to calculate the sum modulo module
    long long sum(long long a, long long b) {
        return (a + b + module) % module;
    }

    // Method to calculate the difference modulo module
    long long sub(long long a, long long b) {
        return (a - b + module) % module;
    }

    // Method to calculate the product modulo module
    long long prod(long long a, long long b) {
        return (a * b) % module;
    }

    // Method to calculate the division modulo module
    long long div(long long a, long long b) {
        return (a * inv(b)) % module;
    }

    // Method to calculate the modular inverse
    long long inv(long long a) {
        long long b = this->module;
        long long u = 1;
        long long v = 0;

        // Extended Euclidean Algorithm to find the modular inverse
        while (b > 0) {
            long long t = a / b;
            a -= t * b;
            u -= t * v;
            long long z = a;
            a = b;
            b = z;
            z = u;
            u = v;
            v = z;
        }

        u %= this->module;
        if (u < 0) u += this->module;
        return u;
    }
};

int main() {
    std::string s;
    std::getline(std::cin, s);

    // Increment the first character of the input by 1 and print it
    std::cout << char(s[0] + 1);

    return 0;
}
