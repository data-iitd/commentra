#include <stdio.h>
#include <math.h>

int main() {
    // Record the start time for performance measurement
    long startTime = clock();

    // Create a Scanner object for input
    int n;
    scanf("%d", &n);

    // Define a modulus value to prevent overflow
    long long div = (long long) pow(10, 9) + 7;

    // Initialize an array to hold the input values
    long long A[n];

    // Variable to store the final answer
    long long ans = 0;

    // Read n long integers into the array A
    for (int i = 0; i < n; i++) {
        scanf("%lld", &A[i]);
    }

    // Iterate through each bit position from 0 to 59
    for (int i = 0; i < 60; i++) {
        long long a = 0; // Variable to accumulate contributions for the current bit
        long long count1 = 0; // Count of numbers with the i-th bit set

        // Count how many numbers have the i-th bit set
        for (int j = 0; j < n; j++) {
            if (A[j] & (1LL << i))
                count1++;
        }

        // Calculate the contribution of the current bit to the answer
        a = a + count1 * (n - count1);

        // Shift the contribution left by i positions (equivalent to multiplying by 2^i)
        for (int j = 0; j < i; j++) {
            a = (a << 1) % div;
        }

        // Add the contribution to the final answer and apply modulus
        ans += a;
        ans %= div;
    }

    // Output the final answer
    printf("%lld\n", ans);

    // Record the end time for performance measurement
    long endTime = clock();

    // Print the elapsed time
    printf("Elapsed time: %f seconds\n", (double)(endTime - startTime) / CLOCKS_PER_SEC);

    return 0;
}
