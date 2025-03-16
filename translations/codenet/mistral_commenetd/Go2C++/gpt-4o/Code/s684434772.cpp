// Include necessary headers
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

// Function to calculate the power of a base raised to an exponent
long long Pow(long long base, unsigned int exponent) {
    long long answer = 1;
    for (unsigned int i = 0; i < exponent; i++) {
        answer *= base;
    }
    return answer;
}

// Function to calculate combinations
long long combi(int n, int k) {
    long long min = (static_cast<long long>(k - 1) * k) / 2;
    long long max = (static_cast<long long>(2 * n - k + 1) * k) / 2;
    return max - min + 1;
}

// Main function
int main() {
    // Read n and k from standard input
    int n, k;
    cin >> n >> k;

    // Initialize total to store the sum of combinations
    long long total = 0;

    // Calculate the sum of combinations of n taken i at a time, where i ranges from k to n + 1
    for (int i = k; i <= n + 1; i++) {
        long long comb = combi(n, i);
        total += comb;
        total = total % (Pow(10, 9) + 7);
    }

    // Print the result to standard output
    cout << total << endl;

    return 0;
}

// <END-OF-CODE>
