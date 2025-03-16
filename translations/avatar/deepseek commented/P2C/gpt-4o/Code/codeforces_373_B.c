#include <stdio.h>

long long sum(long long k) {
    // Initialize the return value and other variables
    long long ret = 0;
    long long pw = 10;
    int len = 1;
    
    // Loop to calculate the sum of digits from 1 to k
    while (1) {
        // Calculate the current range of numbers
        long long cur = (pw - 1 < k) ? pw - 1 : k;
        long long prev = pw / 10;
        
        // Add the count of numbers in the current range to the result
        ret += (cur - prev + 1) * len;
        
        // Break the loop if the current range exceeds k
        if (pw - 1 >= k) {
            break;
        }
        
        // Update the length and power of ten for the next range
        len++;
        pw *= 10;
    }
    
    return ret;
}

int main() {
    // Read input values for w, m, and k
    long long w, m, k;
    scanf("%lld %lld %lld", &w, &m, &k);

    // Initialize the binary search range
    long long lo = 0;
    long long hi = 1000000000000000000LL; // 1e18

    // Perform binary search to find the maximum md
    while (hi - lo > 1) {
        long long md = (lo + hi) / 2;
        // Calculate the count of numbers in the range [m, m+md-1]
        long long c = sum(m + md - 1) - sum(m - 1);
        
        // Adjust the search range based on the condition
        if (c * k <= w) {
            lo = md;
        } else {
            hi = md;
        }
    }

    // Print the result of the binary search
    printf("%lld\n", lo);

    return 0;
}

// <END-OF-CODE>
