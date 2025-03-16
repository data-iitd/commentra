#include <iostream>
using namespace std;

// Function to calculate the sum of digits in a number
long long sum(long long k) {
    // Initialize the sum to zero
    long long ret = 0;
    // Base value for power of ten
    long long pw = 10;
    // Initialize the length of the number to 1
    int len = 1;

    // Continue the loop until the power of ten is less than or equal to the number
    while (true) {
        // Calculate the current digit
        long long cur = min(pw - 1, k);
        // Calculate the previous power of ten
        long long prev = pw / 10;
        // Add the number of digits in the current power of ten to the sum
        ret += (cur - prev + 1) * len;
        // If the power of ten is greater than the number, break the loop
        if (pw - 1 >= k) {
            break;
        }
        // Increment the length of the number
        len++;
        // Multiply the power of ten by 10
        pw *= 10;
    }

    // Return the sum of digits in the number
    return ret;
}

int main() {
    // Take input of w, m, and k
    long long w, m, k;
    cin >> w >> m >> k;

    // Initialize the lower bound to 0
    long long lo = 0;
    // Initialize the upper bound to a very large number
    long long hi = 1e18;

    // Binary search to find the middle value
    while (hi - lo > 1) {
        // Calculate the middle value
        long long md = (lo + hi) / 2;
        // Calculate the sum of digits in the range [m, m+md] and subtract the sum of digits in the range [m-1, m]
        long long c = sum(m + md - 1) - sum(m - 1);
        // If the product of the count and k is less than or equal to w, update the lower bound
        if (c * k <= w) {
            lo = md;
        }
        // Otherwise, update the upper bound
        else {
            hi = md;
        }
    }

    // Print the result
    cout << lo << endl;

    return 0;
}

// <END-OF-CODE>
