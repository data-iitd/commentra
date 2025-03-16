#include <stdio.h>
#include <math.h>

int main() {
    // Record the start time for performance measurement
    long startTime = clock();

    // Read the number of elements
    int n;
    scanf("%d", &n);

    // Define a modulus value to prevent overflow
    long div = (long)pow(10, 9) + 7;

    // Initialize an array to hold the input values
    long A[n];

    // Variable to store the final answer
    long ans = 0;

    // Read n long integers into the array A
    for (int i = 0; i < n; i++) {
        scanf("%ld", &A[i]);
    }

    // Iterate through each bit position from 0 to 59
    for (int i = 0; i < 60; i++) {
        long a = 0; // Variable to accumulate contributions for the current bit
        long count1 = 0; // Count of numbers with the i-th bit set

        // Count how many numbers have the i-th bit set
        for (int j = 0; j < n; j++) {
            if ((A[j] >> i) & 1) {
                count1++;
            }
        }

        // Calculate the contribution of the current bit to the answer
        a = count1 * (n - count1);

        // Shift the contribution left by i positions (equivalent to multiplying by 2^i)
        for (int j = 0; j < i; j++) {
            a = (a << 1) % div;
        }

        // Add the contribution to the final answer and apply modulus
        ans = (ans + a) % div;
    }

    // Output the final answer
    printf("%ld\n", ans);

    // Record the end time for performance measurement
    long endTime = clock();

    return 0;
}

// <END-OF-CODE>
