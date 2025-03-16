#include <iostream>
#include <cmath>
#include <algorithm>

// Abs function returns the absolute value of an integer x.
int Abs(int x) {
    return (x < 0) ? -x : x; // If x is negative, return its negation; otherwise, return x.
}

// min function returns the smaller of two integers a and b.
int min(int a, int b) {
    return (a > b) ? b : a; // If a is greater than b, return b; otherwise, return a.
}

int main() {
    int N, K;
    // Read two integers N and K from standard input.
    std::cin >> N >> K;

    // The following block is commented out; it appears to be an alternative approach
    // to find a minimum value based on some conditions involving N and K.
    /*
    std::unordered_map<int, bool> hm; // Create a map to track seen values of N.
    while (true) {
        if (!hm[N]) { // If N has not been seen before,
            hm[N] = true; // mark it as seen.
            N = Abs(N - K); // Update N to the absolute difference of N and K.
        } else {
            break; // If N has been seen, exit the loop.
        }
    }
    int mini = 999999999; // Initialize mini to a large value.
    for (const auto& k : hm) { // Iterate over the keys in the map.
        mini = min(mini, k.first); // Update mini to the minimum value found.
    }
    std::cout << mini << std::endl; // Print the minimum value found.
    */

    int x;
    // Calculate the remainder of N divided by K.
    x = N % K;
    // Determine the minimum between the absolute difference of (x - K) and x.
    x = min(Abs(x - K), x);
    // Print the final result.
    std::cout << x << std::endl;

    return 0;
}
