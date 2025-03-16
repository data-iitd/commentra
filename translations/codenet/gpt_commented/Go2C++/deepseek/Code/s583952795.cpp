#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

// Function to convert a number from base 10 to base N
std::string TenToN(int number, int n) {
    std::string s = ""; // String to hold the result
    int tmp = number; // Temporary variable to hold the current number
    while (true) {
        // Prepend the remainder of the division to the result string
        s = std::to_string(tmp % n) + s;
        if (tmp < n) { // If the temporary number is less than the base, exit the loop
            break;
        }
        tmp /= n; // Divide the temporary number by the base
    }
    return s; // Return the converted string
}

int main() {
    int N, K;
    std::cin >> N >> K;
    // Convert the number N from base 10 to base K
    std::string s = TenToN(N, K);
    // Print the length of the resulting string
    std::cout << s.length() << std::endl;
    return 0;
}
