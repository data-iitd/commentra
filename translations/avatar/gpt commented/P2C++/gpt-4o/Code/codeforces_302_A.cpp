#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
    // Read two integers n and m from input
    int n, m;
    std::cin >> n >> m;

    // Read the input string and count the number of '-' characters
    std::string input;
    std::cin >> input;
    int sa = std::count(input.begin(), input.end(), '-');

    // Calculate the minimum of the remaining characters (n - sa) and the count of '-' (sa)
    sa = std::min(n - sa, sa);

    // Initialize a vector to store results
    std::vector<std::string> ss;

    // Loop m times to read pairs of integers a and b
    for (int i = 0; i < m; ++i) {
        // Read two integers a and b from input
        int a, b;
        std::cin >> a >> b;

        // Calculate the difference b - a
        b -= a;

        // Check if b is odd and less than or equal to double the count of '-'
        // Append "1\n" to the results if true, otherwise append "0\n"
        if (b % 2 == 1 && b <= sa * 2) {
            ss.push_back("1\n");
        } else {
            ss.push_back("0\n");
        }
    }

    // Print the concatenated results from the vector
    for (const auto& result : ss) {
        std::cout << result;
    }

    return 0;
}

// <END-OF-CODE>
