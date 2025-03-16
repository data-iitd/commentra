#include <iostream>
#include <vector>
#include <string>
#include <sstream>

// Function to read an integer from standard input
int readInt() {
    int i;
    std::cin >> i;
    return i;
}

// Function to read a float64 from standard input
double readFloat64() {
    double f;
    std::cin >> f;
    return f;
}

// Function to read a string from standard input
std::string readString() {
    std::string s;
    std::cin >> s;
    return s;
}

int main() {
    // Set the input to read words instead of lines
    std::cin.sync_with_stdio(false);
    std::cin.tie(nullptr);

    // Read two integers n and m from the input
    int n = readInt();
    int m = readInt();

    // Initialize a vector to hold m integers
    std::vector<int> a(m);
    int sum = 0;

    // Read m integers into the vector a and calculate their sum
    for (int i = 0; i < m; i++) {
        std::cin >> a[i];
        sum += a[i];
    }

    // Check if the sum of integers exceeds n
    if (sum > n) {
        // Print -1 if the sum exceeds n and exit
        std::cout << "-1\n";
        return 0;
    }

    // Print the difference between n and the sum if it's within bounds
    std::cout << (n - sum) << '\n';

    return 0;
}
