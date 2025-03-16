#include <stdio.h> // Including standard input-output library
#include <limits.h> // Including limits.h for LONG_MAX

int main() {
    int N, L, R, QL, QR; // Variables for number of items and cost coefficients
    scanf("%d %d %d %d %d", &N, &L, &R, &QL, &QR); // Reading input values

    int W[N]; // Array to store the weights of items
    long long sum[N + 1]; // Array to store cumulative sums of weights
    sum[0] = 0; // Initializing the first element of cumulative sum

    // Reading the weights and calculating cumulative sums
    for (int n = 0; n < N; n++) {
        scanf("%d", &W[n]);
        sum[n + 1] = sum[n] + W[n];
    }

    // Initializing the minimum cost to a very large value
    long long min = LONG_MAX;

    // Iterating over possible positions for the rightmost item
    for (int firstR = 0; firstR <= N; firstR++) {
        int lCount = firstR; // Number of items on the left
        int rCount = N - lCount; // Number of items on the right

        // Calculating the cost for the current position of the rightmost item
        long long cand = sum[lCount] * L + (sum[N] - sum[lCount]) * R;

        // Calculating the additional costs for unbalanced counts
        int llCount = (lCount > rCount + 1) ? lCount - rCount - 1 : 0;
        int rrCount = (rCount > lCount + 1) ? rCount - lCount - 1 : 0;
        cand += llCount * QL;
        cand += rrCount * QR;

        // Updating the minimum cost found so far
        if (cand < min) {
            min = cand;
        }
    }

    // Printing the minimum cost
    printf("%lld\n", min);
    return 0; // Returning 0 to indicate successful execution
}

// <END-OF-CODE>
