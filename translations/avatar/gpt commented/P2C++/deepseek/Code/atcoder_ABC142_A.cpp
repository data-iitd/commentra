#include <iostream>
#include <vector>
#include <cmath>  // Include cmath for mathematical functions and constants

// Function to read a single integer from input
int next_int() {
    int x;
    std::cin >> x;
    return x;
}

// Function to read a list of integers from input
std::vector<int> next_ints() {
    std::vector<int> numbers;
    int num;
    while (std::cin >> num) {
        numbers.push_back(num);
    }
    return numbers;
}

int main() {
    // Read the number of iterations or elements
    int n = next_int();

    // Initialize a counter for odd indices
    int t = 0;

    // Loop through the range of n
    for (int i = 0; i < n; ++i) {
        // Check if the current index (i + 1) is odd
        if ((i + 1) % 2 != 0) {
            ++t;  // Increment the counter for odd indices
        }
    }

    // Calculate and print the ratio of odd indices to total elements
    std::cout << static_cast<double>(t) / n << std::endl;

    return 0;
}
