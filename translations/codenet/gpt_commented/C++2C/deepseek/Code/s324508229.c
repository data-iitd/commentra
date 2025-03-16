#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// Define macros for convenience
#define PB(x,y) ((x) = (y))
#define MP(x,y) ((x), (y))
#define REP(i,n) for(int i=0;i<(n);i++)

int main() {
    int n, ii, a, b; // Declare variables for input and indices
    scanf("%d", &n); // Read the upper limit of the range

    // Initialize a 2D array to count occurrences of digit pairs
    long long cnt[10][10];
    for (int i = 0; i < 100; i++) cnt[i % 10][i / 10] = 0; // Set all counts to zero

    // Count occurrences of digit pairs (first digit, last digit) for numbers from 1 to n
    for (int i = 1; i <= n; i++) {
        b = i % 10; // Get the last digit of the number
        a = i; // Store the original number
        while (a >= 10) { // Extract the first digit
            a /= 10; // Divide by 10 until we get the first digit
        }
        cnt[a][b]++; // Increment the count for the pair (first digit, last digit)
    }

    long long ans = 0; // Initialize the answer variable to accumulate results

    // Calculate the total number of valid pairs by multiplying counts
    for (int i = 1; i <= 9; i++) { // Iterate over possible first digits
        for (int j = 1; j <= 9; j++) { // Iterate over possible last digits
            // Uncomment the following line for debugging to see counts
            // printf("%d %d %lld %lld\n", i, j, cnt[i][j], cnt[j][i]);
            ans += cnt[i][j] * cnt[j][i]; // Add the product of counts for pairs (i, j) and (j, i)
        }
    }

    printf("%lld\n", ans); // Output the final result
}
