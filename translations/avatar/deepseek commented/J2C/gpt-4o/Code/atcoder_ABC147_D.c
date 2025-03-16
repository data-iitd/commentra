#include <stdio.h>
#include <math.h>

#define MOD 1000000007

int main() {
    long startTime = clock(); // Start time for performance measurement
    int n;
    scanf("%d", &n); // Read the number of elements
    long A[n]; // Initialize array A to store n long integers
    long ans = 0; // Initialize the answer variable

    // Read n long integers from the user and store them in array A
    for (int i = 0; i < n; i++) {
        scanf("%ld", &A[i]);
    }

    // Iterate over each bit position from 0 to 59
    for (int i = 0; i < 60; i++) {
        long a = 0; // Initialize the contribution for the current bit position
        long count1 = 0; // Count of elements with the current bit set to 1

        // Count the number of elements with the current bit set to 1
        for (int j = 0; j < n; j++) {
            if ((A[j] >> i) & 1) count1++;
        }

        // Calculate the contribution of the current bit position
        a = count1 * (n - count1);

        // Shift the contribution left by 1 bit for each lower bit position and take modulo
        for (int j = 0; j < i; j++) {
            a = (a << 1) % MOD;
        }

        // Add the contribution to the answer and take modulo
        ans = (ans + a) % MOD;
    }

    // Print the result
    printf("%ld\n", ans);
    long endTime = clock(); // End time for performance measurement

    return 0;
}

// <END-OF-CODE>
