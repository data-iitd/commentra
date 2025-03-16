#include <iostream>
#include <string>
#include <vector>
#include <sstream>

std::string TenToN(int number, int n) {
    std::string s;
    int tmp = number; // Initialize temporary variable

    // Repeat the following process until the number becomes less than N
    while (true) {
        // Append the remainder of the division by N to the result string
        s = std::to_string(tmp % n) + s;

        // If the number is less than N, break the loop
        if (tmp < n) {
            break;
        }

        // Divide the number by N
        tmp /= n;
    }

    // Return the result string
    return s;
}

int main() {
    int N, K;
    std::cin >> N >> K;

    // Calculate the base-10 representation of N up to digit count K
    std::string s = TenToN(N, K);

    // Print the length of the calculated string
    std::cout << s.length() << std::endl;

    return 0;
}
