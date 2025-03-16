#include <stdio.h>
#include <limits.h>

// Function to calculate the sum of digits in a number
int sum(int k) {
    // Initialize the sum to zero
    int ret = 0;
    // Base value for power of ten
    int pw = 10;
    // Initialize the length of the number to 1
    int len = 1;

    // Continue the loop until the power of ten is less than or equal to the number
    while (1) {
        // Calculate the current digit
        int cur = k < pw ? k : pw - 1;
        // Calculate the previous power of ten
        int prev = pw / 10;
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
    int w, m, k;
    scanf("%d %d %d", &w, &m, &k);

    // Initialize the lower bound to 0
    long long lo = 0;
    // Initialize the upper bound to a very large number
    long long hi = LLONG_MAX;

    // Binary search to find the middle value
    while (hi - lo > 1) {
        // Calculate the middle value
        long long md = (lo + hi) / 2;
        // Calculate the sum of digits in the range [m, m+md] and subtract the sum of digits in the range [m-1, m]
        int c = sum(m + md - 1) - sum(m - 1);
        // If the product of the count and k is less than or equal to w, update the lower bound
        if (c * k <= w) {
            lo = md;
        } else {
            // Otherwise, update the upper bound
            hi = md;
        }
    }

    // Print the result
    printf("%lld\n", lo);

    return 0;
}
