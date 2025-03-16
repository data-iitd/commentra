#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

// Main function is the entry point of our program
int main() {
    // Declare and initialize variables
    int N, M;
    int ans = 0;

    // Read N and M from the standard input
    std::cin >> N >> M;

    // Check if N and M are equal to 1
    if (N == 1 && M == 1) {
        // If so, increment the ans variable
        ans += 1;
    } else if (N > 1 && M > 1) {
        // If N and M are greater than 1, calculate the area of the rectangle
        ans += (N - 2) * (M - 2);
    } else {
        // If N or M is equal to 1, calculate the number of points on the edge
        ans += (N * M) - 2;
    }

    // Print the value of ans to the standard output
    std::cout << ans << std::endl;

    return 0;
}

// Helper functions
int max(int x, int y) {
    // Find the maximum value
    return std::max(x, y);
}

int min(int x, int y) {
    // Find the minimum value
    return std::min(x, y);
}

int pow(int x, int y) {
    // Calculate x raised to the power of y
    return static_cast<int>(std::pow(x, y));
}

int abs(int x) {
    // Calculate the absolute value of x
    return std::abs(x);
}

int floor(double x) {
    // Round x down to the nearest integer
    return static_cast<int>(std::floor(x));
}

// Helper type and function for sorting a vector of integers based on their absolute values
struct SortBy {
    std::vector<int> data;

    bool operator<(const SortBy& other) const {
        return abs(data[0]) < abs(other.data[0]);
    }
};

// Note: The sorting functionality is not used in the main logic of the program.
