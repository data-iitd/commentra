#include <stdio.h>
#include <limits.h>

#define INF INT_MAX

void solve() {
    // Read the number of points N and the target value X
    int N;
    long long X;
    scanf("%d %lld", &N, &X);

    // Initialize an array to store the positions of N points
    long long x[N];
    long long xsum[N + 1];

    // Read the positions of the points into the array x and calculate the cumulative sum
    xsum[0] = 0;
    for (int i = 0; i < N; i++) {
        scanf("%lld", &x[i]);
        xsum[i + 1] = xsum[i] + x[i];
    }

    // Initialize ans with a value calculated using the total sum of positions and the given X value
    long long ans = X * N + 5 * xsum[N];

    // Iterate over possible values of i, which represents the number of points to be removed
    for (int i = 1; i < N; i++) {
        long long cost = X * i + 5 * (xsum[N] - xsum[N - i]);

        // For each value of i, calculate the cost of removing i points and update ans if a better cost is found
        for (int j = 5, k = N - i; k >= 0; j += 2, k -= i) {
            if (cost > ans) {
                break;
            }
            cost += j * (xsum[k] - xsum[k - i > 0 ? k - i : 0]);
        }
        ans = ans < cost ? ans : cost;
    }

    // Print the minimum cost found
    printf("%lld\n", ans + N * X);
}

int main() {
    solve();
    return 0;
}
