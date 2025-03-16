#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

using namespace std;

// Function to calculate combinations
long long combi(int n, int k) {
    long long min = (static_cast<long long>(k - 1) * k) / 2; // Calculate the minimum value of the binomial coefficient.
    long long max = (static_cast<long long>(2 * n - k + 1) * k) / 2; // Calculate the maximum value of the binomial coefficient.
    return max - min + 1; // Return the number of combinations.
}

// Function to calculate power of a number
long long Pow64(long long base, unsigned int exponent) {
    long long answer = 1;
    for (unsigned int i = 0; i < exponent; i++) {
        answer *= base;
    }
    return answer;
}

int main() {
    int n, k;
    cin >> n >> k; // Read the first integer, n, and the second integer, k.

    const long long MOD = Pow64(10, 9) + 7; // Define the modulo constant.
    long long total = 0; // Initialize the total sum of combinations.

    for (int i = k; i <= n + 1; i++) {
        total += combi(n, i); // Calculate the combination and add it to the total.
        total %= MOD; // Apply modulo operation to prevent overflow.
    }

    cout << total << endl; // Print the final result.
    return 0;
}

// <END-OF-CODE>
