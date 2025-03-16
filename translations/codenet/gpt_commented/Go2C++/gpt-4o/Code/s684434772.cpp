#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

// Function to calculate combinations
int64_t combi(int n, int k) {
    int64_t min = (int64_t)(k - 1) * k / 2;
    int64_t max = (int64_t)(2 * n - k + 1) * k / 2;
    return max - min + 1;
}

// Function to calculate power of a base raised to an exponent
int64_t Pow64(int64_t base, unsigned int exponent) {
    int64_t answer = 1;
    for (unsigned int i = 0; i < exponent; i++) {
        answer *= base;
    }
    return answer;
}

int main() {
    // Read two integers n and k from input
    int n, k;
    cin >> n >> k;

    // Initialize a variable to hold the total count
    int64_t total = 0;

    // Calculate the total combinations from k to n+1
    for (int i = k; i <= n + 1; i++) {
        total += combi(n, i); // Add combinations for the current i
        total = total % (Pow64(10, 9) + 7); // Apply modulo to prevent overflow
    }

    // Print the final total
    cout << total << endl;

    return 0;
}

// <END-OF-CODE>
