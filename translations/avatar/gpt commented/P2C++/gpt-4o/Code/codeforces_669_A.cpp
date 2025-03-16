#include <iostream>

int main() {
    // Read an integer input from the user
    int n;
    std::cin >> n;

    // Calculate the result using the formula (n * 2 + 1) / 3
    // This formula effectively computes (2n + 1) divided by 3 and returns the integer part
    int result = (n * 2 + 1) / 3;

    // Print the calculated result
    std::cout << result << std::endl;

    return 0;
}

// <END-OF-CODE>
