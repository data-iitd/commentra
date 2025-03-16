#include <iostream>
#include <cmath>

int main() {
    int N;
    std::cin >> N; // Read the integer N from standard input
    int count = 0; // Initialize a counter to count the number of digits in N
    int temp = N; // Initialize a temporary variable to hold the value of N
    int ans = 0; // Initialize a variable to accumulate the result

    // Calculate the number of digits in N
    while (temp > 0) {
        temp /= 10;
        count++;
    }

    // Iterate from 1 to the number of digits in N
    for (int i = 1; i <= count; i++) {
        if (i == count) { // Check if it's the last digit
            if (i % 2 == 1) { // Check if the position is odd
                ans += (N - std::pow(10, i - 1) + 1); // Add the count of numbers with odd positions
            }
        } else {
            if (i == 1) { // Check if it's the first digit
                ans += 9; // Add the count of single-digit numbers
            } else if (i % 2 == 1) { // Check if the position is odd
                ans += (std::pow(10, i) - std::pow(10, i - 1)); // Add the count of numbers in odd positions
            }
        }
    }

    std::cout << ans << std::endl; // Print the result
    return 0;
}

