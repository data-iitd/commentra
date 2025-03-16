
#include <stdio.h>
#include <limits.h>

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    int Inf = INT_MAX; // Using INT_MAX for infinity, considering the maximum possible distance

    int a[M], b[M], c[M];
    for (int i = 0; i < M; i++) {
        scanf("%d %d %d", &a[i], &b[i], &c[i]);
        c[i] = -c[i]; // Negate the weights for the algorithm (to handle maximization)
    }

    int dist[N];
    for (int i = 0; i < N; i++) {
        dist[i] = Inf; // Set all distances to infinity initially
    }
    dist[0] = 0; // The starting vertex (0) has a distance of 0

    for (int loop = 0; loop < N; loop++) {
        for (int i = 0; i < M; i++) {
            // Skip if the starting vertex distance is infinity (not reachable)
            if (dist[a[i]-1] == Inf) {
                continue;
            }
            // If a shorter path to vertex b[i] is found, update the distance
            if (dist[b[i]-1] > dist[a[i]-1]+c[i]) {
                dist[b[i]-1] = dist[a[i]-1] + c[i]; // Update the distance to b[i]
            }
        }
    }

    int ans = dist[N-1]; // The answer is the distance to the last vertex
    bool navigate[N]; // Array to track reachable vertices

    for (int loop = 0; loop < N; loop++) {
        for (int i = 0; i < M; i++) {
            // Skip if the starting vertex distance is infinity (not reachable)
            if (dist[a[i]-1] == Inf) {
                continue;
            }
            // If a shorter path to vertex b[i] is found, update the distance and mark it as reachable
            if (dist[b[i]-1] > dist[a[i]-1]+c[i]) {
                dist[b[i]-1] = dist[a[i]-1] + c[i];
                navigate[b[i]-1] = true; // Mark b[i] as reachable
            }
            // If a[i] is reachable, then b[i] is also reachable
            if (navigate[a[i]-1] == true) {
                navigate[b[i]-1] = true;
            }
        }
    }

    if (navigate[N-1]) {
        printf("inf\n"); // If the last vertex is reachable, print "inf" (indicating a negative cycle)
    } else {
        printf("%d\n", -ans); // Otherwise, print the negative of the answer (since weights were negated)
    }

    return 0;
}
