#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    long long Inf = 1LL << 62; // Use long long for large values
    int a[M], b[M];
    long long c[M];

    for (int i = 0; i < M; i++) {
        scanf("%d %d %lld", &a[i], &b[i], &c[i]);
        c[i] = -c[i]; // Negate the cost
    }

    long long dist[N];
    for (int i = 0; i < N; i++) {
        dist[i] = Inf; // Initialize distances to infinity
    }
    dist[0] = 0; // Starting point

    for (int loop = 0; loop < N; loop++) {
        for (int i = 0; i < M; i++) {
            if (dist[a[i] - 1] == Inf) {
                continue;
            }
            if (dist[b[i] - 1] > dist[a[i] - 1] + c[i]) {
                dist[b[i] - 1] = dist[a[i] - 1] + c[i]; // Update distance
            }
        }
    }

    long long ans = dist[N - 1]; // Final distance to the last node
    bool navigate[N] = {false}; // Track reachable nodes

    for (int loop = 0; loop < N; loop++) {
        for (int i = 0; i < M; i++) {
            if (dist[a[i] - 1] == Inf) {
                continue;
            }
            if (dist[b[i] - 1] > dist[a[i] - 1] + c[i]) {
                dist[b[i] - 1] = dist[a[i] - 1] + c[i];
                navigate[b[i] - 1] = true; // Mark as reachable
            }
            if (navigate[a[i] - 1] == true) {
                navigate[b[i] - 1] = true; // Propagate reachability
            }
        }
    }

    if (navigate[N - 1]) {
        printf("inf\n");
    } else {
        printf("%lld\n", -ans); // Output the result
    }

    return 0;
}
