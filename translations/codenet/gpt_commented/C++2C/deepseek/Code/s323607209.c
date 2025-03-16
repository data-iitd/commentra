#include <stdio.h>

int main() {
    // Declare variables for the number of elements (n) and the divisor (k)
    int n, k;
    // Initialize counters for specific conditions
    long long int l = 0, r = 0;

    // Read input values for n and k
    scanf("%d%d", &n, &k);

    // Check if k is even
    if (k % 2 == 0) {
        // Loop through numbers from 1 to n
        for (int i = 1; i <= n; i++) {
            // Count how many numbers are exactly half of k (mod k)
            if (i % k == k / 2) l++;
            // Count how many numbers are multiples of k
            else if (i % k == 0) r++;
        }
        // Calculate and print the result based on the counts
        // The result is the cube of l plus the cube of r
        printf("%lld\n", l * l * l + r * r * r);
    } else {
        // If k is odd, only count multiples of k
        for (int i = 1; i <= n; i++) {
            // Count how many numbers are multiples of k
            if (i % k == 0) r++;
        }
        // Print the result as the cube of r
        printf("%lld\n", r * r * r);
    }
}
