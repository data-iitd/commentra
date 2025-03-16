
#include <stdio.h> // Include the standard input/output library

int main() {
    int N, L, R, QL, QR; // Declare variables for the input values
    scanf("%d %d %d %d %d", &N, &L, &R, &QL, &QR); // Read the input values

    int W[N]; // Array to store the weights of items
    int sum[N + 1]; // Array to store cumulative sums of weights

    // Read the weights and calculate cumulative sums
    for (int n = 0; n < N; n++) {
        scanf("%d", &W[n]);
        sum[n + 1] = sum[n] + W[n];
    }

    long min = LLONG_MAX; // Initialize the minimum cost to a very large value

    // Iterate over possible positions for the rightmost item
    for (int firstR = 0; firstR <= N; firstR++) {
        int lCount = firstR; // Number of items on the left
        int rCount = N - lCount; // Number of items on the right

        // Calculate the cost for the current position of the rightmost item
        long cand = (long)sum[lCount] * L + (long)(sum[N] - sum[lCount]) * R;

        // Calculate the additional costs for unbalanced counts
        int llCount = lCount > rCount + 1? lCount - rCount - 1 : 0;
        int rrCount = rCount > lCount + 1? rCount - lCount - 1 : 0;
        cand += (long)llCount * QL;
        cand += (long)rrCount * QR;

        // Update the minimum cost found so far
        if (cand < min) {
            min = cand;
        }
    }

    // Print the minimum cost
    printf("%ld\n", min);

    return 0; // Return 0 to indicate successful execution
}

