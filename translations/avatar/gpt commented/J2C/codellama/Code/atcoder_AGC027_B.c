#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define INF 2147483647

int main() {
    // Initialize a Scanner to read input from the console
    int N, i, j, k;
    long X, cost, ans;
    long *x, *xsum;

    scanf("%d", &N);
    scanf("%ld", &X);

    // Read the elements into the array and compute the prefix sums
    x = (long *)malloc(N * sizeof(long));
    xsum = (long *)malloc((N + 1) * sizeof(long));
    for (i = 0; i < N; i++) {
        scanf("%ld", &x[i]);
        xsum[i + 1] = xsum[i] + x[i];
    }

    // Initialize the answer with the cost of processing all elements with the base cost
    ans = X * N + 5 * xsum[N];

    // Iterate through possible splits of the array
    for (i = 1; i < N; i++) {
        // Calculate the cost for the current split
        cost = X * i + 5 * (xsum[N] - xsum[N - i]);

        // Incrementally add costs based on the current split
        for (j = 5, k = N - i; k >= 0; j += 2, k -= i) {
            // If the current cost exceeds the best answer found, break out of the loop
            if (cost > ans) {
                break;
            }
            // Update the cost based on the prefix sums
            cost += j * (xsum[k] - xsum[max(k - i, 0)]);
        }
        // Update the answer with the minimum cost found
        ans = min(ans, cost);
    }

    // Output the final answer, which includes the base cost
    printf("%ld\n", ans + N * X);

    // Free the memory allocated for the arrays
    free(x);
    free(xsum);

    return 0;
}

