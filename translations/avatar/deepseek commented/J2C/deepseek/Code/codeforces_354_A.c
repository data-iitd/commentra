#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int main() {
    int N, L, R, QL, QR;
    scanf("%d %d %d %d %d", &N, &L, &R, &QL, &QR);
    int W[N];
    int sum[N + 1];

    // Reading the weights and calculating cumulative sums
    sum[0] = 0;
    for (int n = 0; n < N; n++) {
        scanf("%d", &W[n]);
        sum[n + 1] = sum[n] + W[n];
    }

    // Initializing the minimum cost to a very large value
    long long min = LLONG_MAX;

    // Iterating over possible positions for the rightmost item
    for (int firstR = 0; firstR <= N; firstR++) {
        int lCount = firstR; // Number of items on the left
        int rCount = N - lCount; // Number of items on the right

        // Calculating the cost for the current position of the rightmost item
        long long cand = sum[lCount] * L + (sum[N] - sum[lCount]) * R;

        // Calculating the additional costs for unbalanced counts
        int llCount = (lCount > rCount) ? lCount - rCount - 1 : 0;
        int rrCount = (rCount > lCount) ? rCount - lCount - 1 : 0;
        cand += llCount * QL;
        cand += rrCount * QR;

        // Updating the minimum cost found so far
        if (cand < min) {
            min = cand;
        }
    }

    // Printing the minimum cost
    printf("%lld\n", min);

    return 0;
}
