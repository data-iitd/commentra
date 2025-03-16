
#include <stdio.h>
#include <stdlib.h>

int sum(int k) {
    // Initialize the return value and other variables
    int ret = 0;
    int pw = 10;
    int len = 1;
    // Loop to calculate the sum of digits from 1 to k
    while (1) {
        // Calculate the current range of numbers
        int cur = (pw - 1) < k? (pw - 1) : k;
        int prev = pw / 10;
        // Add the count of numbers in the current range to the result
        ret += (cur - prev + 1) * len;
        // Break the loop if the current range exceeds k
        if (pw - 1 >= k) {
            break;
        }
        // Update the length and power of ten for the next range
        len += 1;
        pw *= 10;
    }
    return ret;
}

int main() {
    // Read input values for w, m, and k
    int w, m, k;
    scanf("%d %d %d", &w, &m, &k);
    // Initialize the binary search range
    int lo = 0;
    int hi = 1000000000000000000;
    // Perform binary search to find the maximum md
    while (hi - lo > 1) {
        int md = (lo + hi) / 2;
        // Calculate the count of numbers in the range [m, m+md-1]
        int c = sum(m + md - 1) - sum(m - 1);
        // Adjust the search range based on the condition
        if (c * k <= w) {
            lo = md;
        } else {
            hi = md;
        }
    }
    // Print the result of the binary search
    printf("%d\n", lo);
    return 0;
}

