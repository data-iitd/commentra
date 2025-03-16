#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <cmath>

class FastScanner {
public:
    FastScanner() : buffer("") {}

    // Read the next integer from the input
    int NextInt() {
        int value;
        std::cin >> value;
        return value;
    }

    // Read the next line from the input
    std::string NextLine() {
        std::string line;
        std::getline(std::cin, line);
        return line;
    }

private:
    std::string buffer; // Buffer to hold the input data
};

int main() {
    FastScanner fsc;
    // Read three integers A, B, and C from input
    int A = fsc.NextInt();
    int B = fsc.NextInt();
    int C = fsc.NextInt();

    // Check if the difference between B and A is equal to the difference between C and B
    if (B - A == C - B) {
        // If the differences are equal, print "YES"
        std::cout << "YES" << std::endl;
    } else {
        // Otherwise, print "NO"
        std::cout << "NO" << std::endl;
    }

    return 0;
}

// Additional utility functions can be added here if needed

// <END-OF-CODE>
