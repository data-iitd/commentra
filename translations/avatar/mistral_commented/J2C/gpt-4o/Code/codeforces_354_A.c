#include <stdio.h>
#include <limits.h>

int main() {
    int N, L, R, QL, QR; // Declare variables for input
    scanf("%d %d %d %d %d", &N, &L, &R, &QL, &QR); // Read inputs

    int W[N]; // Declare array W of size N
    long sum[N + 1]; // Declare array sum of size N + 1
    sum[0] = 0; // Initialize the first element of sum

    for (int n = 0; n < N; n++) { // Iterate through each element in W
        scanf("%d", &W[n]); // Read each element into W
        sum[n + 1] = sum[n] + W[n]; // Calculate cumulative sum
    }

    long min = LONG_MAX; // Initialize min to maximum long value

    for (int firstR = 0; firstR <= N; firstR++) { // Iterate through possible starting indices for the right segment
        int lCount = firstR; // Length of the left segment
        int rCount = N - lCount; // Length of the right segment

        long cand = sum[lCount] * L + (sum[N] - sum[lCount]) * R; // Calculate candidate value

        int llCount = (lCount - rCount - 1 > 0) ? (lCount - rCount - 1) : 0; // Calculate left overlap
        int rrCount = (rCount - lCount - 1 > 0) ? (rCount - lCount - 1) : 0; // Calculate right overlap

        cand += llCount * QL; // Add left overlap contribution
        cand += rrCount * QR; // Add right overlap contribution

        if (cand < min) { // Update min if current candidate is smaller
            min = cand;
        }
    }

    printf("%ld\n", min); // Print the minimum value
    return 0; // Return success
}

// <END-OF-CODE>
