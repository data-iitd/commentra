

#include <iostream>
#include <string>

using namespace std;

int main() {
    // Create a BufferedReader to read input from the console
    string s;
    getline(cin, s);

    // Increment the first character of the input by 1 and print it
    cout << char(s[0] + 1);

    return 0;
}

class RemRing {
private:
    long module;

public:
    // Constructor to initialize the module value
    RemRing(long module) {
        this->module = module;
    }

    // Method to calculate the sum modulo module
    long sum(long a, long b) {
        return (a + b + module) % module;
    }

    // Method to calculate the difference modulo module
    long sub(long a, long b) {
        return (a - b + module) % module;
    }

    // Method to calculate the product modulo module
    long prod(long a, long b) {
        return (a * b) % module;
    }

    // Method to calculate the division modulo module
    long div(long a, long b) {
        return (a * inv(b)) % module;
    }

    // Method to calculate the modular inverse
    long inv(long a) {
        long b = this->module;
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

        u %= this->module;
        if (u < 0) u += this->module;
        return u;
    }
};

End with comment "