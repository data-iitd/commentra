#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
    long INF = LONG_MAX;

    // Read the number of points N and the target value X
    int N;
    long X;
    scanf("%d %ld", &N, &X);

    // Initialize an array to store the positions of N points
    long *x = (long *)malloc(N * sizeof(long));
    long *xsum = (long *)malloc((N + 1) * sizeof(long));

    // Read the positions of the points into the array x and calculate the cumulative sum
    xsum[0] = 0;
    for (int i = 0; i < N; i++) {
        scanf("%ld", &x[i]);
        xsum[i + 1] = xsum[i] + x[i];
    }

    // Initialize ans with a value calculated using the total sum of positions and the given X value
    long ans = X * N + 5 * xsum[N];

    // Iterate over possible values of i, which represents the number of points to be removed
    for (int i = 1; i < N; i++) {
        long cost = X * i + 5 * (xsum[N] - xsum[N - i]);

        // For each value of i, calculate the cost of removing i points and update ans if a better cost is found
        for (int j = 5, k = N - i; k >= 0; j += 2, k -= i) {
            if (cost > ans) {
                break;
            }
            cost += j * (xsum[k] - xsum[k > i ? k - i : 0]);
        }
        if (cost < ans) {
            ans = cost;
        }
    }

    // Print the minimum cost found
    printf("%ld\n", ans + N * X);

    // Free allocated memory
    free(x);
    free(xsum);

    return 0;
}

// <END-OF-CODE>
