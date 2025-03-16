#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <stdexcept>
#include <algorithm>

// Function to convert an integer from base 10 to base N
std::string TenToN(int number, int n) {
    std::string s; // String to hold the result
    int tmp = number; // Temporary variable to hold the current number
    do {
        s = std::to_string(tmp % n) + s; // Prepend the remainder of the division to the result string
        tmp /= n; // Divide the temporary number by the base
    } while (tmp > 0); // Continue until tmp is 0
    return s; // Return the converted string
}

// Function to read an integer from input
int readInt() {
    int read;
    std::cin >> read; // Read the next input
    return read; // Return the read integer
}

int main() {
    // Read two integers N and K from input
    int N = readInt();
    int K = readInt();
    
    // Convert the number N from base 10 to base K
    std::string s = TenToN(N, K);
    
    // Print the length of the resulting string
    std::cout << s.length() << std::endl;

    return 0; // Return success
}

// <END-OF-CODE>
