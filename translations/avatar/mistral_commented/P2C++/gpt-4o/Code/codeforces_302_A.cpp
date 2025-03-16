#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
    // Define the number of strings n and the number of operations m
    int n, m;
    std::cin >> n >> m;

    // Calculate the number of '-' symbols in the input string
    std::string input;
    std::cin >> input;
    int sa = std::count(input.begin(), input.end(), '-');

    // Ensure the number of '-' symbols is valid
    sa = std::min(n - sa, sa);

    // Initialize a vector to store the results of each operation
    std::vector<std::string> ss;

    // Perform each operation as described in the problem statement
    for (int i = 0; i < m; ++i) {
        // Read two integers a and b from the input
        int a, b;
        std::cin >> a >> b;

        // Calculate the difference between b and a
        b -= a;

        // Check if the difference is valid based on the number of '-' symbols
        if (b % 2 == 0 || b > sa * 2) {
            // If the difference is valid, add '1' to the result list 'ss'
            ss.push_back("1\n");
        } else {
            // If the difference is not valid, add '0' to the result list 'ss'
            ss.push_back("0\n");
        }
    }

    // Print the final result by joining all the strings in the 'ss' vector
    for (const auto& result : ss) {
        std::cout << result;
    }

    return 0;
}

// <END-OF-CODE>
